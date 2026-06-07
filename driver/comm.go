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

		pConn.NextInputFunc = ""
		pConn.NextInputClosure = nil
		pConn.NextInputObj = nil
		pConn.NextInputArgs = nil
		pConn.InputHidden = false

		lpcInput := &object.String{Value: input}
		callArgs := append([]object.Object{lpcInput}, args...)

		if closure != nil {
			d.ExecuteCallback(obj, closure, callArgs)
		} else {
			if targetObj != nil {
				d.CallFunction(targetObj, funcName, callArgs)
			} else {
				d.CallFunction(obj, funcName, callArgs)
			}
		}

		d.CallFunction(obj, "write_prompt", nil)
		return true
	}



	// 解析動詞與參數
	input = strings.TrimSpace(input)
	if input == "" {
		return true
	}

	verb := ""
	arg := ""
	parts := strings.SplitN(input, " ", 2)
	verb = parts[0]
	if len(parts) > 1 {
		arg = parts[1]
	}

	pConn.CurrentVerb = verb
	pConn.NotifyFail = "" 

	// ==========================================
	// 2. 檢查 add_action 註冊的指令
	// ==========================================
	if obj.Actions != nil {
		// 優先精確匹配
		if action, ok := obj.Actions[verb]; ok {
			oldVerb := pConn.CurrentVerb
			pConn.CurrentVerb = verb
			res := d.CallFunction(action.Provider, action.FuncName, []object.Object{&object.String{Value: arg}})
			pConn.CurrentVerb = oldVerb
			if isLPCTrue(res) {
				d.postCommandCleanup(pConn)
				return true
			}
		}

		// 前綴匹配 (flag == 1)
		for v, action := range obj.Actions {
			if action.Flags == 1 {
				if v == "" { continue }
				if strings.HasPrefix(verb, v) {
					oldVerb := pConn.CurrentVerb
					pConn.CurrentVerb = v
					// 前綴匹配時，剩餘部分併入參數
					remaining := strings.TrimPrefix(input, v)
					res := d.CallFunction(action.Provider, action.FuncName, []object.Object{&object.String{Value: remaining}})
					pConn.CurrentVerb = oldVerb
					if isLPCTrue(res) {
						d.postCommandCleanup(pConn)
						return true
					}
				}
			}
		}

		// 最後處理空動詞匹配 (攔截所有輸入)
		if action, ok := obj.Actions[""]; ok && action.Flags == 1 {
			res := d.CallFunction(action.Provider, action.FuncName, []object.Object{&object.String{Value: input}})
			if isLPCTrue(res) {
				d.postCommandCleanup(pConn)
				return true
			}
		}
	}

	// ==========================================
	// 3. 智慧出口後備機制 (Smart Exit Fallback)
	// ==========================================
	if verb != "go" && obj.Location != nil && !obj.Location.IsDestructed {
		if exitsVal, exists := obj.Location.Vars.Get("exits"); exists {
			if exitsMap, ok := exitsVal.(*object.Mapping); ok {
				verbKey := (&object.String{Value: verb}).HashKey()
				if _, hasExit := exitsMap.Pairs[verbKey]; hasExit {
					if d.ProcessCommand(pConn, "go "+input) {
						return true
					}
				}
			}
		}
	}

	// ==========================================
	// 4. 呼叫 process_input (別名擴展與最後機會)
	// ==========================================
	resInput := d.RunCommand(pConn, obj, "process_input", []object.Object{&object.String{Value: input}})
	if isLPCTrue(resInput) {
		d.postCommandCleanup(pConn)
		return true
	}

	// 若完全找不到指令，報錯
	pConn.Send("什麼？\n")
	d.CallFunction(obj, "write_prompt", nil)

	return false
}

func (d *Driver) postCommandCleanup(pConn *PlayerConnection) {
	if pConn != nil && pConn.Object != nil {
		d.CallFunction(pConn.Object, "write_prompt", nil)
	}
}
