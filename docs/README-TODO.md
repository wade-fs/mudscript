# 我把需求定義如下：

- 目標就是通過 hub site 串連基於 mudscript 建立的星際網路
- 每一個人都可以透過 clone mudscript 建立一個專屬的 edge site
- 我的想法是把每一個 edge site 當成一般個人電腦，可以ssh 到遠端(其它 edge site or hub site)，edge site此時會知道自己登入到遠端，所有命令都是送到遠端執行，
- 遠端執行完的結果訊息再傳送回主機(edge site)
- 因為這是虛擬世界，就像作夢，一旦登入遠端就是一個虛擬身體，如剛出生的嬰兒，一旦返回，則回復原來的身分。可以想像成作夢，也可以想像成平行時空
- 登臨遠端就像投胎，一切從0開始，返回原來的世界就像夢醒一般。
- 所以應該先定義通訊協定與資料結構，如果你評估這樣的作法可行的話，再開始實作。 我是想像成在進行遠端桌面或是 ssh 那樣，身分是遠端的，而不是帶著身體登臨異界，只是轉世而不是整個身體重生。
- 所以本質上是：本機 = SSH client，遠端 = SSH server，不是把遠端地圖抓下來本機跑。
- 遠端身分：玩家在遠端是全新帳號（沒有等級、物品），還是只是「訪客名牌」顯示原來的名字？
	- A: 如果設計完整的話，身分識別可以保留，但是相當於全新帳號，每個人都是 name@mudlib_id
- 離線後：訪客身分是否保留？還是離開就消滅（像 guest session）？
	- A: 可以由每個 edge site 定義自己的站台要不要保留來客身體資訊，預設是消滅
- 遠端限制：遠端站長能否設定「訪客不能做某些事」？
	- A: 因為執行面都是在遠端，譬如你 ssh 到遠端，就是遵守遠端機器的規定，一切就像投胎
- 本機 hub 斷線：如果 hub 中斷，已經在遠端的玩家是繼續留著，還是被踢出？
	- A: 因為我假定每個 Edge Site 都是在防火牆後面，因此無法直接相通，如果能做到直接通相通，那答案就是可以繼續互通，如果一切靠 hub 轉發，那當然就斷線、清空資料
- 補充：我的想法只是每個 Edge Site 就像私人的後花園，可以請別人來玩，當然也可以禁止特定玩家來玩，不是完全開放的
- 身分格式： wade@wade.mud（訪客在遠端以此身分存在）

---

# 遺留系統相容計畫 (Legacy fs/ Mudlib Compatibility)

為了讓具有 30 年歷史的 `fs/` (MudOS 0.9.20 架構) 能夠在 MudScript 引擎上運行，後續開發步驟如下：

## 1. 驅動程式擴展 (Go Driver)
- **啟動參數增強**：
  - [ ] 在 `cmd/fsmud/main.go` 增加 `-global_include` 參數，對應 `config.GlobalInclude`。
  - [ ] 增加 `-simul_efun` 參數，允許手動指定 `simul_efun.c` 的路徑。
- **內建函式 (Efuns) 補完**：
  - [ ] 支援 `efun::` 語法空間。
  - [ ] 實作或 Stub 掉 `fs/` 依賴的關鍵內建函式（如 `read_bytes`, `write_bytes`, `resolve_path` 等）。
- **權限與 UID 系統**：
  - [ ] 強化目前的 `getuid`/`geteuid` 模擬邏輯，使其能與 `fs/` 的安全機制對接。

## 2. Mudlib 腳本調整 (LPC Scripts)
- **入口函式相容**：
  - [ ] 調整 `fs/adm/obj/master.c` 的 `connect` 函式，使其能處理引擎傳入的 `string` 型別參數。
- **錯誤排除 (Bug Fixing)**：
  - [ ] 針對啟動時的 Runtime Error 進行逐一排除，修復因語法微差導致的解析問題。

## 3. 環境與部署
- **啟動指令範例**：
  ```bash
  go run ./cmd/fsmud -mudlib=fs -master=/adm/obj/master.c -global_include=globals.h -simul_efun=/adm/obj/simul_efun.c
  ```
- **編碼檢查**：
  - [ ] 確認所有 `.c` 與 `.o` 檔案已正確轉換為 UTF-8 編碼。

# 協定設計
## 連線生命週期：
1. HANDSHAKE    本機 → hub → 遠端：請求建立 session
2. SESSION_ACK  遠端 → hub → 本機：同意 + 分配訪客身分
3. INPUT        本機 → hub → 遠端：玩家每一行輸入
4. OUTPUT       遠端 → hub → 本機：執行結果文字
5. DISCONNECT   任一方 → hub → 另一方：結束 session
## 訊息格式（每則都走 hub 轉發）：
	- fs_session|from_mudlib|to_mudlib|msg_type|session_id|payload
```
msg_type |   方向    | payload
---------|-----------|----------
connect  | 本機→遠端 | player_name|display_name
ack      | 遠端→本機 | session_id\|welcome_text
deny     | 遠端→本機 | reason
input    | 本機→遠端 | session_id\|command
output   | 遠端→本機 | session_id\|text
disconnect | 雙向    | session_id\|reason
```
