# MudScript Efun 相容性評估報告 v2（原始碼實測版）

> **資料來源**：直接分析 `driver/efun.go`、`evaluator/evaluator.go`、`driver/driver.go`、`mudlib/` 原始碼  
> **版本**：v1.2.1（2026-05-24）  
> **圖例**：✅ 完全相容　⚠️ 語意差異　❌ 缺漏或有缺陷　➕ MudScript 擴充

---

## 關鍵修正：前次評估的錯誤

| 項目 | 前次評估 | 實際狀況 |
|---|---|---|
| `write()` / `say()` / `tell_object()` / `tell_room()` | ❌ 確認狀態 | **✅ 全數已實作**，在 `registerCoreIOEfuns()` 中 |
| `add_action()` | ❌ 確認狀態 | **✅ 已實作**，含 Provider 物件綁定 |
| `input_to()` | ❌ 缺漏 | **✅ 已實作**，含 `__INPUT_HIDDEN__` 機制 |
| `simul_efun` | ⚠️ 確認狀態 | **✅ 完整實作**，`master.c` 有 `get_simul_efun()`，driver 自動載入注入 |
| `sscanf()` | ❌ 缺漏 | **✅ 已實作**，在 evaluator 層以 compiler-level 關鍵字處理 |
| `catch()` | ⚠️ 確認狀態 | **✅ 已實作**，在 evaluator 層攔截 |
| `regexp()` | ❌ 缺漏 | **✅ 已實作**，支援 string 與 array 兩種模式 |
| `allocate()` / `copy()` | ❌ 缺漏 | **✅ 全數已實作** |
| `m_add()` | ❌ 缺漏 | **✅ 已實作** |
| `call_out_info()` | ❌ 缺漏 | **✅ 已實作** |
| `functionp()` / `pointerp()` | ❌ 缺漏 | **✅ 全數已實作** |
| `rm()` / `mkdir()` / `rename()` / `cp()` | ❌ 缺漏 | **✅ 全數已實作**，含 `valid_write` 權限檢查 |
| `break_string()` | ❌ 缺漏 | **✅ 已實作** |

**結論：前次評估的「缺漏」幾乎全數都已實作。整體相容性應大幅修正上調。**

---

## 修正後整體相容性概覽

| 目標 Driver / Mudlib | 前次估計 | 修正後估計 | 說明 |
|---|---|---|---|
| LDMud 3.x | 62% | **~85%** | 主要差距在繼承語意與 `sort_array` 整數模式 |
| FluffOS / MudOS | 71% | **~90%** | 指令系統架構不同，但核心 efun 幾乎齊備 |
| Lima Bean lib | 55% | **~75%** | `command_d` 架構差異，`sscanf` 已有但 `%*` 格式未支援 |
| GodWars2 lib | 68% | **~88%** | 功能集高度重疊 |

---

## 完整 Efun 清單（原始碼實測）

### 1. 訊息輸出（Message I/O）

| Efun | 狀態 | 說明 |
|---|---|---|
| `write(msg)` | ✅ 完全相容 | 發給 current player，fallback 印伺服器終端機 |
| `say(msg, [exclude])` | ✅ 完全相容 | 廣播房間，排除自身與發話者；支援排除陣列 |
| `tell_object(ob, msg)` | ✅ 完全相容 | 直接送給指定物件 |
| `tell_room(room, msg, [exclude])` | ✅ 完全相容 | 廣播指定房間，支援排除清單 |
| `shout(msg)` | ✅ 完全相容 | 全伺服器廣播（排除自身） |

---

### 2. 物件與環境（Object & Environment）

| Efun | 狀態 | 說明 |
|---|---|---|
| `this_player()` | ✅ 完全相容 | 標準 |
| `this_object()` | ✅ 完全相容 | 標準 |
| `previous_object()` | ✅ 完全相容 | 標準 |
| `environment([ob])` | ✅ 完全相容 | 標準 |
| `move_object(dest)` / `move_object(item, dest)` | ✅ 完全相容 | 標準雙參/單參 |
| `clone_object(path)` | ✅ 完全相容 | 自動補 `.c`，含深層 clone |
| `load_object(path)` | ✅ 完全相容 | MudOS 風格 |
| `find_object(path)` | ✅ 完全相容 | 標準 |
| `destruct(ob)` | ✅ 完全相容 | 標準 |
| `object_name([ob])` | ✅ 完全相容 | 回傳 `path#id` |
| `base_name(ob)` | ✅ 完全相容 | 去除 `#clone_id` 的路徑 |
| `present(id, [env])` | ✅ 完全相容 | 呼叫 `id()` 函式判斷 |
| `all_inventory([ob])` | ✅ 完全相容 | 標準 |
| `deep_inventory([ob])` | ✅ 完全相容 | 遞迴深層 |
| `find_player(id)` | ✅ 完全相容 | 呼叫 `get_id()` 比對 |
| `users()` | ✅ 完全相容 | 回傳所有 active 連線 |
| `living(ob)` | ✅ 完全相容 | 呼叫 `is_living()` 判斷 |
| `userp(ob)` | ✅ 完全相容 | 標準 |
| `interactive(ob)` | ✅ 完全相容 | 標準 |
| `is_interactive(ob)` | ✅ 完全相容 | 同 `interactive`，別名 |
| `enable_commands()` | ✅ 完全相容 | 設定 `IsLiving = true` |
| `add_action(func, verb)` | ✅ 完全相容 | 標準，綁定 Provider 物件與玩家 |
| `query_verb()` | ✅ 完全相容 | 標準 |
| `call_other(ob, func, ...)` | ✅ 完全相容 | 標準，支援 `->` 語法糖 |
| `query_idle(ob)` | ✅ 完全相容 | 依 `LastActivity` 計算 |
| `set_living_name(name)` | ✅ 完全相容 | 標準 |

---

### 3. 指令系統架構（Command System Architecture）

| 機制 | 狀態 | 說明 |
|---|---|---|
| `add_action()` efun | ✅ 已實作 | 標準語意：將 verb→func 掛在 player 物件上 |
| `command_d` 集中分派 | ⚠️ 架構差異 | MudScript 以 `command_d.c` 集中管理所有指令，**不依賴** room/item 的 `init()` 呼叫 add_action。傳統 LPMud 每次進房間觸發 `init()`，各物件自己呼叫 add_action。 |
| `init()` 回調觸發 | ❌ 缺漏 | 傳統 LPMud 的「玩家進房間 → 觸發環境內所有物件的 `init()`」機制不存在；現有 mudlib 若依賴此流程需重寫 |
| `command()` efun | ❌ 缺漏 | 程式化觸發指令的 efun |

---

### 4. 排程與時間（Time & Scheduling）

| Efun | 狀態 | 說明 |
|---|---|---|
| `time()` | ✅ 完全相容 | Unix 時間戳 |
| `ctime([ts])` | ✅ 完全相容 | 標準時間字串 |
| `strftime(fmt, [ts])` | ✅ 完全相容 | 標準 strftime，轉換 Go 格式 |
| `call_out(func, delay, ...)` | ✅ 完全相容 | 標準 |
| `remove_call_out(func)` | ✅ 完全相容 | 回傳移除數量 |
| `set_heart_beat(flag)` | ✅ 完全相容 | 智慧心跳（有玩家才觸發） |
| `call_out_info()` | ✅ 完全相容 | 回傳 `({caller, func, time_left})` 陣列 |
| `sleep(ms)` | ⚠️ 語意差異 | MudScript 是真正阻塞（`time.Sleep`），傳統 LPC `sleep` 是 co-routine 切換；會卡住整個 goroutine |
| `input_to(func, [hidden])` | ✅ 完全相容 | 含 `__INPUT_HIDDEN__` 通訊協定 |

---

### 5. 資料結構與函數式（Data Structures & Functional）

| Efun | 狀態 | 說明 |
|---|---|---|
| `sizeof(target)` | ✅ 完全相容 | 支援 array/string/mapping |
| `explode(str, delim)` | ✅ 完全相容 | 標準 |
| `implode(arr, delim)` | ✅ 完全相容 | 標準 |
| `member_array(item, arr)` | ✅ 完全相容 | 找不到回傳 -1 |
| `allocate(size)` | ✅ 完全相容 | 預分配，填充 0 |
| `copy(arg)` | ✅ 完全相容 | 深層複製 array/mapping |
| `keys(mapping)` | ✅ 完全相容 | 標準 |
| `values(mapping)` | ✅ 完全相容 | 標準 |
| `m_delete(m, key)` | ✅ 完全相容 | 標準，回傳修改後的 mapping |
| `m_add(m, key, val)` | ✅ 完全相容 | 新增/更新一對 key-value |
| `filter(coll, func, ...)` | ✅ 完全相容 | 通用，自動分派 array/mapping |
| `filter_array(arr, func, ...)` | ✅ 完全相容 | 支援 string callback 與 closure |
| `filter_mapping(m, func, ...)` | ✅ 完全相容 | 支援 string callback 與 closure |
| `map(coll, func, ...)` | ✅ 完全相容 | 通用，自動分派 array/mapping |
| `map_array(arr, func, ...)` | ✅ 完全相容 | 支援 string callback 與 closure |
| `map_mapping(m, func, ...)` | ✅ 完全相容 | 支援 string callback 與 closure |
| `sort_array(arr, func, ...)` | ⚠️ 語意差異 | 支援 closure 與 string callback；**不支援** `sort_array(arr, 1)` 整數升序模式（LDMud/FluffOS 標準；`executeCallback` 無 Integer case，會回傳錯誤） |
| `unique_array(arr, func, ...)` | ⚠️ 語意差異 | 有兩個定義：v1 是去重（無 callback），v2 是分組（有 callback）。傳統標準是分組版，但呼叫無 callback 版行為不同 |
| `evaluate(cl, ...)` | ✅ 完全相容 | 執行 closure 或 string |
| `apply(cl, ...)` | ✅ 完全相容 | 同 `evaluate` |

---

### 6. 字串處理（Strings）

| Efun | 狀態 | 說明 |
|---|---|---|
| `sprintf(fmt, ...)` | ✅ 完全相容 | 支援 `%d %s %f %O`，`%O` 轉 `%s` |
| `strlen(str)` | ✅ 完全相容 | 以 rune 計算（正確處理 CJK） |
| `substr(str, start, [len])` | ✅ 完全相容 | 支援負數 start，rune-safe |
| `lower_case(str)` | ✅ 完全相容 | 標準 |
| `upper_case(str)` | ✅ 完全相容 | 標準 |
| `capitalize(str)` | ✅ 完全相容 | rune-safe |
| `trim(str, [cutset])` | ✅ 完全相容 | 支援自訂 cutset |
| `replace_string(str, pat, rep)` | ✅ 完全相容 | 全域替換 |
| `strsrch(str, pat, [rev])` | ✅ 完全相容 | 支援 reverse 搜尋，rune-safe |
| `regexp(list, pattern)` | ✅ 完全相容 | 支援 string（回傳 0/1）與 array（回傳過濾後陣列） |
| `sscanf(str, fmt, ...)` | ✅ 完全相容 | Compiler-level 關鍵字，支援 `%d %s %f`；⚠️ 不支援 `%*`（skip）與 `%c`（char）格式 |
| `break_string(str, width, [indent])` | ✅ 完全相容 | 按寬度折行，支援整數或字串縮排 |
| `crypt(str)` | ⚠️ 語意差異 | 使用 SHA-256；傳統為 DES/bcrypt，密碼雜湊值不可互通 |
| `pad_str(str, width)` | ➕ MudScript 擴充 | CJK 寬度計算補空白，標準 driver 無此 efun |
| `resolve_path(rel, [base])` | ➕ MudScript 擴充 | 相對路徑轉絕對路徑，標準 driver 無此 efun |
| `strftime(fmt, [ts])` | ➕ MudScript 擴充 | 時間格式化，部分 driver 有但非標準 |

---

### 7. 型別判斷與數學（Type Predicates & Math）

| Efun | 狀態 | 說明 |
|---|---|---|
| `intp(v)` | ✅ 完全相容 | 標準 |
| `stringp(v)` | ✅ 完全相容 | 標準 |
| `floatp(v)` | ✅ 完全相容 | 標準 |
| `objectp(v)` | ✅ 完全相容 | 標準 |
| `mappingp(v)` / `mapp(v)` | ✅ 完全相容 | 標準 + 別名 |
| `arrayp(v)` / `pointerp(v)` | ✅ 完全相容 | 標準 + LDMud 別名 |
| `nullp(v)` | ✅ 完全相容 | nil 或 0 均為 true |
| `errorp(v)` | ✅ 完全相容 | 標準 |
| `functionp(v)` | ✅ 完全相容 | 支援 Function/Closure/Builtin 三種型別 |
| `to_int(v)` | ✅ 完全相容 | 支援 Float/String/Integer |
| `to_string(v)` | ✅ 完全相容 | 呼叫 `Inspect()` |
| `to_float(v)` | ✅ 完全相容 | 支援 Integer/String/Float |
| `abs(n)` | ✅ 完全相容 | 標準 |
| `max(a, b)` | ✅ 完全相容 | 標準 |
| `min(a, b)` | ✅ 完全相容 | 標準 |
| `random(max)` | ✅ 完全相容 | 0 ~ max-1 |
| `json_encode(data)` | ➕ MudScript 擴充 | LPC → JSON，標準 driver 無此 efun |

---

### 8. 系統、檔案與持久化（System, Files & Persistence）

| Efun | 狀態 | 說明 |
|---|---|---|
| `read_file(path)` | ✅ 完全相容 | 含 `valid_read` 權限檢查 |
| `write_file(path, text, [overwrite])` | ✅ 完全相容 | 含 `valid_write` 權限檢查；預設 append，overwrite=1 覆寫 |
| `file_size(path)` | ✅ 完全相容 | -1 不存在，-2 目錄 |
| `get_dir(path, [recursive])` | ✅ 完全相容 | 支援 glob 萬用字元與遞迴掃描 |
| `rm(path)` | ✅ 完全相容 | 含 `valid_write` |
| `rename(from, to)` | ✅ 完全相容 | 含雙向 `valid_write` |
| `mkdir(path)` | ✅ 完全相容 | `MkdirAll` |
| `rmdir(path)` | ✅ 完全相容 | 含 `valid_write` |
| `cp(from, to)` | ✅ 完全相容 | 含 read + write 雙重權限檢查 |
| `object_name([ob])` | ✅ 完全相容 | 標準 |
| `find_object(path)` | ✅ 完全相容 | 標準 |
| `load_object(path)` | ✅ 完全相容 | MudOS 風格 |
| `query_idle(ob)` | ✅ 完全相容 | 依 `LastActivity` |
| `save_object(path)` | ⚠️ 語意差異 | **JSON 格式** `.o` 檔；傳統格式不可互通 |
| `restore_object(path)` | ⚠️ 語意差異 | 同上，JSON 格式 |
| `exec(target, src)` | ✅ 完全相容 | TCP 連線轉移 |
| `shutdown([code])` | ✅ 完全相容 | 延遲 500ms 確保最後訊息送達 |
| `getenv(var)` | ✅ 完全相容 | 標準 |

---

### 9. 架構層機制（Architecture Mechanisms）

| 機制 | 狀態 | 說明 |
|---|---|---|
| `simul_efun` 物件 | ✅ 完整實作 | `master.c` 提供 `get_simul_efun()`，driver 自動載入並注入所有物件 |
| `master.c` 回調 | ✅ 完整實作 | `connect()`、`runtime_error()`、`get_root_uid()`、`get_bb_uid()`、`get_simul_efun()` |
| `catch(expr)` | ✅ 完整實作 | Evaluator 層攔截，回傳錯誤字串或 0 |
| `inherit` 機制 | ✅ 已實作（有設計缺陷） | 繼承時以複製（copy）方式合併父類別方法；⚠️ **CallFunction 找不到方法時不走 Inherits 鏈，而是直接去 SimulEfun**，意即動態繼承查找不完整 |
| `varargs` 宣告 | ⚠️ 解析無語意 | token 有定義，parser 有識別（作為修飾符跳過），**evaluator 完全未處理**；函式可以接收多餘參數是因為 Go 側 args 是 slice，但 LPC 層 varargs 的語意（如 `sizeof(args)` 取得參數數量）不支援 |
| `foreach` | ✅ 完全相容 | 支援 array/mapping，支援型別宣告，支援雙變數 `(k, v in mapping)` |
| `switch/case` | ✅ 完全相容 | 標準 |
| 三元運算子 `?:` | ✅ 完全相容 | 獨立 AST 節點 |
| Lambda 語法 `(:...:)` | ✅ 完全相容 | 支援 `$1 $2` 匿名參數與具名參數 |
| 位元操作 `& | ^ ~ << >>` | ✅ 完全相容 | 標準 |
| 陣列切片 `arr[1..3]` | ✅ 完全相容 | 標準 LPC 語法 |
| 字串切片 `str[1..3]` | ✅ 完全相容 | rune-safe |
| `#include` / `#define` | ✅ 完全相容 | Preprocessor 實作 |
| P2P 星際互連 | ➕ MudScript 擴充 | WebRTC + WebSocket 信令，`p2p_broadcast()`，傳統 driver 無此功能 |

---

## 真實缺漏彙整（原始碼確認）

以下是**確認存在**的缺口：

| 缺漏項目 | 影響程度 | 說明 |
|---|---|---|
| `init()` 觸發機制 | 🔴 高 | 傳統 LPMud 「進房間觸發所有物件 `init()`」流程不存在，直接影響所有依賴此機制的現有 mudlib |
| `sort_array(arr, 1)` 整數模式 | 🟠 中 | `executeCallback` 無 Integer case；傳統 mudlib 常用此簡寫升序/降序 |
| `sscanf` `%*` 與 `%c` 格式 | 🟠 中 | skip 格式子在文字解析中常用 |
| `varargs` 語意實作 | 🟠 中 | 宣告有解析但無語意；`sizeof(args)` 在 varargs 函式中不可用 |
| `inherit` 動態查找鏈 | 🟠 中 | `CallFunction` 找不到方法時跳 SimulEfun 而非走 Inherits 鏈；運行期間 `::func()` 父類別明確呼叫行為需確認 |
| `command()` efun | 🟡 低 | 程式化觸發指令，部分 mudlib 使用 |
| `crypt()` 格式不相容 | 🟡 低 | SHA-256 vs DES；無法讀舊有玩家密碼存檔 |
| `save/restore_object` 格式 | 🟡 低 | JSON 格式無法與傳統 `.o` 格式互通 |
| `throw()` | 🟡 低 | 主動拋出錯誤的 efun，`catch` 有但 `throw` 無對應 efun |

---

## 指令系統相容性專項分析

MudScript 採用 **集中式 `command_d`** 架構，與傳統 LPMud 的 **分散式 `init()` + `add_action()`** 架構根本不同：

```
傳統 LPMud：
  玩家進房間 → driver 觸發房間/物品/NPC 的 init() → 各物件呼叫 add_action() → 玩家的 Actions map 被填充

MudScript：
  玩家輸入 verb → user.c 的 receive_message() → command_d.execute() → 載入對應 cmd_xxx.c → 呼叫 main()
```

這代表：
- ✅ MudScript **自己的 mudlib** 運作完全正常
- ❌ 外部 mudlib 若依賴 `init()` + room 內 `add_action()`，**需要重寫指令掛接邏輯**
- ⚠️ `add_action()` efun 本身存在，但在 MudScript 的架構下不是主要指令分派路徑

---

## 結論

MudScript 的 efun 集遠比前次評估完整。真正的相容性障礙不在 efun 數量，而在**架構理念差異**：

1. **`init()` 觸發機制缺漏**是移植傳統 mudlib 的最大障礙
2. **`inherit` 動態查找**的設計需要確認 `::` 父類別呼叫是否正確
3. **`varargs` 語意**不完整影響使用 `sizeof(args)` 的函式
4. 其餘多數差異（`sort_array` 整數模式、`sscanf` 格式子）都是小幅修補即可解決的問題

對於**自建 mudlib**（如現有 MudScript mudlib）：相容性極高，架構完整。  
對於**移植傳統 LPMud mudlib**：需要處理 `init()` 流程改寫，其他問題多為小修。
