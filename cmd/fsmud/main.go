// cmd/webmud/main.go
package main

import (
	"fmt"
	"io/fs"
	"log"
	"net/http"
	"os"

	"mudscript" // 導入根目錄 package 以取得 Assets
	"mudscript/driver"
	"mudscript/internal/signaling"
)

func main() {
	log.Println("正在初始化 WebMUD 伺服器 (Hybrid 模式)...")

	// 1. 準備 MUD 引擎配置
	config := driver.DriverConfig{
		MudLibPath:    "./mudlib",
		MasterFile:    "/master.c",
		HeartBeatTick: 0, 
		EmbeddedFS:    mudscript.Assets, 
	}

	// 2. 初始化 MUD 腳本引擎
	d := driver.New(config)
	
	if err := d.Start(); err != nil {
		panic(err)
	}
	log.Println("MUD 引擎啟動成功！")

	// 3. 初始化 WebSocket 與 P2P 信令中心
	hub := signaling.NewHub(d) 
	go hub.Run()

	// 4. 設定 HTTP 與 WebSocket 路由
	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	// 🚀 混合模式網頁服務
	setupStaticServer()

	// 5. 啟動 Web 伺服器
	log.Println("Web 伺服器監聽中 :8080")
	err := http.ListenAndServe(":8080", nil)
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
