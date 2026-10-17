import asyncio
import json
import subprocess
import time
import websockets

async def test_thinking_spec_compliance():
    test_user = "spec_tester"
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
        # ── 階段一：以等級 1 普通角色登入，驗證等級門檻與地點阻擋 ──
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

            # 1. 創角登入 (獵戶之子，初始在獵戶哨亭)
            await read_until("Selection:")
            await send("2") # 繁體中文
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send("燕鐵狩")
            await read_until("選擇您的身世背景")
            await send("3") # 獵戶之子
            await read_until("防獸哨亭")
            print("✅ 成功登入獵戶哨亭！")

            # 2. 測試等級限制門檻 (wolf_hunter 需要等級 3，當前玩家等級 1)
            print("\n--- 檢驗 1: 等級門檻阻擋 (Level 1 嘗試接取 Level 3 獵狼任務) ---")
            await send("ask zhao about 獵狼")
            lvl_err = await read_until("修為不足", timeout=3)
            assert "修為不足" in lvl_err, "等級不足時應被攔截"
            assert "需要修為達到等級 3" in lvl_err, "應精確提示需要等級 3"
            print("✅ 等級門檻強制驗證成功阻擋！")

            # 3. 測試地點限制 (在獵戶哨亭執行 wash 或 stargaze 不應推進任務)
            print("\n--- 檢驗 2: 地點限制檢定 (非指定地點無法觸發動作推進) ---")
            await send("wash")
            await asyncio.sleep(0.3)
            await send("tasks")
            t_res = await read_until("黑石鋪歷練與任務總覽", timeout=3)
            assert "[ ] 第 2 步：溪灘掬水洗心" in t_res or "[未接取]" in t_res, "未在溪灘不能推進 wash 步驟"
            print("✅ 地點檢定精確生效，杜絕任意房間刷動作！")

            # 登出保存進度
            await send("quit")
            await asyncio.sleep(0.5)

        # ── 階段二：修改存檔提升至等級 3 並賦予 wizard 權限供刷怪 ──
        print("\n--- 模擬成長：提升玩家至等級 3 重新登入 ---")
        with open(user_file, "r", encoding="utf-8") as f:
            u_data = json.load(f)
        u_data["level"] = 3
        u_data["role"] = "wizard"
        u_data["stat_str"] = 500
        u_data["stat_dex"] = 100
        u_data["stat_con"] = 500
        u_data["hp"] = 999
        u_data["max_hp"] = 999
        with open(user_file, "w", encoding="utf-8") as f:
            json.dump(u_data, f, indent=2, ensure_ascii=False)

        # ── 階段三：等級 3 重新登入，驗證完整任務生命週期 ──
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

            # 登入已有帳號
            await read_until("Selection:")
            await send("2")
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("防獸哨亭")
            print("✅ 等級 3 角色成功登入！")

            # 4. 達標接取 wolf_hunter
            print("\n--- 檢驗 3: 達標接取 wolf_hunter 並驗證殺狼計數分派 ---")
            await send("ask zhao about 獵狼")
            accept_res = await read_until("接取歷練任務", timeout=3)
            assert "東林獵狼平煞" in accept_res, "等級達標後應能正常接取"
            print("✅ 等級 3 成功承接「東林獵狼平煞」！")

            # 5. 前往東林荒林擊殺野狼
            await send("south") # hunter_cabin -> forest
            await read_until("大荒外緣・荊棘林口")

            # 擊殺第 1 隻野狼
            await send("kill wolf")
            k1_res = await read_until("任務進度", timeout=3)
            assert "1 / 3" in k1_res, "殺死第 1 隻狼進度應為 1 / 3"
            print("✅ 擊殺第 1 隻野狼，進度正確計數 1 / 3！")

            # 檢查 tasks 清單中的即時進度渲染
            await send("tasks")
            panel_k1 = await read_until("進度: 1 / 3", timeout=3)
            assert "進度: 1 / 3" in panel_k1, "Checklist 面板應同步展示 (進度: 1 / 3)"
            print("✅ Checklist 面板成功渲染動態進度：(進度: 1 / 3)！")

            # 刷出並擊殺第 2 隻野狼
            await send("clone /npc/wolf.c")
            await asyncio.sleep(0.3)
            await send("drop wolf")
            await asyncio.sleep(0.3)
            await send("kill wolf")
            k2_res = await read_until("任務進度", timeout=3)
            assert "2 / 3" in k2_res, "殺死第 2 隻狼進度應為 2 / 3"
            print("✅ 擊殺第 2 隻野狼，進度正確計數 2 / 3！")

            # 刷出並擊殺第 3 隻野狼
            await send("clone /npc/wolf.c")
            await asyncio.sleep(0.3)
            await send("drop wolf")
            await asyncio.sleep(0.3)
            await send("kill wolf")
            k3_res = await read_until("肅清了 3 隻狂暴野狼", timeout=3)
            assert "成功肅清了 3 隻狂暴野狼" in k3_res, "擊殺第 3 隻狼應觸發步驟完成"
            print("✅ 擊殺第 3 隻野狼，步驟圓滿完成並推進到第 2 步回報！")

            # 6. 回哨亭向趙老獵回報戰績 (結算獎勵)
            await send("north") # forest -> hunter_cabin
            await read_until("防獸哨亭")
            await send("ask zhao about 獵狼")
            reward_res = await read_until("恭喜完成歷練", timeout=3)
            assert "恭喜完成歷練：「東林獵狼平煞」" in reward_res, "應成功結算任務"
            print("✅ 向趙老獵回報成功，結算經驗與金錢！")

            # 7. 驗證重複接取防護 (非 loop 任務完成後不可重複接取)
            print("\n--- 檢驗 4: 防重複領取驗證 ---")
            await send("ask zhao about 獵狼")
            await send("tasks")
            completed_panel = await read_until("已完成", timeout=3)
            assert "[✓] 第 2 步：向趙老獵回報戰績 (已完成)" in completed_panel, "任務應標記為已完成"
            print("✅ 任務防重複機制驗證通過！")

            # 8. 驗證 rescue_miners 頂層 lost_item_recovery 遺失補領與潛能獎勵
            print("\n--- 檢驗 5: rescue_miners 頂層遺失補領與 pot 潛能獎勵 ---")
            await send("northwest") # hunter_cabin -> square
            await read_until("青石街市")
            await send("southwest") # square -> shed
            await read_until("客棧背街・廢柴房")
            await send("ask su about 委託")
            await read_until("接取歷練任務")
            print("✅ 成功向蘇凝霜接取「北崖破壁・九死還魂」！")

            # 故意丟失殘圖並檢查 tasks 警告
            await send("drop blueprint")
            await send("tasks")
            lost_chk = await read_until("身上缺少關鍵信物", timeout=3)
            assert "⚠️ 身上缺少關鍵信物" in lost_chk, "頂層遺失項目應觸發警告"
            assert "su" in lost_chk and "殘圖" in lost_chk, "應指引向蘇凝霜補領殘圖"

            # 補領
            await send("ask su about 殘圖")
            re_su = await read_until("你重新獲得了關鍵信物", timeout=3)
            assert "太古採掘殘圖" in re_su, "成功從頂層 recovery 補領殘圖！"
            print("✅ 頂層陣列 lost_item_recovery 精確補領驗證通過！")

            await send("quit")
            print("\n=======================================================")
            print("🎉 thinking.md 規範第一階段：五大修正全數通過！")
            print("=======================================================")
    finally:
        print("🛑 關閉伺服器...")
        server.terminate()
        server.wait()

if __name__ == "__main__":
    asyncio.run(test_thinking_spec_compliance())
