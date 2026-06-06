// driver/comm.go
package driver

import (
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

	// 🚀 關鍵相容性：先呼叫 process_input (通常在 alias.c 實作)，它可能會修改指令
	resInput := d.RunCommand(pConn, obj, "process_input", []object.Object{&object.String{Value: input}})
	if resInput != nil && resInput.TokenType() != object.NilType {
		if s, ok := resInput.(*object.String); ok && s.Value != "" {
			input = s.Value // 指令被改寫 (例如 alias 替換)
		} else if isLPCTrue(resInput) {
			return true // 指令已被 process_input 完全處理 (回傳非 0)
		}
		// 若回傳 0 或 nil，則繼續往下處理 add_action 註冊的指令
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
	pConn.NotifyFail = "" // 🚀 關鍵：每次開始處理新指令前，先清空失敗訊息

	// 1. 檢查 add_action 註冊的指令
	if obj.Actions != nil {
		// A. 精確匹配
		if action, exists := obj.Actions[verb]; exists {
			// 🚀 使用 RunCommand 封裝以確保 GetCurrentPlayer 正常
			res := d.RunCommand(pConn, action.Provider, action.FuncName, []object.Object{&object.String{Value: arg}})

			// 回傳值處理
			if isLPCTrue(res) {
				return true
			}
		}
// B. 前綴匹配與萬用攔截 ("")
for v, action := range obj.Actions {
	if action.Flags == 1 {
		if v == "" || strings.HasPrefix(verb, v) {
			// 對於萬用攔截 ("") 與前綴匹配，
			// LPC 通常會把 verb 之後的部分作為參數傳給 action
			callArg := arg
			if v != "" && len(verb) > len(v) {
				// 例如 v="l", verb="look", 則 "ook" 應該被當作參數前綴
				callArg = verb[len(v):] + " " + arg
				callArg = strings.TrimSpace(callArg)
			}

			res := d.RunCommand(pConn, action.Provider, action.FuncName, []object.Object{&object.String{Value: callArg}})
			if isLPCTrue(res) {
				d.postCommandCleanup(pConn)
				return true
			}
		}
	}
}
	}

	// 🚀 關鍵相容性：處理指令失敗訊息 (notify_fail)
	if pConn.NotifyFail != "" {
		pConn.Send(pConn.NotifyFail)
		pConn.NotifyFail = "" // 清除已顯示的訊息
		return true
	}

	// 若完全找不到指令，回傳預設錯誤
	pConn.Send("什麼？\n")

	// 🚀 [新增] 每次指令處理完後，若物件有 write_prompt 則呼叫它
	d.CallFunction(obj, "write_prompt", nil)

	return false
}

// 在 ProcessCommand 成功處理後也要呼叫 write_prompt
func (d *Driver) postCommandCleanup(pConn *PlayerConnection) {
	if pConn != nil && pConn.Object != nil {
		d.CallFunction(pConn.Object, "write_prompt", nil)
	}
}
