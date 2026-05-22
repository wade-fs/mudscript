  1. 核心功能驗證 (Verification)                                                                                       
   * 指令： 既然移除了許多語法，建議對 mudlib 現有的複雜物件（如戰鬥系統 combat.c 或登入流程 login.c）進行全面測試。   
   * 目標： 確保移除 let / fn 等語法後，沒有任何隱藏的腳本錯誤。                                                       
                                                                                                                       
  2. 安全性與權限審核 (Security)                                                                                       
   * 指令： 實作 valid_read 與 valid_write 的完整邏輯。                                                                
   * 目標： 目前雖然有權限檢查框架，但可以針對 shutdown 或 rm 等高風險 efun 建立更嚴密的「管理員 (god)                 
     判定機制」，防止一般玩家越權。                                                                                    
                                                                                                                       
  3. 擴展 LPC 語言特性 (Language Expansion)                                                                            
   * 指令： 實作 call_out（延遲呼叫）或更完整的 mapping 操作函式（如 filter_mapping, map_mapping）。                   
   * 目標： 雖然精簡了核心，但 LPC 強大的地方在於其豐富的內建函式庫（Efuns），這能讓 mudlib 開發更輕鬆。               
                                                                                                                       
  4. 內容開發 (World Building)                                                                                         
   * 指令： 利用目前的自動編譯機制，開始增加新的區域（Area）、更複雜的 NPC 互動任務。                                  
   * 目標： 測試在大量物件載入時，Go Driver 的效能表現與記憶體管理是否穩定。

 🏗️  基礎類別強化摘要：                                                                                                
                                                                                                                       
   1. NPC 智慧化 (std/npc.c)：                                                                                         
       * 好鬥分子：新增 aggressive 標記。當玩家進入房間且該標記開啟時，NPC 會自動發動攻擊。                            
       * 戰鬥記憶：新增 last_attacker 變數。NPC 會記住最後攻擊牠的人，下次見面若血量高於 50% 就會主動「報仇」。        
   2. 房間探索機制 (std/room.c)：                                                                                      
       * 搜尋系統：實作了 search 指令。                                                                                
       * 隱藏元素：支援 add_hidden_element。管理員可以設定隱藏的出口或物品，玩家必須透過搜尋才能發現它們。             
   3. 物品互動性 (std/object.c & std/container.c)：                                                                    
       * 基本旗標：新增 no_get (不可拿取) 與 no_drop (不可丟棄) 屬性。
       * 容器開關：實作了 open / close 邏輯，並能設定 can_open 標記（如寶箱可開，但普通麻袋不行）。
       * 安全取物：支援 get gold from chest 語法，且必須在容器「開啟」狀態下才能取物。

  🗺️  新增展示區域：                                        

   * 幽暗的山腳下 (/area/newbie/secret_entrance.c)：
       * 隱藏著通往北方的入口，需要 search 才能發現。
   * 隱秘的山洞 (/area/newbie/hidden_cave.c)：
       * 裡面住著一隻 飢餓的野狼 (Aggressive)。
       * 角落隱藏著一個 沉重的木箱 (Hidden & No-get)。
   * 沉重的木箱 (/item/treasure_chest.c)：
       * 可以 open / close。
       * 內部放有一堆 金幣，需要使用 get gold from chest 取得。

  🚀 您可以進行的驗證：
   1. 測試搜尋：前往山腳下輸入 search，發現山洞。
   2. 測試好鬥：進入山洞，野狼應該會自動攻擊您。
   3. 測試開關與取物：在山洞 search 找到木箱，嘗試直接 get gold (失敗)，接著 open chest 後再 get gold from chest
      (成功)。


- 玩家:
	- 可以組隊, 自動 follow
- room:
	- 每個主要房間應該都有老闆，可以走動，走到房外可以被砍，要定時重生
- item
	- 可拿、不可拿、不可掉落
	- 裝備、鑑定
	- 升級、鑲嵌
	- 清單顯示
	- 破損、修補、報廢
	- 鍛造
	- 區域地圖
	- 虛擬地圖
- quests
	- 收集徽章
	- 收集物資
	- 戰鬥
	- 升級
	- 遊歷
	- 對答
