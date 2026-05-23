第一步：準備一個可從外網存取的「信令中心 (Hub)」                                                                      
  由於 P2P 建立連線前需要互相交換資訊，必須有一個雙方都能連上的中轉點。                                                 
   * 方法 A (簡單測試)：使用 Ngrok 或是 Cloudflare Tunnel。                                                             
      在您的 Hub 電腦執行：ngrok http 8080。                                                                            
      Ngrok 會給您一個網址，例如 https://xyz.ngrok-free.app。                                                           
   * 方法 B：如果您有公網 IP 的雲端主機（如 AWS, GCP），直接在上面執行 ./bin/fsmud。                                    
                                                                                                                        
  第二步：啟動本機節點 (Node A)                                                                                         
  假設 Hub 網址是 ws://xyz.ngrok-free.app/ws：                                                                          
                                                                                                                        
   1 ./bin/fsmud --port 8080 --hub ws://xyz.ngrok-free.app/ws

  第三步：啟動另一個網路的節點 (Node B)
  在另一台電腦執行：

   1 ./bin/fsmud --port 8080 --hub ws://xyz.ngrok-free.app/ws

  第四步：驗證
   1. 兩邊各自開啟瀏覽器登入自己的 MUD。
   2. 在 Node A 輸入 is 哈囉，我來自台灣！。
   3. 如果 Node B 的畫面出現紫色前綴的 【星際】Anonymous：哈囉，我來自台灣！，則代表 P2P 跨網通訊成功。

  ---

  技術備註：
   * 對稱型 NAT：如果雙方的網路都是極度嚴格的企業級防火牆（Symmetric NAT），單靠 STUN 可能無法穿透，這時需要 TURN
     伺服器（流量中轉）。
   * 目前的配置：我已經在 internal/webrtc/config.go 中預留了 TURN
     的設定空間，但在一般家用網路（如中華電信、凱擘）中，目前的 STUN 配置通常就能直接連通。

  這套系統的目標是：「每個人在家執行伺服器，就能自動編織成一個巨大的全球 MUD 宇宙。」

