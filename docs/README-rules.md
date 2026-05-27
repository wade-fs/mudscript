# 我把 mudscript 的需求定義如下：

- 本 repository 名字叫 mudscript, 放在 git@github.com:wade-fs/mudscript.git
- mudscript 總站在 https://huggingface.co/spaces/wade-fs/fsmud-hub
	- 我會稱呼總站叫做 fsmud，識別碼叫 fantasy.space
- 每一個玩家可以自己 clone mudscript repo
- 每一個玩家可以直接連到任何公開的 mudscript web site
	- 總站做為創始站，允許其他個人站台連過來
- 每一個 mudscript 站台都同時是 mudlib site 與 mudscript hub
	- 所以 hub 的規則要定義好，因為 mudlib 是可以任何人更改的
	- 但是想要加入總站，就得遵守總站的規則
- 每一個 hub 只用來轉發訊息，假設有個 Hub H, site A B 都把 Hub 設定成 H，那麼 A B 就可以互通
	- H 可以是 A B 其中一個，也可以是別的 site C
	- 轉發時，是默默的，不必記錄任何資訊
	- 每一個 Hub 會記住的只有連過來的 mudlib_id 與 mudlib_name, 在 Hub 中都要唯一
	- 只要有衝突就 Reject 連線
	- 每一個 Hub 要記錄 mudlib_id mudlib_name 的黑名單
