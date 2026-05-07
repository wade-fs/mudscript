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
	// 1. 初始化 Telnet 協商 (IAC)
	// WILL ECHO, WILL SGA (Suppress Go Ahead)
	conn.Write([]byte{255, 251, 1, 255, 251, 3})
	conn.Write([]byte("\r\nMudScript 引擎連線成功！\r\n> "))

	pConn := &driver.PlayerConnection{
		Conn:     conn,
		Reader:   bufio.NewReader(conn),
		IsActive: true,
	}

	// 2. 呼叫 Driver 取得 master->connect() 分配的物件
	loginObj := s.Driver.AcceptConnection()
	if loginObj == nil {
		conn.Write([]byte("系統忙碌中，請稍後再試。\n"))
		conn.Close()
		return
	}
	pConn.Object = loginObj

	// 3. 進入輸入迴圈
	s.servePlayer(pConn)
}

func (s *TelnetServer) servePlayer(p *driver.PlayerConnection) {
	defer p.Conn.Close()
	fmt.Println("DEBUG: 玩家連線成功，啟動位元組讀取模式")

	reader := bufio.NewReader(p.Conn)
	var inputBuffer []byte

	for p.IsActive {
		// 逐字元讀取，避免被 \n 鎖死
		b, err := reader.ReadByte()
		if err != nil {
			fmt.Printf("DEBUG: 連線中斷 (%v)\n", err)
			break
		}

		// 判斷是否為換行 (支援 \n, \r)
		if b == '\n' || b == '\r' {
			if len(inputBuffer) == 0 {
				// 如果是空行 (連續的 \r\n 或是單純 Enter)
				p.Send("> ")
				continue
			}

			// 將累積的 buffer 轉為字串並處理
			rawLine := string(inputBuffer)
			inputBuffer = nil // 清空 buffer 供下次使用

			input := s.cleanInput(rawLine)
			if input == "" {
				p.Send("> ")
				continue
			}

			fmt.Printf("DEBUG: 成功解析指令 [%s]\n", input)

			// 執行 LPC
			s.Driver.CurrentPlayer = p
			s.Driver.CallFunction(p.Object, "process_input", []object.Object{&object.String{Value: input}})
			s.Driver.CurrentPlayer = nil
			
			p.Send("> ")
			continue
		}

		// 如果不是換行，就存入 buffer (排除掉 Telnet IAC 指令)
		// 這裡先簡單處理：只存入可見字元
		if b >= 32 && b <= 126 {
			inputBuffer = append(inputBuffer, b)
		}
	}
}

func (s *TelnetServer) cleanInput(in string) string {
	var out []byte
	for i := 0; i < len(in); i++ {
		// 1. 跳過 Telnet IAC (255) 指令區塊
		if in[i] == 255 {
			i += 2
			continue
		}
		// 2. 只接受標準可見字元 (Space 到 ~)
		if in[i] >= 32 && in[i] <= 126 {
			out = append(out, in[i])
		}
	}
	return strings.TrimSpace(string(out))
}
