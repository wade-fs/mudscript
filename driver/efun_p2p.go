// driver/efun_p2p.go
package driver

import (
	"mudscript/evaluator"
	"mudscript/object"
)

// ==========================================
// 🚀 P2P 擴充 (P2P Extensions)
// ==========================================
func (d *Driver) registerP2PEfuns(obj *object.LPCObject) {
	// 語法: void p2p_broadcast(string content, [string sender_id, int p2p_ignore])
	// 說明: 將訊息發送到全球 P2P 網路（星際網路）。
	//       - p2p_ignore: 若為 1，則本機驅動不處理此訊息 (避免 loop)。
	// 範例: p2p_broadcast("Hello World", "my_mud", 1);
	obj.Vars.Set("p2p_broadcast", &object.Builtin{
		Fn: func(args ...object.Object) object.Object {
			if len(args) < 1 {
				return evaluator.NilValue
			}
			content, ok := args[0].(*object.String)
			if !ok {
				return evaluator.NilValue
			}

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

				// 🚀 P2P Ignore 支援：若設定為 1，則在 OnP2PMessage 中略過此訊息
				if len(args) > 2 {
					if ignore, ok := args[2].(*object.Integer); ok && ignore.Value == 1 {
						content.Value = "__P2P_IGNORE__" + content.Value
					}
				}

				d.P2PSendChat(sender, content.Value)
			}
			return evaluator.NilValue
		},
	})
}
