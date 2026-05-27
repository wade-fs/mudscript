# MudScript Built-in Functions (Efuns) 完整參考手冊

本文檔詳盡列出了 MudScript 引擎中所有可用的內建函式 (Efuns)。

## 1. 型別判斷 (Predicates)

檢查變數的資料型別。是回傳 `1`，否回傳 `0`。

### `intp()`
- **語法**: `int intp(mixed arg)`
- **說明**: 判斷是否為整數。
- **範例**: `intp(123) -> 1`

### `stringp()`
- **語法**: `int stringp(mixed arg)`
- **說明**: 判斷是否為字串。
- **範例**: `stringp("hello") -> 1`

### `floatp()`
- **語法**: `int floatp(mixed arg)`
- **說明**: 判斷是否為浮點數。
- **範例**: `floatp(3.14) -> 1`

### `objectp()`
- **語法**: `int objectp(mixed arg)`
- **說明**: 判斷是否為 LPC 物件。
- **範例**: `objectp(this_player()) -> 1`

### `mappingp()` / `mapp()`
- **語法**: `int mappingp(mixed arg)`
- **說明**: 判斷是否為 Mapping (鍵值對)。
- **範例**: `mapp((["a":1])) -> 1`

### `arrayp()` / `pointerp()`
- **語法**: `int arrayp(mixed arg)`
- **說明**: 判斷是否為陣列。
- **範例**: `arrayp(({1, 2})) -> 1`

### `functionp()`
- **語法**: `int functionp(mixed arg)`
- **說明**: 判斷是否為函式指標、閉包 (Closure) 或內建函式。
- **範例**: `functionp((: write :)) -> 1`

### `nullp()`
- **語法**: `int nullp(mixed arg)`
- **說明**: 判斷是否為 `nil` 或整數 `0`。
- **範例**: `nullp(0) -> 1`

### `errorp()`
- **語法**: `int errorp(mixed arg)`
- **說明**: 判斷是否為系統錯誤物件。
- **範例**: `errorp(catch(throw("err"))) -> 1`

## 2. 型別轉換 (Casting)

### `to_int()`
- **語法**: `int to_int(mixed arg)`
- **說明**: 將浮點數或字串轉換為整數。
- **範例**: `to_int("123") -> 123`

### `to_string()`
- **語法**: `string to_string(mixed arg)`
- **說明**: 將任意變數轉換為字串表示。
- **範例**: `to_string(123) -> "123"`

### `to_float()`
- **語法**: `float to_float(mixed arg)`
- **說明**: 將整數或字串轉換為浮點數。
- **範例**: `to_float("3.14") -> 3.14`

## 3. 數學運算 (Math)

### `abs()`
- **語法**: `int abs(int num)`
- **說明**: 取得整數的絕對值。
- **範例**: `abs(-5) -> 5`

### `max()` / `min()`
- **語法**: `int max(int a, int b)` / `int min(int a, int b)`
- **說明**: 回傳兩數之中的最大/最小值。
- **範例**: `max(10, 20) -> 20`

### `random()`
- **語法**: `int random(int max)`
- **說明**: 產生 0 到 max-1 的隨機整數。
- **範例**: `random(10) -> 可能回傳 0 ~ 9`

## 4. 玩家與生物 (Players & Livings)

### `userp()`
- **語法**: `int userp(object ob)`
- **說明**: 判斷該物件是否為玩家物件 (包含離線存檔物件)。
- **範例**: `if (userp(ob)) write("是玩家");`

### `is_interactive()` / `interactive()`
- **語法**: `int is_interactive(object ob)`
- **說明**: 判斷該物件是否為當前正在連線中的玩家。
- **範例**: `if (interactive(this_player())) write("在線上");`

### `find_player()`
- **語法**: `object find_player(string id)`
- **說明**: 根據 ID 尋找線上的玩家物件。
- **範例**: `object me = find_player("wade");`

### `users()`
- **語法**: `object *users()`
- **說明**: 回傳目前線上所有玩家的實體物件陣列。
- **範例**: `object *list = users();`

### `living()`
- **語法**: `int living(object ob)`
- **說明**: 判斷物件是否為活著的生物。
- **範例**: `if (living(ob)) {}`

### `enable_commands()`
- **語法**: `void enable_commands()`
- **說明**: 將當前物件標記為生物 (Living)，使其可以執行指令。
- **範例**: `enable_commands();`

### `set_living_name()`
- **語法**: `void set_living_name(string name)`
- **說明**: 設定生物的對外名稱。
- **範例**: `set_living_name("wade");`

### `add_action()`
- **語法**: `void add_action(string func, string verb)`
- **說明**: 為玩家註冊指令。
- **範例**: `add_action("do_look", "look");`

### `command()`
- **語法**: `int command(string cmd)`
- **說明**: 以當前物件身分執行一條指令。
- **範例**: `command("say hello");`

### `query_verb()`
- **語法**: `string query_verb()`
- **說明**: 回傳當前觸發指令的動詞。
- **範例**: `若輸入 "go north"，回傳 "go"`

### `query_ip_number()` / `query_ip_name()`
- **語法**: `string query_ip_number(object ob)`
- **說明**: 取得連線來源位址。
- **範例**: `write(query_ip_number(this_player()));`

### `is_web_client()`
- **語法**: `int is_web_client(object ob)`
- **說明**: 判斷是否為 Web 介面連線。
- **範例**: `if (is_web_client(me)) {}`

## 5. 環境與物件管理 (Environment & Objects)

### `this_player()`
- **語法**: `object this_player()`
- **說明**: 取得觸發當前行為的玩家物件。
- **範例**: `this_player()->query_name()`

### `this_object()`
- **語法**: `object this_object()`
- **說明**: 取得當前執行程式碼的物件本身。
- **範例**: `destruct(this_object());`

### `previous_object()`
- **語法**: `object previous_object()`
- **說明**: 取得呼叫當前函式的上一個物件。
- **範例**: `if (previous_object() == master()) {}`

### `environment()`
- **語法**: `object environment([object target])`
- **說明**: 取得物件所在的環境 (房間或容器)。
- **範例**: `object room = environment(me);`

### `move_object()`
- **語法**: `void move_object(object dest)` / `void move_object(object item, object dest)`
- **說明**: 移動物件。
- **範例**: `move_object(room);`

### `clone_object()`
- **語法**: `object clone_object(string file)`
- **說明**: 產生一個新的物件實體 (Clone)。
- **範例**: `object sword = clone_object("/obj/sword");`

### `load_object()` / `find_object()`
- **語法**: `object load_object(string file)`
- **說明**: 載入或尋找藍圖物件 (Blueprint)。
- **範例**: `object r = load_object("/area/newbie/room_0_0");`

### `destruct()`
- **語法**: `void destruct(object ob)`
- **說明**: 銷毀物件。
- **範例**: `destruct(item);`

### `present()`
- **語法**: `object present(string id_or_obj, [object env])`
- **說明**: 在指定容器內尋找物件。
- **範例**: `present("sword", me);`

### `all_inventory()` / `deep_inventory()`
- **語法**: `object *all_inventory([object target])`
- **說明**: 取得內部包含的物品。`deep` 為遞迴深層搜尋。
- **範例**: `object *inv = all_inventory(room);`

### `object_name()` / `base_name()`
- **語法**: `string object_name(object ob)`
- **說明**: `object_name` 包含 #id，`base_name` 僅有路徑。
- **範例**: `base_name(this_object()) -> "/std/user.c"`

### `call_other()`
- **語法**: `mixed call_other(object ob, string func, ...)`
- **說明**: 動態呼叫函式。
- **範例**: `call_other(ob, "setup");`

## 6. 通訊與輸出 (Communication)

### `write()`
- **語法**: `void write(string msg)`
- **說明**: 發送訊息給當前玩家。支援 {r} 等 ANSI 顏色標籤。
- **範例**: `write("{r}你好！{n}\n");`

### `printf()`
- **語法**: `void printf(string fmt, mixed arg1, ...)`
- **說明**: 格式化輸出訊息給當前玩家。
- **範例**: `printf("你的經驗值是 %d 點。\n", exp);`

### `shout()`
- **語法**: `void shout(string msg)`
- **說明**: 對全服線上玩家廣播。
- **範例**: `shout("全服廣播...\n");`

### `say()`
- **語法**: `void say(string msg, [mixed exclude])`
- **說明**: 對同房間內的其他物件說話。
- **範例**: `say("一陣風吹過。\n");`

### `tell_object()`
- **語法**: `void tell_object(object target, string msg)`
- **說明**: 對指定物件發送訊息。
- **範例**: `tell_object(me, "你獲得了經驗。\n");`

### `tell_room()`
- **語法**: `void tell_room(object room, string msg, [mixed exclude])`
- **說明**: 對指定房間內的所有人說話。
- **範例**: `tell_room(here, "天空閃過一道雷。\n");`

## 7. 時間與排程 (Time & Scheduling)

### `time()`
- **語法**: `int time()`
- **說明**: 回傳目前的 Unix 時間戳。
- **範例**: `time() -> 1716681600`

### `ctime()` / `strftime()`
- **語法**: `string ctime(int timestamp)`
- **說明**: 將時間格式化為人類可讀字串。
- **範例**: `ctime(time()) -> "Sun May 26 08:30:00 2024"`

### `localtime()` / `gmtime()`
- **語法**: `mapping localtime(int timestamp)`
- **說明**: 回傳時間的 Mapping 詳細資訊 (sec, min, hour, mday, mon, year...)。
- **範例**: `localtime(time())["year"] -> 2024`

### `call_out()` / `remove_call_out()`
- **語法**: `void call_out(string func, int delay, ...)`
- **說明**: 延遲呼叫函式。
- **範例**: `call_out("destroy_self", 5);`

### `find_call_out()` / `call_out_info()`
- **語法**: `int find_call_out(string func)`
- **說明**: 檢查延遲呼叫的剩餘秒數或取得總清單。
- **範例**: `find_call_out("test") -> 3`

### `set_heart_beat()`
- **語法**: `int set_heart_beat(int flag)`
- **說明**: 開啟(1)或關閉(0)物件的每秒心跳。
- **範例**: `set_heart_beat(1);`

### `sleep()`
- **語法**: `void sleep(int ms)`
- **說明**: 暫停執行指定毫秒 (Async)。
- **範例**: `sleep(1000);`

## 8. 資料結構操作 (Data Structures)

### `sizeof()`
- **語法**: `int sizeof(mixed target)`
- **說明**: 回傳長度 (Array/String/Mapping)。
- **範例**: `sizeof(({1, 2})) -> 2`

### `keys()` / `values()`
- **語法**: `mixed *keys(mapping m)`
- **說明**: 取得 Mapping 的所有鍵或所有值。
- **範例**: `keys((["a":1])) -> ({"a"})`

### `allocate()`
- **語法**: `mixed *allocate(int size)`
- **說明**: 預分配陣列空間。
- **範例**: `allocate(10) -> ({0, 0, ...})`

### `m_add()` / `m_delete()`
- **語法**: `mapping m_add(mapping m, mixed key, mixed val)`
- **說明**: 新增或刪除 Mapping 鍵值。
- **範例**: `m_delete(m, "key");`

### `member_array()`
- **語法**: `int member_array(mixed item, mixed *arr)`
- **說明**: 尋找元素索引，找不到回傳 -1。
- **範例**: `member_array(2, ({1, 2, 3})) -> 1`

### `explode()` / `implode()`
- **語法**: `string *explode(string s, string d)` / `string implode(string *a, string d)`
- **說明**: 字串切割與合併。
- **範例**: `explode("a,b", ",") -> ({"a", "b"})`

### `filter()` / `map()`
- **語法**: `mixed filter(mixed coll, string|closure func, ...)`
- **說明**: 陣列或 Mapping 的過濾與映射。
- **範例**: `filter(arr, (: $1 > 0 :))`

### `sort_array()`
- **語法**: `mixed *sort_array(mixed *arr, mixed func)`
- **說明**: 排序陣列。
- **範例**: `sort_array(arr, 1); // 1 為升序`

### `unique_array()`
- **語法**: `mixed *unique_array(mixed *arr, mixed func)`
- **說明**: 將陣列依條件分組。
- **範例**: `unique_array(items, "query_type")`

### `copy()`
- **語法**: `mixed copy(mixed arg)`
- **說明**: 深層複製。
- **範例**: `mapping m2 = copy(m1);`

### `json_encode()`
- **語法**: `string json_encode(mixed data)`
- **說明**: 將資料轉為 JSON 字串。
- **範例**: `json_encode((["a":1])) -> "{\"a\":1}"`

## 9. 字串處理 (Strings)

### `strlen()` / `substr()` / `strsrch()`
- **語法**: `int strlen(string s)` / `string substr(string s, int start, int len)`
- **說明**: 基本字串長度、擷取與搜尋。
- **範例**: `substr("hello", 1, 2) -> "el"`

### `lower_case()` / `upper_case()` / `capitalize()`
- **語法**: `string lower_case(string s)`
- **說明**: 大小寫轉換。
- **範例**: `capitalize("abc") -> "Abc"`

### `trim()`
- **語法**: `string trim(string s)`
- **說明**: 去除前後空白。
- **範例**: `trim(" a ") -> "a"`

### `replace_string()`
- **語法**: `string replace_string(string s, string old, string new)`
- **說明**: 取代子字串。
- **範例**: `replace_string("a-b", "-", "+") -> "a+b"`

### `sprintf()`
- **語法**: `string sprintf(string format, ...)`
- **說明**: 格式化字串 (支援 %d, %s, %O 等)。
- **範例**: `sprintf("%d", 123) -> "123"`

### `sscanf()`
- **語法**: `int sscanf(string str, string format, mixed var1, mixed var2, ...)`
- **說明**: 格式化輸入解析。將字串按 format 解析並賦值給後續變數。
- **範例**: `sscanf("give 10 gold", "give %d %s", amt, item);`

### `regexp()`
- **語法**: `mixed regexp(mixed data, string pattern)`
- **說明**: 正規表達式匹配或過濾陣列。
- **範例**: `regexp(({"abc", "123"}), "[a-z]") -> ({"abc"})`

### `break_string()`
- **語法**: `string break_string(string s, int width)`
- **說明**: 自動換行處理。
- **範例**: `break_string(long_desc, 78)`

### `pad_str()`
- **語法**: `string pad_str(string s, int width)`
- **說明**: 計算顯示寬度 (中文字算 2 格) 並補齊空白。
- **範例**: `pad_str("你好", 10) -> "你好      "`

### `crypt()`
- **語法**: `string crypt(string s, [string seed])`
- **說明**: 使用 bcrypt 進行雜湊加密或驗證。
- **範例**: `crypt("pass") -> "$2a$10$..."`

## 10. 系統與檔案 (System & Files)

### `get_dir()`
- **語法**: `string *get_dir(string path, [int recursive])`
- **說明**: 取得目錄檔案列表。
- **範例**: `get_dir("/cmds/")`

### `read_file()` / `write_file()`
- **語法**: `string read_file(string file)`
- **說明**: 讀寫實體檔案。包含權限檢查。
- **範例**: `write_file("/log/test", "msg");`

### `rm()` / `rename()` / `mkdir()` / `rmdir()` / `cp()`
- **語法**: `int rm(string file)`
- **說明**: 檔案與目錄管理。
- **範例**: `mkdir("/data/user/a");`

### `file_size()`
- **語法**: `int file_size(string file)`
- **說明**: 取得檔案大小。-1 不存在，-2 為目錄。
- **範例**: `if (file_size(f) > 0) {}`

### `objects()` / `livings()`
- **語法**: `object *objects()` / `object *livings()`
- **說明**: 取得目前記憶體中所有的物件或活物。
- **範例**: `sizeof(objects()) -> 150`

### `query_idle()`
- **語法**: `int query_idle(object ob)`
- **說明**: 物件閒置秒數 (自上次函式呼叫起算)。
- **範例**: `if (query_idle(me) > 300) {}`

### `mud_status()` / `memory_summary()`
- **語法**: `string mud_status()`
- **說明**: 系統資源與物件數量摘要。
- **範例**: `write(mud_status())`

### `getenv()`
- **語法**: `string getenv(string var)`
- **說明**: 取得 OS 環境變數。
- **範例**: `getenv("PATH")`

### `shutdown()`
- **語法**: `void shutdown([int code])`
- **說明**: 關閉伺服器。
- **範例**: `shutdown();`

### `replace_program()`
- **語法**: `void replace_program(string path)`
- **說明**: 將當前物件的所有函式替換為指定物件的函式。
- **範例**: `replace_program("/std/room");`

### `resolve_path()`
- **語法**: `string resolve_path(string base, string rel)`
- **說明**: 將相對路徑轉換為絕對路徑。
- **範例**: `resolve_path("/std/user", "./data")`

## 11. 閉包與函式執行 (Functional)

### `evaluate()` / `apply()`
- **語法**: `mixed evaluate(mixed cl, ...)`
- **說明**: 執行閉包或動態函式。
- **範例**: `evaluate((: write, "Hi" :))`

### `throw()`
- **語法**: `void throw(mixed msg)`
- **說明**: 拋出錯誤，中斷目前執行。
- **範例**: `if (!arg) throw("缺少參數");`

## 12. 持久化 (Persistence)

### `save_object()` / `restore_object()`
- **語法**: `int save_object(string file)`
- **說明**: 存取物件狀態為 JSON。
- **範例**: `save_object("/data/user/wade");`

### `exec()`
- **語法**: `int exec(object target, object src)`
- **說明**: 轉移連線。
- **範例**: `exec(new_user, old_login);`

### `input_to()`
- **語法**: `int input_to(string func, [int hidden])`
- **說明**: 攔截下次輸入。
- **範例**: `input_to("get_password", 1);`

## 13. 其他擴充 (Extensions)

### `p2p_broadcast()`
- **語法**: `void p2p_broadcast(string msg)`
- **說明**: 將訊息廣播至星際網路 (P2P 全球連線)。
- **範例**: `p2p_broadcast("來自某星系的問候");`

---

## Efun 字母索引 (Alphabetical Index)

- [abs()](#abs)
- [add_action()](#add_action)
- [all_inventory()](#all_inventory--deep_inventory)
- [allocate()](#allocate)
- [apply()](#evaluate--apply)
- [arrayp()](#arrayp--pointerp)
- [base_name()](#object_name--base_name)
- [break_string()](#break_string)
- [call_other()](#call_other)
- [call_out()](#call_out--remove_call_out)
- [call_out_info()](#find_call_out--call_out_info)
- [capitalize()](#lower_case--upper_case--capitalize)
- [clone_object()](#clone_object)
- [command()](#command)
- [copy()](#copy)
- [cp()](#rm--rename--mkdir--rmdir--cp)
- [crypt()](#crypt)
- [ctime()](#ctime--strftime)
- [deep_inventory()](#all_inventory--deep_inventory)
- [destruct()](#destruct)
- [enable_commands()](#enable_commands)
- [environment()](#environment)
- [errorp()](#errorp)
- [evaluate()](#evaluate--apply)
- [exec()](#exec)
- [explode()](#explode--implode)
- [file_size()](#file_size)
- [filter()](#filter--map)
- [filter_array()](#filter--map)
- [filter_mapping()](#filter--map)
- [find_call_out()](#find_call_out--call_out_info)
- [find_object()](#load_object--find_object)
- [find_player()](#find_player)
- [floatp()](#floatp)
- [functionp()](#functionp)
- [get_dir()](#get_dir)
- [getenv()](#getenv)
- [gmtime()](#localtime--gmtime)
- [implode()](#explode--implode)
- [input_to()](#input_to)
- [intp()](#intp)
- [interactive()](#is_interactive--interactive)
- [is_interactive()](#is_interactive--interactive)
- [is_web_client()](#is_web_client)
- [json_encode()](#json_encode)
- [keys()](#keys--values)
- [living()](#living)
- [livings()](#objects--livings)
- [load_object()](#load_object--find_object)
- [localtime()](#localtime--gmtime)
- [lower_case()](#lower_case--upper_case--capitalize)
- [m_add()](#m_add--m_delete)
- [m_delete()](#m_add--m_delete)
- [map()](#filter--map)
- [map_array()](#filter--map)
- [map_mapping()](#filter--map)
- [mappingp()](#mappingp--mapp)
- [mapp()](#mappingp--mapp)
- [max()](#max--min)
- [member_array()](#member_array)
- [memory_summary()](#mud_status--memory_summary)
- [min()](#max--min)
- [mkdir()](#rm--rename--mkdir--rmdir--cp)
- [move_object()](#move_object)
- [mud_status()](#mud_status--memory_summary)
- [nullp()](#nullp)
- [object_name()](#object_name--base_name)
- [objectp()](#objectp)
- [objects()](#objects--livings)
- [p2p_broadcast()](#p2p_broadcast)
- [pad_str()](#pad_str)
- [pcre_match()](#pcre_match)
- [pcre_replace()](#pcre_replace)
- [pointerp()](#arrayp--pointerp)
- [present()](#present)
- [previous_object()](#previous_object)
- [query_idle()](#query_idle)
- [query_ip_name()](#query_ip_number--query_ip_name)
- [query_ip_number()](#query_ip_number--query_ip_name)
- [query_verb()](#query_verb)
- [random()](#random)
- [read_file()](#read_file--write_file)
- [regexp()](#regexp)
- [remove_call_out()](#call_out--remove_call_out)
- [rename()](#rm--rename--mkdir--rmdir--cp)
- [replace_program()](#replace_program)
- [replace_string()](#replace_string)
- [resolve_path()](#resolve_path)
- [restore_object()](#save_object--restore_object)
- [rm()](#rm--rename--mkdir--rmdir--cp)
- [rmdir()](#rm--rename--mkdir--rmdir--cp)
- [save_object()](#save_object--restore_object)
- [say()](#say)
- [set_heart_beat()](#set_heart_beat)
- [set_living_name()](#set_living_name)
- [shout()](#shout)
- [shutdown()](#shutdown)
- [sizeof()](#sizeof)
- [sleep()](#sleep)
- [sort_array()](#sort_array)
- [sprintf()](#sprintf)
- [sscanf()](#sscanf)
- [strftime()](#ctime--strftime)
- [strlen()](#strlen--substr--strsrch)
- [stringp()](#stringp)
- [strsrch()](#strlen--substr--strsrch)
- [substr()](#strlen--substr--strsrch)
- [tell_object()](#tell_object)
- [tell_room()](#tell_room)
- [this_object()](#this_object)
- [this_player()](#this_player)
- [throw()](#throw)
- [to_float()](#to_float)
- [to_int()](#to_int)
- [to_string()](#to_string)
- [trim()](#trim)
- [unique_array()](#unique_array)
- [userp()](#userp)
- [users()](#users)
- [values()](#keys--values)
- [write()](#write)
- [write_file()](#read_file--write_file)
