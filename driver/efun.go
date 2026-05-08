// driver/efun.go
package driver

import (
	"encoding/json"
	"fmt"
	"math/rand"
	"os"
	"path/filepath"
	"sort"
	"strconv"
	"strings"
	"time"

	"mudscript/object"
)

// ==========================================
// 輔助工具函式 (Internal Helpers)
// ==========================================

// isLPCTrue 判斷 LPC 中的真假值 (非 0 且非 nil 即真)
func isLPCTrue(o object.Object) bool {
	if o == nil || o.TokenType() == object.NilType {
		return false
	}
	if i, ok := o.(*object.Integer); ok && i.Value == 0 {
		return false
	}
	if b, ok := o.(*object.Boolean); ok && !b.Value {
		return false
	}
	if _, ok := o.(*object.Error); ok {
		return false
	}
	return true
}

// isEqual 比較兩個 LPC 物件是否相等 (給 member_array 等使用)
func isEqual(a, b object.Object) bool {
	if a.TokenType() != b.TokenType() {
		return false
	}
	if i1, ok := a.(*object.Integer); ok {
		return i1.Value == b.(*object.Integer).Value
	}
	if s1, ok := a.(*object.String); ok {
		return s1.Value == b.(*object.String).Value
	}
	if o1, ok := a.(*object.LPCObject); ok {
		return o1 == b.(*object.LPCObject)
	}
	return a.Inspect() == b.Inspect()
}

// getTarget 取得目標物件，若未提供則預設為呼叫者 this_object
func getTarget(args []object.Object, defaultObj *object.LPCObject) *object.LPCObject {
	if len(args) > 0 {
		if o, ok := args[0].(*object.LPCObject); ok {
			return o
		}
	}
	return defaultObj
}

// ==========================================
// efun 註冊進入點
// ==========================================

// SetupEfuns 為每個載入的 LPC 物件注入專屬的內建函式
func (d *Driver) SetupEfuns(obj *object.LPCObject) {
	d.registerTypePredicates(obj)
	d.registerTypeCasting(obj)
	d.registerMathEfuns(obj)
	d.registerCoreIOEfuns(obj)
	d.registerEnvironmentEfuns(obj)
	d.registerTimeAndScheduling(obj)
	d.registerDataStructures(obj)
	d.registerStringEfuns(obj)
	d.registerSystemAndFiles(obj)
	d.registerPersistenceEfuns(obj)
}

// ==========================================
// 1. 型別判斷 (Predicates)
// ==========================================
func (d *Driver) registerTypePredicates(obj *object.LPCObject) {
	// 定義一個輔助函式，利用 any (interface{}) 避開精確型別名稱，Go 會自動比對
	register := func(name string, expectedType any) {
		obj.Vars.Set(name, &object.Builtin{
			Fn: func(args ...object.Object) object.Object {
				if len(args) < 1 {
					// 沒傳參數視為 0 (int) -> nullp 時回傳 1，其餘為 0
					if expectedType == object.NilType {
						return &object.Integer{Value: 1}
					}
					return &object.Integer{Value: 0}
				}

				// LPC 慣例：0 也常被當作 null
				if expectedType == object.NilType {
					if args[0].TokenType() == object.NilType {
						return &object.Integer{Value: 1}
					}
					if i, ok := args[0].(*object.Integer); ok && i.Value == 0 {
						return &object.Integer{Value: 1}
					}
					return &object.Integer{Value: 0}
				}

				if args[0].TokenType() == expectedType {
					return &object.Integer{Value: 1}
				}
				return &object.Integer{Value: 0}
			},
		})
	}

	// 依序註冊所有型別判斷
	register("intp", object.IntegerType)
	register("stringp", object.StringType)
	register("floatp", object.FloatType)
	register("objectp", object.LPC_OBJECT_OBJ)
	register("mappingp", object.MAPPING_OBJ)
	register("arrayp", object.ArrayType)
	register("nullp", object.NilType)
}

// ==========================================
// 2. 型別轉換 (Casting)
// ==========================================
func (d *Driver) registerTypeCasting(obj *object.LPCObject) {
	obj.Vars.Set("to_int", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.Integer{Value: 0}
			}
			switch v := args[0].(type) {
			case *object.Integer:
				return v
			case *object.Float:
				return &object.Integer{Value: int64(v.Value)}
			case *object.String:
				i, err := strconv.ParseInt(v.Value, 10, 64)
				if err != nil {
					return &object.Integer{Value: 0}
				}
				return &object.Integer{Value: i}
			default:
				return &object.Integer{Value: 0}
			}
		},
	})

	obj.Vars.Set("to_string", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.String{Value: ""}
			}
			if s, ok := args[0].(*object.String); ok {
				return s
			}
			return &object.String{Value: args[0].Inspect()}
		},
	})
}

// ==========================================
// 3. 數學運算 (Math)
// ==========================================
func (d *Driver) registerMathEfuns(obj *object.LPCObject) {
	obj.Vars.Set("abs", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.Integer{Value: 0}
			}
			if i, ok := args[0].(*object.Integer); ok {
				if i.Value < 0 {
					return &object.Integer{Value: -i.Value}
				}
				return i
			}
			return &object.Integer{Value: 0}
		},
	})

	for _, name := range []string{"max", "min"} {
		op := name
		obj.Vars.Set(op, &object.Builtin{
			Fn: func(args ...object.Object) object.Object {
				if len(args) < 2 {
					return &object.Integer{Value: 0}
				}
				v1, ok1 := args[0].(*object.Integer)
				v2, ok2 := args[1].(*object.Integer)
				if !ok1 || !ok2 {
					return &object.Integer{Value: 0}
				}
				if (op == "max" && v1.Value > v2.Value) || (op == "min" && v1.Value < v2.Value) {
					return v1
				}
				return v2
			},
		})
	}

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
}

// ==========================================
// 4. 核心與 I/O (Core & IO)
// ==========================================
func (d *Driver) registerCoreIOEfuns(obj *object.LPCObject) {
	obj.Vars.Set("set_heart_beat", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("set_heart_beat 需要 1 個整數參數") }
			flag, ok := args[0].(*object.Integer)
			if !ok { return object.NewError("set_heart_beat 參數必須是整數") }

			enable := flag.Value > 0
			thisObj := d.GetThisObject()
			if thisObj == nil { thisObj = obj }

			d.SetHeartBeat(thisObj, enable)
			return &object.Integer{Value: flag.Value}
		},
	})

	obj.Vars.Set("query_heart_beat", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			d.mu.RLock()
			_, active := d.Heartbeats[target]
			d.mu.RUnlock()
			if active { return &object.Integer{Value: 1} }
			return &object.Integer{Value: 0}
		},
	})

	obj.Vars.Set("destruct", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			d.DestructObject(target)
			return &object.Nil{}
		},
	})

	obj.Vars.Set("enable_commands", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			obj.IsLiving = true
			if obj.Actions == nil {
				obj.Actions = make(map[string]*object.Action)
			}
			return &object.Integer{Value: 1}
		},
	})

	obj.Vars.Set("add_action", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("add_action 需 2 個字串參數") }
			funcName, ok1 := args[0].(*object.String)
			verb, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("add_action 參數型別錯誤") }

			playerObj := obj
			if p := d.GetCurrentPlayer(); p != nil && p.Object != nil {
				playerObj = p.Object
			}

			if !playerObj.IsLiving {
				playerObj.IsLiving = true
				if playerObj.Actions == nil {
					playerObj.Actions = make(map[string]*object.Action)
				}
			}

			if playerObj.Actions == nil {
				playerObj.Actions = make(map[string]*object.Action)
			}

			playerObj.Actions[verb.Value] = &object.Action{
				Verb:     verb.Value,
				FuncName: funcName.Value,
				Provider: obj,
			}
			return &object.Integer{Value: 1}
		},
	})

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

			p := d.GetCurrentPlayer()
			if p != nil && p.Conn != nil {
				safeMsg := strings.ReplaceAll(msg, "\r\n", "\n")
				safeMsg = strings.ReplaceAll(safeMsg, "\n", "\r\n")
				p.Send(safeMsg)
			} else {
				fmt.Print(msg)
			}
			return &object.Nil{}
		},
	})

	obj.Vars.Set("this_player", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			p := d.GetCurrentPlayer()
			if p != nil && p.Object != nil { return p.Object }
			return &object.Nil{}
		},
	})

	obj.Vars.Set("this_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object { return obj },
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

	obj.Vars.Set("tell_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("tell_object 需要 2 個參數") }
			targetObj, ok := args[0].(*object.LPCObject)
			if !ok { return object.NewError("tell_object 的第一個參數必須是 object") }

			msg := args[1].Inspect()
			if s, isStr := args[1].(*object.String); isStr { msg = s.Value }

			conn := d.GetConnectionFromObject(targetObj)
			if conn != nil {
				safeMsg := strings.ReplaceAll(msg, "\r\n", "\n")
				safeMsg = strings.ReplaceAll(safeMsg, "\n", "\r\n")
				conn.Send(safeMsg)
			}

			initiator := d.GetCurrentPlayer()
			if initiator != nil {
				d.RunCommand(initiator, targetObj, "catch_tell", []object.Object{&object.String{Value: msg}})
			} else {
				d.CallFunction(targetObj, "catch_tell", []object.Object{&object.String{Value: msg}})
			}

			return &object.Nil{}
		},
	})

	obj.Vars.Set("throw", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return object.NewError("Thrown exception") }
			if str, ok := args[0].(*object.String); ok { return object.NewError(str.Value) }
			return object.NewError(args[0].Inspect())
		},
	})

	obj.Vars.Set("evaluate", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("evaluate 至少需要 1 個參數") }
			c, ok := args[0].(*object.Closure)
			if !ok { return object.NewError("evaluate 的第一個參數必須是閉包") }
			
			target := c.Target
			if target == nil { target = obj }
			
			finalArgs := append([]object.Object{}, c.BoundArgs...)
			finalArgs = append(finalArgs, args[1:]...)
			
			res := d.CallFunction(target, c.FuncName, finalArgs)
			if res == nil { return &object.Integer{Value: 0} }
			return res
		},
	})
}

// ==========================================
// 5. 空間與物件操作 (Environment & Objects)
// ==========================================
func (d *Driver) registerEnvironmentEfuns(obj *object.LPCObject) {
	obj.Vars.Set("environment", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			if target.Location != nil { return target.Location }
			return &object.Nil{}
		},
	})

	obj.Vars.Set("move_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.LPC_OBJECT_OBJ {
				return object.NewError("move_object 需要 object 參數")
			}
			d.MoveObject(obj, args[0].(*object.LPCObject))
			return &object.Nil{}
		},
	})

	obj.Vars.Set("clone_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.StringType {
				return object.NewError("clone_object 需要 string 參數")
			}
			clonedObj, err := d.CloneObject(args[0].(*object.String).Value)
			if err != nil { return object.NewError("clone error: %s", err.Error()) }
			return clonedObj
		},
	})

	obj.Vars.Set("all_inventory", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			elements := make([]object.Object, len(target.Inventory))
			for i, item := range target.Inventory {
				elements[i] = item
			}
			return &object.Array{Elements: elements}
		},
	})

	obj.Vars.Set("deep_inventory", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			var result []object.Object
			var traverse func(*object.LPCObject)
			traverse = func(cur *object.LPCObject) {
				for _, item := range cur.Inventory {
					result = append(result, item)
					traverse(item)
				}
			}
			traverse(target)
			return &object.Array{Elements: result}
		},
	})

	obj.Vars.Set("first_inventory", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			if len(target.Inventory) > 0 { return target.Inventory[0] }
			return &object.Nil{}
		},
	})

	obj.Vars.Set("object_name", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			return &object.String{Value: target.Filename}
		},
	})

	obj.Vars.Set("find_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			fileName, ok := args[0].(*object.String)
			if !ok { return &object.Nil{} }

			d.mu.RLock()
			defer d.mu.RUnlock()
			if found, exists := d.ObjectTable[fileName.Value]; exists {
				return found
			}
			return &object.Nil{}
		},
	})

	obj.Vars.Set("living", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("living 需要 1 個參數") }
			if target, ok := args[0].(*object.LPCObject); ok && target.IsLiving {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})

	obj.Vars.Set("interactive", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("interactive 需要 1 個參數") }
			if target, ok := args[0].(*object.LPCObject); ok && target.IsInteractive {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})

	obj.Vars.Set("present", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("present 至少需要 1 個參數") }
			container := obj
			if len(args) > 1 {
				if c, ok := args[1].(*object.LPCObject); ok { container = c }
			}

			if targetObj, isObj := args[0].(*object.LPCObject); isObj {
				for _, item := range container.Inventory {
					if item == targetObj { return item }
				}
				return &object.Nil{}
			}

			if idStr, isStr := args[0].(*object.String); isStr {
				for _, item := range container.Inventory {
					res := d.CallFunction(item, "id", []object.Object{idStr})
					if isLPCTrue(res) { return item }
				}
			}
			return &object.Nil{}
		},
	})
}

// ==========================================
// 6. 時間與排程 (Time & Scheduling)
// ==========================================
func (d *Driver) registerTimeAndScheduling(obj *object.LPCObject) {
	obj.Vars.Set("time", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return &object.Integer{Value: time.Now().Unix()}
		},
	})

	obj.Vars.Set("call_out", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("call_out 至少需要 2 個參數") }
			funcName, ok := args[0].(*object.String)
			if !ok { return object.NewError("call_out 第一個參數必須是字串") }
			delay, ok := args[1].(*object.Integer)
			if !ok { return object.NewError("call_out 第二個參數必須是整數") }
			
			d.CallOut(obj, funcName.Value, time.Duration(delay.Value)*time.Second, args[2:]...)
			return &object.Nil{}
		},
	})

	obj.Vars.Set("remove_call_out", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			funcName, ok := args[0].(*object.String)
			if !ok { return &object.Integer{Value: 0} }

			d.mu.Lock()
			defer d.mu.Unlock()
			removedCount := 0
			var pending []*ScheduledCall
			for _, call := range d.CallOuts {
				if call.Caller == obj && call.FuncName == funcName.Value {
					removedCount++
				} else {
					pending = append(pending, call)
				}
			}
			d.CallOuts = pending
			
			// 回傳剩餘多少時間 (此處簡化為回傳移除的數量)
			return &object.Integer{Value: int64(removedCount)}
		},
	})

	obj.Vars.Set("call_other", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("call_other 至少需要兩個參數") }
			targetObj, ok := args[0].(*object.LPCObject)
			if !ok { return object.NewError("call_other 第一個參數必須是 object") }
			funcName, ok := args[1].(*object.String)
			if !ok { return object.NewError("call_other 第二個參數必須是 string") }

			result := d.CallFunction(targetObj, funcName.Value, args[2:])
			if result == nil { return &object.Integer{Value: 0} }
			return result
		},
	})
}

// ==========================================
// 7. 資料結構操作 (Strings, Arrays, Mappings)
// ==========================================
func (d *Driver) registerDataStructures(obj *object.LPCObject) {
	obj.Vars.Set("sizeof", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.Integer{Value: 0} }
			switch arg := args[0].(type) {
			case *object.Array:   return &object.Integer{Value: int64(len(arg.Elements))}
			case *object.String:  return &object.Integer{Value: int64(len(arg.Value))}
			case *object.Mapping: return &object.Integer{Value: int64(len(arg.Pairs))}
			}
			return &object.Integer{Value: 0}
		},
	})

	obj.Vars.Set("explode", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 2 { return object.NewError("explode 需要 2 個字串") }
			str, ok1 := args[0].(*object.String)
			delim, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("explode 需要字串") }
			
			parts := strings.Split(str.Value, delim.Value)
			elements := make([]object.Object, len(parts))
			for i, p := range parts { elements[i] = &object.String{Value: p} }
			return &object.Array{Elements: elements}
		},
	})

	obj.Vars.Set("implode", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 2 { return object.NewError("implode 需要 array 與 string") }
			arr, ok1 := args[0].(*object.Array)
			delim, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("implode 型別錯誤") }

			var strs []string
			for _, e := range arr.Elements {
				if s, ok := e.(*object.String); ok { strs = append(strs, s.Value) }
			}
			return &object.String{Value: strings.Join(strs, delim.Value)}
		},
	})

	obj.Vars.Set("keys", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("keys() 需要 1 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("keys() 參數必須是 mapping") }
			elements := make([]object.Object, 0, len(m.Pairs))
			for _, pair := range m.Pairs { elements = append(elements, pair.Key) }
			return &object.Array{Elements: elements}
		},
	})

	obj.Vars.Set("values", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return object.NewError("values() 需要 1 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("values() 參數必須是 mapping") }
			elements := make([]object.Object, 0, len(m.Pairs))
			for _, pair := range m.Pairs { elements = append(elements, pair.Value) }
			return &object.Array{Elements: elements}
		},
	})

	obj.Vars.Set("m_delete", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("m_delete() 需要 2 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("m_delete() 參數必須是 mapping") }
			key := args[1]
			hashable, ok := key.(object.Hashable)
			if !ok { return object.NewError("無法作為 mapping 的 key") }
			delete(m.Pairs, hashable.HashKey())
			return m 
		},
	})

	obj.Vars.Set("m_add", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 3 { return object.NewError("m_add() 需要 3 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("m_add() 參數必須是 mapping") }
			key, val := args[1], args[2]
			hashable, ok := key.(object.Hashable)
			if !ok { return object.NewError("無法作為 mapping 的 key") }
			m.Pairs[hashable.HashKey()] = object.HashPair{Key: key, Value: val}
			return m
		},
	})

	// 共用的 Closure/Func 呼叫器
	callMapFilterFn := func(targetObj *object.LPCObject, cb object.Object, callArgs []object.Object) object.Object {
		if funcName, ok := cb.(*object.String); ok {
			return d.CallFunction(targetObj, funcName.Value, callArgs)
		} else if cl, ok := cb.(*object.Closure); ok {
			target := cl.Target
			if target == nil { target = targetObj }
			fullArgs := append([]object.Object{}, cl.BoundArgs...)
			fullArgs = append(fullArgs, callArgs...)
			return d.CallFunction(target, cl.FuncName, fullArgs)
		}
		return nil
	}

	obj.Vars.Set("map_mapping", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("map_mapping 至少需要 2 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("第一個參數必須是 mapping") }

			newPairs := make(map[object.HashKey]object.HashPair)
			targetObj := getTarget(args[2:], obj)

			for _, pair := range m.Pairs {
				res := callMapFilterFn(targetObj, args[1], []object.Object{pair.Key, pair.Value})
				if res == nil || res.TokenType() == object.ErrorType { res = &object.Integer{Value: 0} }
				newPairs[pair.Key.(object.Hashable).HashKey()] = object.HashPair{Key: pair.Key, Value: res}
			}
			return &object.Mapping{Pairs: newPairs}
		},
	})

	filterFn := &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("filter() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("第一個參數必須是陣列") }

			targetObj := getTarget(args[2:], obj)
			filtered := []object.Object{}
			
			for _, el := range arr.Elements {
				res := callMapFilterFn(targetObj, args[1], []object.Object{el})
				if isLPCTrue(res) { filtered = append(filtered, el) }
			}
			return &object.Array{Elements: filtered}
		},
	}
	obj.Vars.Set("filter", filterFn)
	obj.Vars.Set("filter_array", filterFn)

	mapFn := &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("map() 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("第一個參數必須是陣列") }

			targetObj := getTarget(args[2:], obj)
			mapped := make([]object.Object, len(arr.Elements))
			
			for i, el := range arr.Elements {
				res := callMapFilterFn(targetObj, args[1], []object.Object{el})
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
	obj.Vars.Set("map_array", mapFn)

	obj.Vars.Set("sort_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("sort_array 至少需 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("第一個參數必須是陣列") }

			newElements := make([]object.Object, len(arr.Elements))
			copy(newElements, arr.Elements)
			targetObj := getTarget(args[2:], obj)

			sort.SliceStable(newElements, func(i, j int) bool {
				res := callMapFilterFn(targetObj, args[1], []object.Object{newElements[i], newElements[j]})
				if iRes, ok := res.(*object.Integer); ok { return iRes.Value < 0 }
				return false
			})
			return &object.Array{Elements: newElements}
		},
	})

	obj.Vars.Set("member_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: -1} }
			val := args[0]
			arr, ok := args[1].(*object.Array)
			if !ok { return &object.Integer{Value: -1} }

			for i, el := range arr.Elements {
				if isEqual(val, el) { return &object.Integer{Value: int64(i)} }
			}
			return &object.Integer{Value: -1}
		},
	})

	obj.Vars.Set("unique_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("unique_array 至少需 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("第一個參數必須是陣列") }

			groups := make(map[string][]object.Object)
			targetObj := obj 
			
			for _, el := range arr.Elements {
				res := callMapFilterFn(targetObj, args[1], []object.Object{el})
				if res == nil { res = &object.Integer{Value: 0} }
				key := res.Inspect()
				groups[key] = append(groups[key], el)
			}
			
			result := make([]object.Object, 0, len(groups))
			for _, g := range groups { result = append(result, &object.Array{Elements: g}) }
			return &object.Array{Elements: result}
		},
	})
}

// ==========================================
// 8. 字串操作 (Strings)
// ==========================================
func (d *Driver) registerStringEfuns(obj *object.LPCObject) {
	obj.Vars.Set("sprintf", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return object.NewError("sprintf 需要參數") }
			formatObj, ok := args[0].(*object.String)
			if !ok { return object.NewError("第一個參數必須是字串") }

			var goArgs []interface{}
			for _, arg := range args[1:] {
				switch a := arg.(type) {
				case *object.Integer: goArgs = append(goArgs, a.Value)
				case *object.String:  goArgs = append(goArgs, a.Value)
				case *object.Float:   goArgs = append(goArgs, a.Value)
				default:              goArgs = append(goArgs, a.Inspect())
				}
			}

			formatStr := strings.ReplaceAll(formatObj.Value, "%O", "%s")
			result := fmt.Sprintf(formatStr, goArgs...)
			return &object.String{Value: result}
		},
	})

	obj.Vars.Set("lower_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.String{Value: ""} }
			if str, ok := args[0].(*object.String); ok {
				return &object.String{Value: strings.ToLower(str.Value)}
			}
			return &object.String{Value: ""}
		},
	})

	obj.Vars.Set("upper_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.String{Value: ""} }
			if str, ok := args[0].(*object.String); ok {
				return &object.String{Value: strings.ToUpper(str.Value)}
			}
			return &object.String{Value: ""}
		},
	})

	obj.Vars.Set("strlen", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.Integer{Value: 0} }
			if str, ok := args[0].(*object.String); ok {
				return &object.Integer{Value: int64(len([]rune(str.Value)))}
			}
			return &object.Integer{Value: 0}
		},
	})

	obj.Vars.Set("substr", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("substr 需 2 個參數") }
			str, ok1 := args[0].(*object.String)
			start, ok2 := args[1].(*object.Integer)
			if !ok1 || !ok2 { return object.NewError("substr 型別錯誤") }

			runes := []rune(str.Value)
			length := len(runes)
			sIdx := int(start.Value)
			
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

	obj.Vars.Set("strsrch", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("strsrch 需 2 個參數") }
			str, ok1 := args[0].(*object.String)
			pattern, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("strsrch 參數必須是字串") }

			reverse := false
			if len(args) > 2 {
				if flag, ok := args[2].(*object.Integer); ok && flag.Value != 0 {
					reverse = true 
				}
			}

			var byteIdx int
			if reverse {
				byteIdx = strings.LastIndex(str.Value, pattern.Value)
			} else {
				byteIdx = strings.Index(str.Value, pattern.Value)
			}

			if byteIdx == -1 { return &object.Integer{Value: -1} }
			runeIdx := len([]rune(str.Value[:byteIdx]))
			return &object.Integer{Value: int64(runeIdx)}
		},
	})

	obj.Vars.Set("capitalize", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.String{Value: ""} }
			str, ok := args[0].(*object.String)
			if !ok { return &object.String{Value: ""} }

			runes := []rune(str.Value)
			if len(runes) == 0 { return &object.String{Value: ""} }
			runes[0] = []rune(strings.ToUpper(string(runes[0])))[0]
			return &object.String{Value: string(runes)}
		},
	})

	obj.Vars.Set("trim", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.String{Value: ""} }
			str, ok := args[0].(*object.String)
			if !ok { return &object.String{Value: ""} }
			return &object.String{Value: strings.TrimSpace(str.Value)}
		},
	})
}

// ==========================================
// 9. 系統與檔案 (System & Files)
// ==========================================
func (d *Driver) registerSystemAndFiles(obj *object.LPCObject) {
	obj.Vars.Set("load_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			path := args[0].Inspect()
			if !strings.HasSuffix(path, ".c") { path += ".c" }
			res, err := d.LoadObject(path)
			if err != nil { return object.NewError(err.Error()) }
			return res
		},
	})

	obj.Vars.Set("read_file", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			fileName, ok := args[0].(*object.String)
			if !ok { return object.NewError("read_file 需要字串參數") }

			fullPath := filepath.Join(d.Config.MudLibPath, fileName.Value)
			content, err := os.ReadFile(fullPath)
			if err != nil { return &object.Nil{} }
			return &object.String{Value: string(content)}
		},
	})

	obj.Vars.Set("write_file", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: 0} }
			fileName, ok1 := args[0].(*object.String)
			content, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return object.NewError("write_file 需要兩個字串") }

			flag := 0 // 0 = append, 1 = overwrite
			if len(args) > 2 {
				if i, ok := args[2].(*object.Integer); ok { flag = int(i.Value) }
			}

			fullPath := filepath.Join(d.Config.MudLibPath, fileName.Value)
			mode := os.O_APPEND | os.O_CREATE | os.O_WRONLY
			if flag == 1 { mode = os.O_TRUNC | os.O_CREATE | os.O_WRONLY }

			f, err := os.OpenFile(fullPath, mode, 0644)
			if err != nil { return &object.Integer{Value: 0} }
			defer f.Close()

			if _, err := f.WriteString(content.Value); err != nil {
				return &object.Integer{Value: 0}
			}
			return &object.Integer{Value: 1}
		},
	})

	obj.Vars.Set("ctime", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			ts := time.Now().Unix()
			if len(args) > 0 {
				if i, ok := args[0].(*object.Integer); ok { ts = i.Value }
			}
			// LPC 標準時間格式 (例如 "Mon Jan 02 15:04:05 2006")
			return &object.String{Value: time.Unix(ts, 0).Format("Mon Jan _2 15:04:05 2006")}
		},
	})

	obj.Vars.Set("users", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			var userObjs []object.Object
			d.interactiveObjects.Range(func(key, value interface{}) bool {
				if conn, ok := value.(*PlayerConnection); ok && conn.IsActive {
					userObjs = append(userObjs, conn.Object)
				}
				return true
			})
			return &object.Array{Elements: userObjs}
		},
	})

	obj.Vars.Set("shout", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			msg := args[0].Inspect()
			if s, ok := args[0].(*object.String); ok { msg = s.Value }

			d.interactiveObjects.Range(func(key, value interface{}) bool {
				if conn, ok := value.(*PlayerConnection); ok && conn.IsActive {
					safeMsg := strings.ReplaceAll(msg, "\r\n", "\n")
					safeMsg = strings.ReplaceAll(safeMsg, "\n", "\r\n")
					conn.Send(safeMsg)
				}
				return true
			})
			return &object.Nil{}
		},
	})

	// input_to 實作 (注意：需要配合 driver.go 中的 PlayerConnection 與輸入處理迴圈修改)
	obj.Vars.Set("input_to", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("input_to 需要函式或閉包作為參數") }
			p := d.GetCurrentPlayer()
			if p == nil { return &object.Integer{Value: 0} }

			if funcName, ok := args[0].(*object.String); ok {
				// 將指定的函式名稱存入玩家連線狀態中
				p.NextInputFunc = funcName.Value
				return &object.Integer{Value: 1}
			}

			// DEBUG 用
			fmt.Printf("DEBUG: %s 呼叫了 input_to\n", p.Object.Filename)
			
			return &object.Integer{Value: 0}
		},
	})
}

// ==========================================
// 10. 存檔與連線轉移 (Persistence & Connection)
// ==========================================
func (d *Driver) registerPersistenceEfuns(obj *object.LPCObject) {
	// save_object(string file) - 儲存當前物件的變數到檔案
	obj.Vars.Set("save_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			fileArg, ok := args[0].(*object.String)
			if !ok { return object.NewError("save_object 需要字串參數") }

			fileName := fileArg.Value
			if !strings.HasSuffix(fileName, ".o") { fileName += ".o" } // MUD 慣例存檔副檔名為 .o
			fullPath := filepath.Join(d.Config.MudLibPath, fileName)

			// 將 LPC 變數轉換為 Go 的 map 以便轉成 JSON
			saveData := make(map[string]interface{})
			for k, v := range obj.Vars.GetAll() {
				// 慣例：以底線開頭的變數不存檔 (暫時變數)，且不儲存函式/內建函式
				if strings.HasPrefix(k, "_") { continue }
				if v.TokenType() == object.FunctionType || v.TokenType() == object.BuiltinType || v.TokenType() == object.ClosureType { continue }
				
				saveData[k] = lpcToGoValue(v)
			}

			// 確保目錄存在
			os.MkdirAll(filepath.Dir(fullPath), 0755)

			jsonData, err := json.MarshalIndent(saveData, "", "  ")
			if err != nil { return &object.Integer{Value: 0} }

			err = os.WriteFile(fullPath, jsonData, 0644)
			if err != nil { return &object.Integer{Value: 0} }

			return &object.Integer{Value: 1}
		},
	})

	// restore_object(string file) - 從檔案讀取變數到當前物件
	obj.Vars.Set("restore_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			fileArg, ok := args[0].(*object.String)
			if !ok { return object.NewError("restore_object 需要字串參數") }

			fileName := fileArg.Value
			if !strings.HasSuffix(fileName, ".o") { fileName += ".o" }
			fullPath := filepath.Join(d.Config.MudLibPath, fileName)

			jsonData, err := os.ReadFile(fullPath)
			if err != nil { return &object.Integer{Value: 0} } // 檔案不存在視為無資料，不報錯

			var loadedData map[string]interface{}
			err = json.Unmarshal(jsonData, &loadedData)
			if err != nil { return &object.Integer{Value: 0} }

			// 將讀取到的 Go 資料轉回 LPC 物件並存入環境
			for k, v := range loadedData {
				obj.Vars.Set(k, goToLPCValue(v))
			}

			return &object.Integer{Value: 1}
		},
	})

	// exec(object target, object src) - 轉移玩家連線 (例如從 login.c 轉移到 user.c)
	obj.Vars.Set("exec", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("exec 需要兩個 object 參數") }
			target, ok1 := args[0].(*object.LPCObject)
			src, ok2 := args[1].(*object.LPCObject)
			if !ok1 || !ok2 { return object.NewError("exec 參數必須是 object") }

			// 呼叫 Driver 來處理底層連線轉移
			success := d.TransferConnection(target, src)
			if success {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})
}

// 將 LPC Object 轉為 Go 原生型別 (給 JSON Marshal 用)
func lpcToGoValue(o object.Object) interface{} {
	if o == nil { return nil }
	switch v := o.(type) {
	case *object.Integer: return v.Value
	case *object.Float: return v.Value
	case *object.String: return v.Value
	case *object.Boolean: return v.Value
	case *object.Array:
		arr := make([]interface{}, len(v.Elements))
		for i, el := range v.Elements { arr[i] = lpcToGoValue(el) }
		return arr
	// 註：Mapping 轉 JSON 比較複雜，因為 JSON 的 key 必須是字串。
	// 這裡簡化處理，將 Mapping 轉為 string map。
	case *object.Mapping:
		m := make(map[string]interface{})
		for _, pair := range v.Pairs {
			keyStr := pair.Key.Inspect()
			if s, ok := pair.Key.(*object.String); ok { keyStr = s.Value }
			m[keyStr] = lpcToGoValue(pair.Value)
		}
		return m
	default:
		return nil
	}
}

// 將 Go 原生型別轉回 LPC Object (給 JSON Unmarshal 用)
func goToLPCValue(v interface{}) object.Object {
	if v == nil { return &object.Nil{} }
	switch val := v.(type) {
	case float64: // JSON 數字預設會被解析為 float64
		// 判斷是否為整數
		if val == float64(int64(val)) {
			return &object.Integer{Value: int64(val)}
		}
		return &object.Float{Value: val}
	case string:
		return &object.String{Value: val}
	case bool:
		return &object.Boolean{Value: val}
	case []interface{}:
		arr := make([]object.Object, len(val))
		for i, el := range val { arr[i] = goToLPCValue(el) }
		return &object.Array{Elements: arr}
	case map[string]interface{}:
		m := &object.Mapping{Pairs: make(map[object.HashKey]object.HashPair)}
		for k, el := range val {
			strKey := &object.String{Value: k}
			m.Pairs[strKey.HashKey()] = object.HashPair{Key: strKey, Value: goToLPCValue(el)}
		}
		return m
	default:
		return &object.Nil{}
	}
}
