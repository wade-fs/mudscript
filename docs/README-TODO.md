# MudScript Efun 與 Mudlib 相容性評估 v3
> **資料來源**：直接分析原始碼（v1.2.1）  
> `driver/efun.go`（2757 行）、`evaluator/evaluator.go`、`driver/driver.go`、`mudlib/` 全目錄  
> **圖例**：✅ 完全相容　⚠️ 語意差異　❌ 確認缺漏　➕ MudScript 擴充

---

## 整體相容性（修正後）

| 目標 | 估計相容性 | 主要障礙 |
|---|---|---|
| LDMud 3.x | **~85%** | `varargs` 語意、`sort_array` 整數模式、存檔格式 |
| FluffOS / MudOS | **~92%** | `sscanf %*/%c`、存檔格式 |
| Lima Bean lib | **~78%** | `command_d` 架構差異（但 `init()` 已有） |
| GodWars2 lib | **~90%** | 功能集高度重疊 |

---

## 一、已完整實作的 Efun（原始碼確認）

### 1-1. 訊息輸出

| Efun | 狀態 | 說明 |
|---|---|---|
| `write(msg)` | ✅ | 發給 current player，fallback 印終端機 |
| `say(msg, [exclude])` | ✅ | 廣播房間，支援排除陣列 |
| `tell_object(ob, msg)` | ✅ | 直接送給指定物件 |
| `tell_room(room, msg, [exclude])` | ✅ | 廣播指定房間，支援排除清單 |
| `shout(msg)` | ✅ | 全伺服器廣播，排除自身 |

### 1-2. 物件與環境

| Efun | 狀態 | 說明 |
|---|---|---|
| `this_player()` | ✅ | 標準 |
| `this_object()` | ✅ | 標準 |
| `previous_object()` | ✅ | 標準 |
| `environment([ob])` | ✅ | 標準 |
| `move_object(dest)` / `move_object(item, dest)` | ✅ | 完整實作，含 init 觸發 |
| `clone_object(path)` | ✅ | 自動補 `.c`，深層 clone |
| `load_object(path)` | ✅ | MudOS 風格 |
| `find_object(path)` | ✅ | 標準 |
| `destruct(ob)` | ✅ | 標準 |
| `object_name([ob])` | ✅ | 回傳 `path#id` |
| `base_name(ob)` | ✅ | 去除 `#clone_id` |
| `present(id, [env])` | ✅ | 呼叫 `id()` 判斷 |
| `all_inventory([ob])` | ✅ | 標準 |
| `deep_inventory([ob])` | ✅ | 遞迴深層 |
| `find_player(id)` | ✅ | 呼叫 `get_id()` 比對 |
| `users()` | ✅ | 回傳所有 active 連線 |
| `living(ob)` | ✅ | 檢查 `IsLiving` |
| `userp(ob)` | ✅ | 標準 |
| `interactive(ob)` / `is_interactive(ob)` | ✅ | 標準 + 別名 |
| `enable_commands()` | ✅ | 設定 `IsLiving = true` |
| `add_action(func, verb)` | ✅ | 完整實作，綁定 Provider 物件 |
| `command(str)` | ✅ | 程式化觸發指令，先查 Actions 再走 command_d |
| `query_verb()` | ✅ | 標準 |
| `call_other(ob, func, ...)` | ✅ | 標準，支援 `->` 語法糖 |
| `query_idle(ob)` | ✅ | 依 `LastActivity` 計算秒數 |
| `set_living_name(name)` | ✅ | 標準 |

### 1-3. 排程與時間

| Efun | 狀態 | 說明 |
|---|---|---|
| `time()` | ✅ | Unix 時間戳 |
| `ctime([ts])` | ✅ | 標準時間字串 |
| `strftime(fmt, [ts])` | ✅ | 標準 strftime，自動轉 Go 格式 |
| `call_out(func, delay, ...)` | ✅ | 標準 |
| `remove_call_out(func)` | ✅ | 回傳移除數量 |
| `set_heart_beat(flag)` | ✅ | 智慧心跳（有玩家才觸發） |
| `call_out_info()` | ✅ | 回傳 `({caller, func, time_left})` |
| `input_to(func, [hidden])` | ✅ | 含 `__INPUT_HIDDEN__` 通訊協定 |
| `sleep(ms)` | ⚠️ | 真正的 `time.Sleep`，會阻塞整個 goroutine；傳統 LPC 是 co-routine 切換 |

### 1-4. 資料結構與函數式

| Efun | 狀態 | 說明 |
|---|---|---|
| `sizeof(target)` | ✅ | array / string / mapping |
| `explode(str, delim)` | ✅ | 標準 |
| `implode(arr, delim)` | ✅ | 標準 |
| `member_array(item, arr)` | ✅ | 找不到回傳 -1 |
| `allocate(size)` | ✅ | 預分配陣列，填充 0 |
| `copy(arg)` | ✅ | 深層複製 array / mapping |
| `keys(mapping)` | ✅ | 標準 |
| `values(mapping)` | ✅ | 標準 |
| `m_delete(m, key)` | ✅ | 標準 |
| `m_add(m, key, val)` | ✅ | 新增/更新 key-value |
| `filter(coll, func, ...)` | ✅ | 通用，auto-dispatch array/mapping |
| `filter_array(arr, func, ...)` | ✅ | 支援 string callback 與 closure |
| `filter_mapping(m, func, ...)` | ✅ | 支援 string callback 與 closure |
| `map(coll, func, ...)` | ✅ | 通用，auto-dispatch |
| `map_array(arr, func, ...)` | ✅ | 標準 |
| `map_mapping(m, func, ...)` | ✅ | 標準 |
| `sort_array(arr, closure/string, ...)` | ✅ | 支援 closure 與 string callback；詳見缺漏節 |
| `unique_array(arr)` | ✅ | 去除重複元素版本 |
| `evaluate(cl, ...)` / `apply(cl, ...)` | ✅ | 執行 closure 或 string |

### 1-5. 字串處理

| Efun | 狀態 | 說明 |
|---|---|---|
| `sprintf(fmt, ...)` | ✅ | `%d %s %f %O`，`%O` 轉 `%s` |
| `strlen(str)` | ✅ | rune-safe（正確處理 CJK） |
| `substr(str, start, [len])` | ✅ | 支援負數 start，rune-safe |
| `lower_case(str)` | ✅ | 標準 |
| `upper_case(str)` | ✅ | 標準 |
| `capitalize(str)` | ✅ | rune-safe |
| `trim(str, [cutset])` | ✅ | 支援自訂 cutset |
| `replace_string(str, pat, rep)` | ✅ | 全域替換 |
| `strsrch(str, pat, [rev])` | ✅ | 支援 reverse 搜尋，rune-safe |
| `regexp(target, pattern)` | ✅ | string（回傳 0/1）與 array（回傳過濾後陣列） |
| `sscanf(str, fmt, ...)` | ✅（部分）| 支援 `%d %s %f`；詳見缺漏節 |
| `break_string(str, width, [indent])` | ✅ | 按寬度折行，支援整數或字串縮排 |
| `crypt(str)` | ⚠️ | **SHA-256** 格式；傳統為 DES/bcrypt，密碼雜湊值不可互通 |
| `pad_str(str, width)` | ➕ | CJK 寬度計算補空白 |
| `resolve_path(rel, [base])` | ➕ | 相對路徑轉絕對路徑 |

### 1-6. 型別判斷與數學

| Efun | 狀態 | 說明 |
|---|---|---|
| `intp(v)` | ✅ | 標準 |
| `stringp(v)` | ✅ | 標準 |
| `floatp(v)` | ✅ | 標準 |
| `objectp(v)` | ✅ | 標準 |
| `mappingp(v)` / `mapp(v)` | ✅ | 標準 + 別名 |
| `arrayp(v)` / `pointerp(v)` | ✅ | 標準 + LDMud 別名 |
| `nullp(v)` | ✅ | nil 或 0 均為 true |
| `errorp(v)` | ✅ | 標準 |
| `functionp(v)` | ✅ | 支援 Function / Closure / Builtin |
| `to_int(v)` | ✅ | Float / String / Integer |
| `to_string(v)` | ✅ | 呼叫 `Inspect()` |
| `to_float(v)` | ✅ | Integer / String / Float |
| `abs(n)` | ✅ | 標準 |
| `max(a, b)` | ✅ | 標準 |
| `min(a, b)` | ✅ | 標準 |
| `random(max)` | ✅ | 0 ~ max-1 |
| `json_encode(data)` | ➕ | LPC → JSON |

### 1-7. 系統、檔案與持久化

| Efun | 狀態 | 說明 |
|---|---|---|
| `read_file(path)` | ✅ | 含 `valid_read` 權限檢查 |
| `write_file(path, text, [overwrite])` | ✅ | 含 `valid_write`；預設 append，1 = 覆寫 |
| `file_size(path)` | ✅ | -1 不存在，-2 目錄 |
| `get_dir(path, [recursive])` | ✅ | 支援 glob 與遞迴掃描 |
| `rm(path)` | ✅ | 含 `valid_write` |
| `rename(from, to)` | ✅ | 含雙向 `valid_write` |
| `mkdir(path)` | ✅ | `MkdirAll` |
| `rmdir(path)` | ✅ | 含 `valid_write` |
| `cp(from, to)` | ✅ | 含 read + write 雙重權限 |
| `save_object(path)` | ⚠️ | **JSON 格式**（`.o` 副檔名）；傳統格式不可互通 |
| `restore_object(path)` | ⚠️ | 同上，JSON 格式 |
| `exec(target, src)` | ✅ | TCP 連線轉移 |
| `shutdown([code])` | ✅ | 延遲 500ms 確保訊息送達 |
| `getenv(var)` | ✅ | 標準 |

### 1-8. P2P / 擴充

| Efun | 狀態 | 說明 |
|---|---|---|
| `p2p_broadcast(msg, [targets])` | ➕ | 星際伺服器互連廣播，傳統 driver 無此功能 |
| `throw(msg)` | ✅ | 主動拋出 Error 物件，配合 `catch()` 使用 |

---

## 二、架構層機制（完整確認）

| 機制 | 狀態 | 說明 |
|---|---|---|
| `simul_efun` 物件 | ✅ | `master.c` 提供 `get_simul_efun()`，driver 啟動時自動載入並注入所有物件 |
| `master.c` 回調 | ✅ | `connect()`、`runtime_error()`、`get_root_uid()`、`get_bb_uid()`、`get_simul_efun()` |
| `catch(expr)` | ✅ | evaluator 層攔截，回傳錯誤字串或 0 |
| `init()` 觸發機制 | ✅ | **完整實作**：`MoveObject` 中依照 MudOS 標準，生物移動時觸發 A/B/C 三種情境的 `init()`，並自動清空/重建 Actions |
| `inherit` 機制 | ✅（有注意事項）| 載入時以複製（copy-down）方式合併父類別；見下節說明 |
| `::func()` 父類別呼叫 | ✅ | evaluator 實作遞迴尋找 Inherits 鏈，並重新綁定至子物件環境 |
| `foreach` | ✅ | 支援 array/mapping，型別宣告，雙變數 `(k, v in mapping)` |
| `switch/case` | ✅ | 標準 |
| 三元運算子 `?:` | ✅ | 獨立 AST 節點 |
| Lambda `(:...:)` | ✅ | 支援 `$1 $2` 匿名參數與具名參數 |
| 位元操作 `& \| ^ ~ << >>` | ✅ | 標準 |
| 陣列/字串切片 `arr[1..3]` | ✅ | rune-safe |
| `#include` / `#define` | ✅ | Preprocessor 實作 |
| `varargs` 宣告 | ⚠️（僅解析）| 詳見缺漏節 |

---

## 三、確認缺漏清單（原始碼逐行確認）

### 🔴 中等影響

#### 1. `sort_array(arr, 1)` 整數升序模式
第一版 `sort_array`（第 1236 行）**只接受 `*object.String`** 作為 callback，傳入 `Integer(1)` 時 `!isStr` 判斷失敗，直接回傳原陣列不排序。  
第二版（第 1538 行）使用 `executeCallback`，但 `executeCallback` 只處理 `*object.String` 與 `*object.Closure`，**沒有 Integer case**，傳入 `1` 會回傳 `"callback 必須是字串或 closure"` 錯誤。  
這導致 `sort_array(arr, 1)` / `sort_array(arr, -1)` 這個 LDMud/FluffOS 標準用法完全失效。

```lpc
// 這在 MudScript 無法正常運作
string *sorted = sort_array(keys(map), 1);
```

#### 2. `sscanf` 缺少 `%*`（skip）與 `%c`（單字元）格式子
`evalSscanf` 只處理 `%d`、`%s`、`%f`，遇到其他格式（如 `%*d` 略過整數）直接以 `regexp.QuoteMeta` 轉成字面字元，**無法略過欄位**。部分 mudlib 指令解析依賴此格式。

#### 3. `varargs` 宣告語意未實作
Parser 在函式修飾符處（第 585 行）遇到 `varargs` token 直接呼叫 `p.nextToken()` 跳過，**不建立任何 AST 節點、不設定任何旗標**。  
這代表 `varargs` 宣告只是讓 parser 不報錯，沒有任何語意效果。  
在 Go 側，多餘的 args 被忽略是因為 args 是 slice，所以**呼叫端多傳參數不會崩潰**，但在 LPC 層：

```lpc
varargs int my_func(string a, string b) {
    // 傳統 LPC：sizeof(...) 取得實際參數數量
    // MudScript：無法在 LPC 層感知「實際傳了幾個參數」
}
```

### 🟡 低影響

#### 4. `save_object` / `restore_object` 格式為 JSON
實際存檔確認為 JSON（見 `data/user/wade.o`）。傳統 LPC 存檔格式為自訂文字格式，**兩者不可互通**。若要從舊有 MUD 遷移玩家資料需要轉換工具。

#### 5. `sleep(ms)` 為真正阻塞
`time.Sleep` 會阻塞整個 goroutine，不是 LPC 傳統的 co-routine 讓出。會影響使用 `sleep()` 在事件循環中讓步的 LPC 程式碼。

#### 6. `unique_array` 僅實作去重版本
標準 LPC 的 `unique_array(arr, func)` 接受分組函式，回傳二維陣列（依函式回傳值分組）。MudScript 的 `unique_array` 只有**無 callback 去重版**，傳入 callback 的標準用法不支援。

#### 7. `crypt()` 格式不相容
使用 SHA-256 而非傳統 DES/bcrypt，**無法驗證舊有存檔中的密碼雜湊**（如 `wade.o` 中的密碼欄位若來自傳統 MUD 就無法登入）。

---

## 四、inherit 機制的注意事項

MudScript 採用 **copy-down** 繼承策略：載入物件時，把父類別的所有方法和變數複製到子物件的 `Vars` 環境中。

**優點**：`CallFunction` 查找速度快（直接在 `Vars.Get` 一次找到），不需要走繼承鏈。

**注意事項**：
- `CallFunction` 找不到方法時，fallback 是 **SimulEfun**，不是再走 Inherits 鏈。因為方法已在載入時 copy-down，正常情況下不需要走鏈——只有在 copy-down 漏掉方法時才會出現問題。
- **多重繼承同名方法**：後繼承的父類別方法會**覆蓋**先繼承的，與 LDMud 的「第一個 inherit 優先」語意相反，需注意繼承順序。
- **`::func()` 父類別呼叫**：已完整實作，會遞迴搜尋 Inherits 鏈並重新綁定到子物件環境，行為正確。

---

## 五、指令系統架構說明

MudScript 採用**雙軌並行**架構：

```
玩家輸入 verb
  ├── 1. 優先查 player.Actions（由 add_action() 掛接）
  └── 2. fallback 到 command_d.execute()（集中管理的 cmd_xxx.c）
```

- **`init()` 已完整實作**：`MoveObject` 在生物移動時，依照 MudOS 標準觸發環境、環境內物件、自身攜帶物的 `init()`。測試檔案 `test_init_action.c` 驗證了這個流程。
- 因此，傳統依賴 `init()` + `add_action()` 的 mudlib **可以正常運作**，不需要改寫指令掛接邏輯。

---

## 六、真實缺漏彙整與修補優先序

| 優先 | 問題 | 修補方式 | 工作量 |
|---|---|---|---|
| 🟠 中 | `sort_array(arr, 1)` 整數模式 | `executeCallback` 加 Integer case：正整數升序，負整數降序 | 小（~10 行）|
| 🟠 中 | `sscanf %*` skip 格式子 | `evalSscanf` 加 `case '*'` 建立非捕捉群組 `(?:...)` | 小（~15 行）|
| 🟠 中 | `varargs` 語意 | Parser 記錄旗標，evaluator 讓 LPC 層可感知實際參數數量 | 中（~50 行）|
| 🟡 低 | `unique_array(arr, func)` 分組版 | 補 callback 版本的分組邏輯 | 小（~20 行）|
| 🟡 低 | `sleep()` 非阻塞化 | 改為 goroutine + channel 模式讓出控制權 | 中（架構調整）|
| ⬜ 資訊 | `save/restore_object` JSON 格式 | 可補 LPC 傳統格式的 import 轉換工具 | 中 |
| ⬜ 資訊 | `crypt()` 格式差異 | 影響遷移，不影響新建 MUD | 視需求 |

---

## 七、結論

MudScript 是一個功能完整度**相當高**的現代 LPC driver 實作。

**三個版本評估的最大教訓**：未讀完整原始碼就下結論，會嚴重低估實作品質。

**真正的剩餘缺口很小**，且全部集中在語言細節層面：
- `sort_array` 整數模式（10 行即可修復）
- `sscanf %*` 格式（15 行即可修復）
- `varargs` 語意（最複雜，但仍是局部修改）

**架構層面**（`init()` 機制、`simul_efun`、`::` 繼承呼叫、`catch/throw`、`command()`）**全數已正確實作**，與傳統 MudOS/FluffOS 語意一致。

對於自建 mudlib（現有 MudScript mudlib）：✅ **生產就緒**。  
對於移植傳統 LPMud mudlib：✅ **架構相容**，只需注意 `sort_array` 整數模式與存檔格式差異。
