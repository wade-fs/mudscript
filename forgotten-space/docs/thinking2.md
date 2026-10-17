奇遇稀有性與 quests/ 研究

讀取範圍： 第 1~7 章和卷綱我讀得最完整。第 8~14 章只用關鍵字掃描加讀關鍵段落，沒有逐字讀完；第 15~33 章只有大綱。程式部分是靜態分析，加上我寫的驗證腳本和模擬，沒有在 MUD 上實跑。

一、小說怎麼製造「稀有」

小說不靠機率，而是靠多個條件同時成立。下表右欄是 MUD 現況：

層	小說依據	MUD 現況
世界窗口	第 1 章：枯水、山洪去垢、晨光、低角側光，作者明說是「萬古巧合」	判定本身不檢查時辰，晨光只影響 look_at_item 的描述文字
個人感應	第 1 章的「認知鋼印」，凡人和修士都看不見	只有「身世鎖加天命門檻」，且天命門檻只在 stargaze_altar 真正生效（道童要先拿到松下晶石的 +1）
代價	第 3 章墜入死沼、第 4 章盲眼道人自毀雙目	只扣體力或神識，且一定會恢復，沒有失敗分支
人情	第 5 章：莫三藏了三十年，要沈泥聽風辨器加上託付才起得出	柴房 search wood 只看身世，與莫三的信任度無關
互補	第 9 章五片拼合才完整	dark_alley 已有 compare_map 事件，但沒有任何任務使用

目前所有門檻都是角色的靜態屬性，沒有一個依賴世界的隨機性、時間窗或稀缺性。符合身世的角色，十分鐘內必定拿到遺物，等於是新手禮包。

另一個設計問題是，第 11 章老道明說：「這不是天命……這是人定勝天！」小說主題否定「天命賜予」，但 MUD 把「天命 +1」當成奇遇的主要獎勵與門檻。這需要你決定要不要統一，我傾向把它改成「由有代價的選擇累積的共鳴」，而不是抽籤式的天賦。

二、窗口實際多常出現

我複製了 nature_d 的天氣轉移和 world_state_d 的水位邏輯，在 Python 裡跑了 40 次、每次 1500 遊戲日：

山洪平均每 1.7 遊戲日（約 10 現實小時）就發生一次。
小說版的「水退石出加晴朗破曉」窗口，出現在約 39% 的遊戲日，平均每 0.6 現實天一次。
冬季因為天氣模型只在非冬季從陰天轉成雨，所以山洪完全不會發生。
把洪水門檻從 85 調到 100、有效時數從 24 縮到 6，也只能讓窗口降到約 19% 的遊戲日。水位是會飽和的計數器，雨期一連鎖就頂到上限。

所以稀有窗口不該靠天氣湧現，要改成獨立排程的世界事件。

三、quests/ 的合理性
問題	證據
30 個步驟中有 11 個引擎永遠收不到事件	全專案只有 8 處 trigger_event 呼叫點。deliver 事件完全沒人送出；wash、trap、sharpen 等動作也沒有房間送出
其中非職業鏈的真 bug	cycle_of_craft 第 1 步 gather herb 沒有任何房間送出；rescue_maiden 第 2 步 search boards，dark_alley 有這個指令，但只送出 compare_map
職業鏈的 JSON 是裝飾	三條鏈的實際推進在 CAREER_D 與各 NPC 的硬編碼裡，兩套系統共用 task_chain/*_stage 這個鍵，靠巧合沒有衝突
ancient_order 終局獎勵不會發放	獎勵寫在最後一個 stage 的 rewards，引擎只讀頂層 rewards 和 on_finish
出鄉路引兩套並存	village_pass 要找 elder，但全專案沒有這個 NPC；實際發路引的是舊系統，在四個 NPC 裡各自硬編碼；cmd_quest 還把舊任務隱藏，所以任務列表會顯示一個無法啟動的任務
fa_chain 第 1、4 步地點不符	JSON 寫 /d/village/temple，實際房間是 daoist_temple
欄位被靜默忽略	category、total_stages、need_stage 沒人讀，載入時也不報錯
稀有道具可無限補領	莫三補發天門引沒有次數、代價或冷卻，連任務進入休眠後也還能領
狀態分散在四處	personal_event/*、quests/<id>/*、task_chain/*、舊的 quest/pass_village_ceremony

docs/thinking.md 有幾項已與現行程式不符：pot 獎勵現在有處理，kill 事件也有分支和防重複計數。另外，我的驗證器曾把 lu 和 zhao si 誤報成不存在，我查過 set_id 後確認它們是存在的，已排除。

四、稀有奇遇設計

1. 窗口改成排程事件。 在 world_state_d 加上 windows["stele_dawn"]，以卜瓦松（Poisson）隨機排程，例如平均 20~30 現實天一次、開放約 60 現實分鐘（一個破曉的長度）。

2. 門檻統一成資料。 把 MYSTERY_D 的註冊表搬到 quests/encounter/*.json，由引擎的單一函式判定。草案如下：

```json
{
  "id": "enc_stele_dawn",
  "scope": { "type": "world_slots", "slots": 3, "per": "season" },
  "gates": [
    { "type": "world_window", "id": "stele_dawn" },
    { "type": "background", "any": ["herbalist"] },
    { "type": "resonance", "min": 2 },
    { "type": "cost", "vital": "sen", "amount": 10,
      "backlash": { "chance": 0.3, "effect": "int_down_1h" } }
  ],
  "roll": { "base": 0.35, "pity": { "per_miss": 0.1, "cap": 0.8 } },
  "on_fail": { "clue": "stele_trace" },
  "recovery": { "policy": "echo", "max_reissue": 0 }
}
```
3. 多人稀缺。 「每角色一次」在多人遊戲裡不稀有，因為同身世玩家人人都拿得到。world_slots 限量，晚到的人拿到沒有力量的「回聲」，只有部分情報與經驗。

4. 失敗要留下線索。 失敗不歸零，而是留下可累積的線索，並提高之後的機率（保底）。

5. 互補。 把 dark_alley 的 compare_map 接成條件：同房間要有至少兩種不同身世的碎片，這是小說第 9 章的拼合機制，同時製造隊伍層級的稀缺。

6. 補領改成回聲。 天門引遺失後，莫三補發的是沒有力量的複製品。

7. 保留已有的好模式。 道童的「松下晶石 +1 才能 stargaze」就是一個可運作的階梯，可以推廣到其他奇遇。

五、建議順序
先修 quests/ 的斷點（cycle_of_craft 第 1 步、rescue_maiden 第 2 步、fa_chain 地點、ancient_order 終局獎勵、長老與路引統一）。
決定單一權威：我建議以引擎為準，把房間和 NPC 的動作改成通用的事件發射。
加上載入時驗證器，我寫的 quest_audit.py 可以直接當基礎。
在穩定的引擎上再做 encounter 稀有化，否則規則無法被測試。
