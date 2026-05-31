# MudScript Legacy LPC 解譯能力評估表 (2026-05-29)

本文件紀錄了 MudScript 引擎對 20 年前 ES2 (Legacy) Mudlib (`fs/`) 的相容性評估與目前的開發進度。

## 1. 核心語法與解譯能力 (Core Language)

| 項目 | 狀態 | 詳細說明 |
| :--- | :--- | :--- |
| **基礎型別與運算** | 🟢 Stable | 支援 `int`, `string`, `float`, `mapping`, `array` 與邏輯運算。 |
| **Preprocessor** | 🟢 Stable | 支援 `#include` (含循環保護), `#define`, `#ifdef`, `#if`。 |
| **繼承機制 (Inherit)** | 🟢 Stable | 實作 DAG Resolver，解決鑽石繼承與重複初始化問題，支援 `::func()`。 |
| **Switch 範圍判斷** | 🟢 Stable | 實作 `case 0..100:` 語法。 |
| **函式指標呼叫** | 🟢 Stable | 支援 `(*fn)(args)` 與 `evaluate(cl, args)` 語法。 |
| **真假值判斷** | 🟢 Stable | 與 Legacy 標準對齊：空陣列/Mapping 視為 **TRUE**，未初始化為 **0**。 |

## 2. 系統內建函式 (Efuns) 與 Driver 架構

| 項目 | 狀態 | 詳細說明 |
| :--- | :--- | :--- |
| **物件管理** | 🟢 Stable | 支援 `clone_object`, `destruct`, `load_object`。 |
| **UID/EUID 系統** | 🟢 Stable | 實作 `getuid`, `geteuid`, `seteuid`, `export_uid`。 |
| **心跳系統** | 🟢 Stable | **集中式分層 Daemon 排程器** (Native Go 實作)。 |
| **原生心跳** | 🟢 Stable | `fs/obj/user.c` 心跳邏輯已原生化，大幅降低記憶體負擔。 |
| **網路 Socket** | 🔴 Missing | `socket_*` 系列函式尚未實作。 |
| **Panic 恢復** | 🟢 Stable | 全系統 Panic 恢復機制，避免 Driver 僵死。 |

## 3. 待解決的關鍵議題 (Critical Issues)

1.  **登入流程中斷 (Visibility Issues)**
    *   **現狀**: 在輸入帳號密碼後，進入新手村的流程似乎中斷。
    *   **風險**: `input_to` 的 `InputHidden` 狀態可能遮蔽了關鍵的系統提示，導致無法確認流程是否因錯誤而卡住。
2.  **Legacy 持久化格式 (.o)**
    *   **風險**: 需實作 `.o` 格式的解析與寫入，目前僅支援 JSON。
3.  **Socket Efuns**
    *   **風險**: Legacy 部分功能深度依賴 socket 通訊。

---

## 歷史里程碑
*   **2026-05-29**:
    *   (早) `guest` 登入流程通暢。
    *   (中) 實作 DAG Resolver 與真假值標準對齊。
    *   (晚) 實作 Native Heartbeat Scheduler 與 Panic Recovery，現代 Mudlib 穩定度達 100%。
