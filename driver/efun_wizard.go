// driver/efun_wizard.go
package driver

import (
	"encoding/json"
	"mudscript/evaluator"
	"mudscript/object"
)

func (d *Driver) registerWizardEfuns(obj *object.LPCObject) {
	// 語法: void enable_wizard()
	// 說明: 將當前物件標記為巫師。
	obj.Vars.Set("enable_wizard", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			obj.IsWizard = true
			return &object.Integer{Value: 1}
		},
	})

	// 語法: void disable_wizard()
	// 說明: 移除當前物件的巫師標記。
	obj.Vars.Set("disable_wizard", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			obj.IsWizard = false
			return &object.Integer{Value: 0}
		},
	})

	// 語法: int wizardp(object ob)
	// 說明: 判斷物件是否為巫師。
	obj.Vars.Set("wizardp", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			if target.IsWizard {
				return &object.Integer{Value: 1}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: string wizhood(object ob)
	// 說明: 回傳物件的身分組字串 (如 "(admin)", "(wizard)", "(player)")。
	obj.Vars.Set("wizhood", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			// 🚀 關鍵相容：回傳符合 Mudlib 預期的標籤
			if target.IsWizard {
				return &object.String{Value: "(admin)"}
			}
			// 🚀 關鍵相容性：嘗試透過 query("id") 取得玩家 ID
			id := d.CallFunction(target, "query", []object.Object{&object.String{Value: "id"}})
			if idStr, ok := id.(*object.String); ok {
				if idStr.Value == "guest" {
					return &object.String{Value: "(guest)"}
				}
			}
			return &object.String{Value: "(player)"}
		},
	})

	// 語法: int snoop(object snooper, object snoopee)
	// 說明: 讓 snooper 監看 snoopee 的輸入與輸出。若 snoopee 為空，則停止 snooper 的所有監看。
	obj.Vars.Set("snoop", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return &object.Integer{Value: 0}
			}
			snooper, ok1 := args[0].(*object.LPCObject)
			if !ok1 {
				return &object.Integer{Value: 0}
			}

			snooperConn := d.GetConnectionFromObject(snooper)
			if snooperConn == nil {
				return &object.Integer{Value: 0}
			}

			// 停止監看
			if len(args) == 1 {
				d.interactiveObjects.Range(func(key, value interface{}) bool {
					conn := value.(*PlayerConnection)
					if conn.SnoopedBy == snooperConn {
						conn.SnoopedBy = nil
					}
					return true
				})
				return &object.Integer{Value: 1}
			}

			snoopee, ok2 := args[1].(*object.LPCObject)
			if !ok2 {
				return &object.Integer{Value: 0}
			}

			snoopeeConn := d.GetConnectionFromObject(snoopee)
			if snoopeeConn == nil {
				return &object.Integer{Value: 0}
			}

			// 防止循環監看
			temp := snooperConn
			for temp != nil {
				if temp == snoopeeConn {
					return &object.Integer{Value: 0}
				}
				temp = temp.SnoopedBy
			}

			snoopeeConn.SnoopedBy = snooperConn
			return &object.Integer{Value: 1}
		},
	})

	// 語法: object query_snoop(object ob)
	// 說明: 查詢誰正在監看 ob。
	obj.Vars.Set("query_snoop", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			conn := d.GetConnectionFromObject(target)
			if conn != nil && conn.SnoopedBy != nil && conn.SnoopedBy.Object != nil {
				return conn.SnoopedBy.Object
			}
			return &object.Nil{}
		},
	})

	// 語法: object query_snooping(object ob)
	// 說明: 查詢 ob 正在監看誰。
	obj.Vars.Set("query_snooping", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			targetConn := d.GetConnectionFromObject(target)
			if targetConn == nil {
				return &object.Nil{}
			}

			var snooping object.Object = &object.Nil{}
			d.interactiveObjects.Range(func(key, value interface{}) bool {
				conn := value.(*PlayerConnection)
				if conn.SnoopedBy == targetConn && conn.Object != nil {
					snooping = conn.Object
					return false
				}
				return true
			})
			return snooping
		},
	})

	// 語法: void set_this_player(object ob)
	// 說明: 設定當前執行緒的 this_player。
	obj.Vars.Set("set_this_player", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return evaluator.NilValue
			}
			target, ok := args[0].(*object.LPCObject)
			if !ok {
				return evaluator.NilValue
			}

			conn := d.GetConnectionFromObject(target)
			if conn == nil {
				// 如果不是互動玩家，建立一個臨時的虛擬連線以支持 GetCurrentPlayer().Object
				conn = &PlayerConnection{Object: target, IsActive: true}
			}
			
			gid := getGID()
			d.playerContexts.Store(gid, conn)
			return evaluator.NilValue
		},
	})

	// 語法: int is_web_client([object ob])
	// 說明: 判斷玩家是否使用 Web 客戶端。
	obj.Vars.Set("is_web_client", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			target := getTarget(args, obj)
			if conn := d.GetConnectionFromObject(target); conn != nil {
				if conn.OutputCallback != nil {
					return &object.Integer{Value: 1}
				}
			}
			return &object.Integer{Value: 0}
		},
	})

	// 語法: void request_web_edit(string path)
	// 說明: 請求前端開啟 Web 編輯器處理指定檔案。
	obj.Vars.Set("request_web_edit", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return evaluator.NilValue
			}
			path, ok := args[0].(*object.String)
			if !ok {
				return evaluator.NilValue
			}

			p := d.GetCurrentPlayer()
			if p == nil && obj.IsInteractive {
				p = d.GetConnectionFromObject(obj)
			}
			if p == nil || !p.IsActive {
				return evaluator.NilValue
			}

			content, err := d.ReadFile(path.Value)
			if err != nil {
				// 如果檔案不存在，給空字串
				content = []byte("")
			}

			// 包裝成 JSON
			payload := map[string]string{
				"path":    path.Value,
				"content": string(content),
			}
			jsonData, _ := json.Marshal(payload)

			// 使用 __EDIT__ 前綴送出
			p.Send("__EDIT__" + string(jsonData))
			return evaluator.NilValue
		},
	})
}
