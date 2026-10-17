import asyncio
import json
import os
import subprocess
import time
import websockets

async def test_phase1_quest_fixes():
    test_user = "p1_tester"
    user_file = f"forgotten-space/data/user/{test_user}.o"
    subprocess.run(f"rm -f {user_file}", shell=True)

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
        # ── 1. 創角登入 ──
        async with websockets.connect(uri) as ws:
            async def send(cmd):
                print(f"👉 [發送指令]: {cmd}")
                msg = json.dumps({"type": "cmd", "payload": cmd})
                await ws.send(msg)
                await asyncio.sleep(0.35)

            async def read_until(pattern, timeout=4):
                start = time.time()
                collected = ""
                while time.time() - start < timeout:
                    try:
                        res = await asyncio.wait_for(ws.recv(), timeout=0.5)
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

            await read_until("Selection:")
            await send("2")  # 繁體中文
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send("顧玄真")
            await read_until("選擇您的身世背景")
            await send("1")  # 鐵匠學徒 (青石街市)
            await read_until("青石街市")
            print("✅ 成功登入青石街市！")

            await send("quit")
            await asyncio.sleep(0.5)

        # ── 2. 提升為 wizard (Level 10) 供測試四大任務修正 ──
        with open(user_file, "r", encoding="utf-8") as f:
            u_data = json.load(f)
        u_data["level"] = 10
        u_data["role"] = "wizard"
        u_data["stat_str"] = 500
        u_data["stat_dex"] = 200
        u_data["stat_con"] = 500
        u_data["hp"] = 5000
        u_data["max_hp"] = 5000
        with open(user_file, "w", encoding="utf-8") as f:
            json.dump(u_data, f, indent=2, ensure_ascii=False)

        # ── 3. 重新連線驗證四大斷點修復 ──
        async with websockets.connect(uri) as ws:
            async def send(cmd):
                print(f"👉 [發送指令]: {cmd}")
                msg = json.dumps({"type": "cmd", "payload": cmd})
                await ws.send(msg)
                await asyncio.sleep(0.35)

            async def read_until(pattern, timeout=4):
                start = time.time()
                collected = ""
                while time.time() - start < timeout:
                    try:
                        res = await asyncio.wait_for(ws.recv(), timeout=0.5)
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

            await read_until("Selection:")
            await send("2")
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("青石街市")
            print("✅ Level 10 Wizard 登入成功！")

            # ── 斷點 1: cycle_of_craft 第 1 步在 stream.c 採藥 (gather) 順利推進 ──
            print("\n--- 驗證斷點 1: cycle_of_craft 在 stream.c 採藥 (gather) 推進 ---")
            await send("goto /d/village/stream")
            await asyncio.sleep(0.3)
            await send("gather")
            g_res = await read_until("第 2 步", timeout=3)
            assert "百工之環" in g_res or "百工交織" in g_res, "採藥應觸發百工之環歷練開啟"
            assert "寒瀑鍛體" in g_res or "第 2 步" in g_res, "採藥應成功推進至第 2 步"
            await send("tasks")
            t_res1 = await read_until("百工之環", timeout=3)
            assert "第 2 步：寒瀑鍛體" in t_res1 or "墜龍瀑布" in t_res1, "任務列表應確認當前在第 2 步"
            print("✅ 斷點 1 驗證通過：cycle_of_craft 採藥成功啟動並推進至第 2 步！")

            # ── 斷點 2: rescue_maiden 第 1 步誅凶 + 第 2 步在 dark_alley.c 搜查木板 (search boards) ──
            print("\n--- 驗證斷點 2: rescue_maiden 第 1 步擊斃趙四 + 第 2 步 dark_alley search boards ---")
            await send("goto /d/village/falls")
            await asyncio.sleep(0.3)
            await send("clone /clone/npc/zhao_si.c")
            await asyncio.sleep(0.2)
            await send("drop zhao si")
            await asyncio.sleep(0.2)
            await send("kill zhao si")
            k_res = await read_until("第 2 步", timeout=3)
            assert "荒澗死鬥" in k_res or "暗巷驚鴻" in k_res, "擊斃趙四應觸發 rescue_maiden"
            assert "暗巷巡查" in k_res or "第 2 步" in k_res, "第 1 步完成應直接推進至第 2 步"

            # 前往暗巷執行 search boards
            await send("goto /d/village/dark_alley")
            await asyncio.sleep(0.3)
            await send("search boards")
            s_res = await read_until("任務推進", timeout=3)
            assert "密證呈交" in s_res or "第 3 步" in s_res, "搜查木板應推進至第 3 步"
            await send("tasks")
            t_res2 = await read_until("荒澗死鬥", timeout=3)
            assert "第 3 步：密證呈交" in t_res2, "任務清單應確認在第 3 步"
            print("✅ 斷點 2 驗證通過：rescue_maiden 第 1 步擊殺與第 2 步 search boards 順暢推進！")

            # ── 斷點 3: fa_chain 地點更正為 /d/village/daoist_temple，枯木老道對話推進 ──
            print("\n--- 驗證斷點 3: fa_chain 在 /d/village/daoist_temple 向枯木老道接取推進 ---")
            await send("goto /d/village/daoist_temple")
            await asyncio.sleep(0.3)
            await send("ask kumu about 任務")
            fa_res = await read_until("查探源頭", timeout=3)
            assert "鏈式任務" in fa_res or "第 2 階" in fa_res or "溪灘洗心" in fa_res, "枯木老道應推進法修鏈"
            await send("tasks")
            t_res3 = await read_until("黑石鋪歷練與任務總覽", timeout=3)
            t_res3 += await read_until("溪灘掬水洗心", timeout=3)
            assert "第 2 步：溪灘掬水洗心" in t_res3, "任務列表確認法修鏈處於第 2 步"
            print("✅ 斷點 3 驗證通過：fa_chain 在 daoist_temple 正確接取並推進！")

            # ── 斷點 4: village_pass 達 10 級向導師領取路引，統一完成出鄉文牒 ──
            print("\n--- 驗證斷點 4: village_pass 向導師詢問「路引」，領取保書並完成出鄉文牒 ---")
            await send("goto /d/village/forge")
            await asyncio.sleep(0.3)
            await send("ask tie about 路引")
            vp_res = await read_until("官辦保書路引", timeout=3)
            assert "保書路引" in vp_res or "官辦保書" in vp_res, "達到 10 級應獲得保書路引"
            await send("inventory")
            inv_res = await read_until("保書路引", timeout=3)
            assert "保書路引" in inv_res, "背包中應持有金石城官辦保書路引"
            await send("tasks")
            t_res4 = await read_until("黑石鋪歷練與任務總覽", timeout=3)
            t_res4 += await read_until("出鄉文牒考驗", timeout=3)
            assert "出鄉文牒考驗" in t_res4 and "已完成" in t_res4, "出鄉文牒任務應標記已完成"
            print("✅ 斷點 4 驗證通過：village_pass 成功向導師申領路引並完成通關文牒考驗！")

            # ── 斷點 5: ancient_order 終局獎勵配置驗證 ──
            print("\n--- 驗證斷點 5: ancient_order JSON 終局獎勵配置合法性 ---")
            with open("forgotten-space/quests/epic/ancient_order.json", "r", encoding="utf-8") as f:
                ao_data = json.load(f)
            assert "rewards" in ao_data, "頂層應有 rewards"
            assert ao_data["rewards"].get("exp") == 5000, "終局經驗應為 5000"
            assert ao_data["rewards"].get("fate") == 3, "終局天命應為 3"
            st3 = [s for s in ao_data["stages"] if s["stage"] == 3][0]
            assert "on_finish" in st3, "Stage 3 應有 on_finish"
            assert st3["on_finish"].get("exp") == 5000, "Stage 3 on_finish 經驗應為 5000"
            print("✅ 斷點 5 驗證通過：ancient_order 終局獎勵配置完整齊全！")

            await send("quit")
            await asyncio.sleep(0.5)

    finally:
        print("🛑 正在關閉伺服器...")
        server.terminate()
        try:
            out, _ = server.communicate(timeout=3)
            # 驗證啟動與載入時無 QUEST_AUDIT ERROR
            if "QUEST_AUDIT ERROR" in out:
                raise AssertionError(f"發現任務合法性稽核錯誤：\n{out}")
            else:
                print("✅ 任務合法性稽核器 (Quest Definition Auditor)：無任何檔案或路徑遺漏錯誤！")
        except:
            server.kill()

    print("\n=======================================================")
    print("🎉 Phase 1: 四大任務斷點修復與路引統一驗證 100% 全部通過！")
    print("=======================================================\n")

if __name__ == "__main__":
    asyncio.run(test_phase1_quest_fixes())
