// net/server.go
package net

import (
	"bufio"
	"fmt"
	"net"
	"strings"

	"mudscript/driver"
	"mudscript/object"
)

type TelnetServer struct {
	Port   int
	Driver *driver.Driver
}

func NewServer(port int, d *driver.Driver) *TelnetServer {
	return &TelnetServer{Port: port, Driver: d}
}

func (s *TelnetServer) Listen() error {
	listener, err := net.Listen("tcp", fmt.Sprintf(":%d", s.Port))
	if err != nil {
		return err
	}
	defer listener.Close()

	fmt.Printf("📡 MUD Telnet Server 啟動於埠號 %d...\n", s.Port)

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Printf("⚠️ 連線接受失敗: %v\n", err)
			continue
		}

		// 交給獨立的 goroutine 處理
		go s.handleConnection(conn)
	}
}

func (s *TelnetServer) handleConnection(conn net.Conn) {
	conn.Write([]byte{255, 251, 1, 255, 251, 3})
	
	pConn := &driver.PlayerConnection{
		Conn:     conn,
		IsActive: true,
	}

	loginObj := s.Driver.AcceptConnection()
	if loginObj == nil {
		conn.Write([]byte("系統忙碌中，請稍後再試。\n"))
		conn.Close()
		return
	}
	pConn.Object = loginObj

	s.servePlayer(pConn)
}

func (s *TelnetServer) servePlayer(p *driver.PlayerConnection) {
	defer p.Conn.Close()
	p.Send("\r\n[系統] 歡迎來到 MudScript！\r\n> ")

	reader := bufio.NewReader(p.Conn)
	var inputBuffer []byte

	for p.IsActive {
		b, err := reader.ReadByte()
		if err != nil {
			fmt.Println("DEBUG: 玩家離線")
			break
		}

		// ==========================================
		// 1. 處理 Telnet IAC (Interpret As Command)
		// ==========================================
		if b == 255 {
			// Telnet 協商指令通常是 2~3 bytes
			cmd, err := reader.ReadByte()
			if err != nil { break }

			// WILL(251), WONT(252), DO(253), DONT(254) 後面會跟著一個選項 byte
			if cmd >= 251 && cmd <= 254 {
				reader.ReadByte() // 吃掉選項位元組 (例如 ECHO, SGA 等)
			}
			continue // 忽略控制碼，繼續讀下一個字元
		}

		// ==========================================
		// 2. 處理退格鍵 Backspace (Ctrl+H) 或 Delete
		// ==========================================
		if b == 8 || b == 127 {
			if len(inputBuffer) > 0 {
				inputBuffer = inputBuffer[:len(inputBuffer)-1] // 從緩衝區移除最後一個字元
				
				// 【視覺魔法】讓客戶端的游標退後一格 -> 印出空白蓋掉字元 -> 再退後一格
				p.Send("\b \b") 
			}
			continue
		}

		// ==========================================
		// 3. 處理換行 (Enter 鍵)
		// ==========================================
		if b == '\n' || b == '\r' {
			if len(inputBuffer) == 0 {
				p.Send("\r\n> ") // 空行直接給新提示符
				continue
			}

			// 玩家按下 Enter 時，伺服器先回傳一個換行，讓畫面排版往下跳
			p.Send("\r\n") 

			// 取出緩衝區內容並清空
			rawLine := string(inputBuffer)
			inputBuffer = nil
			
			input := strings.TrimSpace(rawLine)
			if input != "" {
				// 呼叫指令處理
				s.Driver.RunCommand(p, p.Object, "process_input", []object.Object{&object.String{Value: input}})
			}

			p.Send("> ")
			continue
		}

		// ==========================================
		// 4. 一般可見字元與伺服器回顯 (Echo)
		// ==========================================
		if b >= 32 && b <= 126 {
			inputBuffer = append(inputBuffer, b)
			
			// 【實作 WILL ECHO 的承諾】將收到的字元即時印回給客戶端！
			p.Send(string(b)) 
		}
	}
}

func (s *TelnetServer) cleanInput(in string) string {
	return strings.TrimSpace(in)
}
