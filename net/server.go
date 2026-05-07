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
		// 逐字元讀取，不被特定換行符鎖死
		b, err := reader.ReadByte()
		if err != nil {
			fmt.Println("DEBUG: 玩家離線")
			break
		}

		if b == '\n' || b == '\r' {
			if len(inputBuffer) == 0 {
				p.Send("> ")
				continue
			}

			rawLine := string(inputBuffer)
			inputBuffer = nil

			input := s.cleanInput(rawLine)
			if input == "" {
				p.Send("> ")
				continue
			}

			// 魔法：呼叫 RunCommand！這會自動幫我們設定好 this_player()
			s.Driver.RunCommand(p, p.Object, "process_input", []object.Object{&object.String{Value: input}})
			
			p.Send("> ")
			continue
		}

		// 只保留可見字元
		if b >= 32 && b <= 126 {
			inputBuffer = append(inputBuffer, b)
		}
	}
}

func (s *TelnetServer) cleanInput(in string) string {
	return strings.TrimSpace(in)
}
