// cmd/fs/main.go
package main

import (
	"flag"
	"fmt"
	"io/fs"
	"log"
	"net/http"
	"os"
	"time"

	"mudscript" // 導入根目錄 package 以取得 Assets
	"mudscript/driver"
	"mudscript/internal/signaling"
)

func main() {
	webPort := flag.String("webport", "4444", "HTTP server port")
	mudlib := flag.String("mudlib", "fs", "mudlib directory")
	master := flag.String("master", "/adm/obj/master.c", "Master of world in mudlib directory")
	simul := flag.String("simul", "/adm/obj/simul_efun.c", "SimulEfun file path")
	gInclude := flag.String("ginclude", "globals.h", "Global include file (e.g. globals.h)")
	flag.Parse()

	log.Println("正在初始化 Legacy FS MUD 伺服器...")

	// 1. 準備 MUD 引擎配置
	config := driver.DriverConfig{
		MudLibPath:      *mudlib,
		MasterFile:      *master,
		SimulEfunFile:   *simul,
		GlobalInclude:   *gInclude,
		StripModifiers:  true, // 🚀 關鍵：針對 Legacy FS 剝除函式修飾詞
		HeartBeatTick:   2 * time.Second, 
		CleanUpInterval: 15 * time.Minute,
		EmbeddedFS:      mudscript.Assets, 
	}

	// 2. 初始化 MUD 腳本引擎
	d := driver.New(config)

	if err := d.Start(); err != nil {
		log.Fatalf("致命錯誤: %v", err)
	}
	log.Println("MUD 引擎啟動成功！")

	// 4. 初始化 WebSocket 信令中心 (僅用於網頁連線，不啟用 P2P Hub 轉發)
	hub := signaling.NewHub(d) 
	go hub.Run()

	// 🚀 新增：同步玩家名稱至信令中心
	d.OnUsernameUpdate = func(sid, newName string) {
		hub.UpdateClientUsername(sid, newName)
	}

	// 5. 設定 HTTP 與 WebSocket 路由
	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	// 🚀 混合模式網頁服務
	setupStaticServer()

	// 6. 啟動 Web 伺服器
	log.Printf("Legacy FS Web 介面監聽中 :%s\n", *webPort)
	err := http.ListenAndServe(":"+*webPort, nil)
	if err != nil {
		panic(err)
	}
}

func setupStaticServer() {
	diskPath := "./fs/web/static"

	if info, err := os.Stat(diskPath); err == nil && info.IsDir() {
		log.Println("🌐 [WEB] 使用外部磁碟網頁檔案 (支援熱更新)")
		http.Handle("/", http.FileServer(http.Dir(diskPath)))
	} else {
		log.Println("📦 [WEB] 使用內建嵌入網頁檔案")
		subFS, err := fs.Sub(mudscript.Assets, "fs/web/static")
		if err != nil {
			panic(fmt.Sprintf("無法開啟嵌入網頁目錄: %v", err))
		}
		http.Handle("/", http.FileServer(http.FS(subFS)))
	}
}

