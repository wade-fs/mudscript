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
		if action, exists := obj.Actions[verb]; exists {
			// 🚀 使用 RunCommand 封裝以確保 GetCurrentPlayer 正常
			res := d.RunCommand(pConn, action.Provider, action.FuncName, []object.Object{&object.String{Value: arg}})

			// 回傳值處理
			if res != nil {
				if i, ok := res.(*object.Integer); ok && i.Value == 0 {
					// 如果回傳 0，代表指令雖然匹配但拒絕處理 (由 notify_fail 接手)
					return false
				}
				// 否則視為成功
				return true
			}
			return true
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
