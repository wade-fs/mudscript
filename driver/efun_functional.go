// driver/efun_functional.go
package driver

import (
	"mudscript/evaluator"
	"mudscript/object"
)

func (d *Driver) registerFunctionalEfuns(obj *object.LPCObject) {
	// 語法: mixed evaluate(mixed cl, [mixed args...])
	// 說明: 執行閉包 (closure) 或呼叫函式名稱。
	// 範例: evaluate((: write, "Hello" :));
	obj.Vars.Set("evaluate", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return evaluator.NilValue }
			return d.executeCallback(obj, args[0], args[1:])
		},
	})

	// 語法: mixed apply(mixed cl, [mixed args...])
	// 說明: 同 evaluate，執行閉包或呼叫函式名稱。
	// 範例: apply("write", "Hello");
	obj.Vars.Set("apply", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return evaluator.NilValue }
			return d.executeCallback(obj, args[0], args[1:])
		},
	})
}
