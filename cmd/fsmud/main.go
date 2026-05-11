// cmd/webmud/main.go  (您可以取名為 webmud 或直接覆蓋原本的 main)
package main

import (
	"log"
	"net/http"

	"mudscript/driver"
	"mudscript/internal/signaling"
)

func main() {
	log.Println("正在初始化 WebMUD 伺服器...")

	// 1. 初始化 MUD 腳本引擎 (邏輯大腦)
	d := driver.New(driver.DriverConfig{
		MudLibPath: "./mudlib",
		MasterFile: "/master.c",
	})
	
	if err := d.Start(); err != nil {
		panic(err)
	}
	log.Println("MUD 引擎啟動成功！")

	// 2. 初始化 WebSocket 與 P2P 信令中心 (網路大腦)
	// 👉 注意：我們將 MUD Driver 注入到 Hub 中，讓 Hub 可以呼叫遊戲邏輯
	hub := signaling.NewHub(d) 
	go hub.Run()

	// 3. 設定 HTTP 與 WebSocket 路由
	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	// 靜態網頁服務 (您的 P2P Chat 與 MUD 前端畫面)
	http.Handle("/", http.FileServer(http.Dir("./web/static")))

	// 4. 啟動 Web 伺服器
	log.Println("Web 伺服器監聽中 :8080")
	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		panic(err)
	}
}
