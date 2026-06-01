// driver/efun_monitor.go
package driver

import (
	"os"
	"time"

	"mudscript/evaluator"
	"mudscript/object"
)

func (d *Driver) registerPerformanceEfuns(obj *object.LPCObject) {
	// 語法: string query_host_name()
	obj.Vars.Set("query_host_name", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			hostname, _ := os.Hostname()
			return &object.String{Value: hostname}
		},
	})

	// 語法: float query_load_average()
	obj.Vars.Set("query_load_average", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return &object.Float{Value: 0.0} // Placeholder
		},
	})

	// 語法: int time_expression(closure f)
	obj.Vars.Set("time_expression", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.Integer{Value: 0}
			}
			start := time.Now()
			
			// 執行閉包
			switch f := args[0].(type) {
			case *object.Closure:
				d.CallFunction(f.Target, f.FuncName, f.BoundArgs)
			case *object.Builtin:
				f.Fn()
			}

			elapsed := time.Since(start).Microseconds()
			return &object.Integer{Value: int64(elapsed)}
		},
	})

	// 語法: void set_eval_limit(int limit)
	obj.Vars.Set("set_eval_limit", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return evaluator.NilValue
		},
	})

	// 語法: int eval_cost()
	obj.Vars.Set("eval_cost", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return &object.Integer{Value: 0}
		},
	})

	// 語法: void reset_eval_cost()
	obj.Vars.Set("reset_eval_cost", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return evaluator.NilValue
		},
	})
}
