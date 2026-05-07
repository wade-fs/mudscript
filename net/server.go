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
	
	// 取得登入物件
	loginObj := s.Driver.AcceptConnection()
	if loginObj == nil {
		conn.Write([]byte("系統忙碌中，請稍後再試。\n"))
		conn.Close()
		return
	}

	// [修改] 使用新的工廠函式建立帶有 TCP Buffer 的連線
	pConn := driver.NewPlayerConnection(conn, loginObj)
	
	// [關鍵] 將這個物件註冊為「互動中的玩家」，讓 tell_object 找得到
	s.Driver.RegisterInteractive(loginObj, pConn)
	defer s.Driver.UnregisterInteractive(loginObj)

	s.servePlayer(pConn)
}

func (s *TelnetServer) servePlayer(p *driver.PlayerConnection) {
	defer p.Conn.Close()
	p.Send("\r\n[系統] 歡迎來到 MudScript！\r\n> ")

	reader := bufio.NewReader(p.Conn)
	var inputBuffer []byte

	for p.IsActive {
		b, err := reader.ReadByte()
		if err != nil { break }

		if b == 255 {
			cmd, err := reader.ReadByte()
			if err != nil { break }
			if cmd >= 251 && cmd <= 254 { reader.ReadByte() }
			continue
		}

		if b == 8 || b == 127 {
			if len(inputBuffer) > 0 {
				inputBuffer = inputBuffer[:len(inputBuffer)-1]
				p.Send("\b \b") 
			}
			continue
		}

		if b == '\n' || b == '\r' {
			if len(inputBuffer) == 0 {
				p.Send("\r\n> ")
				continue
			}

			p.Send("\r\n") 
			rawLine := string(inputBuffer)
			inputBuffer = nil
			
			input := s.cleanInput(rawLine)
			
			// [新增] 展開命令歷史 (! 系列)
			finalInput := p.ExpandHistory(input)
			
			// [新增] 內部指令攔截：如果玩家輸入 history，直接由底層回傳
			if finalInput == "history" {
				p.Send("--- 命令歷史 ---\r\n")
				for i, cmd := range p.History {
					p.Send(fmt.Sprintf("%2d. %s\r\n", i+1, cmd))
				}
				p.Send("> ")
				continue
			}

			if finalInput != "" {
				s.Driver.RunCommand(p, p.Object, "process_input", []object.Object{&object.String{Value: finalInput}})
			}

			p.Send("> ")
			continue
		}

		if b >= 32 && b <= 126 {
			inputBuffer = append(inputBuffer, b)
			p.Send(string(b)) 
		}
	}
}

func (s *TelnetServer) cleanInput(in string) string {
	return strings.TrimSpace(in)
}
