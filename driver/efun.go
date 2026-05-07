// driver/efun.go
package driver

import (
	"fmt"
	"math/rand"
	"sort"
	"strings"
	"time"

	"mudscript/object"
)

// SetupEfuns 為每個載入的 LPC 物件注入專屬的內建函式
func (d *Driver) SetupEfuns(obj *object.LPCObject) {

	// ==========================================
	// 1. 核心與 I/O (Core & IO)
	// ==========================================

	// enable_commands() - 讓物件成為「活物」，可以接收 add_action
	obj.Vars.Set("enable_commands", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			obj.IsLiving = true
			if obj.Actions == nil {
				obj.Actions = make(map[string]*object.Action)
			}
			return &object.Integer{Value: 1}
		},
	})

	// add_action(string func, string verb) - 把指令塞給當前玩家
	obj.Vars.Set("add_action", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("add_action 需 2 個字串參數") }
			
			funcName, ok1 := args[0].(*object.String)
			verb, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("add_action 參數型別錯誤") }

			// 誰呼叫了這個動作？通常是 this_player() (正在執行 init 的人)
			p := d.GetCurrentPlayer()
			if p == nil || p.Object == nil {
				return &object.Integer{Value: 0}
			}

			targetObj := p.Object
			if !targetObj.IsLiving {
				return &object.Integer{Value: 0} // 只有活物能學指令
			}

			// 初始化並寫入指令表
			if targetObj.Actions == nil {
				targetObj.Actions = make(map[string]*object.Action)
			}

			targetObj.Actions[verb.Value] = &object.Action{
				Verb:     verb.Value,
				FuncName: funcName.Value,
				Provider: obj, // 提供者就是呼叫 add_action 的這個物品
			}

			return &object.Integer{Value: 1}
		},
	})

	// write(string msg) - 印出訊息
	obj.Vars.Set("write", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			msg := ""
			if len(args) > 0 {
				if s, ok := args[0].(*object.String); ok {
					msg = s.Value
				} else {
					msg = args[0].Inspect()
				}
			}

			// 魔法：透過 Goroutine ID 抓取呼叫此函式的玩家
			p := d.GetCurrentPlayer()

			if p != nil && p.Conn != nil {
				p.Send(msg + "\r\n") // 確保網路回傳換行
			} else {
				fmt.Print(msg) // 無玩家時印在 Server
			}
			return &object.Nil{}
		},
	})

	// this_player() - 取得當前下指令的玩家物件
	obj.Vars.Set("this_player", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			p := d.GetCurrentPlayer()
			if p != nil && p.Object != nil {
				return p.Object
			}
			return &object.Nil{}
		},
	})

	obj.Vars.Set("say", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.Nil{} }
			msg := args[0].Inspect()
			if s, ok := args[0].(*object.String); ok { msg = s.Value }

			env := obj.Location
			if env != nil {
				for _, other := range env.Inventory {
					if other != obj {
						d.CallFunction(other, "catch_tell", []object.Object{&object.String{Value: msg}})
					}
				}
			}
			return &object.Nil{}
		},
	})

	// tell_object(object ob, string msg) - 私訊指定物件
	obj.Vars.Set("tell_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 {
				return object.NewError("tell_object 需要 2 個參數 (object, string)")
			}

			targetObj, ok := args[0].(*object.LPCObject)
			if !ok {
				return object.NewError("tell_object 的第一個參數必須是 object")
			}

			// 取得要發送的字串內容
			msg := args[1].Inspect()
			if s, isStr := args[1].(*object.String); isStr {
				msg = s.Value
			}

			// 1. 如果目標是一個連線中的玩家，直接發送 TCP 訊息
			conn := d.GetConnectionFromObject(targetObj)
			if conn != nil {
				conn.Send(msg + "\r\n")
			}

			// 2. 無論是否為玩家，都觸發該物件的 catch_tell，這讓 NPC 也能處理聽到的訊息
			// 並且透過 RunCommand 確保 `this_player()` 是發話者
			initiator := d.GetCurrentPlayer()
			if initiator != nil {
				d.RunCommand(initiator, targetObj, "catch_tell", []object.Object{&object.String{Value: msg}})
			} else {
				d.CallFunction(targetObj, "catch_tell", []object.Object{&object.String{Value: msg}})
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

	// evaluate(closure, ...args) - 執行函數指標
	obj.Vars.Set("evaluate", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("evaluate 至少需要 1 個參數 (closure)") }
			
			c, ok := args[0].(*object.Closure)
			if !ok { return object.NewError("evaluate 的第一個參數必須是閉包 (: :)") }
			
			// 如果閉包沒有指定 Target，就預設呼叫者 (this_object)
			target := c.Target
			if target == nil {
				target = obj 
			}
			
			// 魔法發生的地方：把當初「預先綁定」的參數，跟「現在傳入」的參數結合！
			finalArgs := append([]object.Object{}, c.BoundArgs...)
			finalArgs = append(finalArgs, args[1:]...)
			
			res := d.CallFunction(target, c.FuncName, finalArgs)
			if res == nil { return &object.Integer{Value: 0} }
			return res
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
			d.MoveObject(obj, args[0].(*object.LPCObject))
			return &object.Nil{}
		},
	})

	// destruct(object ob) - 摧毀物件
	obj.Vars.Set("destruct", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.LPC_OBJECT_OBJ {
				return object.NewError("argument to `destruct` must be OBJECT")
			}
			d.DestructObject(args[0].(*object.LPCObject))
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

	// m_delete(mapping, key) - 刪除指定的鍵值對，回傳修改後的 mapping (原地修改)
	obj.Vars.Set("m_delete", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("m_delete() 需要 2 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("m_delete() 第一個參數必須是 mapping") }

			key := args[1]
			hashable, ok := key.(object.Hashable)
			if !ok {
				return object.NewError("給定的鍵 (%s) 無法作為 mapping 的 key", key.TokenType())
			}

			// 從 Go 的 map 中刪除該鍵
			delete(m.Pairs, hashable.HashKey())
			
			// LPC 慣例通常會回傳修改後的 mapping
			return m 
		},
	})

	// m_add(mapping, key, val) - 新增或修改鍵值對 (通常可以用 m[key] = val 代替)
	obj.Vars.Set("m_add", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 3 { return object.NewError("m_add() 需要 3 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("m_add() 第一個參數必須是 mapping") }

			key := args[1]
			val := args[2]

			hashable, ok := key.(object.Hashable)
			if !ok {
				return object.NewError("給定的鍵 (%s) 無法作為 mapping 的 key", key.TokenType())
			}

			m.Pairs[hashable.HashKey()] = object.HashPair{Key: key, Value: val}
			return m
		},
	})

	// [額外建議] map_mapping(mapping, func) - 對 mapping 進行轉換
	// 類似 map_array，但傳入的函式會接收 (key, value) 兩個參數
	obj.Vars.Set("map_mapping", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("map_mapping() 至少需要 2 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("map_mapping() 第一個參數必須是 mapping") }

			// 建立一個新的 Mapping 來存放結果 (保持函數式編程不改動原本資料的好習慣)
			newPairs := make(map[object.HashKey]object.HashPair)

			for _, pair := range m.Pairs {
				var res object.Object

				if funcName, ok := args[1].(*object.String); ok {
					targetObj := obj
					if len(args) > 2 {
						if o, isObj := args[2].(*object.LPCObject); isObj { targetObj = o }
					}
					// 傳入 Key 和 Value 給目標函式
					res = d.CallFunction(targetObj, funcName.Value, []object.Object{pair.Key, pair.Value})
				} else if cl, ok := args[1].(*object.Closure); ok {
					target := cl.Target
					if target == nil { target = obj }
					callArgs := append([]object.Object{}, cl.BoundArgs...)
					callArgs = append(callArgs, pair.Key, pair.Value)
					res = d.CallFunction(target, cl.FuncName, callArgs)
				}

				if res == nil || res.TokenType() == object.ErrorType {
					res = &object.Integer{Value: 0} // 預設值
				}
				
				// 將新的 Value 存入新 Mapping
				newPairs[pair.Key.(object.Hashable).HashKey()] = object.HashPair{Key: pair.Key, Value: res}
			}
			return &object.Mapping{Pairs: newPairs}
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

	// 輔助函式：比較兩個 LPC 物件是否相等 (給 member_array 用)
	isEqual := func(a, b object.Object) bool {
		if a.TokenType() != b.TokenType() { return false }
		if i1, ok := a.(*object.Integer); ok { return i1.Value == b.(*object.Integer).Value }
		if s1, ok := a.(*object.String); ok { return s1.Value == b.(*object.String).Value }
		if o1, ok := a.(*object.LPCObject); ok { return o1 == b.(*object.LPCObject) } // 比較記憶體位址
		return a.Inspect() == b.Inspect() // Fallback 暴力比較字串表示法
	}

	// --- 升級版的 Filter ---
	// 支援: filter(arr, "func", obj) 以及 filter(arr, (: closure :))
	filterFn := &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("filter() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("filter() 第一個參數必須是陣列") }

			filtered := []object.Object{}
			for _, el := range arr.Elements {
				var res object.Object

				if funcName, ok := args[1].(*object.String); ok {
					targetObj := obj
					extraStart := 2
					if len(args) > 2 {
						if o, isObj := args[2].(*object.LPCObject); isObj {
							targetObj = o
							extraStart = 3
						}
					}
					var extraArgs []object.Object
					if len(args) > extraStart { extraArgs = args[extraStart:] }
					
					callArgs := append([]object.Object{el}, extraArgs...)
					res = d.CallFunction(targetObj, funcName.Value, callArgs)
				} else if cl, ok := args[1].(*object.Closure); ok {
					target := cl.Target
					if target == nil { target = obj }
					callArgs := append([]object.Object{}, cl.BoundArgs...)
					callArgs = append(callArgs, el)
					if len(args) > 2 { callArgs = append(callArgs, args[2:]...) }
					
					res = d.CallFunction(target, cl.FuncName, callArgs)
				} else {
					return object.NewError("filter() 第二個參數必須是字串或閉包")
				}

				if isLPCTrue(res) {
					filtered = append(filtered, el)
				}
			}
			return &object.Array{Elements: filtered}
		},
	}
	obj.Vars.Set("filter", filterFn)
	obj.Vars.Set("filter_array", filterFn) // 設定別名支援舊腳本

	// --- 升級版的 Map ---
	mapFn := &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("map() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("map() 第一個參數必須是陣列") }

			mapped := make([]object.Object, len(arr.Elements))
			for i, el := range arr.Elements {
				var res object.Object

				if funcName, ok := args[1].(*object.String); ok {
					targetObj := obj
					extraStart := 2
					if len(args) > 2 {
						if o, isObj := args[2].(*object.LPCObject); isObj {
							targetObj = o
							extraStart = 3
						}
					}
					var extraArgs []object.Object
					if len(args) > extraStart { extraArgs = args[extraStart:] }
					
					callArgs := append([]object.Object{el}, extraArgs...)
					res = d.CallFunction(targetObj, funcName.Value, callArgs)
				} else if cl, ok := args[1].(*object.Closure); ok {
					target := cl.Target
					if target == nil { target = obj }
					callArgs := append([]object.Object{}, cl.BoundArgs...)
					callArgs = append(callArgs, el)
					if len(args) > 2 { callArgs = append(callArgs, args[2:]...) }
					
					res = d.CallFunction(target, cl.FuncName, callArgs)
				}

				if res == nil || res.TokenType() == object.ErrorType {
					mapped[i] = &object.Integer{Value: 0}
				} else {
					mapped[i] = res
				}
			}
			return &object.Array{Elements: mapped}
		},
	}
	obj.Vars.Set("map", mapFn)
	obj.Vars.Set("map_array", mapFn) // 設定別名

	// --- 陣列排序 (sort_array) ---
	obj.Vars.Set("sort_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("sort_array() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("sort_array() 第一個參數必須是陣列") }

			// 複製一份，避免原地修改原陣列 (LPC 的慣例是回傳新陣列)
			newElements := make([]object.Object, len(arr.Elements))
			copy(newElements, arr.Elements)

			// 呼叫 Go 的排序，並在比較函式中 callback 回 LPC
			sort.SliceStable(newElements, func(i, j int) bool {
				el1, el2 := newElements[i], newElements[j]
				var res object.Object

				if funcName, ok := args[1].(*object.String); ok {
					targetObj := obj
					if len(args) > 2 {
						if o, isObj := args[2].(*object.LPCObject); isObj { targetObj = o }
					}
					res = d.CallFunction(targetObj, funcName.Value, []object.Object{el1, el2})
				} else if cl, ok := args[1].(*object.Closure); ok {
					target := cl.Target
					if target == nil { target = obj }
					callArgs := append([]object.Object{}, cl.BoundArgs...)
					callArgs = append(callArgs, el1, el2)
					res = d.CallFunction(target, cl.FuncName, callArgs)
				}

				// LPC 的排序慣例：回傳 < 0 的值代表 el1 應該在 el2 前面
				if iRes, ok := res.(*object.Integer); ok {
					return iRes.Value < 0
				}
				return false
			})
			return &object.Array{Elements: newElements}
		},
	})

	// --- 陣列元素尋找 (member_array) ---
	obj.Vars.Set("member_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: -1} }
			val := args[0]
			arr, ok := args[1].(*object.Array)
			if !ok { return &object.Integer{Value: -1} }

			for i, el := range arr.Elements {
				if isEqual(val, el) {
					return &object.Integer{Value: int64(i)}
				}
			}
			return &object.Integer{Value: -1}
		},
	})

	// --- 陣列分類 (unique_array) ---
	obj.Vars.Set("unique_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("unique_array() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("unique_array() 第一個參數必須是陣列") }

			groups := make(map[string][]object.Object)
			
			for _, el := range arr.Elements {
				var res object.Object
				if funcName, ok := args[1].(*object.String); ok {
					res = d.CallFunction(obj, funcName.Value, []object.Object{el})
				} else if cl, ok := args[1].(*object.Closure); ok {
					target := cl.Target
					if target == nil { target = obj }
					callArgs := append([]object.Object{}, cl.BoundArgs...)
					res = d.CallFunction(target, cl.FuncName, append(callArgs, el))
				}

				if res == nil { res = &object.Integer{Value: 0} }
				key := res.Inspect() // 利用字串化結果作為 Go map 的分類 Key
				groups[key] = append(groups[key], el)
			}
			
			result := make([]object.Object, 0, len(groups))
			for _, g := range groups {
				result = append(result, &object.Array{Elements: g})
			}
			return &object.Array{Elements: result}
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

	// lower_case(string str) - 轉小寫
	obj.Vars.Set("lower_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("lower_case 需要 1 個參數") }
			str, ok := args[0].(*object.String)
			if !ok { return object.NewError("lower_case 參數必須是字串") }
			return &object.String{Value: strings.ToLower(str.Value)}
		},
	})

	// upper_case(string str) - 轉大寫
	obj.Vars.Set("upper_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("upper_case 需要 1 個參數") }
			str, ok := args[0].(*object.String)
			if !ok { return object.NewError("upper_case 參數必須是字串") }
			return &object.String{Value: strings.ToUpper(str.Value)}
		},
	})

	// strlen(string str) - 取得字串長度 (支援中文字元)
	obj.Vars.Set("strlen", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.Integer{Value: 0} }
			str, ok := args[0].(*object.String)
			if !ok { return &object.Integer{Value: 0} }
			// 使用 []rune 確保中文字算 1 個字元
			return &object.Integer{Value: int64(len([]rune(str.Value)))}
		},
	})

	// substr(string str, int start, [int length]) - 截取字串 (支援中文字元)
	obj.Vars.Set("substr", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("substr 至少需要 2 個參數") }
			str, ok1 := args[0].(*object.String)
			start, ok2 := args[1].(*object.Integer)
			if !ok1 || !ok2 { return object.NewError("substr 參數型別錯誤") }

			runes := []rune(str.Value)
			length := len(runes)
			
			sIdx := int(start.Value)
			// 支援負數索引 (從後面算起)
			if sIdx < 0 { sIdx = length + sIdx }
			if sIdx < 0 { sIdx = 0 }
			if sIdx >= length { return &object.String{Value: ""} }

			eIdx := length
			if len(args) > 2 {
				if l, ok := args[2].(*object.Integer); ok {
					eIdx = sIdx + int(l.Value)
				}
			}
			if eIdx > length { eIdx = length }
			if eIdx < sIdx { return &object.String{Value: ""} }

			return &object.String{Value: string(runes[sIdx:eIdx])}
		},
	})

	// strsrch(string str, string pattern, [int flag]) - 搜尋字串位置
	obj.Vars.Set("strsrch", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("strsrch 需要 2 個參數") }
			str, ok1 := args[0].(*object.String)
			pattern, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("strsrch 參數必須是字串") }

			// 預設找第一個符合的
			reverse := false
			if len(args) > 2 {
				if flag, ok := args[2].(*object.Integer); ok && flag.Value != 0 {
					reverse = true // 第三個參數非 0 代表從後面找 (LastIndex)
				}
			}

			var byteIdx int
			if reverse {
				byteIdx = strings.LastIndex(str.Value, pattern.Value)
			} else {
				byteIdx = strings.Index(str.Value, pattern.Value)
			}

			if byteIdx == -1 {
				return &object.Integer{Value: -1}
			}
			
			// 將 Byte Index 轉換為 Rune Index (給 LPC 用的字元索引)
			runeIdx := len([]rune(str.Value[:byteIdx]))
			return &object.Integer{Value: int64(runeIdx)}
		},
	})

	// capitalize(string str) - 首字母大寫
	obj.Vars.Set("capitalize", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("capitalize 需要 1 個參數") }
			str, ok := args[0].(*object.String)
			if !ok { return object.NewError("capitalize 參數必須是字串") }

			runes := []rune(str.Value)
			if len(runes) == 0 { return &object.String{Value: ""} }

			// 只有第一個字元轉大寫
			runes[0] = []rune(strings.ToUpper(string(runes[0])))[0]
			return &object.String{Value: string(runes)}
		},
	})

	// trim(string str) - 移除前後空白與換行
	obj.Vars.Set("trim", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("trim 需要 1 個參數") }
			str, ok := args[0].(*object.String)
			if !ok { return object.NewError("trim 參數必須是字串") }
			return &object.String{Value: strings.TrimSpace(str.Value)}
		},
	})
}
