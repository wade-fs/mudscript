# P2P Chat 聊天室 (WebRTC Signaling Server)

這是一個基於 Go 語言與 WebSocket 實作的即時通訊與信令伺服器（Signaling Server）。專案目前支援多使用者即時聊天、上下線廣播，並為後續的 WebRTC 點對點（Peer-to-Peer）影音或檔案傳輸打下基礎。

## ✨ 功能特色 (Features)

* **自訂名稱登入**：使用者可輸入自訂名稱進入聊天室，系統會自動分配唯一的 UUID 作為識別。
* **即時狀態廣播 (Presence)**：
  * 當有新使用者加入時，所有在線成員會即時收到「👋 xxx 加入了聊天室」通知。
  * 當使用者關閉分頁或斷線時，系統會自動向所有人廣播「🚪 xxx 離開了」。
* **公開聊天室 (Broadcast Chat)**：支援群發文字訊息，訊息會帶上發送者的名稱即時顯示在所有人的畫面上。
* **自動斷線重連**：前端具備斷線偵測機制，若與伺服器失去連線，會每隔 2 秒自動嘗試重新連線。
* **WebRTC 信令轉發支援**：後端架構已準備好處理 WebRTC 的 `SDP` (Offer/Answer) 與 `ICE Candidate` 點對點信令轉發。

## 🛠️ 技術棧 (Technologies)

### 後端 (Backend)
* **[Go (Golang)](https://go.dev/)**: 核心伺服器邏輯開發。
* **[Gorilla WebSocket](https://github.com/gorilla/websocket)**: 處理 HTTP 升級與高併發的 WebSocket 連線。
* **[Google UUID](https://github.com/google/uuid)**: 為每個連線配發唯一的識別碼。
* **[Pion WebRTC](https://github.com/pion/webrtc)**: Go 語言原生的 WebRTC 實作庫（用於進階 P2P 擴充）。

### 前端 (Frontend)
* **HTML5 / CSS3**: 簡潔的使用者介面。
* **Vanilla JavaScript**: 使用瀏覽器原生的 `WebSocket` API 進行通訊，零前端框架負擔。

## 📁 專案架構 (Project Structure)

```text
p2pchat/
├── cmd/
│   └── p2pchat/
│       └── main.go           # 程式進入點，負責啟動 HTTP 與 WebSocket 路由
├── internal/
│   ├── signaling/            # 信令伺服器核心邏輯
│   │   ├── hub.go            # 負責管理所有 Client 與訊息廣播 (Broadcasting)
│   │   ├── client.go         # 處理單一 WebSocket 連線的讀寫迴圈
│   │   └── message.go        # 定義客戶端與伺服器間傳遞的 JSON 結構
│   ├── webrtc/               # WebRTC 相關配置 (ICE Servers 等)
│   └── room/                 # 多房間管理邏輯 (擴充用)
└── web/
    └── static/
        └── index.html        # 前端聊天室網頁
```
