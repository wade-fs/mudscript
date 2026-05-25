// driver/efun.go
package driver

import (
	"encoding/json"
	"fmt"
	"io/fs"
	"log"
	"math/rand"
	"os"
	"path/filepath"
	"regexp"
	"runtime"
	"sort"
	"strconv"
	"strings"
	"time"

	"golang.org/x/crypto/bcrypt"
	"mudscript/evaluator"
	"mudscript/object"
)

// ==========================================
// 輔助工具函式 (Internal Helpers)
// ==========================================

// isLPCTrue 判斷 LPC 中的真假值 (符合現代語言習慣：0, "", [], ([]) 皆為假)
func isLPCTrue(o object.Object) bool {
	if o == nil || o.TokenType() == object.NilType {
		return false
	}
	if i, ok := o.(*object.Integer); ok && i.Value == 0 {
		return false
	}
	if s, ok := o.(*object.String); ok && s.Value == "" {
		return false
	}
	if a, ok := o.(*object.Array); ok && len(a.Elements) == 0 {
		return false
	}
	if m, ok := o.(*object.Mapping); ok && len(m.Pairs) == 0 {
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
	d.registerFunctionalEfuns(obj)
	d.registerStringEfuns(obj)
	d.registerSystemAndFiles(obj)
	d.registerPersistenceEfuns(obj)
	d.registerP2PEfuns(obj)

	// 🚀 新增：註冊 SimulEfuns
	d.RegisterSimulEfuns(obj)
}

// RegisterSimulEfuns 掃描 SimulEfun 物件並將其函式注入目標物件
func (d *Driver) RegisterSimulEfuns(obj *object.LPCObject) {
	if d.SimulEfunObj == nil || obj == d.SimulEfunObj {
		return
	}

	// 遍歷 SimulEfun 物件的所有變數/函式
	for name, val := range d.SimulEfunObj.Vars.GetAll() {
		// 只注入函式 (Function)，不注入一般變數
		if _, ok := val.(*object.Function); ok {
			// 使用閉包包裝呼叫，確保執行時的 context 正確
			funcName := name // 捕獲變數
			obj.Vars.Set(funcName, &object.Builtin{
				Fn: func(args ...object.Object) object.Object {
					return d.CallFunction(d.SimulEfunObj, funcName, args)
				},
			})
		}
	}
}

// ==========================================
// 🚀 P2P 擴充 (P2P Extensions)
// ==========================================
func (d *Driver) registerP2PEfuns(obj *object.LPCObject) {
	// 語法: void p2p_broadcast(string content, [string sender_id])
	// 說明: 將訊息發送到全球 P2P 網路（星際網路）。
	obj.Vars.Set("p2p_broadcast", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return evaluator.NilValue }
			content, ok := args[0].(*object.String)
			if !ok { return evaluator.NilValue }

			if d.P2PSendChat != nil {
				sender := ""
				if len(args) > 1 {
					if customSender, ok := args[1].(*object.String); ok && customSender.Value != "" {
						sender = customSender.Value
					}
				}
				
				if sender == "" {
					if p := d.GetCurrentPlayer(); p != nil {
						sender = p.Username
					} else {
						// 🚀 關鍵修正：若無當前玩家，則代表是系統驅動的通訊 (如 fs_d)
						// 這裡應該優先取用 system_d 定義的 FS_MUDLIB_ID
						systemD, err := d.LoadObject("/secure/system_d")
						if err == nil && systemD != nil {
							if res := d.CallFunction(systemD, "query_mudlib_id", nil); res != nil {
								if s, ok := res.(*object.String); ok {
									sender = s.Value
								}
							}
						}
						// 備援：若連 system_d 都沒法回傳，才用 Filename
						if sender == "" {
							sender = obj.Filename
						}
					}
				}
				d.P2PSendChat(sender, content.Value)
			}
			return evaluator.NilValue
		},
	})
}

// ==========================================
// 1. 型別判斷 (Predicates)
// ==========================================
func (d *Driver) registerTypePredicates(obj *object.LPCObject) {
	// 語法: int <type>p(mixed arg)
	// 說明: 判斷傳入的變數是否為指定型別。是回傳 1，否回傳 0。
	// 範例: intp(123) -> 1; stringp(123) -> 0; nullp(0) -> 1
	register := func(name string, expectedType object.TokenType) {
		obj.Vars.Set(name, &object.Builtin{
			Fn: func(args ...object.Object) object.Object {
				if len(args) < 1 {
					if expectedType == object.NilType {
						return &object.Integer{Value: 1}
					}
					return &object.Integer{Value: 0}
				}

				arg := args[0]
				if arg == nil {
					if expectedType == object.NilType { return &object.Integer{Value: 1} }
					return &object.Integer{Value: 0}
				}

				if expectedType == object.NilType {
					if arg.TokenType() == object.NilType {
						return &object.Integer{Value: 1}
					}
					if i, ok := arg.(*object.Integer); ok && i.Value == 0 {
						return &object.Integer{Value: 1}
					}
					return &object.Integer{Value: 0}
				}

				if arg.TokenType() == expectedType {
					return &object.Integer{Value: 1}
				}
				return &object.Integer{Value: 0}
			},
		})
	}

	register("intp", object.IntegerType)
	register("stringp", object.StringType)
	register("floatp", object.FloatType)
	register("objectp", object.LPC_OBJECT_OBJ)
	register("mappingp", object.MAPPING_OBJ)
	register("mapp", object.MAPPING_OBJ) // 🚀 別名
	register("arrayp", object.ArrayType)
	register("pointerp", object.ArrayType) // 🚀 別名
	register("nullp", object.NilType)
	register("errorp", object.ErrorType)

	// functionp 判斷是否為函式指標或閉包
	obj.Vars.Set("functionp", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			tt := args[0].TokenType()
			if tt == object.FunctionType || tt == object.ClosureType || tt == object.BuiltinType {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})
}

// ==========================================
// 2. 型別轉換 (Casting)
// ==========================================
func (d *Driver) registerTypeCasting(obj *object.LPCObject) {
	// 語法: int to_int(mixed arg)
	// 說明: 將浮點數或字串轉換為整數。
	// 範例: to_int("123") -> 123; to_int(3.14) -> 3
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

	// 語法: string to_string(mixed arg)
	// 說明: 將任意變數轉換為字串表示。
	// 範例: to_string(123) -> "123"; to_string(({1, 2})) -> "[1, 2]"
	obj.Vars.Set("to_string", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 || args[0] == nil {
				return &object.String{Value: "0"}
			}
			if s, ok := args[0].(*object.String); ok {
				return s
			}
			return &object.String{Value: args[0].Inspect()}
		},
	})

	// 語法: float to_float(mixed arg)
	// 說明: 將整數或字串轉換為浮點數。
	// 範例: to_float(123) -> 123.0; to_float("3.14") -> 3.14
	obj.Vars.Set("to_float", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.Float{Value: 0.0}
			}
			switch v := args[0].(type) {
			case *object.Float:
				return v
			case *object.Integer:
				return &object.Float{Value: float64(v.Value)}
			case *object.String:
				f, err := strconv.ParseFloat(v.Value, 64)
				if err != nil {
					return &object.Float{Value: 0.0}
				}
				return &object.Float{Value: f}
			default:
				return &object.Float{Value: 0.0}
			}
		},
	})
}

// ==========================================
// 3. 數學運算 (Math)
// ==========================================
func (d *Driver) registerMathEfuns(obj *object.LPCObject) {
	// 語法: int abs(int num)
	// 說明: 取得整數的絕對值。
	// 範例: abs(-5) -> 5
	obj.Vars.Set("abs", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			if i, ok := args[0].(*object.Integer); ok {
				if i.Value < 0 { return &object.Integer{Value: -i.Value} }
				return i
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: int max(int a, int b) / int min(int a, int b)
	// 說明: 回傳兩數之中的最大/最小值。
	// 範例: max(10, 20) -> 20; min(10, 20) -> 10
	for _, name := range []string{"max", "min"} {
		op := name
		obj.Vars.Set(op, &object.Builtin{
			Fn: func(args ...object.Object) object.Object {
				if len(args) < 2 { return &object.Integer{Value: 0} }
				v1, ok1 := args[0].(*object.Integer)
				v2, ok2 := args[1].(*object.Integer)
				if !ok1 || !ok2 { return &object.Integer{Value: 0} }
				if (op == "max" && v1.Value > v2.Value) || (op == "min" && v1.Value < v2.Value) {
					return v1
				}
				return v2
			},
		})
	}

	// 語法: int random(int max)
	// 說明: 產生 0 到 max-1 的隨機整數。
	// 範例: random(10) -> 可能回傳 0 ~ 9 之間的任意數字
	obj.Vars.Set("random", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.IntegerType {
				return object.NewError("argument to `random` must be INTEGER")
			}
			max := args[0].(*object.Integer).Value
			if max <= 0 { return &object.Integer{Value: 0} }
			return &object.Integer{Value: rand.Int63n(max)}
		},
	})
}

// ==========================================
// 4. 核心與 I/O (Core & IO)
// ==========================================
func (d *Driver) registerCoreIOEfuns(obj *object.LPCObject) {
	
	// 語法: int userp(object ob)
	// 說明: 判斷該物件是否為玩家物件。
	// 範例: if (userp(this_player())) {}
	obj.Vars.Set("userp", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 {
				if obj.IsInteractive { return &object.Integer{Value: 1} }
				return &object.Integer{Value: 0}
			}
			if o, ok := args[0].(*object.LPCObject); ok {
				if o.IsInteractive { return &object.Integer{Value: 1} }
				if strings.HasPrefix(o.Filename, "/std/user.c") || strings.HasPrefix(o.Filename, "/data/user/") {
					return &object.Integer{Value: 1}
				}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: int is_interactive(object ob)
	// 說明: 判斷該物件是否為連線中的玩家。
	obj.Vars.Set("is_interactive", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			if target.IsInteractive {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: string query_verb()
	// 說明: 回傳當前觸發指令的動詞。
	// 範例: 若輸入 "go north"，query_verb() 回傳 "go"。
	obj.Vars.Set("query_verb", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			conn := d.GetCurrentPlayer()
			if conn != nil {
				return &object.String{Value: conn.CurrentVerb}
			}
			return &object.Nil{}
		},
	})

	// 語法: mixed call_other(object ob, string func, [mixed args...])
	// 說明: 動態呼叫物件上的函式。當函式名稱是變數時非常有用。
	// 範例: call_other(this_player(), "set_" + prop_name, value);
	obj.Vars.Set("call_other", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Nil{} }
			target, ok1 := args[0].(*object.LPCObject)
			funcName, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return &object.Nil{} }
			return d.CallFunction(target, funcName.Value, args[2:])
		},
	})

	// 語法: int living(object ob)
	// 說明: 判斷物件是否為活著的生物。
	// 實作: 呼叫物件上的 is_living() 函式，回傳 1 代表是生物。
	obj.Vars.Set("living", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			res := d.CallFunction(target, "is_living", nil)
			if isLPCTrue(res) {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: object find_player(string id)
	// 說明: 找到 player id 的物件
	// 範例: object user = find_player(arg);
	obj.Vars.Set("find_player", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.Nil{} }
			idStr, ok := args[0].(*object.String)
			if !ok { return &object.Nil{} }
			
			var target object.Object = &object.Nil{}
			d.interactiveObjects.Range(func(key, value interface{}) bool {
				conn, ok := value.(*PlayerConnection)
				if ok && conn.IsActive && conn.Object != nil {
					res := d.CallFunction(conn.Object, "get_id", nil)
					if s, isStr := res.(*object.String); isStr && s.Value == idStr.Value {
						target = conn.Object
						return false // 找到即中斷
					}
				}
				return true
			})
			return target
		},
	})

	// 語法: int interactive(object ob)
	// 說明: 判斷該物件是否為正在連線中的玩家 (有網路 Socket 綁定)。
	// 範例: if (interactive(target)) { write("玩家在線上。\\n"); }
	obj.Vars.Set("interactive", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := obj
			if len(args) > 0 {
				if o, ok := args[0].(*object.LPCObject); ok {
					target = o
				} else {
					return &object.Integer{Value: 0}
				}
			}
			if d.GetConnectionFromObject(target) != nil {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: string query_ip_number(object ob)
	// 說明: 取得玩家連線的 IP 位址。
	obj.Vars.Set("query_ip_number", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := obj
			if len(args) > 0 {
				if o, ok := args[0].(*object.LPCObject); ok {
					target = o
				} else {
					return &object.String{Value: ""}
				}
			}
			if conn := d.GetConnectionFromObject(target); conn != nil && conn.Conn != nil {
				addr := conn.Conn.RemoteAddr().String()
				// Remove port if present
				if colonIdx := strings.LastIndex(addr, ":"); colonIdx != -1 {
					return &object.String{Value: addr[:colonIdx]}
				}
				return &object.String{Value: addr}
			}
			return &object.String{Value: "127.0.0.1"}
		},
	})

	// 語法: string query_ip_name(object ob)
	// 說明: 取得玩家連線的 Hostname (暫以 IP 代替)。
	obj.Vars.Set("query_ip_name", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := obj
			if len(args) > 0 {
				if o, ok := args[0].(*object.LPCObject); ok {
					target = o
				} else {
					return &object.String{Value: ""}
				}
			}
			if conn := d.GetConnectionFromObject(target); conn != nil && conn.Conn != nil {
				addr := conn.Conn.RemoteAddr().String()
				if colonIdx := strings.LastIndex(addr, ":"); colonIdx != -1 {
					return &object.String{Value: addr[:colonIdx]}
				}
				return &object.String{Value: addr}
			}
			return &object.String{Value: "localhost"}
		},
	})

	// 語法: int is_web_client(object ob)
	// 說明: 判斷玩家是否使用 Web 介面連線。
	obj.Vars.Set("is_web_client", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := obj
			if len(args) > 0 {
				if o, ok := args[0].(*object.LPCObject); ok {
					target = o
				} else {
					return &object.Integer{Value: 0}
				}
			}
			if conn := d.GetConnectionFromObject(target); conn != nil {
				if conn.OutputCallback != nil {
					return &object.Integer{Value: 1}
				}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: void shout(string msg)
	// 說明: 對全伺服器所有連線中的玩家廣播訊息 (會自動排除自己)。
	// 範例: shout("【謠言】" + query_name() + " 登入了遊戲！\\n");
	obj.Vars.Set("shout", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.Nil{} }
			msg := args[0].Inspect()
			if s, ok := args[0].(*object.String); ok { msg = s.Value }
			
			tp := d.GetCurrentPlayer()
			if tp == nil && obj.IsInteractive {
				tp = d.GetConnectionFromObject(obj)
			}

			d.interactiveObjects.Range(func(key, value interface{}) bool {
				if conn, ok := value.(*PlayerConnection); ok && conn.IsActive {
					if tp == nil || conn != tp { // 排除發送者自己
						safeMsg := strings.ReplaceAll(msg, "\r\n", "\n")
						conn.Send(strings.ReplaceAll(safeMsg, "\n", "\r\n"))
					}
				}
				return true
			})
			return &object.Nil{}
		},
	})

	// 語法: int set_heart_beat(int flag)
	// 說明: 開啟(1)或關閉(0)物件的心跳機制 (每秒觸發一次 heart_beat 函式)。
	// 範例: if (living(inv[i])) inv[i]->set_heart_beat(1);
	obj.Vars.Set("set_heart_beat", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("set_heart_beat 需要 1 個整數參數") }
			flag, ok := args[0].(*object.Integer)
			if !ok { return object.NewError("set_heart_beat 參數必須是整數") }
			enable := flag.Value > 0
			
			// 🚀 修正：直接使用傳入的 obj，確保是設定在 NPC 自己身上
			// 而不是誤設在當前發話的玩家 (GetThisObject) 身上。
			d.SetHeartBeat(obj, enable)
			return &object.Integer{Value: flag.Value}
		},
	})

	// 語法: void destruct(object ob)
	// 說明: 從記憶體中徹底銷毀指定的物件。若未指定參數，則銷毀自己。
	// 範例: destruct(me);
	obj.Vars.Set("destruct", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			d.DestructObject(target)
			return &object.Nil{}
		},
	})

	// 語法: void enable_commands()
	// 說明: 將當前物件標記為生物 (Living)，使其可以接收與執行 add_action 註冊的指令。
	// 範例: enable_commands();
	obj.Vars.Set("enable_commands", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			obj.IsLiving = true
			if obj.Actions == nil {
				obj.Actions = make(map[string]*object.Action)
			}
			return &object.Integer{Value: 1}
		},
	})

	// 語法: void set_living_name(string name)
	// 說明: 設定生物的對外名稱，並同步至連線資訊中。
	obj.Vars.Set("set_living_name", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return evaluator.NilValue }
			name, ok := args[0].(*object.String)
			if !ok { return evaluator.NilValue }
			
			d.UpdatePlayerUsername(obj, name.Value)
			return evaluator.NilValue
		},
	})

	// 語法: void add_action(string func_name, string verb)
	// 說明: 為玩家註冊一個指令，當玩家輸入 verb 時，會呼叫 func_name。
	// 範例: add_action("do_look", "look");
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

	// 語法: int command(string cmd)
	// 說明: 以當前物件的身分執行一條指令。回傳 1 表示執行成功，0 表示失敗。
	// 範例: command("say hello");
	obj.Vars.Set("command", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.StringType {
				return object.NewError("command 需 1 個字串參數")
			}
			input := strings.TrimSpace(args[0].(*object.String).Value)
			if input == "" {
				return &object.Integer{Value: 0}
			}

			// 解析動詞與參數
			verb := ""
			arg := ""
			parts := strings.SplitN(input, " ", 2)
			verb = parts[0]
			if len(parts) > 1 {
				arg = parts[1]
			}

			// 1. 優先檢查 add_action 註冊的指令
			if obj.Actions != nil {
				if action, exists := obj.Actions[verb]; exists {
					// 設定玩家上下文以便執行指令
					pConn := d.getPlayerConnection(obj)
					if pConn == nil {
						pConn = &PlayerConnection{Object: obj, IsActive: true}
					}
					
					// 🚀 使用 RunCommand 封裝以確保 GetCurrentPlayer 正常
					res := d.RunCommand(pConn, action.Provider, action.FuncName, []object.Object{&object.String{Value: arg}})
					
					if i, ok := res.(*object.Integer); ok && i.Value != 0 {
						return &object.Integer{Value: 1}
					}
					return &object.Integer{Value: 1} // 只要有對應 Action 就算成功
				}
			}

			// 2. 備援：呼叫物件本身的 process_input (通常在 user.c 或 npc.c 實作)
			res := d.CallFunction(obj, "process_input", []object.Object{&object.String{Value: input}})
			if i, ok := res.(*object.Integer); ok && i.Value != 0 {
				return &object.Integer{Value: 1}
			}

			return &object.Integer{Value: 0}
		},
	})

	// 語法: void throw(mixed msg)
	// 說明: 主動拋出一個執行期錯誤，可被 catch() 攔截。
	// 範例: if (!arg) throw("參數不能為空！\n");
	obj.Vars.Set("throw", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			msg := "LPC Error"
			if len(args) > 0 {
				msg = args[0].Inspect()
				if s, ok := args[0].(*object.String); ok {
					msg = s.Value
				}
			}
			return object.NewError(msg)
		},
	})

	// 語法: void write(string msg)
	// 說明: 發送訊息給觸發當前行為的玩家。
	// 範例: write("你看了看四周。\n");
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
	        // 👉 關鍵修正：若無全域玩家上下文 (如 NPC 心跳中)，但呼叫者是玩家物件，則自動導向該玩家
	        if p == nil && obj.IsInteractive {
	            p = d.GetConnectionFromObject(obj)
	        }

	        // 只要玩家物件存在且處於活動狀態，就呼叫 p.Send
	        if p != nil && p.IsActive {
	            safeMsg := strings.ReplaceAll(msg, "\r\n", "\n")
	            safeMsg = strings.ReplaceAll(safeMsg, "\n", "\r\n")
	            p.Send(safeMsg)
	        } else {
	            // 只有在找不到玩家上下文時（例如系統背景執行），才印到伺服器終端機
				// 在終端機模式下，我們嘗試轉換 {r} 標籤為 ANSI
				processed := d.ProcessAnsi(msg)
	            fmt.Print(processed)
	        }
	        return &object.Nil{}
	    },
	})
	// 語法: object this_player()
	// 說明: 取得觸發當前執行緒的玩家物件。若無則回傳 0。
	// 範例: if (me == this_player()) continue; // skip self
	obj.Vars.Set("this_player", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			p := d.GetCurrentPlayer()
			if p != nil && p.Object != nil { return p.Object }
			return &object.Nil{}
		},
	})

	// 語法: object this_object()
	// 說明: 取得當前正在執行程式碼的物件。
	// 範例: mixed here_inv = all_inventory(this_object());
	obj.Vars.Set("this_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object { return obj },
	})

	// 語法: object previous_object()
	// 說明: 取得呼叫當前函式的物件。
	obj.Vars.Set("previous_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			prev := d.GetPreviousObject()
			if prev != nil { return prev }
			return &object.Nil{}
		},
	})

	// 語法: void say(string msg, [mixed exclude])
	// 說明: 將訊息廣播給與當前物件處於同一環境(房間)內的所有其他物件。
	// 範例: say("一陣微風吹過。\n");
	obj.Vars.Set("say", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.Nil{} }
			msgStr := args[0].Inspect()
			if s, ok := args[0].(*object.String); ok { msgStr = s.Value }

			var exclude []*object.LPCObject
			
			// 1. 預設排除執行此程式碼的物件 (例如指令物件)
			exclude = append(exclude, obj) 

			// 2. 獲取當前玩家連線
			tp := d.GetCurrentPlayer()
			if tp != nil && tp.Object != nil {
				exclude = append(exclude, tp.Object)
			}

			// 3. 處理手動指定的額外排除對象
			if len(args) > 1 {
				if o, ok := args[1].(*object.LPCObject); ok {
					exclude = append(exclude, o)
				} else if arr, ok := args[1].(*object.Array); ok {
					for _, el := range arr.Elements {
						if o, ok := el.(*object.LPCObject); ok {
							exclude = append(exclude, o)
						}
					}
				}
			}

			// 取得環境 (指令物件本身不在房間，所以要取 tp 的環境)
			env := obj.Location
			if env == nil && tp != nil && tp.Object != nil {
				env = tp.Object.Location
			}
			
			if env == nil { return &object.Nil{} }

			// 4. 🚀 核心邏輯：遍歷房間
			for _, ob := range env.Inventory {
				if ob == nil || ob.IsDestructed { continue }

				// 檢查排除清單
				isExcluded := false
				for _, ex := range exclude {
					if ob == ex || (ex != nil && ob.Filename == ex.Filename) {
						isExcluded = true
						break
					}
				}
				
				// 🚀 終極排除：如果這個物件對應的連線就是當前發話者的連線，排除之！
				if tp != nil {
					obConn := d.GetConnectionFromObject(ob)
					if obConn != nil && obConn == tp {
						isExcluded = true
					}
				}

				if isExcluded { continue }

				// A. 判定是否為玩家
				isUser := false
				if ob.IsInteractive || strings.HasPrefix(ob.Filename, "/std/user.c") || strings.HasPrefix(ob.Filename, "/data/user/") {
					isUser = true
				}

				// B. 判定是否為生物
				isLiving := false
				res := d.CallFunction(ob, "is_living", nil)
				if isLPCTrue(res) { isLiving = true }

				if isUser {
					// 發送訊息到玩家終端 (TellObject 會處理 Socket 發送)
					d.TellObject(ob, msgStr)
				} else if isLiving {
					// 主動對 NPC 呼叫 catch_tell
					if tp != nil {
						d.RunCommand(tp, ob, "catch_tell", []object.Object{&object.String{Value: msgStr}})
					} else {
						d.CallFunction(ob, "catch_tell", []object.Object{&object.String{Value: msgStr}})
					}
				}
			}

			return &object.Nil{}
		},
	})

	// 語法: void tell_object(object target, string msg)
	// 說明: 直接向指定物件 (通常是玩家) 發送訊息。
	// 範例: tell_object(user, "你感受到一股強大的力量。\n");
	obj.Vars.Set("tell_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("tell_object 需要 2 個參數") }
			targetObj, ok := args[0].(*object.LPCObject)
			if !ok { return object.NewError("tell_object 的第一個參數必須是 object") }

			msg := args[1].Inspect()
			if s, isStr := args[1].(*object.String); isStr { msg = s.Value }

			d.TellObject(targetObj, msg)
			return &object.Nil{}
		},
	})

	// 語法: void tell_room(object room, string msg, [mixed exclude])
	// 說明: 向指定房間廣播訊息。
	obj.Vars.Set("tell_room", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("tell_room 需要 2 個參數") }
			roomObj, ok := args[0].(*object.LPCObject)
			if !ok { return object.NewError("tell_room 的第一個參數必須是 object") }

			msg := args[1].Inspect()
			if s, isStr := args[1].(*object.String); isStr { msg = s.Value }

			var exclude []*object.LPCObject
			if len(args) > 2 {
				if o, ok := args[2].(*object.LPCObject); ok {
					exclude = append(exclude, o)
				} else if arr, ok := args[2].(*object.Array); ok {
					for _, el := range arr.Elements {
						if o, ok := el.(*object.LPCObject); ok {
							exclude = append(exclude, o)
						}
					}
				}
			}

			// 🚀 tell_room 也加入終極連線排除
			tp := d.GetCurrentPlayer()

			for _, item := range roomObj.Inventory {
				if item == nil || item.IsDestructed { continue }
				
				shouldExclude := false
				for _, ex := range exclude {
					if item == ex || (ex != nil && item.Filename == ex.Filename) {
						shouldExclude = true
						break
					}
				}
				
				if tp != nil {
					itemConn := d.GetConnectionFromObject(item)
					if itemConn != nil && itemConn == tp {
						shouldExclude = true
					}
				}
				
				if !shouldExclude {
					d.TellObject(item, msg)
				}
			}
			return &object.Nil{}
		},
	})
}

// ==========================================
// 5. 空間與物件操作 (Environment & Objects)
// ==========================================
func (d *Driver) registerEnvironmentEfuns(obj *object.LPCObject) {
	// 語法: object environment([object target])
	// 說明: 取得物件所在的環境 (房間或容器)。
	// 範例: object room = environment(this_player());
	obj.Vars.Set("environment", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			if target.Location != nil { return target.Location }
			return &object.Nil{}
		},
	})

	// 語法: int move_object(object dest) / int move_object(object item, object dest)
	// 說明: 將物件移動到目標物件(房間或容器)之內。回傳 1 成功。
	// 範例: move_object(load_object("/d/city/square"));
	obj.Vars.Set("move_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 1 && args[0].TokenType() == object.LPC_OBJECT_OBJ {
				d.MoveObject(obj, args[0].(*object.LPCObject))
				return &object.Integer{Value: 1}
			} else if len(args) == 2 && args[0].TokenType() == object.LPC_OBJECT_OBJ && args[1].TokenType() == object.LPC_OBJECT_OBJ {
				d.MoveObject(args[0].(*object.LPCObject), args[1].(*object.LPCObject))
				return &object.Integer{Value: 1}
			}
			return object.NewError("move_object 參數錯誤，需要 1 或 2 個 object 參數")
		},
	})
	// 語法: object clone_object(string file)
	// 說明: 根據腳本路徑，複製並產生一個新的物件實體 (Clone)。
	// 範例: object sword = clone_object("/obj/weapon/sword");
	obj.Vars.Set("clone_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 || args[0].TokenType() != object.StringType {
				return object.NewError("clone_object 需要 string 參數")
			}
			path := d.ResolvePath(obj.Filename, args[0].(*object.String).Value)
			clonedObj, err := d.CloneObject(path)
			if err != nil { return object.NewError("clone error: %s", err.Error()) }
			return clonedObj
		},
	})

	// 語法: object *all_inventory([object target])
	// 說明: 取得目標物件內部包含的所有物件 (淺層搜尋)。回傳陣列。
	// 範例: object *items = all_inventory(this_player());
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

	// 語法: object *deep_inventory([object target])
	// 說明: 取得目標物件內部包含的所有物件，包含子容器內的物品 (遞迴深層搜尋)。
	// 範例: object *inv = deep_inventory(this_object());
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

	// 語法: object present(string id_or_obj, [object env])
	// 說明: 在指定容器中尋找符合特定 ID 的物件。
	// 範例: object sword = present("sword", this_player());
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
	// 語法: string base_name(object ob)
	// 說明: 取得物件的原始檔案路徑 (去除 #clone_id)。
	// 範例: base_name(find_player("wade")) -> "/std/user.c"
	obj.Vars.Set("base_name", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			target, ok := args[0].(*object.LPCObject)
			if !ok { return &object.Nil{} }
			
			name := target.Filename
			if pos := strings.Index(name, "#"); pos != -1 {
				name = name[:pos]
			}
			return &object.String{Value: name}
		},
	})
}

// ==========================================
// 6. 時間與排程 (Time & Scheduling)
// ==========================================
func (d *Driver) registerTimeAndScheduling(obj *object.LPCObject) {
	// 語法: int time()
	// 說明: 回傳目前的 Unix 時間戳 (從 1970 年開始的秒數)。
	// 範例: int t = time();
	obj.Vars.Set("time", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			return &object.Integer{Value: time.Now().Unix()}
		},
	})

	// 語法: void sleep(int ms)
	// 說明: 暫停執行指定的毫秒數。
	// 範例: sleep(3000); // 暫停 3 秒
	obj.Vars.Set("sleep", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			if ms, ok := args[0].(*object.Integer); ok {
				return &object.AsyncPause{Duration: time.Duration(ms.Value) * time.Millisecond}
			}
			return &object.Nil{}
		},
	})

	// 語法: void call_out(string func_name, int delay, [mixed args...])
	// 說明: 延遲 delay 秒後，自動呼叫 func_name 函式，並可傳入參數。
	// 範例: call_out("destroy_self", 5); // 5秒後呼叫 destroy_self()
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

	// 語法: int remove_call_out(string func_name)
	// 說明: 移除排程中準備呼叫的 func_name。回傳移除的數量。
	// 範例: remove_call_out("respawn");
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
			return &object.Integer{Value: int64(removedCount)}
		},
	})

	// 語法: int find_call_out(string func_name)
	// 說明: 尋找指定排程函式還有多少秒會執行。若找不到回傳 -1。
	// 範例: int left = find_call_out("respawn");
	obj.Vars.Set("find_call_out", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: -1} }
			funcName, ok := args[0].(*object.String)
			if !ok { return &object.Integer{Value: -1} }

			d.mu.Lock()
			defer d.mu.Unlock()
			for _, call := range d.CallOuts {
				if call.Caller == obj && call.FuncName == funcName.Value {
					timeLeft := int64(time.Until(call.FireTime).Seconds())
					if timeLeft < 0 { timeLeft = 0 }
					return &object.Integer{Value: timeLeft}
				}
			}
			return &object.Integer{Value: -1}
		},
	})

	// 語法: mixed *call_out_info()
	// 說明: 取得目前所有排程中 (call_out) 的詳細清單。
	// 範例: mixed *info = call_out_info();
	obj.Vars.Set("call_out_info", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			d.mu.Lock()
			defer d.mu.Unlock()
			
			var elements []object.Object
			for _, call := range d.CallOuts {
				// 格式: ({ object caller, string function, int time_left })
				timeLeft := int64(time.Until(call.FireTime).Seconds())
				if timeLeft < 0 { timeLeft = 0 }
				
				elements = append(elements, &object.Array{Elements: []object.Object{
					call.Caller,
					&object.String{Value: call.FuncName},
					&object.Integer{Value: timeLeft},
				}})
			}
			return &object.Array{Elements: elements}
		},
	})
}

// ==========================================
// 7. 資料結構操作 (Arrays, Mappings)
// ==========================================
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
            // 這個函式在您的 efun.go 結尾處應該已經有了
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

	// 語法: mixed *filter(mixed *arr, string func, [object target])
	// 說明: 遍歷陣列，將元素傳入指定的函式，若回傳為真 (非 0) 則保留該元素。
	// 範例: object *players = filter(users(), "is_admin", this_object());
	obj.Vars.Set("filter", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			arr, isArr := args[0].(*object.Array)
			funcName, isStr := args[1].(*object.String)
			if !isArr || !isStr { return args[0] }

			target := obj
			if len(args) > 2 {
				if t, ok := args[2].(*object.LPCObject); ok { target = t }
			}

			var result []object.Object
			for _, el := range arr.Elements {
				res := d.CallFunction(target, funcName.Value, []object.Object{el})
				if isLPCTrue(res) { result = append(result, el) }
			}
			return &object.Array{Elements: result}
		},
	})

	// 語法: mixed *map(mixed *arr, string func, [object target])
	// 說明: 遍歷陣列，將每個元素傳入指定的函式，並用回傳值取代原本的元素。
	// 範例: string *names = map(users(), "query_name");
	obj.Vars.Set("map", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			arr, isArr := args[0].(*object.Array)
			funcName, isStr := args[1].(*object.String)
			if !isArr || !isStr { return args[0] }

			target := obj
			if len(args) > 2 {
				if t, ok := args[2].(*object.LPCObject); ok { target = t }
			}

			var result []object.Object
			for _, el := range arr.Elements {
				res := d.CallFunction(target, funcName.Value, []object.Object{el})
				result = append(result, res)
			}
			return &object.Array{Elements: result}
		},
	})

	// 語法: mixed *sort_array(mixed *arr, string func, [object target])
	// 說明: 使用自訂的比較函式對陣列進行排序。函式需接收兩個元素，並回傳 1, 0 或 -1。
	// 範例: sort_array(items, "compare_value", this_object());
	obj.Vars.Set("sort_array", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			arr, isArr := args[0].(*object.Array)
			funcName, isStr := args[1].(*object.String)
			if !isArr || !isStr { return args[0] }

			target := obj
			if len(args) > 2 {
				if t, ok := args[2].(*object.LPCObject); ok { target = t }
			}

			// 複製一份新陣列避免修改原陣列 (LPC 慣例)
			newElements := make([]object.Object, len(arr.Elements))
			copy(newElements, arr.Elements)

			sort.SliceStable(newElements, func(i, j int) bool {
				res := d.CallFunction(target, funcName.Value, []object.Object{newElements[i], newElements[j]})
				if val, ok := res.(*object.Integer); ok {
					return val.Value < 0 // 依據 LPC 習慣，回傳負數代表 i 排在 j 前面
				}
				return false
			})

			return &object.Array{Elements: newElements}
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

// executeCallback 支援傳入函式名稱 (string) 或 函式指標 (closure)
func (d *Driver) executeCallback(obj *object.LPCObject, fnArg object.Object, args []object.Object) object.Object {
	switch v := fnArg.(type) {
	case *object.String:
		return d.CallFunction(obj, v.Value, args)
	case *object.Closure:
		// 🚀 執行 Lambda
		if v.Lambda != nil || len(v.Expressions) > 0 || len(v.Parameters) > 0 {
			// 建立一個閉包環境，繼承自定義時的環境
			lambdaEnv := object.NewEnclosedEnvironment(v.Env)

			// 1. 注入具名型別參數 (如果有的話)
			if len(v.Parameters) > 0 {
				for i, param := range v.Parameters {
					if i < len(args) {
						lambdaEnv.Set(param.Name.Value, args[i])
					} else {
						// 如果參數不足，給予預設值
						lambdaEnv.Set(param.Name.Value, evaluator.GetDefaultLPCValue(param.Token.Literal))
					}
				}
			}

			// 2. 注入 $1, $2, $3... (傳統 Lambda 參數)
			for i, arg := range args {
				lambdaEnv.Set(fmt.Sprintf("$%d", i+1), arg)
			}

			// 3. 執行 Lambda
			if v.Lambda != nil {
				return evaluator.Eval(v.Lambda, lambdaEnv)
			}

			var result object.Object
			for _, expr := range v.Expressions {
				result = evaluator.Eval(expr, lambdaEnv)
				if result != nil && result.TokenType() == object.ReturnValueType {
					return result.(*object.ReturnValue).Value
				}
			}
			return result
		}

		target := v.Target
		if target == nil { target = obj }
		// 合併綁定參數與傳入參數
		callArgs := append([]object.Object{}, v.BoundArgs...)
		callArgs = append(callArgs, args...)
		return d.CallFunction(target, v.FuncName, callArgs)
	default:
		return object.NewError("callback 必須是字串或 closure")
	}
}

func (d *Driver) registerFunctionalEfuns(obj *object.LPCObject) {
	// 語法: mixed evaluate(mixed cl, [mixed args...])
	// 說明: 執行閉包 (closure) 或呼叫函式名稱。
	obj.Vars.Set("evaluate", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return evaluator.NilValue }
			return d.executeCallback(obj, args[0], args[1:])
		},
	})

	// 語法: mixed apply(mixed cl, [mixed args...])
	// 說明: 同 evaluate，執行閉包或呼叫函式名稱。
	obj.Vars.Set("apply", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return evaluator.NilValue }
			return d.executeCallback(obj, args[0], args[1:])
		},
	})
}

// ==========================================
// 8. 字串操作 (Strings)
// ==========================================
func (d *Driver) registerStringEfuns(obj *object.LPCObject) {
	
	// 語法: string *get_dir(string path, [int recursive])
	// 說明: 取得指定路徑下的所有檔案與目錄清單。
	//       - 支援萬用字元，例如 "/cmds/*.c"
	//       - 若為目錄，回傳的名稱結尾會帶有 "/" 方便判斷
	//       - recursive = 1 時，會遞迴往下掃描所有子目錄 (此模式下不支援萬用字元，需傳入明確目錄)
	// 範例:
	//   get_dir("/cmds/")          -> ({ "cmd_info.c", "cmd_look.c", "login.c", ... })
	//   get_dir("/data/user/*.o")  -> ({ "wade.o", "admin.o" })
	//   get_dir("/cmds/", 1)       -> ({ "cmd_info.c", "admin/cmd_shutdown.c", ... })
	obj.Vars.Set("get_dir", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.Array{Elements: []object.Object{}}
			}
			pathArg, ok := args[0].(*object.String)
			if !ok {
				return object.NewError("get_dir 的第一個參數必須是字串")
			}

			resolvedPath := d.ResolvePath(obj.Filename, pathArg.Value)

			// 🚀 權限檢查
			allowed, errMsg := d.checkReadPermission(obj, resolvedPath, "get_dir")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil {
					p.Send(fmt.Sprintf("\r\n⚠️ 系統安全攔截：%s\r\n", errMsg))
				}
				return &object.Array{Elements: []object.Object{}}
			}

			recursive := false
			if len(args) > 1 {
				if flag, ok := args[1].(*object.Integer); ok && flag.Value > 0 {
					recursive = true
				}
			}

			// 處理路徑與安全防護 (防止 ../ 跳出 MudLib 目錄)
			searchPath := resolvedPath
			if !strings.HasPrefix(searchPath, "/") {
				searchPath = "/" + searchPath
			}
			fullPath := filepath.Clean(filepath.Join(d.Config.MudLibPath, searchPath))
			if !strings.HasPrefix(fullPath, filepath.Clean(d.Config.MudLibPath)) {
				return object.NewError("get_dir 權限錯誤：無法存取根目錄以外的檔案")
			}

			var results []string

			if recursive {
				// ── 模式 1：遞迴掃描目錄 ──
				info, err := os.Stat(fullPath)
				if err == nil && info.IsDir() {
					filepath.WalkDir(fullPath, func(path string, entry os.DirEntry, err error) error {
						if err != nil { return nil }
						if path == fullPath { return nil } // 略過根目錄自己
						
						// 取得相對於目標目錄的路徑
						rel, _ := filepath.Rel(fullPath, path)
						// 統一轉換路徑斜線為 LPC 習慣的 "/"
						rel = filepath.ToSlash(rel)
						
						if entry.IsDir() {
							results = append(results, rel+"/")
						} else {
							results = append(results, rel)
						}
						return nil
					})
				}
			} else {
				// ── 模式 2：單層目錄或萬用字元 ──
				if strings.Contains(searchPath, "*") || strings.Contains(searchPath, "?") {
					// 處理萬用字元 (例如 /cmds/*.c)
					matches, err := filepath.Glob(fullPath)
					if err == nil {
						for _, match := range matches {
							info, err := os.Stat(match)
							if err != nil { continue }
							_, name := filepath.Split(match)
							if info.IsDir() {
								results = append(results, name+"/")
							} else {
								results = append(results, name)
							}
						}
					}
				} else {
					// 處理單純目錄讀取 (例如 /cmds/)
					entries, err := os.ReadDir(fullPath)
					if err == nil {
						for _, entry := range entries {
							if entry.IsDir() {
								results = append(results, entry.Name()+"/")
							} else {
								results = append(results, entry.Name())
							}
						}
					} else {
						// 如果不是目錄但檔案存在，就回傳它自己
						info, err := os.Stat(fullPath)
						if err == nil && !info.IsDir() {
							_, name := filepath.Split(fullPath)
							results = append(results, name)
						}
					}
				}
			}

			// 轉換為 LPC Array 回傳
			elements := make([]object.Object, len(results))
			for i, res := range results {
				elements[i] = &object.String{Value: res}
			}

			return &object.Array{Elements: elements}
		},
	})

	// 語法: string lower_case(string str)
	// 說明: 將字串中所有的大寫英文字母轉換為小寫。
	// 範例: lower_case("HELLO") -> "hello"
	obj.Vars.Set("lower_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.String{Value: ""} }
			if s, ok := args[0].(*object.String); ok {
				return &object.String{Value: strings.ToLower(s.Value)}
			}
			return &object.String{Value: ""}
		},
	})

	// 語法: string upper_case(string str)
	// 說明: 將字串中所有的小寫英文字母轉換為大寫。
	// 範例: upper_case("hello") -> "HELLO"
	obj.Vars.Set("upper_case", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.String{Value: ""} }
			if s, ok := args[0].(*object.String); ok {
				return &object.String{Value: strings.ToUpper(s.Value)}
			}
			return &object.String{Value: ""}
		},
	})

	// 語法: string capitalize(string str)
	// 說明: 將字串的第一個英文字母轉換為大寫。
	// 範例: capitalize("apple") -> "Apple"
	obj.Vars.Set("capitalize", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.String{Value: ""} }
			if s, ok := args[0].(*object.String); ok && len(s.Value) > 0 {
				runes := []rune(s.Value)
				runes[0] = []rune(strings.ToUpper(string(runes[0])))[0]
				return &object.String{Value: string(runes)}
			}
			return &object.String{Value: ""}
		},
	})

	// 語法: string trim(string str, [string cutset])
	// 說明: 移除字串前後的空白字元 (包含空白、換行與 Tab)。若指定 cutset，則移除指定的特定字元。
	// 範例: trim("  hello  ") -> "hello"
	//       trim("===hello===", "=") -> "hello"
	obj.Vars.Set("trim", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.String{Value: ""} }
			s, ok := args[0].(*object.String)
			if !ok { return &object.String{Value: ""} }

			// 若有提供第二個參數作為 cutset
			if len(args) > 1 {
				if cutset, ok := args[1].(*object.String); ok {
					return &object.String{Value: strings.Trim(s.Value, cutset.Value)}
				}
			}
			
			// 預設行為：移除空白與換行
			return &object.String{Value: strings.TrimSpace(s.Value)}
		},
	})

	// 語法: string replace_string(string str, string pattern, string replace)
	// 說明: 將字串 str 中的所有 pattern 替換為 replace。
	// 範例: replace_string("hello world", "world", "mud") -> "hello mud"
	//       replace_string("a,b,c", ",", "|") -> "a|b|c"
	obj.Vars.Set("replace_string", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 3 { 
				return object.NewError("replace_string 需要 3 個參數") 
			}
			
			str, ok1 := args[0].(*object.String)
			pattern, ok2 := args[1].(*object.String)
			repl, ok3 := args[2].(*object.String)
			
			if !ok1 || !ok2 || !ok3 { 
				return object.NewError("replace_string 的參數必須都是字串") 
			}

			// 使用 Go 原生的 strings.ReplaceAll 進行全域替換
			result := strings.ReplaceAll(str.Value, pattern.Value, repl.Value)
			return &object.String{Value: result}
		},
	})

	// 語法: string sprintf(string format, ...)
	// 說明: C 語言風格的字串格式化。
	// 範例: sprintf("HP: %d/%d", 10, 20) -> "HP: 10/20"
	obj.Vars.Set("sprintf", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return object.NewError("sprintf 需要參數") }
			formatObj, ok := args[0].(*object.String)
			if !ok { return object.NewError("第一個參數必須是字串") }

			var goArgs []interface{}
			for _, arg := range args[1:] {
				if arg == nil {
					goArgs = append(goArgs, "nil")
					continue
				}
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

	// 語法: int strlen(string str)
	// 說明: 回傳字串長度。
	// 範例: strlen("hello") -> 5
	obj.Vars.Set("strlen", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) != 1 { return &object.Integer{Value: 0} }
			if str, ok := args[0].(*object.String); ok {
				return &object.Integer{Value: int64(len([]rune(str.Value)))}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: string substr(string str, int start, [int length])
	// 說明: 截取子字串。
	// 範例: substr("hello", 1, 3) -> "ell"
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

	// 語法: mixed regexp(mixed list, string pattern)
	// 說明: 若 list 為字串，則回傳 1 (匹配) 或 0 (不匹配)。
	//       若 list 為字串陣列，則回傳包含所有匹配元素的子陣列。
	// 範例: regexp(({ "apple", "banana", "pear" }), "a") -> ({ "apple", "banana", "pear" })
	//       regexp("apple", "a") -> 1
	obj.Vars.Set("regexp", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("regexp 需 2 個參數") }
			patternObj, ok := args[1].(*object.String)
			if !ok { return object.NewError("regexp 第二個參數必須是字串") }

			re, err := regexp.Compile(patternObj.Value)
			if err != nil { return object.NewError("regexp 格式錯誤: %v", err) }

			switch list := args[0].(type) {
			case *object.String:
				if re.MatchString(list.Value) { return &object.Integer{Value: 1} }
				return &object.Integer{Value: 0}
			case *object.Array:
				var result []object.Object
				for _, el := range list.Elements {
					if s, ok := el.(*object.String); ok {
						if re.MatchString(s.Value) { result = append(result, s) }
					}
				}
				return &object.Array{Elements: result}
			default:
				return object.NewError("regexp 第一個參數必須是字串或陣列")
			}
		},
	})

	// 語法: string break_string(string str, int width, [int indent])
	// 說明: 將字串按指定寬度折行。
	// 範例: break_string(long_desc, 78)
	obj.Vars.Set("break_string", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return args[0] }
			str, ok1 := args[0].(*object.String)
			width, ok2 := args[1].(*object.Integer)
			if !ok1 || !ok2 { return args[0] }

			indent := ""
			if len(args) > 2 {
				if i, ok := args[2].(*object.String); ok { indent = i.Value }
				if i, ok := args[2].(*object.Integer); ok { indent = strings.Repeat(" ", int(i.Value)) }
			}

			w := int(width.Value)
			if w < 1 { w = 80 }
			
			words := strings.Fields(str.Value)
			if len(words) == 0 { return &object.String{Value: ""} }

			var result strings.Builder
			currentLine := indent
			for _, word := range words {
				if len(currentLine)+len(word)+1 > w {
					result.WriteString(currentLine + "\n")
					currentLine = indent + word
				} else {
					if currentLine == indent {
						currentLine += word
					} else {
						currentLine += " " + word
					}
				}
			}
			result.WriteString(currentLine + "\n")
			return &object.String{Value: result.String()}
		},
	})

	// 語法: int strsrch(string str, string pattern, [int reverse])
	// 說明: 尋找 pattern 在 str 中第一次出現的位置，若無則回傳 -1。
	// 範例: strsrch("hello", "l") -> 2
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

	// 語法: string pad_str(string str, int width)
	// 說明: 計算終端機顯示寬度 (中文字算 2 格)，將字串向右補空白直到滿足 width。
	// 範例: pad_str("攻擊", 10) -> "攻擊      "
	obj.Vars.Set("pad_str", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.String{Value: ""} }
			str, ok1 := args[0].(*object.String)
			width, ok2 := args[1].(*object.Integer)
			if !ok1 || !ok2 { return &object.String{Value: ""} }

			s := str.Value
			targetWidth := int(width.Value)
			
			currentWidth := 0
			for _, r := range s {
				if r > 127 {
					currentWidth += 2 // 中文字或全形算 2 格
				} else {
					currentWidth += 1 // 英數字算 1 格
				}
			}
			
			if currentWidth < targetWidth {
				s += strings.Repeat(" ", targetWidth-currentWidth)
			}
			return &object.String{Value: s}
		},
	})

	// 語法: string|int crypt(string str, [string seed])
	// 說明: 使用 bcrypt 進行密碼雜湊。若無傳入 seed，則產生一組新的雜湊字串。若有傳入，則比對密碼是否相符，相符回傳 seed，不符回傳 0。
	// 範例: crypt("1234") -> 產生 bcrypt 雜湊。crypt("1234", hash) == hash 可用來驗證。
	obj.Vars.Set("crypt", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.String{Value: ""} }
			str, ok := args[0].(*object.String)
			if !ok { return &object.String{Value: ""} }
			
			if len(args) > 1 {
				if hash, isStr := args[1].(*object.String); isStr {
					// 進行比對
					err := bcrypt.CompareHashAndPassword([]byte(hash.Value), []byte(str.Value))
					if err == nil {
						return hash // 驗證成功回傳原本的 hash
					}
					return &object.Integer{Value: 0} // 驗證失敗回傳 0
				}
			}

			// 產生新雜湊
			hashBytes, err := bcrypt.GenerateFromPassword([]byte(str.Value), bcrypt.DefaultCost)
			if err != nil {
				return &object.String{Value: ""}
			}
			return &object.String{Value: string(hashBytes)}
		},
	})
}

// checkReadPermission 呼叫 LPC 的 valid_read 來判定權限
func (d *Driver) checkReadPermission(caller *object.LPCObject, path string, efunName string) (bool, string) {
	cleanPath := filepath.Clean(path)
	cleanPath = filepath.ToSlash(cleanPath)
	if !strings.HasPrefix(cleanPath, "/") {
		cleanPath = "/" + cleanPath
	}

	validOb, err := d.LoadObject("/secure/valid.c")
	if err != nil {
		return true, "" // 若沒寫 valid.c 則預設允許
	}

	player := d.GetCurrentPlayer()
	var userObj object.Object = &object.Nil{}
	if player != nil && player.Object != nil {
		userObj = player.Object
	} else if caller != nil {
		// 🚀 關鍵強化：偵測是否為具有 Role 的使用者物件 (即使非互動連線)
		if caller.Vars != nil {
			if r, ok := caller.Vars.Get("role"); ok && r.TokenType() != object.NilType {
				userObj = caller
			} else if caller.IsInteractive {
				userObj = caller
			}
		}
	}

	res := d.CallFunction(validOb, "valid_read", []object.Object{
		&object.String{Value: cleanPath},
		userObj,
		&object.String{Value: efunName},
	})

	switch v := res.(type) {
	case *object.Integer:
		if v.Value != 0 {
			return true, ""
		}
		return false, "權限拒絕：無法讀取該路徑。"
	case *object.String:
		return false, v.Value
	case *object.Nil:
		return true, ""
	default:
		return true, ""
	}
}

// checkWritePermission 呼叫 LPC 的 valid_write 來判定權限
// 回傳值: (是否允許寫入 bool, 錯誤訊息 string)
func (d *Driver) checkWritePermission(caller *object.LPCObject, path string, efunName string) (bool, string) {
	// 1. 【路徑正規化】：防禦 ../ 目錄穿越攻擊
	cleanPath := filepath.Clean(path)
	cleanPath = filepath.ToSlash(cleanPath) // 確保跨平台都使用 MUD 習慣的 "/"
	if !strings.HasPrefix(cleanPath, "/") {
		cleanPath = "/" + cleanPath
	}

	// 2. 載入權限管理物件
	validOb, err := d.LoadObject("/secure/valid")
	if err != nil {
		return false, "系統嚴重錯誤：找不到 /secure/valid，安全鎖定啟動。"
	}

	// 🚀 關鍵修正：直接傳遞發起寫入的「物件」 (caller) 給 valid_write
	// 權限系統應根據此物件的身分（路徑或內部 Role）來判定
	res := d.CallFunction(validOb, "valid_write", []object.Object{
		&object.String{Value: cleanPath},
		caller,
		&object.String{Value: efunName},
	})

	// 4. 【解析動態錯誤訊息】：判斷回傳型別
	allowed := false
	errMsg := "權限不足：寫入拒絕。"

	switch v := res.(type) {
	case *object.Integer:
		if v.Value != 0 {
			allowed = true
			errMsg = ""
		}
	case *object.String:
		allowed = false
		errMsg = v.Value
	}

	// 🚀 背景日誌：方便追蹤所有的權限行為
	if !allowed {
		log.Printf("🛡️ [Permission] Denied msg: %s", errMsg)
	}

	return allowed, errMsg
}

// ==========================================
// 9. 系統與檔案 (System & Files)
// ==========================================
func (d *Driver) registerSystemAndFiles(obj *object.LPCObject) {
	// 語法: int rm(string file)
	// 說明: 刪除檔案。回傳 1 成功，0 失敗。
	obj.Vars.Set("rm", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			file, ok := args[0].(*object.String)
			if !ok { return &object.Integer{Value: 0} }

			resolvedPath := d.ResolvePath(obj.Filename, file.Value)
			allowed, errMsg := d.checkWritePermission(obj, resolvedPath, "rm")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil {
					p.Send(fmt.Sprintf("\r\n⚠️ 系統安全攔截：%s\r\n", errMsg))
				}
				return &object.Integer{Value: 0}
			}

			fullPath := filepath.Join(d.Config.MudLibPath, resolvedPath)
			err := os.Remove(fullPath)
			if err != nil { return &object.Integer{Value: 0} }
			return &object.Integer{Value: 1}
		},
	})

	// 語法: int rename(string from, string to)
	// 說明: 移動或重新命名檔案。回傳 1 成功，0 失敗。
	obj.Vars.Set("rename", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: 0} }
			from, ok1 := args[0].(*object.String)
			to, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return &object.Integer{Value: 0} }

			resolvedFrom := d.ResolvePath(obj.Filename, from.Value)
			resolvedTo := d.ResolvePath(obj.Filename, to.Value)

			// 兩邊都要檢查權限
			allowed, errMsg := d.checkWritePermission(obj, resolvedFrom, "rename_from")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil { p.Send(fmt.Sprintf("\r\n⚠️ 來源權限拒絕：%s\r\n", errMsg)) }
				return &object.Integer{Value: 0}
			}
			allowed, errMsg = d.checkWritePermission(obj, resolvedTo, "rename_to")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil { p.Send(fmt.Sprintf("\r\n⚠️ 目標權限拒絕：%s\r\n", errMsg)) }
				return &object.Integer{Value: 0}
			}

			fullFrom := filepath.Join(d.Config.MudLibPath, resolvedFrom)
			fullTo := filepath.Join(d.Config.MudLibPath, resolvedTo)

			os.MkdirAll(filepath.Dir(fullTo), 0755)
			err := os.Rename(fullFrom, fullTo)
			if err != nil { return &object.Integer{Value: 0} }
			return &object.Integer{Value: 1}
		},
	})

	// 語法: int mkdir(string path)
	// 說明: 建立目錄。回傳 1 成功，0 失敗。
	obj.Vars.Set("mkdir", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			path, ok := args[0].(*object.String)
			if !ok { return &object.Integer{Value: 0} }

			resolvedPath := d.ResolvePath(obj.Filename, path.Value)
			allowed, errMsg := d.checkWritePermission(obj, resolvedPath, "mkdir")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil { p.Send(fmt.Sprintf("\r\n⚠️ 系統安全攔截：%s\r\n", errMsg)) }
				return &object.Integer{Value: 0}
			}

			fullPath := filepath.Join(d.Config.MudLibPath, resolvedPath)
			err := os.MkdirAll(fullPath, 0755)
			if err != nil { return &object.Integer{Value: 0} }
			return &object.Integer{Value: 1}
		},
	})

	// 語法: int rmdir(string path)
	// 說明: 移除目錄。回傳 1 成功，0 失敗。
	obj.Vars.Set("rmdir", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			path, ok := args[0].(*object.String)
			if !ok { return &object.Integer{Value: 0} }

			resolvedPath := d.ResolvePath(obj.Filename, path.Value)
			allowed, errMsg := d.checkWritePermission(obj, resolvedPath, "rmdir")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil { p.Send(fmt.Sprintf("\r\n⚠️ 系統安全攔截：%s\r\n", errMsg)) }
				return &object.Integer{Value: 0}
			}

			fullPath := filepath.Join(d.Config.MudLibPath, resolvedPath)
			err := os.Remove(fullPath)
			if err != nil { return &object.Integer{Value: 0} }
			return &object.Integer{Value: 1}
		},
	})

	// 語法: int cp(string from, string to)
	// 說明: 複製檔案。回傳 1 成功，0 失敗。
	obj.Vars.Set("cp", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: 0} }
			from, ok1 := args[0].(*object.String)
			to, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return &object.Integer{Value: 0} }

			resolvedFrom := d.ResolvePath(obj.Filename, from.Value)
			resolvedTo := d.ResolvePath(obj.Filename, to.Value)

			allowed, errMsg := d.checkReadPermission(obj, resolvedFrom, "cp_from")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil { p.Send(fmt.Sprintf("\r\n⚠️ 來源權限拒絕：%s\r\n", errMsg)) }
				return &object.Integer{Value: 0}
			}
			allowed, errMsg = d.checkWritePermission(obj, resolvedTo, "cp_to")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil { p.Send(fmt.Sprintf("\r\n⚠️ 目標權限拒絕：%s\r\n", errMsg)) }
				return &object.Integer{Value: 0}
			}

			fullFrom := filepath.Join(d.Config.MudLibPath, resolvedFrom)
			fullTo := filepath.Join(d.Config.MudLibPath, resolvedTo)

			content, err := os.ReadFile(fullFrom)
			if err != nil { return &object.Integer{Value: 0} }
			
			os.MkdirAll(filepath.Dir(fullTo), 0755)
			err = os.WriteFile(fullTo, content, 0644)
			if err != nil { return &object.Integer{Value: 0} }
			return &object.Integer{Value: 1}
		},
	})

	// 語法: string object_name(object ob)
	// 說明: 取得該實體物件的檔案路徑與識別名稱 (例如 /std/user.c#3)。
	// 範例: write(object_name(this_player()));
	obj.Vars.Set("object_name", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.String{Value: obj.Filename} }
			if o, ok := args[0].(*object.LPCObject); ok {
				return &object.String{Value: o.Filename}
			}
			return &object.String{Value: ""}
		},
	})

	// 語法: object find_object(string path)
	// 說明: 尋找記憶體中是否已經載入該路徑的藍圖物件。不產生新 clone。
	// 範例: object room = find_object("/d/city/square");
	obj.Vars.Set("find_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) == 0 { return &object.Nil{} }
			if path, ok := args[0].(*object.String); ok {
				resolvedPath := d.ResolvePath(obj.Filename, path.Value)
				res, err := d.LoadObject(resolvedPath)
				if err == nil { return res }
			}
			return &object.Nil{}
		},
	})

	// 語法: object *all_objects()
	// 說明: 回傳目前記憶體中載入的所有物件（包含藍圖與副本）。
	obj.Vars.Set("objects", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			d.mu.RLock()
			defer d.mu.RUnlock()

			var objs []object.Object
			for _, ob := range d.ObjectTable {
				if ob != nil && !ob.IsDestructed {
					objs = append(objs, ob)
				}
			}
			return &object.Array{Elements: objs}
		},
	})

	// 語法: int query_idle(object ob)
	// 說明: 傳回物件自最後一次活動（函式呼叫）以來經過的秒數。
	obj.Vars.Set("query_idle", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := obj
			if len(args) > 0 {
				if t, ok := args[0].(*object.LPCObject); ok {
					target = t
				}
			}
			if target == nil { return &object.Integer{Value: 0} }
			idle := time.Now().Unix() - target.LastActivity
			return &object.Integer{Value: idle}
		},
	})

	// 語法: object *livings()
	// 說明: 回傳目前記憶體中所有的活物 (IsLiving == true)。
	obj.Vars.Set("livings", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			d.mu.RLock()
			defer d.mu.RUnlock()
			var res []object.Object
			for _, ob := range d.ObjectTable {
				if ob != nil && ob.IsLiving && !ob.IsDestructed {
					res = append(res, ob)
				}
			}
			return &object.Array{Elements: res}
		},
	})

	// 語法: int pcre_match(string text, string pattern)
	// 說明: 使用正規表示式進行比對。
	obj.Vars.Set("pcre_match", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: 0} }
			text, ok1 := args[0].(*object.String)
			pattern, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return &object.Integer{Value: 0} }
			
			matched, err := regexp.MatchString(pattern.Value, text.Value)
			if err != nil || !matched { return &object.Integer{Value: 0} }
			return &object.Integer{Value: 1}
		},
	})

	// 語法: string pcre_replace(string text, string pattern, string replacement)
	// 說明: 使用正規表示式進行替換。
	obj.Vars.Set("pcre_replace", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 3 { return args[0] }
			text, ok1 := args[0].(*object.String)
			pattern, ok2 := args[1].(*object.String)
			repl, ok3 := args[2].(*object.String)
			if !ok1 || !ok2 || !ok3 { return args[0] }
			
			re, err := regexp.Compile(pattern.Value)
			if err != nil { return text }
			res := re.ReplaceAllString(text.Value, repl.Value)
			return &object.String{Value: res}
		},
	})

	// 輔助：時間轉換為 Mapping
	timeToMap := func(t time.Time) *object.Mapping {
		m := &object.Mapping{Pairs: make(map[object.HashKey]object.HashPair)}
		set := func(k string, v int) {
			ks := &object.String{Value: k}
			vs := &object.Integer{Value: int64(v)}
			m.Pairs[ks.HashKey()] = object.HashPair{Key: ks, Value: vs}
		}
		set("sec", t.Second())
		set("min", t.Minute())
		set("hour", t.Hour())
		set("mday", t.Day())
		set("mon", int(t.Month())-1) // LPC mon 0-11
		set("year", t.Year())
		set("wday", int(t.Weekday()))
		set("yday", t.YearDay())
		return m
	}

	// 語法: mapping localtime(int timestamp)
	obj.Vars.Set("localtime", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			ts := time.Now().Unix()
			if len(args) > 0 {
				if i, ok := args[0].(*object.Integer); ok { ts = i.Value }
			}
			return timeToMap(time.Unix(ts, 0).Local())
		},
	})

	// 語法: mapping gmtime(int timestamp)
	obj.Vars.Set("gmtime", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			ts := time.Now().Unix()
			if len(args) > 0 {
				if i, ok := args[0].(*object.Integer); ok { ts = i.Value }
			}
			return timeToMap(time.Unix(ts, 0).UTC())
		},
	})

	// 語法: string resolve_path(string base, string rel)
	// 說明: 將相對路徑轉換為絕對路徑。
	// 範例: resolve_path("/area/newbie/room_0_0.c", "./room_0_1.c") -> "/area/newbie/room_0_1.c"
	obj.Vars.Set("resolve_path", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			rel, ok := args[0].(*object.String)
			if !ok { return &object.Nil{} }
			
			base := obj.Filename
			if len(args) > 1 {
				if b, ok := args[1].(*object.String); ok {
					base = b.Value
				}
			}
			
			return &object.String{Value: d.ResolvePath(base, rel.Value)}
		},
	})

	// 語法: int write_file(string file, string text, [int overwrite])
	// 說明: 將文字寫入實體硬碟的檔案中。預設為接續寫入(Append)，若 overwrite=1 則覆寫。
	// 範例: write_file("/log/debug.log", "發生錯誤\\n");
	obj.Vars.Set("write_file", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return &object.Integer{Value: 0} }
			file, ok1 := args[0].(*object.String)
			text, ok2 := args[1].(*object.String)
			if !ok1 || !ok2 { return &object.Integer{Value: 0} }

			resolvedPath := d.ResolvePath(obj.Filename, file.Value)
			allowed, errMsg := d.checkWritePermission(obj, resolvedPath, "write_file")
			if !allowed {
				// 直接將錯誤訊息印給當前玩家
				if p := d.GetCurrentPlayer(); p != nil {
					p.Send(fmt.Sprintf("\r\n⚠️ 系統安全攔截：%s\r\n", errMsg))
				} else {
					fmt.Printf("🚫 寫入拒絕: %s\n", errMsg)
				}
				return &object.Integer{Value: 0}
			}

			flag := os.O_APPEND | os.O_CREATE | os.O_WRONLY
			if len(args) > 2 {
				if i, ok := args[2].(*object.Integer); ok && i.Value == 1 {
					flag = os.O_TRUNC | os.O_CREATE | os.O_WRONLY
				}
			}

			fullPath := filepath.Join(d.Config.MudLibPath, resolvedPath)

			os.MkdirAll(filepath.Dir(fullPath), 0755)
			f, err := os.OpenFile(fullPath, flag, 0644)
			if err != nil { return &object.Integer{Value: 0} }
			defer f.Close()

			f.WriteString(text.Value)
			return &object.Integer{Value: 1}
		},
	})

	// 語法: object load_object(string file)
	// 說明: 載入並回傳指定路徑的藍圖物件 (Blueprint)，若已載入則直接回傳。不會建立 Clone。
	// 範例: object room = load_object("/d/city/square");
	obj.Vars.Set("load_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			path := ""
			if s, ok := args[0].(*object.String); ok {
				path = s.Value
			} else {
				path = args[0].Inspect()
			}
			
			resolvedPath := d.ResolvePath(obj.Filename, path)
			if !strings.HasSuffix(resolvedPath, ".c") { resolvedPath += ".c" }
			res, err := d.LoadObject(resolvedPath)
			if err != nil { return object.NewError("%s", err.Error()) }
			return res
		},
	})

	// 語法: string read_file(string file)
	// 說明: 讀取並回傳檔案的完整文字內容。
	// 範例: string issue = read_file(ISSUE_FILE);
	obj.Vars.Set("read_file", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			fileName, ok := args[0].(*object.String)
			if !ok { return object.NewError("read_file 需要字串參數") }

			resolvedPath := d.ResolvePath(obj.Filename, fileName.Value)
			// 🚀 權限檢查
			allowed, errMsg := d.checkReadPermission(obj, resolvedPath, "read_file")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil {
					p.Send(fmt.Sprintf("\r\n⚠️ 系統安全攔截：%s\r\n", errMsg))
				}
				return &object.Nil{}
			}

			content, err := d.ReadFile(resolvedPath)
			if err != nil { return &object.Nil{} }
			return &object.String{Value: string(content)}
		},
	})

	// 語法: int file_size(string file)
	// 說明: 取得檔案大小。若不存在回傳 -1，若為目錄回傳 -2。
	// 範例: if (file_size("/data/user/wade.o") > 0) { ... }
	obj.Vars.Set("file_size", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: -1} }
			fileName, ok := args[0].(*object.String)
			if !ok { return &object.Integer{Value: -1} }

			resolvedPath := d.ResolvePath(obj.Filename, fileName.Value)
			
			// 1. 優先檢查實體磁碟
			fullPath := filepath.Join(d.Config.MudLibPath, resolvedPath)
			if info, err := os.Stat(fullPath); err == nil {
				if info.IsDir() { return &object.Integer{Value: -2} }
				return &object.Integer{Value: info.Size()}
			}
			
			// 2. 備援檢查嵌入檔案
			if d.Config.EmbeddedFS != nil {
				embedPath := filepath.Join("mudlib", strings.TrimPrefix(resolvedPath, "/"))
				if info, err := fs.Stat(d.Config.EmbeddedFS, embedPath); err == nil {
					if info.IsDir() { return &object.Integer{Value: -2} }
					return &object.Integer{Value: info.Size()}
				}
			}

			return &object.Integer{Value: -1}
		},
	})

	// 語法: string strftime(string format, [int timestamp])
	// 說明: 格式化時間。
	obj.Vars.Set("strftime", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			format := "%Y%m%d_%H%M%S"
			if len(args) > 0 {
				if s, ok := args[0].(*object.String); ok { format = s.Value }
			}
			ts := time.Now().Unix()
			if len(args) > 1 {
				if i, ok := args[1].(*object.Integer); ok { ts = i.Value }
			}
			
			// 轉換 Go 的 time format
			t := time.Unix(ts, 0)
			f := format
			f = strings.ReplaceAll(f, "%Y", "2006")
			f = strings.ReplaceAll(f, "%m", "01")
			f = strings.ReplaceAll(f, "%d", "02")
			f = strings.ReplaceAll(f, "%H", "15")
			f = strings.ReplaceAll(f, "%M", "04")
			f = strings.ReplaceAll(f, "%S", "05")
			
			return &object.String{Value: t.Format(f)}
		},
	})

	// 語法: string ctime(int time)
	// 說明: 將 Unix 時間戳轉為人類可讀的字串格式。
	// 範例: write(ctime(time()));
	obj.Vars.Set("ctime", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			ts := time.Now().Unix()
			if len(args) > 0 {
				if i, ok := args[0].(*object.Integer); ok { ts = i.Value }
			}
			return &object.String{Value: time.Unix(ts, 0).Format("Mon Jan _2 15:04:05 2006")}
		},
	})

	// 語法: object *users()
	// 說明: 回傳目前線上所有玩家(已成功連線並處於互動狀態)的實體物件陣列。
	// 範例: string *onlines = users();
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

	// 語法: string mud_status()
	obj.Vars.Set("mud_status", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			d.mu.RLock()
			objCount := len(d.ObjectTable)
			hbCount := len(d.Heartbeats)
			coCount := len(d.CallOuts)
			d.mu.RUnlock()
			
			var stats runtime.MemStats
			runtime.ReadMemStats(&stats)
			
			res := fmt.Sprintf("MUD Status:\n  Objects: %d\n  Heartbeats: %d\n  Pending CallOuts: %d\n  Goroutines: %d\n  Allocated Memory: %v MB\n",
				objCount, hbCount, coCount, runtime.NumGoroutine(), stats.Alloc / 1024 / 1024)
			return &object.String{Value: res}
		},
	})

	// 語法: mapping memory_summary()
	obj.Vars.Set("memory_summary", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			var stats runtime.MemStats
			runtime.ReadMemStats(&stats)
			
			m := &object.Mapping{Pairs: make(map[object.HashKey]object.HashPair)}
			set := func(k string, v int64) {
				ks := &object.String{Value: k}
				vs := &object.Integer{Value: v}
				m.Pairs[ks.HashKey()] = object.HashPair{Key: ks, Value: vs}
			}
			set("alloc", int64(stats.Alloc))
			set("total_alloc", int64(stats.TotalAlloc))
			set("sys", int64(stats.Sys))
			set("num_gc", int64(stats.NumGC))
			set("objects", int64(stats.HeapObjects))
			return m
		},
	})

	// 語法: void replace_program(string path)
	// 說明: 將當前物件的所有函式替換為指定物件的函式。通常用於節省記憶體。
	obj.Vars.Set("replace_program", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return evaluator.NilValue }
			path, ok := args[0].(*object.String)
			if !ok { return evaluator.NilValue }
			
			resolved := d.ResolvePath(obj.Filename, path.Value)
			target, err := d.LoadObject(resolved)
			if err != nil { return object.NewError("replace_program error: %s", err.Error()) }
			
			// 🚀 關鍵操作：置換函式表與繼承鏈
			obj.Functions = target.Functions
			obj.Inherits = target.Inherits
			// 同時保留原有的 Vars，但函式行為已變。
			
			return evaluator.NilValue
		},
	})

	// 語法: int input_to(string func_name, [int hidden])
	// 說明: 攔截玩家的下一次終端機輸入，強制將輸入的字串丟給指定的函式處理。若 hidden=1 則終端機會隱藏輸入(打星號)。
	// 範例: write("請輸入密碼:"); input_to("get_pass", 1);
	obj.Vars.Set("input_to", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return object.NewError("input_to 需要函式字串作為參數") }
			
			p := d.GetCurrentPlayer()
			if p == nil && obj.IsInteractive {
				p = d.GetConnectionFromObject(obj)
			}

			if p == nil { return &object.Integer{Value: 0} }

			if funcName, ok := args[0].(*object.String); ok {
				p.NextInputFunc = funcName.Value
				p.InputHidden = false
				if len(args) > 1 {
					if flag, ok := args[1].(*object.Integer); ok && flag.Value != 0 {
						p.InputHidden = true
						p.Send("__INPUT_HIDDEN__")
					}
				}
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: void shutdown([int exit_code])
	// 說明: 關閉 MUD 伺服器並結束進程。可選傳入結束代碼 (預設 0)。
	// 範例: shutdown(); 或 shutdown(1);
	obj.Vars.Set("shutdown", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			exitCode := 0
			if len(args) > 0 {
				if i, ok := args[0].(*object.Integer); ok {
					exitCode = int(i.Value)
				}
			}
			fmt.Printf("🛑 收到關閉指令 (Code: %d)，伺服器準備關閉...\n", exitCode)
			// 延遲一秒讓廣播訊息與最後的 write 有時間送達客戶端
			go func() {
				time.Sleep(500 * time.Millisecond)
				os.Exit(exitCode)
			}()
			return &object.Nil{}
		},
	})
	// 語法: string getenv(string var)
	// 說明: 取得系統環境變數。
	// 範例: if (getenv("MUD_TEST_MODE")) { ... }
	obj.Vars.Set("getenv", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Nil{} }
			varName, ok := args[0].(*object.String)
			if !ok { return &object.Nil{} }
			val := os.Getenv(varName.Value)
			if val == "" { return &object.Nil{} }
			return &object.String{Value: val}
		},
	})
}

// ==========================================
// 10. 存檔與連線轉移 (Persistence & Connection)
// ==========================================
func (d *Driver) registerPersistenceEfuns(obj *object.LPCObject) {
	// 語法: int save_object(string file)
	// 說明: 將當前物件內的所有變數狀態，以 JSON 格式儲存至硬碟。
	// 範例: save_object("/data/user/" + id);
	obj.Vars.Set("save_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			fileArg, ok := args[0].(*object.String)
			if !ok { return object.NewError("save_object 需要字串參數") }

			fileName := fileArg.Value
			if !strings.HasSuffix(fileName, ".o") { fileName += ".o" }

			allowed, errMsg := d.checkWritePermission(obj, fileName, "save_object")
			if !allowed {
				if p := d.GetCurrentPlayer(); p != nil {
					p.Send(fmt.Sprintf("\r\n⚠️ 系統安全攔截：%s\r\n", errMsg))
				} else {
					fmt.Printf("🚫 存檔拒絕: %s\n", errMsg)
				}
				return &object.Integer{Value: 0}
			}

			fullPath := filepath.Join(d.Config.MudLibPath, fileName)

			saveData := make(map[string]interface{})
			for k, v := range obj.Vars.GetAll() {
				if strings.HasPrefix(k, "_") { continue }
				if v.TokenType() == object.FunctionType || v.TokenType() == object.BuiltinType || v.TokenType() == object.ClosureType { continue }
				saveData[k] = lpcToGoValue(v)
			}

			os.MkdirAll(filepath.Dir(fullPath), 0755)
			jsonData, err := json.MarshalIndent(saveData, "", "  ")
			if err != nil { return &object.Integer{Value: 0} }

			err = os.WriteFile(fullPath, jsonData, 0644)
			if err != nil { return &object.Integer{Value: 0} }
			return &object.Integer{Value: 1}
		},
	})

	// 語法: int restore_object(string file)
	// 說明: 從硬碟讀取儲存的 JSON 變數，恢復當前物件的狀態。成功回傳 1，失敗回傳 0。
	// 範例: if(restore_object("/data/user/" + id)) { write("讀檔成功"); }
	obj.Vars.Set("restore_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 { return &object.Integer{Value: 0} }
			fileArg, ok := args[0].(*object.String)
			if !ok { return object.NewError("restore_object 需要字串參數") }

			fileName := fileArg.Value
			if !strings.HasSuffix(fileName, ".o") { fileName += ".o" }
			fullPath := filepath.Join(d.Config.MudLibPath, fileName)

			jsonData, err := os.ReadFile(fullPath)
			if err != nil { return &object.Integer{Value: 0} }

			var loadedData map[string]interface{}
			err = json.Unmarshal(jsonData, &loadedData)
			if err != nil { return &object.Integer{Value: 0} }

			for k, v := range loadedData {
				obj.Vars.Set(k, goToLPCValue(v))
			}
			return &object.Integer{Value: 1}
		},
	})

	// 語法: int exec(object target, object src)
	// 說明: 將 TCP 連線狀態從來源物件(src)轉移到目標物件(target)上。常用於登入系統連線切換。
	// 範例: exec(user_ob, this_object());
	obj.Vars.Set("exec", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 2 { return object.NewError("exec 需要兩個 object 參數") }
			target, ok1 := args[0].(*object.LPCObject)
			src, ok2 := args[1].(*object.LPCObject)
			if !ok1 || !ok2 { return object.NewError("exec 參數必須是 object") }

			success := d.TransferConnection(target, src)
			if success { return &object.Integer{Value: 1} }
			return &object.Integer{Value: 0}
		},
	})
}

// ==========================================
// 轉換工具 (LPC 與 Go 原生型別互轉，供 JSON 存檔用)
// ==========================================

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

func goToLPCValue(v interface{}) object.Object {
	if v == nil { return &object.Nil{} }
	switch val := v.(type) {
	case float64: 
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
