# MudScript Built-in Functions (Efuns) 參考手冊

本文檔列出了 MudScript 引擎中所有可用的內建函式 (Efuns) 及其詳細用法與範例。

## 1. 型別判斷 (Predicates)

## 2. 型別轉換 (Casting)

### `to_int()`
- **語法**: `int to_int(mixed arg)`
- **說明**: 將浮點數或字串轉換為整數。
- **範例**: `to_int("123") -> 123; to_int(3.14) -> 3`

### `to_string()`
- **語法**: `string to_string(mixed arg)`
- **說明**: 將任意變數轉換為字串表示。
- **範例**: `to_string(123) -> "123"; to_string(({1, 2})) -> "[1, 2]"`

### `to_float()`
- **語法**: `float to_float(mixed arg)`
- **說明**: 將整數或字串轉換為浮點數。
- **範例**: `to_float(123) -> 123.0; to_float("3.14") -> 3.14`

## 3. 數學運算 (Math)

### `abs()`
- **語法**: `int abs(int num)`
- **說明**: 取得整數的絕對值。
- **範例**: `abs(-5) -> 5`

### `random()`
- **語法**: `int random(int max)`
- **說明**: 產生 0 到 max-1 的隨機整數。
- **範例**: `random(10) -> 可能回傳 0 ~ 9 之間的任意數字`

## 4. 核心輸出入 (Core IO)

### `write()`
- **語法**: `void write(string msg)`
- **說明**: 發送訊息給觸發當前行為的玩家。
- **範例**: `write("你看了看四周。\n");`

### `say()`
- **語法**: `void say(string msg)`
- **說明**: 將訊息廣播給與當前物件處於同一環境(房間)內的所有其他物件。
- **範例**: `say("一陣微風吹過。\n");`

### `shout()`
- **語法**: `void shout(string msg)`
- **說明**: 對全伺服器所有連線中的玩家廣播訊息 (會自動排除自己)。
- **範例**: `shout("【謠言】" + query_name() + " 登入了遊戲！\\n");`

### `tell_object()`
- **語法**: `void tell_object(object target, string msg)`
- **說明**: 直接向指定物件 (通常是玩家) 發送訊息。
- **範例**: `tell_object(user, "你感受到一股強大的力量。\n");`

### `input_to()`
- **語法**: `int input_to(string func_name, [int hidden])`
- **說明**: 攔截玩家的下一次終端機輸入，強制將輸入的字串丟給指定的函式處理。若 hidden=1 則終端機會隱藏輸入(打星號)。
- **範例**: `write("請輸入密碼:"); input_to("get_pass", 1);`

### `query_username()`
- **說明**: 在 efun.go 的 registerCoreIOEfuns 或類似位置加入

## 5. 環境與物件管理 (Environment & Objects)

### `this_player()`
- **語法**: `object this_player()`
- **說明**: 取得觸發當前執行緒的玩家物件。若無則回傳 0。

### `this_object()`
- **語法**: `object this_object()`
- **說明**: 取得當前正在執行程式碼的物件。

### `environment()`
- **語法**: `object environment([object target])`
- **說明**: 取得物件所在的環境 (房間或容器)。
- **範例**: `object room = environment(this_player());`

### `move_object()`
- **語法**: `void move_object(object dest) / void move_object(object item, object dest)`
- **說明**: 將物件移動到目標物件(房間或容器)之內。
- **範例**: `move_object(load_object("/d/city/square"));`

### `clone_object()`
- **語法**: `object clone_object(string file)`
- **說明**: 根據腳本路徑，複製並產生一個新的物件實體 (Clone)。
- **範例**: `object sword = clone_object("/obj/weapon/sword");`

### `load_object()`
- **語法**: `object load_object(string file)`
- **說明**: 載入並回傳指定路徑的藍圖物件 (Blueprint)，若已載入則直接回傳。不會建立 Clone。
- **範例**: `object room = load_object("/d/city/square");`

### `destruct()`
- **語法**: `void destruct(object ob)`
- **說明**: 從記憶體中徹底銷毀指定的物件。若未指定參數，則銷毀自己。

### `present()`
- **語法**: `object present(string id_or_obj, [object env])`
- **說明**: 在指定容器中尋找符合特定 ID 的物件。
- **範例**: `object sword = present("sword", this_player());`

### `all_inventory()`
- **語法**: `object *all_inventory([object target])`
- **說明**: 取得目標物件內部包含的所有物件 (淺層搜尋)。回傳陣列。
- **範例**: `object *items = all_inventory(this_player());`

### `deep_inventory()`
- **語法**: `object *deep_inventory([object target])`
- **說明**: 取得目標物件內部包含的所有物件，包含子容器內的物品 (遞迴深層搜尋)。

### `object_name()`
- **語法**: `string object_name(object ob)`
- **說明**: 取得該實體物件的檔案路徑與識別名稱 (例如 /std/user.c#3)。
- **範例**: `write(object_name(this_player()));`

### `find_object()`
- **語法**: `object find_object(string path)`
- **說明**: 尋找記憶體中是否已經載入該路徑的藍圖物件。不產生新 clone。
- **範例**: `object room = find_object("/d/city/square");`

### `find_player()`
- **語法**: `object find_player(string id)`

### `exec()`
- **語法**: `int exec(object target, object src)`
- **說明**: 將 TCP 連線狀態從來源物件(src)轉移到目標物件(target)上。常用於登入系統連線切換。
- **範例**: `exec(user_ob, this_object());`

### `interactive()`
- **語法**: `int interactive(object ob)`
- **說明**: 判斷該物件是否為正在連線中的玩家 (有網路 Socket 綁定)。
- **範例**: `if (interactive(target)) { write("玩家在線上。\\n"); }`

### `userp()`
- **語法**: `int userp(object ob)`
- **說明**: 判斷該物件是否為玩家物件。

### `query_verb()`
- **語法**: `string query_verb()`
- **說明**: 回傳當前觸發指令的動詞。
- **範例**: `若輸入 "go north"，query_verb() 回傳 "go"。`

### `call_other()`
- **語法**: `mixed call_other(object ob, string func, [mixed args...])`
- **說明**: 動態呼叫物件上的函式。當函式名稱是變數時非常有用。
- **範例**: `call_other(this_player(), "set_" + prop_name, value);`

## 6. 時間與排程 (Time & Scheduling)

### `time()`
- **語法**: `int time()`
- **說明**: 回傳目前的 Unix 時間戳 (從 1970 年開始的秒數)。

### `ctime()`
- **語法**: `string ctime(int time)`
- **說明**: 將 Unix 時間戳轉為人類可讀的字串格式。
- **範例**: `write(ctime(time()));`

### `call_out()`
- **語法**: `void call_out(string func_name, int delay, [mixed args...])`
- **說明**: 延遲 delay 秒後，自動呼叫 func_name 函式，並可傳入參數。
- **範例**: `call_out("destroy_self", 5); // 5秒後呼叫 destroy_self()`

### `remove_call_out()`
- **語法**: `int remove_call_out(string func_name)`
- **說明**: 移除排程中準備呼叫的 func_name。回傳移除的數量。

### `set_heart_beat()`
- **語法**: `int set_heart_beat(int flag)`
- **說明**: 開啟(1)或關閉(0)物件的心跳機制 (每秒觸發一次 heart_beat 函式)。

## 7. 資料結構與字串操作 (Data & Strings)

### `sizeof()`
- **語法**: `int sizeof(mixed target)`
- **說明**: 回傳陣列元素數量、字串長度，或是 Mapping 鍵值對數量。
- **範例**: `sizeof(({1, 2, 3})) -> 3; sizeof("abc") -> 3`

### `keys()`
- **語法**: `mixed *keys(mapping m)`
- **說明**: 取得 Mapping 中所有的 Key，回傳為陣列。
- **範例**: `keys((["a": 1, "b": 2])) -> ({"a", "b"})`

### `values()`
- **語法**: `mixed *values(mapping m)`
- **說明**: 取得 Mapping 中所有的 Value，回傳為陣列。
- **範例**: `values((["hp": 100, "mp": 50])) -> ({ 100, 50 })`

### `m_delete()`
- **語法**: `mapping m_delete(mapping m, mixed key)`
- **說明**: 從 Mapping 中刪除指定的 Key 與其對應的 Value。
- **範例**: `m_delete(my_map, "hp");`

### `explode()`
- **語法**: `string *explode(string str, string delim)`
- **說明**: 以 delim 為分隔符號，將字串切割成陣列。
- **範例**: `explode("a,b,c", ",") -> ({"a", "b", "c"})`

### `implode()`
- **語法**: `string implode(string *arr, string delim)`
- **說明**: 以 delim 為連接符號，將字串陣列合併為單一字串。
- **範例**: `implode(({"a", "b"}), "-") -> "a-b"`

### `member_array()`
- **語法**: `int member_array(mixed item, mixed *arr)`
- **說明**: 尋找 item 在陣列中的索引位置。若找不到回傳 -1。
- **範例**: `member_array("b", ({"a", "b", "c"})) -> 1`

### `filter()`
- **語法**: `mixed *filter(mixed *arr, string func, [object target])`
- **說明**: 遍歷陣列，將元素傳入指定的函式，若回傳為真 (非 0) 則保留該元素。
- **範例**: `object *players = filter(users(), "is_admin", this_object());`

### `map()`
- **語法**: `mixed *map(mixed *arr, string func, [object target])`
- **說明**: 遍歷陣列，將每個元素傳入指定的函式，並用回傳值取代原本的元素。
- **範例**: `string *names = map(users(), "query_name");`

### `sort_array()`
- **語法**: `mixed *sort_array(mixed *arr, string func, [object target])`
- **說明**: 使用自訂的比較函式對陣列進行排序。函式需接收兩個元素，並回傳 1, 0 或 -1。
- **範例**: `sort_array(items, "compare_value", this_object());`

### `unique_array()`
- **語法**: `mixed *unique_array(mixed *arr)`
- **說明**: 移除陣列中重複的元素，回傳一個只包含唯一元素的新陣列。
- **範例**: `unique_array(({ 1, 2, 2, 3 })) -> ({ 1, 2, 3 })`

### `json_encode()`

### `strlen()`
- **語法**: `int strlen(string str)`
- **說明**: 回傳字串長度。
- **範例**: `strlen("hello") -> 5`

### `substr()`
- **語法**: `string substr(string str, int start, [int length])`
- **說明**: 截取子字串。
- **範例**: `substr("hello", 1, 3) -> "ell"`

### `strsrch()`
- **語法**: `int strsrch(string str, string pattern, [int reverse])`
- **說明**: 尋找 pattern 在 str 中第一次出現的位置，若無則回傳 -1。
- **範例**: `strsrch("hello", "l") -> 2`

### `lower_case()`
- **語法**: `string lower_case(string str)`
- **說明**: 將字串中所有的大寫英文字母轉換為小寫。
- **範例**: `lower_case("HELLO") -> "hello"`

### `upper_case()`
- **語法**: `string upper_case(string str)`
- **說明**: 將字串中所有的小寫英文字母轉換為大寫。
- **範例**: `upper_case("hello") -> "HELLO"`

### `capitalize()`
- **語法**: `string capitalize(string str)`
- **說明**: 將字串的第一個英文字母轉換為大寫。
- **範例**: `capitalize("apple") -> "Apple"`

### `trim()`
- **語法**: `string trim(string str, [string cutset])`
- **說明**: 移除字串前後的空白字元 (包含空白、換行與 Tab)。若指定 cutset，則移除指定的特定字元。
- **範例**: `trim("  hello  ") -> "hello"`

### `replace_string()`
- **語法**: `string replace_string(string str, string pattern, string replace)`
- **說明**: 將字串 str 中的所有 pattern 替換為 replace。
- **範例**: `replace_string("hello world", "world", "mud") -> "hello mud"`

### `sprintf()`
- **語法**: `string sprintf(string format, ...)`
- **說明**: C 語言風格的字串格式化。
- **範例**: `sprintf("HP: %d/%d", 10, 20) -> "HP: 10/20"`

### `pad_str()`
- **語法**: `string pad_str(string str, int width)`
- **說明**: 計算終端機顯示寬度 (中文字算 2 格)，將字串向右補空白直到滿足 width。
- **範例**: `pad_str("攻擊", 10) -> "攻擊      "`

### `crypt()`
- **語法**: `string crypt(string str)`
- **說明**: 使用 SHA-256 對字串進行單向雜湊加密，常用於密碼儲存。
- **範例**: `crypt("1234") -> "03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4"`

## 8. 系統與檔案 (System & Files)

### `get_dir()`
- **語法**: `string *get_dir(string path, [int recursive])`
- **說明**: 取得指定路徑下的所有檔案與目錄清單。

### `read_file()`
- **語法**: `string read_file(string file)`
- **說明**: 讀取並回傳檔案的完整文字內容。

### `write_file()`
- **語法**: `int write_file(string file, string text, [int overwrite])`
- **說明**: 將文字寫入實體硬碟的檔案中。預設為接續寫入(Append)，若 overwrite=1 則覆寫。
- **範例**: `write_file("/log/debug.log", "發生錯誤\\n");`

### `file_size()`
- **語法**: `int file_size(string file)`
- **說明**: 取得檔案大小。若不存在回傳 -1，若為目錄回傳 -2。
- **範例**: `if (file_size("/data/user/wade.o") > 0) { ... }`

## 9. 持久化 (Persistence)

### `save_object()`
- **語法**: `int save_object(string file)`
- **說明**: 將當前物件內的所有變數狀態，以 JSON 格式儲存至硬碟。
- **範例**: `save_object("/data/user/" + id);`

### `restore_object()`
- **語法**: `int restore_object(string file)`
- **說明**: 從硬碟讀取儲存的 JSON 變數，恢復當前物件的狀態。成功回傳 1，失敗回傳 0。
- **範例**: `if(restore_object("/data/user/" + id)) { write("讀檔成功"); }`

