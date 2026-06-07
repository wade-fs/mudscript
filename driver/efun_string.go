// driver/efun_string.go
package driver

import (
	"fmt"
	"log"
	"regexp"
	"strings"

	"mudscript/object"
)

func (d *Driver) registerStringEfuns(obj *object.LPCObject) {
	// 語法: string capitalize(string str)
	// 說明: 將字串的第一個字母轉換為大寫。
	// 範例: capitalize("hello") -> "Hello"
	obj.Vars.Set("capitalize", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return &object.String{Value: ""}
			}
			str, ok := args[0].(*object.String)
			if !ok {
				return &object.String{Value: args[0].Inspect()}
			}
			if len(str.Value) == 0 {
				return &object.String{Value: ""}
			}
			return &object.String{Value: strings.ToUpper(str.Value[:1]) + str.Value[1:]}
		},
	})

	// 語法: string lower_case(string str)
	// 說明: 將字串全部轉換為小寫。
	// 範例: lower_case("HELLO") -> "hello"
	obj.Vars.Set("lower_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return &object.String{Value: ""}
			}
			str, ok := args[0].(*object.String)
			if !ok {
				return &object.String{Value: strings.ToLower(args[0].Inspect())}
			}
			return &object.String{Value: strings.ToLower(str.Value)}
		},
	})

	// 語法: string upper_case(string str)
	// 說明: 將字串全部轉換為大寫。
	// 範例: upper_case("hello") -> "HELLO"
	obj.Vars.Set("upper_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return &object.String{Value: ""}
			}
			str, ok := args[0].(*object.String)
			if !ok {
				return &object.String{Value: strings.ToUpper(args[0].Inspect())}
			}
			return &object.String{Value: strings.ToUpper(str.Value)}
		},
	})

	// 語法: string sprintf(string format, ...)
	// 說明: C 語言風格的字串格式化。
	// 範例: sprintf("HP: %d/%d", 10, 20) -> "HP: 10/20"
	obj.Vars.Set("sprintf", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return object.NewError("sprintf 需要參數")
			}
			formatObj, ok := args[0].(*object.String)
			if !ok {
				return object.NewError("第一個參數必須是字串")
			}

			// 🚀 關鍵最佳化：將 LPC 格式標籤轉換為 Go 相容格式
			// 我們將 %d, %s, %f, %O 等轉換為 %v，但保留填充與寬度
			// e.g. %02d -> %02v, %-10s -> %-10v
			// 注意：不匹配 %% (轉義的百分比)
			var re = regexp.MustCompile(`%[-+ #0]*[0-9]*(\.[0-9]+)?[dsfO]`)
			formatStr := re.ReplaceAllStringFunc(formatObj.Value, func(m string) string {
				return m[:len(m)-1] + "v"
			})

			var goArgs []interface{}
			for _, arg := range args[1:] {
				if arg == nil {
					goArgs = append(goArgs, "nil")
				} else {
					switch v := arg.(type) {
					case *object.Integer:
						goArgs = append(goArgs, v.Value)
					case *object.Float:
						goArgs = append(goArgs, v.Value)
					case *object.String:
						goArgs = append(goArgs, v.Value)
					default:
						goArgs = append(goArgs, arg.Inspect())
					}
				}
			}

			// 防護：使用 recover 避免 sprintf 拋出 panic
			defer func() {
				if r := recover(); r != nil {
					log.Printf("sprintf error: %v, format: %s", r, formatStr)
				}
			}()

			result := fmt.Sprintf(formatStr, goArgs...)
			return &object.String{Value: result}
		},
	})

	// 語法: int strlen(string str)
	// 說明: 回傳字串長度。
	// 範例: strlen("hello") -> 5
	obj.Vars.Set("strlen", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return &object.Integer{Value: 0}
			}
			str, ok := args[0].(*object.String)
			if !ok {
				return &object.Integer{Value: int64(len(args[0].Inspect()))}
			}
			return &object.Integer{Value: int64(len(str.Value))}
		},
	})

	// 語法: string *explode(string str, string del)
	// 說明: 將字串依分隔符號切割成陣列。
	// 範例: explode("a,b,c", ",") -> ({ "a", "b", "c" })
	obj.Vars.Set("explode", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 {
				return &object.Array{Elements: []object.Object{}}
			}
			str, ok1 := args[0].(*object.String)
			del, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 {
				return &object.Array{Elements: []object.Object{}}
			}
			if del.Value == "" {
				// 特殊情況：空分隔符號，切割每個字元 (包含多位元組 UTF-8)
				parts := strings.Split(str.Value, "")
				elements := make([]object.Object, len(parts))
				for i, p := range parts {
					elements[i] = &object.String{Value: p}
				}
				return &object.Array{Elements: elements}
			}
			parts := strings.Split(str.Value, del.Value)
			elements := make([]object.Object, len(parts))
			for i, p := range parts {
				elements[i] = &object.String{Value: p}
			}
			return &object.Array{Elements: elements}
		},
	})

	// 語法: string implode(string *arr, string del)
	// 說明: 將陣列中的元素依分隔符號組合成字串。
	// 範例: implode(({ "a", "b", "c" }), ",") -> "a,b,c"
	obj.Vars.Set("implode", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 {
				return &object.String{Value: ""}
			}
			arr, ok1 := args[0].(*object.Array)
			del, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 {
				return &object.String{Value: ""}
			}
			parts := make([]string, len(arr.Elements))
			for i, el := range arr.Elements {
				if s, ok := el.(*object.String); ok {
					parts[i] = s.Value
				} else {
					parts[i] = el.Inspect()
				}
			}
			return &object.String{Value: strings.Join(parts, del.Value)}
		},
	})

	// 語法: string replace_string(string str, string old, string new)
	// 說明: 取代字串中所有的特定子字串。
	// 範例: replace_string("hello", "l", "w") -> "hewwo"
	obj.Vars.Set("replace_string", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 3 {
				if len(args) > 0 {
					return args[0]
				}
				return &object.String{Value: ""}
			}
			str, ok1 := args[0].(*object.String)
			old, ok2 := args[1].(*object.String)
			newS, ok3 := args[2].(*object.String)
			if !ok1 || !ok2 || !ok3 {
				return args[0]
			}
			return &object.String{Value: strings.ReplaceAll(str.Value, old.Value, newS.Value)}
		},
	})

	// 語法: int strsrch(string str, string sub, [int start])
	// 說明: 搜尋子字串第一次出現的位置。回傳 -1 代表未找到。
	// 範例: strsrch("hello", "e") -> 1
	obj.Vars.Set("strsrch", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 {
				return &object.Integer{Value: -1}
			}
			str, ok1 := args[0].(*object.String)
			sub, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 {
				return &object.Integer{Value: -1}
			}
			start := 0
			if len(args) > 2 {
				if i, ok := args[2].(*object.Integer); ok {
					start = int(i.Value)
				}
			}
			if start < 0 {
				start = 0
			}
			if start >= len(str.Value) {
				return &object.Integer{Value: -1}
			}
			pos := strings.Index(str.Value[start:], sub.Value)
			if pos == -1 {
				return &object.Integer{Value: -1}
			}
			return &object.Integer{Value: int64(pos + start)}
		},
	})

	// 語法: string substr(string str, int start, [int length])
	// 說明: 取得子字串。
	// 範例: substr("hello", 1, 2) -> "el"
	obj.Vars.Set("substr", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 {
				if len(args) == 1 {
					return args[0]
				}
				return &object.String{Value: ""}
			}
			str, ok1 := args[0].(*object.String)
			start, ok2 := args[1].(*object.Integer)
			if !ok1 || !ok2 {
				return &object.String{Value: ""}
			}
			
			s := int(start.Value)
			if s < 0 { s = 0 }
			if s >= len(str.Value) { return &object.String{Value: ""} }

			if len(args) > 2 {
				length, ok3 := args[2].(*object.Integer)
				if ok3 {
					l := int(length.Value)
					if s+l > len(str.Value) { l = len(str.Value) - s }
					if l < 0 { l = 0 }
					return &object.String{Value: str.Value[s : s+l]}
				}
			}
			return &object.String{Value: str.Value[s:]}
		},
	})

	// 語法: string trim(string str)
	// 說明: 移除字串前後的空白與換行。
	// 範例: trim("  hello  \n") -> "hello"
	obj.Vars.Set("trim", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				return &object.String{Value: ""}
			}
			str, ok := args[0].(*object.String)
			if !ok {
				return &object.String{Value: strings.TrimSpace(args[0].Inspect())}
			}
			return &object.String{Value: strings.TrimSpace(str.Value)}
		},
	})
}

func (d *Driver) registerAdvancedStringEfuns2(obj *object.LPCObject) {
	// 🚀 新增：sprintf 強化版別名 (與某些 Mudlib 相容)
	obj.Vars.Set("printf", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			res := obj.Vars.GetMust("sprintf").(*object.Builtin).Fn(args...)
			if s, ok := res.(*object.String); ok {
				d.TellObject(obj, s.Value)
			}
			return res
		},
	})
}
