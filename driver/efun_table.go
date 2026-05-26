// driver/efun_table.go
package driver

import (
	"encoding/json"
	"sort"
	"strings"

	"mudscript/object"
)

func (d *Driver) registerDataStructures(obj *object.LPCObject) {
	// 語法: mixed allocate(int size)
	// 說明: 預分配指定長度的陣列。
	// 範例: mixed *arr = allocate(10);
	obj.Vars.Set("allocate", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Array{Elements: []object.Object{}} }
			size, ok := args[0].(*object.Integer)
			if !ok { return &object.Array{Elements: []object.Object{}} }
			
			elements := make([]object.Object, size.Value)
			for i := range elements {
				elements[i] = &object.Integer{Value: 0}
			}
			return &object.Array{Elements: elements}
		},
	})

	// 語法: mixed copy(mixed arg)
	// 說明: 深層複製一個物件、陣列或 Mapping。
	// 範例: mapping m2 = copy(m1);
	obj.Vars.Set("copy", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			return deepCopyLPCValue(args[0])
		},
	})

	// 語法: mapping m_add(mapping m, mixed key, mixed val)
	// 說明: 在 mapping 中加入一對 key-value。
	// 範例: m_add(my_map, "hp", 100);
	obj.Vars.Set("m_add", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("m_add 需要至少 2 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("m_add 第一個參數必須是 mapping") }
			
			key := args[1]
			val := object.Object(&object.Integer{Value: 0})
			if len(args) > 2 {
				val = args[2]
			}
			
			if h, ok := key.(object.Hashable); ok {
				m.Pairs[h.HashKey()] = object.HashPair{Key: key, Value: val}
			}
			return m
		},
	})

	// 語法: string json_encode(mixed data)
	// 說明: 將物件轉成 JSON
	// 範例: payload = sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data));
	obj.Vars.Set("json_encode", &object.Builtin{
        Fn: func(args ...object.Object) object.Object {
            if len(args) < 1 {
                return &object.String{Value: "{}"}
            }
            
            // 1. 利用現有的輔助函式將 LPC 物件轉為 Go interface{}
            goVal := lpcToGoValue(args[0])
            
            // 2. 使用 Go 標準庫進行 JSON 編碼
            jsonData, err := json.Marshal(goVal)
            if err != nil {
                return &object.String{Value: "{}"}
            }
            
            return &object.String{Value: string(jsonData)}
        },
    })
	// 語法: mixed *values(mapping m)
	// 說明: 取得 Mapping 中所有的 Value，回傳為陣列。
	// 範例: values((["hp": 100, "mp": 50])) -> ({ 100, 50 })
	obj.Vars.Set("values", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.Array{Elements: []object.Object{}} }
			m, ok := args[0].(*object.Mapping)
			if !ok { return &object.Array{Elements: []object.Object{}} }
			var elements []object.Object
			for _, pair := range m.Pairs { elements = append(elements, pair.Value) }
			return &object.Array{Elements: elements}
		},
	})

	// 語法: int sizeof(mixed target)
	// 說明: 回傳陣列元素數量、字串長度，或是 Mapping 鍵值對數量。
	// 範例: sizeof(({1, 2, 3})) -> 3; sizeof("abc") -> 3
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

	// 語法: string *explode(string str, string delim)
	// 說明: 以 delim 為分隔符號，將字串切割成陣列。
	// 範例: explode("a,b,c", ",") -> ({"a", "b", "c"})
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

	// 語法: string implode(string *arr, string delim)
	// 說明: 以 delim 為連接符號，將字串陣列合併為單一字串。
	// 範例: implode(({"a", "b"}), "-") -> "a-b"
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

	// 語法: mixed *keys(mapping m)
	// 說明: 取得 Mapping 中所有的 Key，回傳為陣列。
	// 範例: keys((["a": 1, "b": 2])) -> ({"a", "b"})
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

	// 語法: mapping m_delete(mapping m, mixed key)
	// 說明: 從 Mapping 中刪除指定的 Key 與其對應的 Value。
	// 範例: m_delete(my_map, "hp");
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

	// 語法: int member_array(mixed item, mixed *arr, [int start])
	// 說明: 尋找 item 在陣列中的索引位置。若找不到回傳 -1。
	// 範例: member_array("b", ({"a", "b", "c"})) -> 1
	obj.Vars.Set("member_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: -1} }
			val := args[0]
			arr, ok := args[1].(*object.Array)
			if !ok { return &object.Integer{Value: -1} }

			start := 0
			if len(args) > 2 {
				if startInt, ok := args[2].(*object.Integer); ok {
					start = int(startInt.Value)
				}
			}

			if start < 0 { start = 0 }
			if start >= len(arr.Elements) { return &object.Integer{Value: -1} }

			for i := start; i < len(arr.Elements); i++ {
				if isEqual(val, arr.Elements[i]) { return &object.Integer{Value: int64(i)} }
			}
			return &object.Integer{Value: -1}
		},
	})

	// 語法: mapping filter_mapping(mapping m, string|closure func, [mixed args...])
	// 說明: 過濾 Mapping。
	// 範例: filter_mapping(m, "is_high_score");
	obj.Vars.Set("filter_mapping", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("filter_mapping 至少需要 2 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("filter_mapping 第一個參數必須是 mapping") }
			
			fnArg := args[1]
			var extraArgs []object.Object
			if len(args) > 2 { extraArgs = args[2:] }

			newPairs := make(map[object.HashKey]object.HashPair)
			for hKey, pair := range m.Pairs {
				callArgs := append([]object.Object{pair.Key, pair.Value}, extraArgs...)
				res := d.executeCallback(obj, fnArg, callArgs)
				if isLPCTrue(res) {
					newPairs[hKey] = pair
				}
			}
			return &object.Mapping{Pairs: newPairs}
		},
	})

	// 語法: mapping map_mapping(mapping m, string|closure func, [mixed args...])
	// 說明: 映射 Mapping。
	// 範例: map_mapping(m, "double_value");
	obj.Vars.Set("map_mapping", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("map_mapping 至少需要 2 個參數") }
			m, ok := args[0].(*object.Mapping)
			if !ok { return object.NewError("map_mapping 第一個參數必須是 mapping") }
			
			fnArg := args[1]
			var extraArgs []object.Object
			if len(args) > 2 { extraArgs = args[2:] }

			newPairs := make(map[object.HashKey]object.HashPair)
			for hKey, pair := range m.Pairs {
				callArgs := append([]object.Object{pair.Key, pair.Value}, extraArgs...)
				res := d.executeCallback(obj, fnArg, callArgs)
				newPairs[hKey] = object.HashPair{Key: pair.Key, Value: res}
			}
			return &object.Mapping{Pairs: newPairs}
		},
	})

	// 語法: mixed *filter_array(mixed *arr, string|closure func, [mixed args...])
	// 說明: 過濾陣列。
	// 範例: filter_array(arr, "is_even");
	obj.Vars.Set("filter_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("filter_array 至少需要 2 個參數") }
			arr, ok := args[0].(*object.Array)
			if !ok { return object.NewError("filter_array 第一個參數必須是 array") }
			
			fnArg := args[1]
			var extraArgs []object.Object
			if len(args) > 2 { extraArgs = args[2:] }

			var newElems []object.Object
			for _, el := range arr.Elements {
				callArgs := append([]object.Object{el}, extraArgs...)
				res := d.executeCallback(obj, fnArg, callArgs)
				if isLPCTrue(res) {
					newElems = append(newElems, el)
				}
			}
			return &object.Array{Elements: newElems}
		},
	})

	// 語法: mixed *map_array(mixed *arr, string|closure func, [mixed args...])
	// 說明: 映射陣列。
	// 範例: map_array(arr, "to_upper");
	obj.Vars.Set("map_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			arr, ok := args[0].(*object.Array)
			if !ok { return args[0] }
			
			fnArg := args[1]
			var extraArgs []object.Object
			if len(args) > 2 { extraArgs = args[2:] }

			newElems := make([]object.Object, len(arr.Elements))
			for i, el := range arr.Elements {
				callArgs := append([]object.Object{el}, extraArgs...)
				res := d.executeCallback(obj, fnArg, callArgs)
				newElems[i] = res
			}
			return &object.Array{Elements: newElems}
		},
	})

	// 語法: mixed filter(mixed coll, string|closure func, [mixed args...])
	// 說明: 通用過濾函式，支援 Array 與 Mapping。
	// 範例: filter(coll, "is_valid");
	obj.Vars.Set("filter", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			if _, ok := args[0].(*object.Array); ok {
				return obj.Vars.GetMust("filter_array").(*object.Builtin).Fn(args...)
			}
			if _, ok := args[0].(*object.Mapping); ok {
				return obj.Vars.GetMust("filter_mapping").(*object.Builtin).Fn(args...)
			}
			return args[0]
		},
	})

	// 語法: mixed map(mixed coll, string|closure func, [mixed args...])
	// 說明: 通用映射函式，支援 Array 與 Mapping。
	// 範例: map(coll, "process");
	obj.Vars.Set("map", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			if _, ok := args[0].(*object.Array); ok {
				return obj.Vars.GetMust("map_array").(*object.Builtin).Fn(args...)
			}
			if _, ok := args[0].(*object.Mapping); ok {
				return obj.Vars.GetMust("map_mapping").(*object.Builtin).Fn(args...)
			}
			return args[0]
		},
	})

	// 語法: mixed *unique_array(mixed *arr, [string|closure func], [mixed args...])
	// 說明: 若提供 callback，則根據 callback 回傳值將陣列分組，回傳一個二維陣列。若無 callback，則移除重複元素。
	// 範例: unique_array(arr, "group_by_type");
	obj.Vars.Set("unique_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Array{Elements: []object.Object{}} }
			arr, ok := args[0].(*object.Array)
			if !ok { return args[0] }

			// 只有一個參數，執行去重
			if len(args) == 1 {
				var unique []object.Object
				for _, el := range arr.Elements {
					found := false
					for _, u := range unique {
						if isEqual(el, u) {
							found = true
							break
						}
					}
					if !found { unique = append(unique, el) }
				}
				return &object.Array{Elements: unique}
			}

			// 兩個參數以上，執行分組
			fnArg := args[1]
			var extraArgs []object.Object
			if len(args) > 2 { extraArgs = args[2:] }

			groups := make(map[string][]object.Object)
			var keys []string

			for _, el := range arr.Elements {
				callArgs := append([]object.Object{el}, extraArgs...)
				res := d.executeCallback(obj, fnArg, callArgs)
				key := res.Inspect()
				if _, exists := groups[key]; !exists {
					keys = append(keys, key)
				}
				groups[key] = append(groups[key], el)
			}

			var result []object.Object
			for _, k := range keys {
				result = append(result, &object.Array{Elements: groups[k]})
			}
			return &object.Array{Elements: result}
		},
	})

	// 語法: mixed *sort_array(mixed *arr, string|closure|int func, [mixed args...])
	// 說明: 排序陣列。callback(a, b) 回傳 >0 代表 a > b, <0 代表 a < b, 0 代表相等。傳入整數 1 為升序，-1 為降序。
	// 範例: sort_array(arr, 1); 或 sort_array(arr, "compare_func");
	obj.Vars.Set("sort_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			arr, ok := args[0].(*object.Array)
			if !ok { return args[0] }

			fnArg := args[1]
			var extraArgs []object.Object
			if len(args) > 2 { extraArgs = args[2:] }

			// 複製陣列避免原地修改
			newElems := make([]object.Object, len(arr.Elements))
			copy(newElems, arr.Elements)

			sort.SliceStable(newElems, func(i, j int) bool {
				if direction, isInt := fnArg.(*object.Integer); isInt {
					a, b := newElems[i], newElems[j]
					var cmp int
					if a.TokenType() == object.IntegerType && b.TokenType() == object.IntegerType {
						av := a.(*object.Integer).Value
						bv := b.(*object.Integer).Value
						if av < bv { cmp = -1 } else if av > bv { cmp = 1 }
					} else if a.TokenType() == object.StringType && b.TokenType() == object.StringType {
						av := a.(*object.String).Value
						bv := b.(*object.String).Value
						if av < bv { cmp = -1 } else if av > bv { cmp = 1 }
					} else if a.TokenType() == object.FloatType && b.TokenType() == object.FloatType {
						av := a.(*object.Float).Value
						bv := b.(*object.Float).Value
						if av < bv { cmp = -1 } else if av > bv { cmp = 1 }
					} else {
						av := a.Inspect()
						bv := b.Inspect()
						if av < bv { cmp = -1 } else if av > bv { cmp = 1 }
					}
					
					if direction.Value > 0 {
						return cmp < 0
					}
					return cmp > 0
				}

				callArgs := append([]object.Object{newElems[i], newElems[j]}, extraArgs...)
				res := d.executeCallback(obj, fnArg, callArgs)
				if val, ok := res.(*object.Integer); ok {
					return val.Value < 0 // 昇序排列：當 res < 0 時代表 i 應在 j 前面
				}
				return false
			})

			return &object.Array{Elements: newElems}
		},
	})
}
