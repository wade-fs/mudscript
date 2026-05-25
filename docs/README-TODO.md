# MudScript 最強相容性 Efuns 補完建議文件

**版本**：2026.05  
**目標**：讓 MudScript 高度相容 Dead Souls / FluffOS 主流 mudlib（目標相容度 90%+）  
**作者**：MudScript 開發團隊  
**最後更新**：2026-05-25

---

## 1. 補完優先等級總覽

| 優先等級 | 說明 | 預估影響 |
|---------|------|---------|
| **高優先** | 核心系統幾乎必用，缺少會直接導致大量錯誤 | ★★★★★ |
| **中優先** | 大多數 mudlib 常用 | ★★★☆☆ |
| **低優先** | 特定進階功能或優化 | ★☆☆☆☆ |

---

## 2. 高優先 Efuns（建議優先實作）

| 序 | Efun / SimulEfun | 建議實作位置 | 重要性 | 說明 |
|----|------------------|--------------|--------|------|
| 1 | `capitalize(str)` | `/secure/simul_efun.c` | ★★★★★ | 玩家名稱、物品名稱格式化 |
| 2 | `lower_case(str)` | `/secure/simul_efun.c` | ★★★★★ | 與 capitalize 成對 |
| 3 | `member_array(item, arr [, start])` | `/secure/simul_efun.c` | ★★★★★ | 陣列搜尋，極度常用 |
| 4 | `shuffle(array)` | `/secure/simul_efun.c` | ★★★★★ | 隨機掉寶、任務、洗牌 |
| 5 | `element_of(array)` / `random_element(array)` | `/secure/simul_efun.c` | ★★★★☆ | 從陣列隨機取一個元素 |
| 6 | `deep_inventory(ob)` | `/secure/simul_efun.c` | ★★★★☆ | 遞迴取得所有物品（含身上、容器內） |
| 7 | `call_out(func, delay, ...)` | Driver + simul | ★★★★★ | 計時器、狀態、AI、重置 |
| 8 | `remove_call_out(id)` / `find_call_out(id)` | Driver 層 | ★★★★★ | call_out 管理 |
| 9 | `set_heart_beat(flag)` | Driver 層 | ★★★★★ | 生物心跳機制 |
| 10 | `query_ip_name(ob)` / `query_ip_number(ob)` | `/secure/simul_efun.c` | ★★★★☆ | IP 相關管理功能 |

---

## 3. 中優先 Efuns

| 序 | Efun / SimulEfun | 說明 |
|----|------------------|------|
| 11 | `explode(str, delim)` | 字串分割 |
| 12 | `implode(arr, delim)` | 字串合併 |
| 13 | `sprintf(format, ...)` | 格式化輸出（非常重要） |
| 14 | `livings()` | 取得所有生物 |
| 15 | `objects()` | 取得所有物件 |
| 16 | `all_inventory(ob)` | 已支援，建議確認遞迴版本 |
| 17 | `present(str, ob)` | 多層搜尋強化 |
| 18 | `file_size(path)` | 檔案狀態判斷 |
| 19 | `get_dir(path [, flag])` | 目錄列表 |
| 20 | `replace_string(str, from, to [, count])` | 完整版字串替換 |

---

## 4. 低優先 / 進階 Efuns

- `pcre_match()` / `pcre_replace()`
- `compress()` / `uncompress()`
- `localtime(time)` / `gmtime(time)`
- `reclaim_objects()`
- `mud_status()` / `memory_summary()`
- `shadow(ob)` / `unshadow()`
- `replace_program()`
- Socket 相關 efuns（若要做跨服通訊）

---

## 5. 實作建議

### 5.1 `/secure/simul_efun.c` 推薦實作範例

```lpc
// === 字串處理 ===
string capitalize(string str) {
    if (!stringp(str) || str == "") return str;
    return upper_case(str[0..0]) + lower_case(str[1..]);
}

string lower_case(string str) {
    if (!stringp(str)) return str;
    // 若 driver 已有內建，可直接呼叫；否則自行實作
    return str; // 暫時回傳原字串，後續可替換
}

// === 陣列工具 ===
int member_array(mixed item, mixed *arr, int start = 0) {
    if (!arrayp(arr)) return -1;
    for (int i = start; i < sizeof(arr); i++) {
        if (arr[i] == item) return i;
    }
    return -1;
}

mixed *shuffle(mixed *arr) {
    if (!arrayp(arr)) return ({});
    mixed *tmp = copy(arr);
    int i = sizeof(tmp);
    while (i > 0) {
        int j = random(i);
        i--;
        mixed t = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = t;
    }
    return tmp;
}

mixed element_of(mixed *arr) {
    if (!arrayp(arr) || sizeof(arr) == 0) return 0;
    return arr[random(sizeof(arr))];
}

mixed *deep_inventory(object ob) {
    mixed *result = ({});
    if (!ob) return result;
    object *inv = all_inventory(ob);
    foreach (object item in inv) {
        result += ({ item }) + deep_inventory(item);
    }
    return result;
}
```

### 5.2 Driver 端重點強化

- call_out 系列機制
- heart_beat 排程器
- reset_eval_cost()（防止無窮迴圈）

## 6. 驗證與測試流程

- 實作高優先前 10 項
- 執行 tests 指令跑全部測試
- 載入 Dead Souls 的 /std/object.c、/std/living.c 觀察錯誤
- 使用以下指令檢查：
	- lpcefuns()          // 列出目前支援的 efuns
	- call_out_info()  // 檢查 call_out 狀態

## 7. 後續優化方向

- 開發專用 efun_compatibility 測試套件
