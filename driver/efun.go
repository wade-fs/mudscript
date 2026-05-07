// driver/efun.go
package driver

import (
	"fmt"
	"math/rand"
	"strings"
	"time"

	"mudscript/object"
)

// SetupEfuns 為每個載入的 LPC 物件注入專屬的內建函式
func (d *Driver) SetupEfuns(obj *object.LPCObject) {

	// ==========================================
	// 1. 核心與 I/O (Core & IO)
	// ==========================================

	// write(string msg) - 印出訊息
	obj.Vars.Set("write", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) > 0 && args[0].TokenType() == object.StringType {
				fmt.Print(args[0].(*object.String).Value)
			}
			return &object.Nil{}
		},
	})

	// say(string msg) - 對周圍的其他物件廣播訊息
	obj.Vars.Set("say", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 || args[0].TokenType() != object.StringType {
				return object.NewError("argument to `say` must be STRING")
			}
			msg := args[0].(*object.String).Value
			env := obj.Location
			if env != nil {
				// 呼叫房間內所有其他物件的 catch_tell 函式 (NPC 會聽見)
				for _, other := range env.Inventory {
					if other != obj {
						d.CallFunction(other, "catch_tell", []object.Object{&object.String{Value: msg}})
					}
				}
			}
			return &object.Nil{}
		},
	})

	// this_object() - 回傳自己
	obj.Vars.Set("this_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object { return obj },
	})

	// throw(mixed err) - 主動拋出例外
	obj.Vars.Set("throw", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return object.NewError("Thrown exception")
			}
			// 將拋出的物件轉為字串形式的 Error
			if str, ok := args[0].(*object.String); ok {
				return object.NewError(str.Value)
			}
			return object.NewError(args[0].Inspect())
		},
	})

	// ==========================================
	// 2. 空間與物件操作 (Environment & Objects)
	// ==========================================

	// environment([object ob]) - 取得所在環境
	obj.Vars.Set("environment", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := obj
			if len(args) > 0 && args[0].TokenType() == object.LPC_OBJECT_OBJ {
				target = args[0].(*object.LPCObject)
			}
			if target.Location != nil {
				return target.Location
			}
			return &object.Nil{}
		},
	})

	// move_object(object dest) - 移動物件
	obj.Vars.Set("move_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.LPC_OBJECT_OBJ {
				return object.NewError("argument to `move_object` must be OBJECT")
			}
			dest := args[0].(*object.LPCObject)
			d.MoveObject(obj, dest)
			return &object.Nil{}
		},
	})

	// destruct(object ob) - 摧毀物件
	obj.Vars.Set("destruct", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.LPC_OBJECT_OBJ {
				return object.NewError("argument to `destruct` must be OBJECT")
			}
			target := args[0].(*object.LPCObject)
			d.DestructObject(target)
			return &object.Nil{}
		},
	})

	// clone_object(string file) - 複製物件
	obj.Vars.Set("clone_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.StringType {
				return object.NewError("argument to `clone_object` must be STRING")
			}
			clonedObj, err := d.CloneObject(args[0].(*object.String).Value)
			if err != nil {
				return object.NewError("clone error: %s", err.Error())
			}
			return clonedObj
		},
	})

	// call_out(string func, int delay, ...args)
	obj.Vars.Set("call_out", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("call_out needs 2+ args") }
			funcName, _ := args[0].(*object.String)
			delay, _ := args[1].(*object.Integer)
			d.CallOut(obj, funcName.Value, time.Duration(delay.Value)*time.Second, args[2:]...)
			return &object.Nil{}
		},
	})

	// call_other(object ob, string func, ...args) - 跨物件函式呼叫
	obj.Vars.Set("call_other", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 {
				return object.NewError("call_other 至少需要兩個參數 (object, string)")
			}

			targetObj, ok := args[0].(*object.LPCObject)
			if !ok {
				return object.NewError("call_other 第一個參數必須是 object")
			}

			funcName, ok := args[1].(*object.String)
			if !ok {
				return object.NewError("call_other 第二個參數必須是 string")
			}

			// 呼叫 Driver 原本寫好的 CallFunction！
			result := d.CallFunction(targetObj, funcName.Value, args[2:])
			if result == nil {
				return &object.Integer{Value: 0}
			}
			return result
		},
	})

	// ==========================================
	// 3. 時間與排程 (Time & Scheduling)
	// ==========================================

	// time() - 回傳 Unix Timestamp
	obj.Vars.Set("time", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return &object.Integer{Value: time.Now().Unix()}
		},
	})

	// random(int n) - 取亂數 0 ~ (n-1)
	obj.Vars.Set("random", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.IntegerType {
				return object.NewError("argument to `random` must be INTEGER")
			}
			max := args[0].(*object.Integer).Value
			if max <= 0 {
				return &object.Integer{Value: 0}
			}
			return &object.Integer{Value: rand.Int63n(max)}
		},
	})

	// ==========================================
	// 4. 資料結構操作 (Strings, Arrays, Mappings)
	// ==========================================

	// sizeof(array/string/mapping) - 取得長度
	obj.Vars.Set("sizeof", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.Integer{Value: 0} }
			switch arg := args[0].(type) {
			case *object.Array:
				return &object.Integer{Value: int64(len(arg.Elements))}
			case *object.String:
				return &object.Integer{Value: int64(len(arg.Value))}
			case *object.Mapping:
				return &object.Integer{Value: int64(len(arg.Pairs))}
			}
			return &object.Integer{Value: 0}
		},
	})

	// explode(string str, string delim) - 字串分割成 Array
	obj.Vars.Set("explode", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 2 { return object.NewError("explode requires 2 strings") }
			str, ok1 := args[0].(*object.String)
			delim, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("explode requires strings") }
			
			parts := strings.Split(str.Value, delim.Value)
			elements := make([]object.Object, len(parts))
			for i, p := range parts {
				elements[i] = &object.String{Value: p}
			}
			return &object.Array{Elements: elements}
		},
	})

	// implode(array arr, string delim) - Array 結合成字串
	obj.Vars.Set("implode", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 2 { return object.NewError("implode requires array and string") }
			arr, ok1 := args[0].(*object.Array)
			delim, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("implode type mismatch") }

			var strs []string
			for _, e := range arr.Elements {
				if s, ok := e.(*object.String); ok {
					strs = append(strs, s.Value)
				}
			}
			return &object.String{Value: strings.Join(strs, delim.Value)}
		},
	})

	// keys(mapping) - 取出 mapping 所有的 key 變成 array
	obj.Vars.Set("keys", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("keys() 需要 1 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("keys() 參數必須是 mapping") }

			elements := make([]object.Object, 0, len(m.Pairs))
			for _, pair := range m.Pairs {
				elements = append(elements, pair.Key)
			}
			return &object.Array{Elements: elements}
		},
	})

	// values(mapping) - 取出 mapping 所有的 value 變成 array
	obj.Vars.Set("values", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("values() 需要 1 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("values() 參數必須是 mapping") }

			elements := make([]object.Object, 0, len(m.Pairs))
			for _, pair := range m.Pairs {
				elements = append(elements, pair.Value)
			}
			return &object.Array{Elements: elements}
		},
	})

	// 輔助函式：判斷 LPC 中的真假值 (非 0 即真)
	isLPCTrue := func(o object.Object) bool {
		if o == nil || o.TokenType() == object.NilType { return false }
		if i, ok := o.(*object.Integer); ok && i.Value == 0 { return false }
		if b, ok := o.(*object.Boolean); ok && !b.Value { return false }
		if _, ok := o.(*object.Error); ok { return false }
		return true
	}

	// filter_array(array, string func, object ob, ...extra_args) 
	// 過濾陣列：將陣列元素逐一代入函式，回傳非 0 則保留
	obj.Vars.Set("filter_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("filter_array() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("filter_array() 第 1 個參數必須是 array") }
			funcName, ok := args[1].(*object.String)
			if !ok { return object.NewError("filter_array() 第 2 個參數必須是 string") }

			// 預設呼叫者是自己 (this_object)
			targetObj := obj 
			extraStart := 2
			
			// 如果有傳第 3 個參數且是物件，就改為呼叫該物件
			if len(args) > 2 {
				if o, isObj := args[2].(*object.LPCObject); isObj {
					targetObj = o
					extraStart = 3
				}
			}

			// 整理額外的參數
			var extraArgs []object.Object
			if len(args) > extraStart {
				extraArgs = args[extraStart:]
			}

			filtered := []object.Object{}
			for _, el := range arr.Elements {
				// 組合呼叫參數： func( element, extra1, extra2... )
				callArgs := append([]object.Object{el}, extraArgs...)
				res := d.CallFunction(targetObj, funcName.Value, callArgs)
				
				if isLPCTrue(res) {
					filtered = append(filtered, el)
				}
			}
			return &object.Array{Elements: filtered}
		},
	})

	// map_array(array, string func, object ob, ...extra_args)
	// 映射陣列：將陣列元素逐一代入函式，用函式的回傳值替換原本的元素
	obj.Vars.Set("map_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("map_array() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("map_array() 第 1 個參數必須是 array") }
			funcName, ok := args[1].(*object.String)
			if !ok { return object.NewError("map_array() 第 2 個參數必須是 string") }

			targetObj := obj
			extraStart := 2
			if len(args) > 2 {
				if o, isObj := args[2].(*object.LPCObject); isObj {
					targetObj = o
					extraStart = 3
				}
			}

			var extraArgs []object.Object
			if len(args) > extraStart {
				extraArgs = args[extraStart:]
			}

			mapped := make([]object.Object, len(arr.Elements))
			for i, el := range arr.Elements {
				callArgs := append([]object.Object{el}, extraArgs...)
				res := d.CallFunction(targetObj, funcName.Value, callArgs)
				
				if res == nil || res.TokenType() == object.ErrorType {
					mapped[i] = &object.Integer{Value: 0}
				} else {
					mapped[i] = res
				}
			}
			return &object.Array{Elements: mapped}
		},
	})

	// ==========================================
	// 5. 字串操作
	// ==========================================

	// sprintf(string format, ...args) - 格式化字串
	obj.Vars.Set("sprintf", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return object.NewError("sprintf 至少需要一個參數")
			}
			formatObj, ok := args[0].(*object.String)
			if !ok {
				return object.NewError("sprintf 的第一個參數必須是字串")
			}

			// 將 LPC 的 Object 轉換為 Go 的原生型別，餵給 fmt.Sprintf
			var goArgs []interface{}
			for _, arg := range args[1:] {
				switch a := arg.(type) {
				case *object.Integer:
					goArgs = append(goArgs, a.Value)
				case *object.String:
					goArgs = append(goArgs, a.Value)
				case *object.Float:
					goArgs = append(goArgs, a.Value)
				default:
					goArgs = append(goArgs, a.Inspect())
				}
			}

			// 這裡直接借用 Go 的 fmt.Sprintf
			// 將 LPC 專屬的 %O 替換為 Go 的字串格式 %s，因為我們已經用 Inspect() 轉字串了
			formatStr := strings.ReplaceAll(formatObj.Value, "%O", "%s")
			result := fmt.Sprintf(formatStr, goArgs...)
			return &object.String{Value: result}
		},
	})
}
