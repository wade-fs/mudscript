   * P2P
       * 整個 mudlib 新建的角色身分一定是 "god", 因此在建立 god 前，請先為 mudlib 命名，規則如下
           * mudlib 名稱一定是英文單字，最多四個，總長最多64個字母
           * 因為是有加入 hub, 由 hub 統一 mudlib 識別字的唯一性，譬如 "fantasy space" 識別字 "fantasy.space"
           * 本 mudlib 的名稱就叫 'fantasy space' 也就是識別字 'fantasy.space' 由本 mudlib 占用，其它人無法再使用
       * 新增 3 個命令 fsjoin fsleave fsflush，要實作可以跨服，想法如下:
           * 不事先 clone area, 只在第一次需要時才從遠端 clone, 包含 room, item, npc
           * clone data 存在本地端緩存
           * 當執行 fsleave 時，清空該遠端 mudlib 的 clone data
           * 當執行 fsflush 時，重新 cloned remote area
       * 玩家資料:
           * 可能每個人就類似 email 那樣識別？譬如 wade@fantasy.space 由我獨占
           * 如果有更好的解決辦法也可以提出解決
