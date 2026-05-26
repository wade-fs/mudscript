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
