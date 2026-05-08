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
		go s.handleConnection(conn)
	}
}

func (s *TelnetServer) handleConnection(conn net.Conn) {
	conn.Write([]byte{255, 251, 1, 255, 251, 3})

	pConn := driver.NewPlayerConnection(conn, nil)

	userObj := s.Driver.AcceptConnection(pConn)
	if userObj == nil {
		conn.Write([]byte("系統忙碌中，請稍後再試。\r\n"))
		conn.Close()
		return
	}

	pConn.Object = userObj
	s.Driver.RegisterInteractive(userObj, pConn)
	defer s.Driver.UnregisterInteractive(userObj)

	s.Driver.RunCommand(pConn, userObj, "enable_commands", nil)
	s.Driver.RunCommand(pConn, userObj, "setup", nil)
	s.Driver.RunCommand(pConn, userObj, "init", nil)
	pConn.Send("\r\n[系統] 歡迎來到 MudScript！\r\n")
	s.Driver.RunCommand(pConn, userObj, "logon", nil)

	s.servePlayer(pConn)
}

func (s *TelnetServer) servePlayer(p *driver.PlayerConnection) {
	defer p.Conn.Close()

	reader := bufio.NewReader(p.Conn)
	var inputBuffer []byte

	for p.IsActive {
		b, err := reader.ReadByte()
		if err != nil {
			break
		}

		// ── Telnet 協定控制碼 ──────────────────────────────────
		if b == 255 {
			cmd, err := reader.ReadByte()
			if err != nil { break }
			if cmd >= 251 && cmd <= 254 { reader.ReadByte() }
			continue
		}

		// ── Backspace ──────────────────────────────────────────
		if b == 8 || b == 127 {
			if len(inputBuffer) > 0 {
				inputBuffer = inputBuffer[:len(inputBuffer)-1]
				p.Send("\b \b")
			}
			continue
		}

		// ── Enter ─────────────────────────────────────────────
		if b == '\r' || b == '\n' {
			if b == '\r' {
				next, err := reader.Peek(1)
				if err == nil && (next[0] == '\n' || next[0] == 0) {
					reader.ReadByte()
				}
			}

			p.Send("\r\n")
			rawLine := string(inputBuffer)
			inputBuffer = nil
			input := s.cleanInput(rawLine)

			// ── input_to 模式：直接交給等待中的函式 ──────────
			if p.NextInputFunc != "" {
				funcName := p.NextInputFunc
				p.NextInputFunc = ""
				p.InputHidden = false
				res := s.Driver.RunCommand(p, p.Object, funcName, []object.Object{&object.String{Value: input}})
				if errObj, ok := res.(*object.Error); ok {
					p.Send(fmt.Sprintf("\r\n【系統嚴重警告】對話執行期錯誤！\r\n訊息：%s\r\n", errObj.Message))
				}

				if p.NextInputFunc == "" {
					p.Send("> ")
				}
				continue
			}

			if input == "" {
				p.Send("> ")
				continue
			}

			// ── 展開歷史符號（!! 等） ─────────────────────────
			finalInput := p.ExpandHistory(input)
			if finalInput == "" {
				p.Send("> ")
				continue
			}

			// ── Alias 展開 ────────────────────────────────────
			expandedResult := s.Driver.RunCommand(
				p, p.Object, "expand_alias",
				[]object.Object{&object.String{Value: finalInput}},
			)
			if expandedResult != nil {
				if expanded, ok := expandedResult.(*object.String); ok && expanded.Value != finalInput {
					finalInput = expanded.Value
					// ▼ [新增這行] 直接在底層發送 UX 提示，讓玩家知道發生了什麼事
					p.Send(fmt.Sprintf("（別名展開：%s）\r\n", finalInput))
				}
			}

			// ── 派送指令 ─────────────────────────────────────
			s.dispatchCommand(p, finalInput)

			if p.NextInputFunc == "" {
				p.Send("> ")
			}
			continue
		}

		// ── 一般可見字元 ──────────────────────────────────────
		if b >= 32 && b <= 126 {
			inputBuffer = append(inputBuffer, b)
			if p.InputHidden {
				p.Send("*")
			} else {
				p.Send(string(b))
			}
		}
	}
}

// dispatchCommand 將輸入拆成 verb + arg，依序查詢 Actions 表；
// 找不到時交給 process_input 處理。
func (s *TelnetServer) dispatchCommand(p *driver.PlayerConnection, input string) {
	parts := strings.SplitN(input, " ", 2)
	verb := parts[0]
	arg := ""
	if len(parts) > 1 {
		arg = parts[1]
	}

	// 1. 查 Actions 表（由 add_action / cmd_*_setup() 注冊）
	if p.Object.Actions != nil {
		if action, exists := p.Object.Actions[verb]; exists {
			callArgs := []object.Object{}
			if arg != "" {
				callArgs = append(callArgs, &object.String{Value: arg})
			}
			res := s.Driver.RunCommand(p, p.Object, action.FuncName, callArgs)
			if errObj, ok := res.(*object.Error); ok {
				p.Send(fmt.Sprintf("\r\n【系統嚴重警告】指令執行期錯誤！\r\n訊息：%s\r\n", errObj.Message))
				return
			}
			if res != nil {
				if i, ok := res.(*object.Integer); !ok || i.Value != 0 {
					return // 指令處理成功
				}
			}
		}
	}

	// 2. 交給 process_input（來自 user.c，做 alias fallback 或印錯誤）
	res := s.Driver.RunCommand(p, p.Object, "process_input", []object.Object{&object.String{Value: input}})
	if res != nil {
		if i, ok := res.(*object.Integer); ok && i.Value == 0 {
			p.Send("什麼？\r\n")
		}
	} else {
		p.Send("什麼？\r\n")
	}
}

func (s *TelnetServer) cleanInput(in string) string {
	return strings.TrimSpace(in)
}
