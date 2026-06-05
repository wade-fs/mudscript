// cmd/fs/main.go
package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"net"
	"net/http"
	"time"

	"mudscript" // 導入根目錄 package 以取得 Assets
	"mudscript/driver"
	"mudscript/internal/signaling"
)

func main() {
	port := flag.String("port", "4000", "Telnet/TCP server port")
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

	// 3. 啟動 TCP Telnet 伺服器
	go startTelnetServer(d, *port)

	// 4. 初始化 WebSocket 信令中心 (僅用於網頁連線，不啟用 P2P Hub 轉發)
	hub := signaling.NewHub(d) 
	go hub.Run()

	// 5. 設定 HTTP 與 WebSocket 路由
	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Legacy FS Server is running. Connect to /ws for websocket, or use telnet on port %s", *port)
	})

	// 6. 啟動 Web 伺服器
	log.Printf("Legacy FS Web 介面監聽中 :%s\n", *webPort)
	err := http.ListenAndServe(":"+*webPort, nil)
	if err != nil {
		panic(err)
	}
}

func startTelnetServer(d *driver.Driver, port string) {
	ln, err := net.Listen("tcp", ":"+port)
	if err != nil {
		log.Fatalf("無法啟動 Telnet 伺服器: %v", err)
	}
	log.Printf("Legacy FS Telnet 伺服器監聽中 :%s\n", port)

	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Printf("接受連線失敗: %v", err)
			continue
		}

		go handleTelnetConnection(d, conn)
	}
}

func handleTelnetConnection(d *driver.Driver, conn net.Conn) {
	// 建立玩家連線物件
	pConn := driver.NewPlayerConnection(conn, nil)

	// 呼叫 Master Object 的 connect 取得 Login 物件
	// 傳統 Telnet 通常不帶語系參數，這裡傳入 0 或空字串
	userObj := d.AcceptConnection(pConn, 0)
	if userObj == nil {
		conn.Write([]byte("系統目前無法接受連線。\r\n"))
		conn.Close()
		return
	}

	pConn.Object = userObj
	d.RegisterInteractive(userObj, pConn)

	// 啟動指令讀取迴圈
	log.Printf("新 Telnet 連線: %s -> %s", conn.RemoteAddr(), userObj.Filename)

	// 執行登入初始化
	d.RunCommand(pConn, userObj, "logon", nil)

	scanner := bufio.NewScanner(conn)
	for scanner.Scan() {
		input := scanner.Text()
		d.ProcessCommand(pConn, input)
	}

	log.Printf("Telnet 連線中斷: %s", conn.RemoteAddr())
	d.UnregisterInteractive(userObj)
	conn.Close()
}

