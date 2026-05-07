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
	userObj := s.Driver.AcceptConnection()
	if userObj == nil {
		conn.Write([]byte("系統忙碌中，請稍後再試。\n"))
		conn.Close()
		return
	}

	// [修改] 使用新的工廠函式建立帶有 TCP Buffer 的連線
	pConn := driver.NewPlayerConnection(conn, userObj)
	s.Driver.RegisterInteractive(userObj, pConn)
	fmt.Printf("DEBUG: 成功註冊互動玩家 -> %s (IsInteractive=%v)\n", userObj.Filename, userObj.IsInteractive)
	defer s.Driver.UnregisterInteractive(userObj)

	s.Driver.RunCommand(pConn, userObj, "enable_commands", nil)
	s.Driver.RunCommand(pConn, userObj, "setup", nil)
	s.Driver.RunCommand(pConn, userObj, "init", nil)

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
			fmt.Printf("DEBUG: 玩家 %s 讀取錯誤 (已斷線): %v\n", p.Object.Filename, err)
			break
		}

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
				// 將輸入分割為 動詞 (verb) 和 參數 (arg)
				parts := strings.SplitN(finalInput, " ", 2)
				verb := parts[0]
				arg := ""
				if len(parts) > 1 {
					arg = parts[1]
				}
			
				cmdHandled := false
			
				// 1. 檢查玩家身上有沒有註冊這個動詞
				if p.Object.Actions != nil {
				    if action, exists := p.Object.Actions[verb]; exists {
				        fmt.Printf("DEBUG: 執行 action %s -> %s() by provider %s (player=%s)\n", 
				            verb, action.FuncName, action.Provider.Filename, p.Object.Filename)
				
				        callArgs := []object.Object{}
				        if arg != "" {
				            callArgs = append(callArgs, &object.String{Value: arg})
				        }
				
				        // 【關鍵修正】：永遠用 p.Object（玩家的 clone）作為執行主體
				        res := s.Driver.RunCommand(p, p.Object, action.FuncName, callArgs)
				
				        if res != nil {
				            if i, ok := res.(*object.Integer); !ok || i.Value != 0 {
				                cmdHandled = true
				            }
				        }
				    }
				}
			
				// 2. 如果指令表裡找不到，退回到原本的 process_input (供聊天或系統指令使用)
				if !cmdHandled {
					fmt.Printf("DEBUG: 玩家 %s 輸入 '%s', 目前有 %d 個 action\n", 
				        p.Object.Filename, finalInput, len(p.Object.Actions))
					for v := range p.Object.Actions {
				        fmt.Printf("  - action: %s\n", v)
				    }

					res := s.Driver.RunCommand(p, p.Object, "process_input", []object.Object{&object.String{Value: finalInput}})
					
					// 如果 process_input 也回傳 0，我們就印出經典的 MUD 提示
					if res != nil {
						if i, ok := res.(*object.Integer); ok && i.Value == 0 {
							p.Send("什麼？\r\n")
						}
					} else {
			            p.Send("什麼？\r\n")
			        }
				}
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
