// cmd/fs/main.go
package main

import (
	"flag"
	"fmt"
	"log"
	"net/http"
	"time"

	"mudscript" // 導入根目錄 package 以取得 Assets
	"mudscript/driver"
	"mudscript/internal/signaling"
)

func main() {
	port := flag.String("port", "4000", "HTTP server port")
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

	// 3. 初始化 WebSocket 信令中心 (僅用於網頁連線，不啟用 P2P Hub 轉發)
	hub := signaling.NewHub(d) 
	go hub.Run()

	// 4. 設定 HTTP 與 WebSocket 路由
	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Legacy FS Server is running. Connect to /ws for websocket.")
	})

	// 5. 啟動 Web 伺服器
	log.Printf("Legacy FS 伺服器監聽中 :%s\n", *port)
	err := http.ListenAndServe(":"+*port, nil)
	if err != nil {
		panic(err)
	}
}
