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

	// 3. 初始化 WebSocket 與 P2P 信令中心 (若為 Hub 模式)
	spaceID := os.Getenv("SPACE_ID")
	normalizedSpaceID := strings.ReplaceAll(spaceID, "/", "-")
	isHubMode := spaceID != "" && (strings.Contains(*hubURL, normalizedSpaceID) || strings.Contains(*hubURL, "localhost") || *hubURL == "none")

	var hub *signaling.Hub
	if isHubMode {
		hub = signaling.NewHub(d)
		go hub.Run()
		log.Println("🌟 偵測到雲端環境，啟動本地星際信令中心 (Signaling Hub) 於 /ws")

		// 🚀 只有在 Hub 模式下才需要同步玩家名稱到全域
		d.OnUsernameUpdate = func(sid, newName string) {
			if hub != nil {
				hub.UpdateClientUsername(sid, newName)
			}
		}
	}

	// 4. 🚀 P2P 整合核心：雙向連結驅動與信令系統
	var node *p2p.Node

	// 連結 P2P -> MUD (接收訊息)
	d.OnP2PMessage = func(senderID, senderName, content string) {
		// 🚀 關鍵修正：支援 __P2P_IGNORE__ 標記
		// 如果訊息是以此標記開頭，代表是發送者不希望自己重複處理 (避免 loop)
		if strings.HasPrefix(content, "__P2P_IGNORE__") {
			content = strings.TrimPrefix(content, "__P2P_IGNORE__")
			
			// 只有當發送者 UUID 等於本機 UUID 時才略過
			// (注意：如果是 Hub 本身發出的系統訊息，senderID 會是 "local")
			isSelf := (node != nil && senderID == node.ID) || (senderID == "local")
			if isSelf {
				log.Printf("🌌 [P2P] 略過本機發出的訊息: %s", content)
				return
			}
		}

		log.Printf("🌌 [P2P] 收到來自 %s(%s) 的訊息: %s", senderName, senderID, content)
		// Hub 模式：只處理一般聊天，不處理協議封包 (避免重複處理)
		if isHubMode && (strings.HasPrefix(content, "fs_session|") ||
			strings.HasPrefix(content, "fs_query|") ||
			strings.HasPrefix(content, "fs_resp|") ||
			strings.HasPrefix(content, "fs_presence|") ||
			strings.HasPrefix(content, "dist_msg|") ||
			strings.Contains(content, "\"tag\":\"")) {
			return
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
	isRemoteHub := *hubURL != "" && *hubURL != "none" && !isHubMode
	
	if isRemoteHub {
		node = p2p.NewNode(d, *hubURL)
		
		d.P2PSendChat = func(sender, content string) {
			node.SendChat(sender, content)
		}

		node.Start()
		log.Println("🚀 P2P 節點已啟動，連接至:", *hubURL)
	} else {
		// 如果自己是信令中心，直接透過 hub 廣播
		d.P2PSendChat = func(sender, content string) {
			if hub != nil {
				hub.BroadcastChat(sender, content)
			}
		}
	}

	// 5. 設定 HTTP 與 WebSocket 路由
	if hub != nil {
		http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
			signaling.HandleWS(hub, w, r)
		})
	}

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
