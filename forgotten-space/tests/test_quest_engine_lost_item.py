import asyncio
import json
import subprocess
import time
import websockets

async def test_quest_engine_and_lost_item_recovery():
    test_user = "quest_tester"
    subprocess.run(f"rm -f forgotten-space/data/user/{test_user}.o", shell=True)

    print("🚀 啟動 forgotten-space 伺服器...")
    server = subprocess.Popen(
        ["./bin/fsmud", "-mudlib", "forgotten-space", "-master", "master.c", "-hub", "none"],
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True
    )

    time.sleep(2)
    uri = "ws://localhost:8080/ws"
    print(f"🔌 連線至 {uri}...")

    try:
        async with websockets.connect(uri) as ws:
            async def send(cmd):
                print(f"👉 [發送指令]: {cmd}")
                msg = json.dumps({"type": "cmd", "payload": cmd})
                await ws.send(msg)
                await asyncio.sleep(0.4)

            async def read_until(pattern, timeout=4):
                start = time.time()
                collected = ""
                while time.time() - start < timeout:
                    try:
                        res = await asyncio.wait_for(ws.recv(), timeout=0.6)
                        data = json.loads(res)
                        txt = data.get("payload", "")
                        for line in str(txt).splitlines():
                            if line.strip():
                                print(f"📩 {line.strip()}")
                        collected += "\n" + str(txt)
                        if pattern in collected:
                            return collected
                    except asyncio.TimeoutError:
                        pass
                return collected

            # 1. 創角登入
            await read_until("Selection:")
            await send("2") # 繁體中文
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send("段工生")
            await read_until("選擇您的身世背景")
            await send("2") # 打鐵學徒
            await read_until("老鐵匠鋪")
            print("✅ 成功登入老鐵匠鋪！")

            # 2. 檢驗任務總覽與初始 Checklist
            await send("quest")
            q_res = await read_until("黑石鋪歷練與任務總覽", timeout=3)
            assert "物修之鏈・百工互生環" in q_res, "應載入物修 JSON 任務"
            assert "[ ] 第 1 步：接應受困礦工" in q_res, "未接取時第 1 步應為 [ ]"
            print("✅ 成功從 /quests/*.json 載入任務並呈現結構化 Checklist！")

            # 3. 向阿鐵接取物修任務 (S0 -> S1)
            await send("ask tie about 任務")
            await read_until("接取鏈式任務")
            await send("quest")
            q_s1 = await read_until("進行中", timeout=3)
            assert "[▶] 第 1 步：接應受困礦工 (進行中)" in q_s1, "接取後應呈現進行中指引"
            print("✅ 任務狀態機成功流轉至 Step 1！")

            # 4. 前往北崖古礦道向魯大山推進任務 (S1 -> S2)
            await send("west")
            await send("north")
            await send("north")
            await send("ask lu about 任務")
            await read_until("採藥療毒")
            print("✅ 成功接應魯大山並領取粗鐵原礦，進入 Step 2！")

            # 5. 前往南谷採集晨露草並交給葛半仙 (S2 -> S3)
            await send("south")
            await send("south")
            await send("gather")
            await asyncio.sleep(0.4)
            await send("down")
            await send("give herb to ge")
            await read_until("葛氏活絡散")
            print("✅ 葛半仙調配藥散完畢，任務進入 Step 3！")

            # 6. 【關鍵情境測試】：玩家意外丟失信物（丟棄活絡散）！
            await send("drop san")
            await read_until("你丟下了")
            print("💥 [信物丟失情境] 玩家把葛氏活絡散丟在地上！")

            # 7. 檢查 quest 指令是否精確提示信物缺失與補領途徑
            await send("quest")
            q_lost = await read_until("缺少關鍵信物", timeout=3)
            print(f"📩 丟失信物後的 Checklist 輸出:\n{q_lost}")
            assert "⚠️ 身上缺少關鍵信物" in q_lost, "引擎應精確偵測信物遺失"
            assert "活絡散" in q_lost and "ge" in q_lost, "應指引向葛半仙補領活絡散"
            print("✅ 引擎成功標記信物遺失並提供補領指引！")

            # 8. 向葛半仙詢問「活絡散」進行補領
            await send("ask ge about 活絡散")
            re_res = await read_until("你重新獲得了關鍵信物", timeout=3)
            print(f"📩 補領對白與回饋:\n{re_res}")
            assert "連救命藥散都能弄丟" in re_res, "應觸發 JSON 定義的補領專屬對白"
            assert "葛氏活絡散" in re_res, "應成功重新獲得補發物品"
            print("🎉 成功向葛半仙補領信物，死鎖問題徹底解開！")

            # 9. 檢查再次輸入 quest，警告標籤應自動消除
            await send("quest")
            q_recovered = await read_until("療毒復命交代開爐 (進行中)", timeout=3)
            assert "⚠️" not in q_recovered, "補領後缺失信物警告應已消除"
            print("✅ 信物補領後 Checklist 恢復正常進行中狀態！")

            # 10. 送藥給魯大山推進至第 4 步開爐
            await send("up")
            await send("north")
            await send("north")
            await send("north")
            await send("give san to lu")
            await read_until("準備回鐵匠鋪開爐")
            print("✅ 成功將補領的藥散交給魯大山，傷勢痊癒！")

            # 11. 回鐵匠鋪開爐鍛造，完成閉環歷練 (S4 -> S0)
            await send("south")
            await send("east")
            await send("wield hammer")
            await send("strike ore")
            fin_res = await read_until("恭喜完成歷練", timeout=4)
            print("🎉 開爐完成，成功結算閉環獎勵！")

            await send("quit")
            print("\n=======================================================")
            print("🎉 任務引擎 JSON 狀態機與信物防呆補領機制全面驗證通過！")
            print("=======================================================")
    finally:
        print("🛑 關閉伺服器...")
        server.terminate()
        server.wait()

if __name__ == "__main__":
    asyncio.run(test_quest_engine_and_lost_item_recovery())
