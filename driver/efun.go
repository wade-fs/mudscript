// driver/efun.go
package driver

import (
	"fmt"
	"time"

	"mudscript/object"
)

// SetupEfuns 為每個載入的 LPC 物件注入專屬的內建函式
func (d *Driver) SetupEfuns(obj *object.LPCObject) {

	// 1. write(string msg) - 輸出訊息到控制台
	obj.Vars.Set("write", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.StringType {
				return object.NewError("argument to `write` must be STRING")
			}
			msg := args[0].(*object.String).Value
			fmt.Print(msg)
			return &object.Nil{}
		},
	})

	// 2. this_object() - 回傳自己這個物件實體
	obj.Vars.Set("this_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return obj
		},
	})

	// 3. clone_object(string filename) - 複製新物件
	obj.Vars.Set("clone_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.StringType {
				return object.NewError("argument to `clone_object` must be STRING")
			}
			filename := args[0].(*object.String).Value
			clonedObj, err := d.CloneObject(filename)
			if err != nil {
				return object.NewError("failed to clone object: %s", err.Error())
			}
			return clonedObj
		},
	})

	// 4. call_out(string funcName, int delay, ...args) - 延遲執行
	obj.Vars.Set("call_out", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 {
				return object.NewError("call_out requires at least 2 arguments")
			}
			funcName, ok := args[0].(*object.String)
			if !ok {
				return object.NewError("first argument to call_out must be STRING")
			}
			delay, ok := args[1].(*object.Integer)
			if !ok {
				return object.NewError("second argument to call_out must be INTEGER")
			}

			// 將 LPC 的整數轉換為 Go 的時間單位 (秒)
			duration := time.Duration(delay.Value) * time.Second

			// 將剩餘的參數收集起來，準備傳給目標函式
			callArgs := args[2:]

			// 呼叫 Driver 的排程系統
			d.CallOut(obj, funcName.Value, duration, callArgs...)

			return &object.Nil{}
		},
	})
}
