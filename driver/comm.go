// driver/comm.go
package driver

import (
	"log"
	"strings"

	"mudscript/object"
)

// ProcessAnsi 將自定義的 {r} 標籤轉換為 ANSI 色碼 (用於終端機)
func (d *Driver) ProcessAnsi(text string) string {
	colorMap := map[string]string{
		"r":  "\x1b[31m",
		"g":  "\x1b[32m",
		"y":  "\x1b[33m",
		"b":  "\x1b[34m",
		"m":  "\x1b[35m",
		"c":  "\x1b[36m",
		"w":  "\x1b[37m",
		"gr": "\x1b[90m",
		"n":  "\x1b[0m",
	}

	res := text
	for tag, code := range colorMap {
		res = strings.ReplaceAll(res, "{"+tag+"}", code)
	}
	return res
}

// TellObject 向指定物件發送訊息 (封裝通訊邏輯)
func (d *Driver) TellObject(target *object.LPCObject, msg string) {
	if target == nil || target.IsDestructed {
		return
	}

	// 1. 若為連線中的玩家，直接透過 Socket 發送
	conn := d.GetConnectionFromObject(target)
	if conn != nil {
		safeMsg := strings.ReplaceAll(msg, "\r\n", "\n")
		safeMsg = strings.ReplaceAll(safeMsg, "\n", "\r\n")
		conn.Send(safeMsg)
	}

	// 2. 不論是否為玩家，都觸發 catch_tell 函式 (供 NPC 或腳本攔截訊息)
	initiator := d.GetCurrentPlayer()
	if initiator != nil {
		d.RunCommand(initiator, target, "catch_tell", []object.Object{&object.String{Value: msg}})
	} else {
		d.CallFunction(target, "catch_tell", []object.Object{&object.String{Value: msg}})
	}
}

// TellRoom 向指定房間內的所有物件廣播訊息 (支援排除清單)
func (d *Driver) TellRoom(room *object.LPCObject, msg string, exclude []*object.LPCObject) {
	if room == nil || room.IsDestructed {
		return
	}

	for _, item := range room.Inventory {
		if item == nil || item.IsDestructed {
			continue
		}

		shouldExclude := false
		for _, ex := range exclude {
			if item == ex {
				shouldExclude = true
				break
			}
		}

		if !shouldExclude {
			d.TellObject(item, msg)
		}
	}
}

// ProcessCommand 處理玩家輸入的指令。回傳 true 代表指令被成功處理，false 代表指令不存在或執行失敗。
func (d *Driver) ProcessCommand(pConn *PlayerConnection, input string) bool {
	if pConn == nil || pConn.Object == nil {
		return false
	}
	obj := pConn.Object

	// 🚀 新增：記錄玩家輸入
	log.Printf("📥 [Input] %s (%s): %s", pConn.Username, obj.Filename, input)

	// ==========================================
	// 0. 優先處理 input_to 攔截
	// ==========================================
	if pConn.NextInputFunc != "" || pConn.NextInputClosure != nil {
		funcName := pConn.NextInputFunc
		closure := pConn.NextInputClosure
		targetObj := pConn.NextInputObj
		args := pConn.NextInputArgs

		// 清除攔截器 (以免遞迴或重複執行)
		pConn.NextInputFunc = ""
		pConn.NextInputClosure = nil
		pConn.NextInputObj = nil
		pConn.NextInputArgs = nil

		// 準備傳遞給 callback 的參數：[玩家輸入, ...其餘預設參數]
		finalArgs := append([]object.Object{&object.String{Value: input}}, args...)

		if closure != nil {
			// 🚀 關鍵修正：必須綁定 Context，否則 write() 等 efun 會找不到目標
			gid := getGID()
			oldContext, hasOld := d.playerContexts.Load(gid)
			d.playerContexts.Store(gid, pConn)
			defer func() {
				if hasOld {
					d.playerContexts.Store(gid, oldContext)
				} else {
					d.playerContexts.Delete(gid)
				}
			}()

			d.ExecuteCallback(obj, closure, finalArgs)
		} else if targetObj != nil {
			d.RunCommand(pConn, targetObj, funcName, finalArgs)
		}
		return true
	}

	input = strings.TrimSpace(input)
	if input == "" {
		return true
	}

	// 處理動詞歷史與 ! 展開
	input = pConn.ExpandHistory(input)
	if input == "" {
		return true
	}

	// 解析動詞與參數
	verb := ""
	arg := ""
	parts := strings.SplitN(input, " ", 2)
	verb = parts[0]
	if len(parts) > 1 {
		arg = parts[1]
	}

	pConn.CurrentVerb = verb

	// 1. 優先檢查 add_action 註冊的指令
	if obj.Actions != nil {
		// A. 精確匹配
		if action, exists := obj.Actions[verb]; exists {
			// 🚀 使用 RunCommand 封裝以確保 GetCurrentPlayer 正常
			res := d.RunCommand(pConn, action.Provider, action.FuncName, []object.Object{&object.String{Value: arg}})

			// 回傳值處理
			if res != nil {
				if i, ok := res.(*object.Integer); ok && i.Value == 0 {
					// 如果回傳 0，代表指令雖然匹配但拒絕處理 (由 notify_fail 接手)
				} else {
					return true
				}
			} else {
				return true
			}
		}

		// B. 前綴匹配與萬用攔截 ("")
		for v, action := range obj.Actions {
			if action.Flags == 1 {
				if v == "" || strings.HasPrefix(verb, v) {
					// 對於萬用攔截 ("")，傳遞完整的 input (包含 verb) 給 action
					// 對於前綴匹配 (例如 "l" 匹配 "look")，LPC 通常會把剩餘部分傳給 arg
					// 但這裡我們簡化處理：如果 v 為空，則 arg 為完整的 input
					callArg := arg
					if v == "" {
						callArg = input
					} else if len(verb) > len(v) {
						// 如果 verb 比 v 長，例如輸入 "lookat" 而 v 是 "look"，則 arg = "at " + arg
						callArg = verb[len(v):] + " " + arg
						callArg = strings.TrimSpace(callArg)
					}

					log.Printf("DEBUG: Calling action %s::%s with arg '%s'", action.Provider.Filename, action.FuncName, callArg)
					res := d.RunCommand(pConn, action.Provider, action.FuncName, []object.Object{&object.String{Value: callArg}})
					if isLPCTrue(res) {
						log.Printf("DEBUG: Action %s::%s returned true", action.Provider.Filename, action.FuncName)
						return true
					}
					log.Printf("DEBUG: Action %s::%s returned false (or nil)", action.Provider.Filename, action.FuncName)
				}
			}
		}
	}

	// 2. 備援：呼叫物件本身的 process_input (通常在 user.c 或 npc.c 實作)
	res := d.RunCommand(pConn, obj, "process_input", []object.Object{&object.String{Value: input}})
	if res != nil {
		if i, ok := res.(*object.Integer); ok && i.Value != 0 {
			return true
		}
		if s, ok := res.(*object.String); ok && s.Value != "" {
			// 如果回傳字串，通常代表指令已被改寫並成功處理
			return true
		}
	}

	return false
}
