# MudScript Efun 相容性評估清單

> 對比對象：LDMud 3.x、FluffOS（MudOS 後繼）、Lima Bean lib、GodWars2 lib  
> 圖例：✅ 完全相容　⚠️ 語意差異　❌ 缺漏　➕ MudScript 擴充

---

## 整體相容性概覽

| 目標 Driver / Mudlib | 相容性估計 |
|---|---|
| LDMud 3.x | 62% |
| FluffOS / MudOS | 71% |
| Lima Bean lib | 55% |
| GodWars2 lib | 68% |

---

## 1. 物件與環境（Object & Environment）

| Efun | 狀態 | 說明 |
|---|---|---|
| `this_player()` | ✅ 完全相容 | 標準，完全符合 |
| `this_object()` | ✅ 完全相容 | 標準，完全符合 |
| `environment()` | ✅ 完全相容 | 標準，完全符合 |
| `move_object()` | ⚠️ 語意差異 | 僅支援單/雙參形式，無 LDMud 的 `move_object` driver hook 機制 |
| `clone_object()` | ✅ 完全相容 | 標準，自動補 `.c` 副檔名 |
| `load_object()` | ✅ 完全相容 | MudOS 風格；LDMud 慣用 `find_object` + 自動載入 |
| `destruct()` | ✅ 完全相容 | 標準 |
| `present()` | ✅ 完全相容 | 標準 |
| `find_object()` | ✅ 完全相容 | 標準 |
| `object_name()` | ✅ 完全相容 | 標準，回傳格式 `path#id` |
| `call_other()` | ✅ 完全相容 | 標準，支援 `->` 語法糖 |
| `all_inventory()` | ✅ 完全相容 | 標準 |
| `deep_inventory()` | ✅ 完全相容 | 標準 |
| `find_player()` | ✅ 完全相容 | 標準 |
| `users()` | ✅ 完全相容 | 標準 |
| `living()` | ✅ 完全相容 | 標準 |
| `userp()` | ✅ 完全相容 | 標準 |
| `enable_commands()` | ✅ 完全相容 | 標準 |
| `query_verb()` | ✅ 完全相容 | 標準 |

---

## 2. 排程與時間（Time & Scheduling）

| Efun | 狀態 | 說明 |
|---|---|---|
| `call_out()` | ✅ 完全相容 | 標準 |
| `remove_call_out()` | ✅ 完全相容 | 標準 |
| `set_heart_beat()` | ✅ 完全相容 | 標準，MudScript 有智慧心跳優化（有人才跳動） |
| `time()` | ✅ 完全相容 | 標準 Unix 時間戳 |
| `ctime()` | ✅ 完全相容 | 標準 |
| `call_out_info()` | ❌ 缺漏 | LDMud/FluffOS 標準 efun，可查詢所有排程中的 call_out |
| `input_to()` | ❌ 缺漏 | 登入流程、密碼輸入、對話系統的基礎，未實作 |

---

## 3. 資料結構與函數式（Data Structures & Functional）

| Efun | 狀態 | 說明 |
|---|---|---|
| `sizeof()` | ✅ 完全相容 | 標準，支援 array / string / mapping |
| `explode()` | ✅ 完全相容 | 標準 |
| `implode()` | ✅ 完全相容 | 標準 |
| `member_array()` | ✅ 完全相容 | 標準；FluffOS 別名為 `member()` |
| `filter()` | ✅ 完全相容 | 通用，支援 Array 與 Mapping |
| `filter_array()` | ✅ 完全相容 | `filter()` 的 array 特化版 |
| `filter_mapping()` | ✅ 完全相容 | `filter()` 的 mapping 特化版 |
| `map()` | ✅ 完全相容 | 通用，支援 Array 與 Mapping |
| `map_array()` | ✅ 完全相容 | `map()` 的 array 特化版 |
| `map_mapping()` | ✅ 完全相容 | `map()` 的 mapping 特化版 |
| `sort_array()` | ✅ 完全相容 | 標準，支援 closure 比較函式 |
| `unique_array()` | ✅ 完全相容 | 標準，回傳二維分組陣列 |
| `keys()` | ✅ 完全相容 | 標準 mapping 操作 |
| `values()` | ✅ 完全相容 | 標準 mapping 操作 |
| `m_delete()` | ✅ 完全相容 | 標準 |
| `evaluate()` / `apply()` | ✅ 完全相容 | closure 執行，支援 `$1`/`$2` 匿名參數語法 |
| `m_add()` | ❌ 缺漏 | LDMud 標準，合併兩個 mapping |
| `allocate()` | ❌ 缺漏 | 預分配指定長度陣列，多數 mudlib 依賴 |
| `copy()` | ❌ 缺漏 | 深層複製物件/陣列，mudlib 常用 |

---

## 4. 字串處理（Strings）

| Efun | 狀態 | 說明 |
|---|---|---|
| `sprintf()` | ✅ 完全相容 | 標準 C 風格格式化，含 `%O` 物件擴充 |
| `strlen()` | ✅ 完全相容 | 標準 |
| `substr()` | ✅ 完全相容 | 標準 |
| `lower_case()` | ✅ 完全相容 | 標準 |
| `upper_case()` | ✅ 完全相容 | 標準 |
| `capitalize()` | ✅ 完全相容 | 標準 |
| `trim()` | ✅ 完全相容 | 標準，支援自訂 cutset |
| `replace_string()` | ✅ 完全相容 | 標準，全部替換 |
| `strsrch()` | ✅ 完全相容 | MudOS/FluffOS 風格字串搜尋 |
| `pad_str()` | ➕ MudScript 擴充 | CJK 全形字元寬度計算，標準 driver 無此 efun |
| `crypt()` | ⚠️ 語意差異 | MudScript 使用 SHA-256；傳統 `crypt()` 為 DES 或 bcrypt，兩者雜湊結果不相容 |
| `regexp()` | ❌ 缺漏 | LDMud/FluffOS 核心 efun，大量 mudlib 的文字解析依賴此功能 |
| `sscanf()` | ❌ 缺漏 | **影響最大的缺漏**。幾乎所有 mudlib 的指令解析都用 `sscanf`，缺少此 efun 會導致大量現有 mudlib 程式碼無法執行 |
| `break_string()` | ❌ 缺漏 | 文字排版標準 efun，按指定寬度折行 |

---

## 5. 型別判斷與數學（Type Predicates & Math）

| Efun | 狀態 | 說明 |
|---|---|---|
| `intp()` | ✅ 完全相容 | 標準 |
| `stringp()` | ✅ 完全相容 | 標準 |
| `floatp()` | ✅ 完全相容 | 標準 |
| `objectp()` | ✅ 完全相容 | 標準 |
| `mappingp()` | ✅ 完全相容 | 標準 |
| `arrayp()` | ✅ 完全相容 | 標準 |
| `nullp()` | ✅ 完全相容 | 標準，`nil` 或整數 `0` 均回傳真 |
| `errorp()` | ✅ 完全相容 | 標準 |
| `to_int()` | ✅ 完全相容 | 標準型別轉換 |
| `to_string()` | ✅ 完全相容 | 標準型別轉換 |
| `to_float()` | ✅ 完全相容 | 標準型別轉換 |
| `abs()` | ✅ 完全相容 | 標準 |
| `random()` | ✅ 完全相容 | 標準 |
| `json_encode()` | ➕ MudScript 擴充 | JSON 序列化，標準 driver 無此 efun |
| `functionp()` | ❌ 缺漏 | closure/function 型別謂詞，mudlib 常用 |
| `pointerp()` | ❌ 缺漏 | `arrayp()` 的 LDMud 別名，部分 mudlib 使用此名稱 |

---

## 6. 系統、檔案與持久化（System, Files & Persistence）

| Efun | 狀態 | 說明 |
|---|---|---|
| `read_file()` | ✅ 完全相容 | 標準 |
| `write_file()` | ✅ 完全相容 | 標準，支援 append / overwrite |
| `file_size()` | ✅ 完全相容 | 標準，不存在回傳 -1，目錄回傳 -2 |
| `get_dir()` | ✅ 完全相容 | 標準，支援 glob 萬用字元與遞迴掃描 |
| `shutdown()` | ✅ 完全相容 | 標準 |
| `exec()` | ✅ 完全相容 | TCP 連線轉移，登入系統必備 |
| `getenv()` | ✅ 完全相容 | 標準 |
| `save_object()` | ⚠️ 語意差異 | MudScript 使用 **JSON** 格式；傳統 driver 使用自訂 `.o` 格式，兩者的存檔不可互通 |
| `restore_object()` | ⚠️ 語意差異 | 同上，JSON 格式而非傳統格式 |
| `rm()` | ❌ 缺漏 | 刪除檔案，mudlib 管理工具常用 |
| `rename()` | ❌ 缺漏 | 檔案改名/移動 |
| `mkdir()` | ❌ 缺漏 | 建立目錄，mudlib 常用 |
| `cp()` | ❌ 缺漏 | 複製檔案 |

---

## 7. 重大架構層缺漏（影響 Mudlib 可移植性）

以下功能並非單純 efun，而是影響整個 mudlib 運作模式的**架構層機制**。

| 功能 | 狀態 | 影響說明 |
|---|---|---|
| `write()` / `say()` / `tell_object()` / `tell_room()` | ❌ 確認狀態 | 訊息輸出的核心 efun。幾乎所有 mudlib 物件（room、npc、item）都直接呼叫這些名稱。若非以 driver 層 efun 方式提供，外部 mudlib 程式碼無法無縫接入。 |
| `add_action()` / `command()` | ❌ 確認狀態 | LPC 指令系統的核心。所有 mudlib 的 room/Npc/item 都靠 `add_action` 掛接動詞。目前 MudScript 有 `enable_commands` 與 `query_verb`，但 `add_action` 的完整 driver 層語意需確認。 |
| `sscanf()` | ❌ 缺漏 | 補實作後可解鎖最多現有 mudlib，幾乎所有 LPC 指令解析都依賴此 efun。 |
| `input_to()` | ❌ 缺漏 | 登入流程、密碼輸入、menu 系統的基礎。沒有此 efun，任何現有 mudlib 的 `login.c` 均無法直接使用。 |
| `catch()` / `throw()` | ⚠️ 確認狀態 | LPC 錯誤處理標準語法。MudScript 目前的錯誤模型是否與傳統 LPC 的 `catch(){}`語塊完全相容，需進一步確認。 |
| `simul_efun` 物件機制 | ⚠️ 確認狀態 | 幾乎所有主流 mudlib（Lima、GodWars、Discworld 等）都靠 `simul_efun` 擴充 efun 集以橋接 driver 差異。`master.c` 中是否有此機制需要確認。 |
| `inherit_file()` master 回調 | ❌ 缺漏 | LDMud 特有，控制 `inherit` 路徑解析，LDMud 系 mudlib 依賴此機制。 |

---

## 8. 補實作優先級建議

| 優先 | Efun / 機制 | 理由 |
|---|---|---|
| 🔴 最高 | `sscanf()` | 補了就能解鎖最多現有 mudlib，幾乎所有指令解析依賴 |
| 🔴 最高 | `input_to()` | 任何現有 mudlib 的登入系統必備 |
| 🔴 最高 | `add_action()` driver 層確認 | mudlib 指令系統的根基 |
| 🟠 高 | `simul_efun` 物件支援 | 讓 mudlib 自行橋接 driver 差異，最彈性的解法 |
| 🟠 高 | `regexp()` | 文字解析常用，Lima/CD mudlib 大量使用 |
| 🟡 中 | `allocate()` / `copy()` | 部分 mudlib 依賴，補上可提升相容性 |
| 🟡 中 | `rm()` / `mkdir()` / `rename()` | 巫師工具與 mudlib 管理功能 |
| 🟢 低 | `call_out_info()` | 偵錯用途，非核心功能 |
| 🟢 低 | `break_string()` | 文字排版，可在 simul_efun 層補 |
| 🟢 低 | `functionp()` / `pointerp()` | 可在 simul_efun 層補別名 |
