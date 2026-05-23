# 🚀 MudScript 雲端部署指南 (Hugging Face Spaces 版)

這份指南將引導您將 `fsmud` 作為全域「星際信令中心 (Signaling Hub)」部署到免費的雲端空間。

## 1. 申請帳號與空間
1.  註冊 [Hugging Face](https://huggingface.co/) 帳號。
2.  點擊右上角 **New Space**。
3.  設定 **Space Name** (例如：`fsmud-hub`)。
4.  **SDK** 選擇 **Docker**。
5.  **Template** 選擇 **Blank**。
6.  隱私設定選 **Public** (公開)。
7.  點擊 **Create Space**。

## 2. 上傳程式碼
您可以直接透過瀏覽器上傳檔案，或者使用 Git。
您需要確保 Space 根目錄包含以下內容：
- `Dockerfile` (我已經幫您準備好了)
- `go.mod`, `go.sum`
- 所有 `.go` 源碼資料夾 (`driver/`, `evaluator/`, `internal/` 等)
- `mudlib/` 資料夾
- `web/` 資料夾
- `Makefile`

一旦檔案上傳，Hugging Face 會自動開始執行 **Building**。

## 3. 取得您的全域 Hub 網址
1.  部署成功後，您的 Space 會顯示 **Running**。
2.  點擊網頁右上角的 **... (Embed this space)**。
3.  您會看到一個網址，通常格式為：`https://<your-username>-<space-name>.hf.space`。
4.  您的 **P2P 信令網址** 就是將其改為 WebSocket 格式：
    - `wss://<your-username>-<space-name>.hf.space/ws`

## 4. 本機連結至雲端 Hub
現在，您與您的朋友只要在本機執行以下指令，就能互通了：
```bash
./bin/fsmud --hub wss://<your-username>-<space-name>.hf.space/ws
```

---

## 💡 為什麼選擇 Hugging Face？
- **免費且強大**：提供穩定的 CPU 資源。
- **HTTPS 支援**：自動提供 SSL 憑證。
- **Docker 彈性**：我們可以精確控制運行環境。
- **不會自動休眠**：只要有人訪問網址，它就會一直保持運行。
