// cmd/fs/main.go
package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"net"
	"net/http"
	_ "net/http/pprof"
	"os"
	"os/signal"
	"path/filepath"
	"runtime/pprof"
	"strings"
	"syscall"
	"time"

	"mudscript/driver"
	"mudscript/fs"
	"mudscript/object"
)

func main() {
	// 🚀 新增：自動記憶體剖析 dump
	go func() {
		http.ListenAndServe("localhost:6060", nil)
	}()

	defer func() {
		wd, _ := os.Getwd()
		path := filepath.Join(wd, "mem.prof")
		f, err := os.Create(path)
		if err != nil {
			log.Printf("無法建立記憶體剖析檔 (%s): %v\n", path, err)
			return
		}
		pprof.WriteHeapProfile(f)
		f.Close()
		log.Printf("記憶體剖析檔已寫入 %s\n", path)
	}()

	port := flag.String("port", "4000", "Telnet server port")
	ml := flag.String("mudlib", "./fs", "mudlib path")
	master := flag.String("master", "adm/obj/master.c", "master.c relative to mudlib")
	flag.Parse()

	log.Println("正在初始化 Legacy MUD 伺服器 in ", *ml, "/", *master)

	// 動態決定 EmbeddedPath，例如 "./fs" -> "fs"
	embeddedPath := strings.TrimPrefix(*ml, "./")

	// 1. 準備 MUD 引擎配置
	config := driver.DriverConfig{
		MudLibPath:      *ml,
		MasterFile:      *master,
		HeartBeatTick:   2 * time.Second, 
		CleanUpInterval: 15 * time.Minute,
		EmbeddedFS:      fs.Assets, 
		EmbeddedPath:    embeddedPath,
		GlobalInclude:   "/include/globals.h",     // 🚀 Legacy Mudlib 需要自動引入 globals.h
		SimulEfunFile:   "/adm/obj/simul_efun.c", // 🚀 指定 SimulEfun 路徑
	}

	// 2. 初始化 MUD 腳本引擎
	fmt.Println("MAIN: Calling driver.New...")
	d := driver.New(config)
	fmt.Println("MAIN: driver.New returned.")

	// 🚀 新增：捕捉系統訊號以支援優雅關機
	sigCh := make(chan os.Signal, 1)
	signal.Notify(sigCh, os.Interrupt, syscall.SIGTERM)
	go func() {
		<-sigCh
		log.Println("\n🛑 收到系統中斷訊號，正在關閉伺服器...")
		d.Stop()
		os.Exit(0)
	}()

	// 🚀 新增：支援從控制台直接輸入指令關機
	go func() {
		scanner := bufio.NewScanner(os.Stdin)
		for scanner.Scan() {
			cmd := strings.ToLower(strings.TrimSpace(scanner.Text()))
			if cmd == "exit" || cmd == "quit" || cmd == "shutdown" {
				log.Println("🛑 從控制台收到關機指令，正在關閉伺服器...")
				d.Stop()
				os.Exit(0)
			}
		}
	}()

	if err := d.Start(); err != nil {
		panic(err)
	}
	log.Println("MUD 引擎啟動成功！")

	// 3. 啟動 TCP 監聽 (Telnet)
	listener, err := net.Listen("tcp", ":"+*port)
	if err != nil {
		log.Fatalf("無法啟動監聽: %v", err)
	}
	log.Printf("Telnet 伺服器監聽中 :%s\n", *port)
    log.Printf("DEBUG: Entering listener loop\n")

	portInt := 4000
	fmt.Sscanf(*port, "%d", &portInt)

	// 🚀 新增：自動測試流程模擬玩家登入
	if os.Getenv("MUD_TEST_MODE") != "" {
		go func() {
			time.Sleep(1 * time.Second) // 等待伺服器啟動
			conn, err := net.Dial("tcp", "127.0.0.1:"+*port)
			if err != nil {
				log.Printf("自動測試連線失敗: %v", err)
				os.Exit(1)
			}
			defer conn.Close()

			reader := bufio.NewReader(conn)
			go func() {
				buf := make([]byte, 1024)
				for {
					n, err := reader.Read(buf)
					if err != nil { return }
					// 🚀 直接輸出原始位元組，避免 Go 字串轉換破壞 Big5
					fmt.Print(string(buf[:n]))
				}
			}()

			time.Sleep(1 * time.Second)

			if os.Getenv("GUEST_TEST") != "" {
				fmt.Println("\n🤖 [AutoTest] 送出帳號: guest")
				conn.Write([]byte("guest\r\n"))
				time.Sleep(2 * time.Second)
				fmt.Println("🤖 [AutoTest] 送出: Enter")
				conn.Write([]byte("\r\n"))
				time.Sleep(2 * time.Second)
				fmt.Println("🤖 [AutoTest] 送出: look")
				conn.Write([]byte("look\r\n"))
				time.Sleep(5 * time.Second)
				fmt.Println("\n🤖 [AutoTest] 測試完成 (Guest)，準備關閉...")
				return
			}

			fmt.Println("🤖 [AutoTest] 送出帳號: wade")
			conn.Write([]byte("wade\r\n"))

			time.Sleep(1 * time.Second)
			fmt.Println("🤖 [AutoTest] 送出: y")
			conn.Write([]byte("y\r\n"))

			time.Sleep(1 * time.Second)
			fmt.Println("🤖 [AutoTest] 送出中文名字: 菠蘿麵包")
			// 由於 fs/ 使用 Big5 邏輯，我們需要送出 Big5 編碼的字串才能通過 check_legal_name
			// "菠蘿麵包" 的 Big5 編碼 (這裡使用硬編碼以避免依賴 x/text 模組增加編譯複雜度)
			big5Name := []byte{0xbd, 0x5d, 0xc1, 0x56, 0xc4, 0xd1, 0xa5, 0x5d, '\r', '\n'}
			conn.Write(big5Name)

			time.Sleep(1 * time.Second)
			fmt.Println("🤖 [AutoTest] 送出密碼")
			conn.Write([]byte("testpwd\r\n"))

			time.Sleep(1 * time.Second)
			fmt.Println("🤖 [AutoTest] 再次送出密碼確認")
			conn.Write([]byte("testpwd\r\n"))

			time.Sleep(2 * time.Second)
			fmt.Println("🤖 [AutoTest] 測試完成，準備關閉...")
			os.Exit(0)
		}()
	}

	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Printf("Accept 錯誤: %v", err)
			continue
		}
		go handleConnection(d, conn, portInt)
	}
}

func handleConnection(d *driver.Driver, conn net.Conn, port int) {
	log.Printf("DEBUG: handleConnection called for %s\n", conn.RemoteAddr().String())
	// 1. 建立玩家連線物件
	pConn := driver.NewPlayerConnection(conn, nil)
	
	// 2. 透過 Master 物件接受連線 (取得 Login Object)
	userObj := d.AcceptConnection(pConn, port)
	if userObj == nil {
		conn.Write([]byte("系統暫時無法接受連線。\r\n"))
		conn.Close()
		return
	}

	pConn.Object = userObj
	d.RegisterInteractive(userObj, pConn)

	// 3. 執行 logon()
	d.RunCommand(pConn, userObj, "logon", nil)

	// 4. 輸入處理迴圈
	scanner := bufio.NewScanner(conn)
	// fmt.Printf("DEBUG: 開始輸入迴圈 (%s)\n", pConn.Object.Filename)
	for scanner.Scan() {
		input := scanner.Text()
		log.Printf("DEBUG: handleConnection received: '%s'\n", input)
		
		// 簡單過濾 Telnet 控制字元 (IAC)
		if strings.HasPrefix(input, "\xff") {
			continue // 忽略單純的 Telnet 協商封包
		}
		
		// 清理可能的不可見字元
		input = strings.Map(func(r rune) rune {
			if r == '\x00' || r == '\r' || r == '\n' {
				return -1
			}
			return r
		}, input)

		// 處理指令
		processInput(d, pConn, input)
	}

	// 連線中斷處理
	if userObj != nil {
		d.RunCommand(pConn, userObj, "net_dead", nil)
		d.UnregisterInteractive(userObj)
	}
	pConn.Close()
}

func processInput(d *driver.Driver, p *driver.PlayerConnection, input string) {
	log.Printf("DEBUG: processInput received input: '%s'\n", input)
	
	// 🚀 關鍵修正：如果有 callback 等待中，不應因為 input 為空就直接 return
	if p.NextInputFunc == "" && p.NextInputClosure == nil {
		input = strings.TrimSpace(input)
		if input == "" {
			return
		}
	}

	log.Printf("DEBUG: processInput - Input: '%s', NextInputFunc: '%s', InputHidden: %v\n", input, p.NextInputFunc, p.InputHidden)
	// 處理 NextInputFunc (如密碼輸入或 input_to)
	if p.NextInputFunc != "" || p.NextInputClosure != nil {
		targetObj := p.Object
		if p.NextInputObj != nil {
			targetObj = p.NextInputObj
		}

		var callback object.Object
		if p.NextInputClosure != nil {
			callback = p.NextInputClosure
		} else {
			callback = &object.String{Value: p.NextInputFunc}
		}

		// 準備參數：[輸入字串, 額外參數...]
		callbackArgs := []object.Object{&object.String{Value: input}}
		if p.NextInputArgs != nil {
			callbackArgs = append(callbackArgs, p.NextInputArgs...)
		}

		p.NextInputFunc = ""
		p.NextInputObj = nil
		p.NextInputClosure = nil
		p.NextInputArgs = nil // 🚀 使用後清除
		p.InputHidden = false
		log.Printf("DEBUG: processInput - State Reset, NextInputFunc cleared, InputHidden set to false\n")

		// 執行 callback
		res := d.ExecuteCallback(targetObj, callback, callbackArgs)
		if res != nil && res.TokenType() == object.ErrorType {
			p.Send(fmt.Sprintf("執行 callback 錯誤: %v\n", res))
		}
		return
	}

	handleInput(d, p, input)
}

func handleInput(d *driver.Driver, p *driver.PlayerConnection, input string) {
	if !d.ProcessCommand(p, input) {
		msg := "什麼？\n"
		if p.NotifyFail != "" {
			msg = p.NotifyFail
			p.NotifyFail = ""
		}
		d.TellObject(p.Object, msg)
	}
}

