  第一階段：鞏固基礎與協議對接 (Phase 1 & 2 回收與落實)
  目前程式碼中雖然 Driver 已經具備 request_web_edit 與 is_web_client 等 Efun，但指令層與前端尚未完全對接。
   1. 指令層對接：修改 /fsmud/cmds/admin/cmd_edit.c，偵測到 Web 玩家時自動呼叫 request_web_edit()，而非進入舊有的 input_to 循環。
   2. Monaco Editor 導入：更新 index.html，引入 Monaco Editor 並實作 edit_file (Server->Client) 與 save_file (Client->Server) 的處理邏輯。
   3. 編輯狀態管理：在 LPC 層（如 user.c）增加 in_edit() 狀態追蹤，防止多位巫師同時編輯同一檔案導致衝突。
                                    
  第二階段：實作 Phase 3 - 檔案總管與腳手架 (Scaffolding)
  這是本次開發的核心，旨在提升開發效率。
   1. 檔案總管 (File Explorer)：
       * 在 Driver 或 LPC 中實作 ls_json 邏輯，返回 JSON 格式的目錄樹。
       * 在前端 Web IDE 左側建立樹狀目錄導航列。
   2. 腳手架範本 (Scaffolding Templates)：
       * 建立 /secure/daemons/template_d.c 用於管理常用範本（Room, NPC, Item, Command）。
       * 前端「新增檔案」時，彈出對話框讓巫師選擇範本類型。
       * 自動填入基礎結構（如 inherit "/std/room";, create() { ... }），巫師只需填入敘述即可。

  第三階段：安全性加強與自動編譯                                                                                                                  
   1. 權限與安全性：確保 Web 端所有的檔案操作都嚴格通過 valid_read 與 valid_write 檢查，防止目錄逃逸。                                            
   2. 自動 Update 整合：儲存成功後，Server 端自動觸發 update 指令，並將編譯結果（成功或錯誤訊息）即時回傳至前端狀態列。  


  第一步：修復通訊協議 (已完成 ✅)
   * 變動：我已經修改了 driver/efun_wizard.go 中的 request_web_edit。
   * 結果：現在檔案路徑與內容會正確封裝在 payload 欄位中。這修復了之前「網頁編輯器接收到空資料而打不開」的致命 Bug。

  第二步：強化編輯鎖定機制 (待執行 ⏳)
   * 目標：在 hub.go 或 LPC 層實作全域鎖定。
   * 功能：防止兩位巫師同時編輯同一個檔案，避免內容覆蓋。

  第三步：實作編譯錯誤回傳 (待執行 ⏳)
   * 目標：讓網頁編輯器能顯示「存檔失敗」或「第 X 行語法錯誤」。
   * 做法：在執行 save_file 時捕獲 update 指令的輸出結果，並透過 WebSocket 回傳給前端。

  第四步：完善腳手架 (Scaffolding) (待執行 ⏳)
   * 目標：讓「建立新檔」功能更順暢。
   * 做法：確保巫師選擇範本（房間/NPC/物品）後，系統能正確在授權目錄下建立檔案並立刻開啟編輯。
