# MudScript Built-in Functions (Efuns) 參考手冊

本文檔列出了 MudScript 引擎中所有可用的內建函式 (Efuns) 及其用法說明。

## 1. 型別判斷 (Predicates)
用於檢查變數的資料型別。是回傳 `1`，否回傳 `0`。

- `intp(mixed arg)`: 判斷是否為整數。
- `stringp(mixed arg)`: 判斷是否為字串。
- `floatp(mixed arg)`: 判斷是否為浮點數。
- `objectp(mixed arg)`: 判斷是否為 LPC 物件。
- `mappingp(mixed arg)`: 判斷是否為 Mapping (鍵值對)。
- `arrayp(mixed arg)`: 判斷是否為陣列。
- `nullp(mixed arg)`: 判斷是否為 `nil` 或整數 `0`。
- `errorp(mixed arg)`: 判斷是否為系統錯誤物件。

## 2. 型別轉換 (Casting)
- `to_int(mixed arg)`: 轉換為整數。支援字串與浮點數。
- `to_string(mixed arg)`: 轉換為字串表示。

## 3. 數學運算 (Math)
- `abs(int num)`: 取得絕對值。
- `max(val1, val2, ...)`: 取得最大值。
- `min(val1, val2, ...)`: 取得最小值。
- `random(int max)`: 產生 `0` 到 `max-1` 之間的隨機整數。

## 4. 核心輸出入 (Core IO)
- `write(string msg)`: 發送訊息給當前觸發行為的玩家。
- `say(string msg)`: 廣播訊息給同一房間內的所有人 (排除發言者)。
- `shout(string msg)`: 對全伺服器玩家廣播訊息。
- `tell_object(object target, string msg)`: 直接傳送訊息給指定物件。
- `input_to(string func_name, [int hidden])`: 攔截玩家下一次輸入並傳給指定函式。

## 5. 環境與物件管理 (Environment & Objects)
- `this_player()`: 取得當前動作的觸發玩家。
- `this_object()`: 取得目前執行中的物件實體。
- `environment([object ob])`: 取得物件所在的環境 (房間)。
- `move_object(object item, object dest)`: 移動物件。
- `clone_object(string path)`: 產生一個物件的新克隆 (Clone)。
- `load_object(string path)`: 載入並取得藍圖物件 (Blueprint)。
- `destruct(object ob)`: 銷毀物件。
- `present(string id, [object env])`: 在環境中尋找特定 ID 的物件。
- `all_inventory([object ob])`: 取得物件內部所有物品。
- `deep_inventory([object ob])`: 遞迴取得物件內部所有物品 (包含子容器)。
- `object_name(object ob)`: 取得物件的唯一識別路徑 (含 #編號)。
- `find_object(string path)`: 尋找已載入的藍圖物件。
- `find_player(string id)`: 根據帳號 ID 尋找線上玩家。
- `exec(object target, object src)`: 轉移網路連線。
- `interactive(object ob)`: 判斷是否為連線中的互動玩家。
- `userp(object ob)`: 判斷是否為玩家物件。

## 6. 時間與排程 (Time & Scheduling)
- `time()`: 取得 Unix 時間戳。
- `ctime(int time)`: 將時間戳轉為人類可讀字串。
- `call_out(string func, int delay, [mixed args...])`: 預約延遲呼叫。
- `remove_call_out(string func)`: 移除預約呼叫。
- `set_heart_beat(int flag)`: 開啟或關閉物件的心跳 (每秒觸發 `heart_beat()`)。

## 7. 資料結構操作 (Arrays & Mappings)
- `sizeof(mixed target)`: 回傳陣列、字串或 Mapping 的大小。
- `keys(mapping m)`: 取得 Mapping 的所有鍵名。
- `values(mapping m)`: 取得 Mapping 的所有值。
- `m_delete(mapping m, mixed key)`: 刪除 Mapping 中的鍵值。
- `explode(string str, string delim)`: 分割字串為陣列。
- `implode(string *arr, string delim)`: 合併陣列為字串。
- `member_array(mixed item, mixed *arr)`: 尋找元素在陣列中的索引。
- `filter(mixed *arr, string func, [object target])`: 過濾陣列元素。
- `map(mixed *arr, string func, [object target])`: 對陣列元素執行轉換。
- `sort_array(mixed *arr, string func, [object target])`: 排序陣列。
- `unique_array(mixed *arr)`: 移除重複元素。
- `json_encode(mixed data)`: 將資料轉為 JSON 字串。

## 8. 字串處理 (Strings)
- `strlen(string str)`: 取得字串長度。
- `substr(string str, int start, [int len])`: 擷取子字串。
- `strsrch(string str, string pattern, [int reverse])`: 搜尋字串位置。
- `lower_case(string str)`: 轉小寫。
- `upper_case(string str)`: 轉大寫。
- `capitalize(string str)`: 字首大寫。
- `trim(string str, [string cutset])`: 去除前後空白。
- `replace_string(string str, string old, string new)`: 替換字串。
- `sprintf(string format, ...)`: 格式化字串。
- `pad_str(string str, int width)`: 向右補齊寬度。
- `crypt(string str)`: SHA-256 加密。

## 9. 系統與檔案 (System & Files)
- `get_dir(string path, [int recursive])`: 取得目錄列表。支援磁碟與嵌入式混合讀取。
- `read_file(string file)`: 讀取檔案內容。
- `write_file(string file, string text, [int overwrite])`: 寫入檔案。
- `file_size(string file)`: 取得檔案大小。

## 10. 持久化 (Persistence)
- `save_object(string file)`: 將物件狀態儲存為 JSON 檔。
- `restore_object(string file)`: 從 JSON 檔恢復物件狀態。
