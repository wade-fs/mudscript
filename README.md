# MudScript: Fantasy Space MUD Engine

MudScript 是一個基於 Go 語言實作的高效能 MUD (Multi-User Dungeon) 引擎，結合了傳統 LPC 腳本語言的彈性與現代 Web 技術。它不僅僅是一個直譯器，更是一個完整的虛擬世界伺服器。

## 🚀 核心特色

- **強大的 LPC 直譯器**：支援多重繼承、複雜巨集展開（含參數巨集）、以及 LPC 風格的陣列/字串切片語法 `[start..end]`。
- **混合式檔案系統 (Hybrid FS)**：支援將整個 `mudlib` 嵌入執行檔中，實現「單一檔案分發」，同時保留外部磁碟覆蓋機制，支援熱更新與開發調試。
- **現代化 Web 介面**：內建基於 WebSocket 的網頁前端，支援點擊式互動、自動 ID 標註、以及小地圖顯示。
- **高效能 NPC 系統**：實作了智慧型心跳（有人才跳動）、多種族屬性加成、以及基於話題的 `ask` 詢問對話系統。
- **安全防護**：全自動 HTML Sanitization，徹底杜絕 XSS 攻擊，並具備並發安全的環境變數管理。

## 🛠️ 技術棧

- **Backend**: Go 1.26.2 (使用 `embed` 資源封裝)
- **Frontend**: Vanilla JS / HTML5 / CSS Grid (具備終端機與 UI 雙模式)
- **Scripting**: LPC-like 腳本 (位於 `/mudlib`)
- **Protocol**: WebSocket & WebRTC (信令伺服器支援)

## 📦 如何編譯

專案提供了一個強大的 `Makefile`，支援 Linux 與 Windows 跨平台編譯。

### 編譯 Linux 版本
```bash
make fsmud
```

### 編譯 Windows 版本 (.exe)
```bash
make fsmud.exe
```

編譯產物將存放在 `bin/` 目錄中。

## 🎮 快速開始

1. **啟動伺服器**：
   ```bash
   ./bin/fsmud
   ```
2. **登入遊戲**：開啟瀏覽器訪問 `http://localhost:8080`。
3. **建立角色**：輸入帳號後，系統將引導您選擇**物種 (Race)** 與 **天性 (Nature)**，這將影響您的初始能力值與技能。

## 🗺️ 世界觀：新手村 (Newbie Town)

目前的 `mudlib` 包含了一個完整 8x8 規模的新手城鎮：
- **中央廣場 (4,4)**：出發與重生的中心點。
- **冒險者公會 (4,5)**：找會長艾德蒙打聽消息、承接任務。
- **鐵匠鋪 (3,4)**：矮人索林經營，提供強力的兵器。
- **煉金藥劑店 (4,3)**：精靈艾拉經營，販售各類恢復藥劑。

## 💬 NPC 互動指南

在 MudScript 中，您不需要辛苦輸入中文名稱。
- **查看**：輸入 `look` 會看到 NPC 及其 ID，例如 `[公會會長 艾德蒙(edmund)]`。
- **點擊**：在網頁上直接點擊 NPC 名稱即可自動執行 `look`。
- **詢問**：使用 `ask <ID> <話題>`。例如：
    - `ask edmund help` (尋求幫助)
    - `ask edmund job` (詢問工作)
    - `ask edmund topics` (列出所有可聊的話題)

## 📂 目錄結構與文件

- `/cmd`: 伺服器進入點 (fsmud)。
- `/driver`: MUD 引擎核心與 Efun 實作。
- `/evaluator`: LPC 腳本執行器與語法樹處理。
- `/mudlib`: 遊戲內容 (房間、NPC、指令、標頭檔)。
- `/web/static`: 前端網頁資源。
- [**Efuns 參考手冊**](docs/README-efuns.md)：完整的內建函式清單與用法說明。

## 📜 授權

本專案基於 MIT 授權協議開放原始碼。
