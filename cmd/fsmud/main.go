// cmd/webmud/main.go
package main

import (
	"flag"
	"fmt"
	"io/fs"
	"log"
	"net/http"
	"os"
	"strings"
	"time"

	"mudscript" // 導入根目錄 package 以取得 Assets
	"mudscript/driver"
	"mudscript/internal/p2p"
	"mudscript/internal/signaling"
	"mudscript/object"
)

func main() {
	hubURL := flag.String("hub", "wss://wade-fs-fsmud-hub.hf.space/ws", "Signaling hub URL (set to 'none' to run in isolation)")
	port := flag.String("port", "8080", "HTTP server port")
	flag.Parse()

	log.Println("正在初始化 WebMUD 伺服器 (Hybrid 模式)...")

	// 1. 準備 MUD 引擎配置
	config := driver.DriverConfig{
		MudLibPath:      "./mudlib",
		MasterFile:      "/master.c",
		HeartBeatTick:   0, 
		CleanUpInterval: 5 * time.Minute, // 🚀 新增：5分鐘執行一次 GC
		EmbeddedFS:      mudscript.Assets, 
	}

	// 2. 初始化 MUD 腳本引擎
	d := driver.New(config)
	
	if err := d.Start(); err != nil {
		panic(err)
	}
	log.Println("MUD 引擎啟動成功！")

	// 3. 初始化 WebSocket 與 P2P 信令中心 (每個節點都有一套，處理自己的 Web 玩家)
	hub := signaling.NewHub(d)
	go hub.Run()

	// 🚀 新增：同步玩家名稱至信令中心
	d.OnUsernameUpdate = func(sid, newName string) {
		hub.UpdateClientUsername(sid, newName)
	}

	// 4. 🚀 P2P 整合核心：雙向連結驅動與信令系統
	var node *p2p.Node

	// A. 偵測是否為雲端 Hub 模式 (決定是否要對外連線)
	// Hugging Face 的 SPACE_ID 可能是 "user/space-name"，但 URL 會是 "user-space-name.hf.space"
	spaceID := os.Getenv("SPACE_ID")
	normalizedSpaceID := strings.ReplaceAll(spaceID, "/", "-")
	
	// 如果 hubURL 包含自己的 SpaceID，或者指向 localhost，或者設為 none，我們就認定自己是 Hub 中心
	isHubMode := spaceID != "" && strings.Contains(*hubURL, normalizedSpaceID)
	if *hubURL == "none" || strings.Contains(*hubURL, "localhost") {
		isHubMode = true
	}

	// 連結 P2P -> MUD (接收訊息)
	d.OnP2PMessage = func(senderID, senderName, content string) {
		// 🚀 關鍵修正：支援 __P2P_IGNORE__ 標記
		// 如果訊息是以此標記開頭，代表是發送者不希望自己重複處理 (避免 loop)
		if strings.HasPrefix(content, "__P2P_IGNORE__") {
			content = strings.TrimPrefix(content, "__P2P_IGNORE__")
			
			// 🚀 核心邏輯：判定是否為「回環」訊息
			isSelf := false
			if node != nil && senderID == node.ID {
				// 情況 A：訊息是從本機 P2P Node 發出並繞回來的
				isSelf = true
			} else if isHubMode && senderID == "local" {
				// 情況 B：訊息是本機 Hub 廣播中心發出的
				isSelf = true
			}

			if isSelf {
				log.Printf("🌌 [P2P] 略過本機發出的訊息: %s", content)
				return
			}
		}

		log.Printf("🌌 [P2P] 收到來自 %s(%s) 的訊息: %s", senderName, senderID, content)
		
		// Hub 路由過濾策略：
		// 1. 如果本機是 Hub 中心，且這是一則協議封包 (fs_session, fs_query 等)
		// 2. 且該封包的「目標」不是本機也不是廣播，則 Hub 僅負責轉發，不送入本機 MUD 處理以免重複。
		if isHubMode && (strings.HasPrefix(content, "fs_session|") ||
			strings.HasPrefix(content, "fs_query|") ||
			strings.HasPrefix(content, "fs_resp|") ||
			strings.HasPrefix(content, "fs_presence|") ||
			strings.HasPrefix(content, "dist_msg|") ||
			strings.Contains(content, "\"tag\":")) {
			
			// 🚀 關鍵判定：檢查 JSON 中的 "to" 欄位
			// 如果目標不是本機 MUD ID (例如 "fantasy.space") 且不是廣播 "*"，則略過
			// 這裡為了效能，簡單判定：如果內容中沒出現自己的 mudlib_id 或 "*"，就略過
			// (注意：這裡的判定較為寬鬆，後續在 interstellar_d.c 還會有一層精確比對)
			systemD, _ := d.LoadObject("/secure/system_d.c")
			myID := "unnamed.mud"
			if systemD != nil {
				if res := d.CallFunction(systemD, "query_mudlib_id", nil); res != nil {
					if s, ok := res.(*object.String); ok {
						myID = s.Value
					}
				}
			}

			// 如果是協議封包且目標不是我，則 Hub 只負責轉發（Hub 核心已在 signaling/hub.go 轉發了），這裡直接 return
			if !strings.Contains(content, "\""+myID+"\"") && !strings.Contains(content, "\"*\"") &&
			   !strings.Contains(content, "|"+myID+"|") && !strings.Contains(content, "|*|") {
				return
			}
		}

		interstellar, err := d.LoadObject("/secure/interstellar_d.c")
		if err == nil && interstellar != nil {
			msgType := "chat"
			if strings.HasPrefix(senderName, "SYSTEM") {
				msgType = "system"
			}
			d.CallFunction(interstellar, "receive_p2p_message", []object.Object{
				&object.String{Value: senderName},
				&object.String{Value: content},
				&object.String{Value: msgType},
			})
		}
	}

	// B. 連結 MUD -> P2P (發送訊息)
	// 如果不是 Hub 模式且 URL 不是 none，則建立連線到遠端 Hub
	if !isHubMode && *hubURL != "" && *hubURL != "none" {
		node = p2p.NewNode(d, *hubURL)
		
		d.P2PSendChat = func(sender, content string) {
			node.SendChat(sender, content)
		}

		node.Start()
		log.Println("🚀 P2P 節點已啟動，連接至:", *hubURL)
	} else {
		// 如果自己是信令中心，直接透過自己的 hub 廣播
		log.Println("🌟 以星際信令中心 (Signaling Hub) 模式執行。")
		d.P2PSendChat = func(sender, content string) {
			hub.BroadcastChat(sender, content)
		}
	}

	// 5. 設定 HTTP 與 WebSocket 路由
	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	// 🚀 混合模式網頁服務
	setupStaticServer()

	// 6. 啟動 Web 伺服器
	log.Printf("Web 伺服器監聽中 :%s\n", *port)
	err := http.ListenAndServe(":"+*port, nil)
	if err != nil {
		panic(err)
	}
}

func setupStaticServer() {
	diskPath := "./web/static"
	
	if info, err := os.Stat(diskPath); err == nil && info.IsDir() {
		log.Println("🌐 [WEB] 使用外部磁碟網頁檔案 (支援熱更新)")
		http.Handle("/", http.FileServer(http.Dir(diskPath)))
	} else {
		log.Println("📦 [WEB] 使用內建嵌入網頁檔案")
		subFS, err := fs.Sub(mudscript.Assets, "web/static")
		if err != nil {
			panic(fmt.Sprintf("無法開啟嵌入網頁目錄: %v", err))
		}
		http.Handle("/", http.FileServer(http.FS(subFS)))
	}
}
