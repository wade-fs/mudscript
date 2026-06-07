# 🚀 現代化 Web IDE 開發計劃 (Roadmap)

## 🎯 目標
將 MudOS 傳統且難用的 `ed()` 行編輯器，轉型為整合在網頁前端的現代化開發環境。

## 🏗️ 架構設計

### 1. 前端：Monaco Editor 整合
- **編輯器**：使用 VS Code 同款的 Monaco Editor。
- **語法高亮**：基於 C 語言擴充 LPC 特有關鍵字（`inherit`, `mixed`, `object` 等）。
- **檔案瀏覽器**：在側邊欄建立樹狀目錄。
- **多分頁支援**：允許同時編輯多個檔案。

### 2. 通訊協議 (WebSocket Types)
- **開啟檔案**：
  - `Server -> Client`: `{ "type": "edit_file", "path": "/u/wade/workroom.c", "content": "..." }`
- **儲存檔案**：
  - `Client -> Server`: `{ "type": "save_file", "path": "/u/wade/workroom.c", "content": "..." }`
- **狀態通知**：
  - `Server -> Client`: `{ "type": "compile_error", "file": "...", "line": 10, "msg": "..." }`

### 3. 驅動層支援 (Driver Efuns)
- `request_web_edit(path)`: 讀取檔案並觸發前端編輯。
- `save_web_file(path, content)`: 接收前端回傳並寫入硬碟。
- `in_edit(me)`: 維持傳統 LPC 狀態鎖定。

### 4. 檔案建立範本 (Scaffolding Templates)
針對「新增檔案」場景，提供引導式範本，避免從零開始撰寫重複的基礎結構：
- **選擇類型**：新增檔案時，可選擇「房間 (Room)」、「NPC」、「物品 (Item)」或「指令 (Command)」。
- **自動產生結構**：根據選擇，自動帶入對應的 `inherit` 與 `create()` 基礎框架。
- **靈活性**：範本產生後，巫師仍可透過文字編輯器自由修改所有細節。

## 🛠️ 執行階段

### 第一階段：基礎通訊與簡單 TextArea (已規劃)
- 實作 WebSocket 的 `edit_file` / `save_file` 路由。
- 在網頁建立基礎面板。

### 第二階段：Monaco Editor 導入
- 替換為高效能編輯器。
- 實作 `Ctrl+S` 自動觸發 `update` 指令。

### 第三階段：安全性與檔案總管
- 整合 `valid_read` / `valid_write` 權限檢查。
- 實作網頁端目錄瀏覽。

## 📜 巫師指令變更
- `/cmds/std/ed.c` 將檢測玩家連線類型。
- 若為 Web 玩家，則導向 `request_web_edit()` 而非進入舊版行編輯模式。

## TODO
- 建立新檔時，提供 Template, 先選定類型，再根據 Template 來編輯
