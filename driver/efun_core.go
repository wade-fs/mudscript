// driver/efun_core.go
package driver

import (
	"strings"

	"mudscript/evaluator"
	"mudscript/object"
)

func (d *Driver) registerCoreEfuns(obj *object.LPCObject) {
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
	// 範例: if (is_interactive(this_player())) {}
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
	// 範例: if (living(this_player())) {}
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

	// 語法: void set_interactive(object ob, int flag)
	// 說明: 手動將物件標記為互動式 (1) 或非互動式 (0)。主要用於 P2P Guest。
	// 範例: set_interactive(this_object(), 1);
	obj.Vars.Set("set_interactive", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := obj
			if len(args) > 0 {
				if o, ok := args[0].(*object.LPCObject); ok {
					target = o
				}
			}
			flag := int64(1)
			if len(args) > 1 {
				if i, ok := args[1].(*object.Integer); ok {
					flag = i.Value
				}
			}
			target.IsInteractive = (flag > 0)
			return &object.Integer{Value: flag}
		},
	})

	// 語法: int interactive(object ob)
	// 說明: 判斷該物件是否為正在連線中的玩家 (有網路 Socket 綁定)。
	// 範例: if (interactive(target)) { write("玩家在線上。\n"); }
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
	// 範例: write(query_ip_number(this_player()));
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
	// 範例: write(query_ip_name(this_player()));
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
	// 範例: if (is_web_client(this_player())) {}
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
	// 範例: set_living_name("wade");
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
			pConn := d.getPlayerConnection(obj)
			if pConn == nil {
			        pConn = &PlayerConnection{Object: obj, IsActive: true}
			}
			res := d.RunCommand(pConn, obj, "process_input", []object.Object{&object.String{Value: input}})
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
			return object.NewError("%s", msg)
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
	// 範例: if (previous_object() == find_object(MASTER_OB)) {}
	obj.Vars.Set("previous_object", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			prev := d.GetPreviousObject()
			if prev != nil { return prev }
			return &object.Nil{}
		},
	})
}
