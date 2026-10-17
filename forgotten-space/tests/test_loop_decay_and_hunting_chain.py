#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
test_loop_decay_and_hunting_chain.py
驗證兩大持續遊玩型態：
1. 單一循環任務 (mining_loop)：收益遞減機制（前幾輪全額經驗，超過臨界點後經驗潛能歸零，保底純物資材料）
2. 階梯進階式多環狩獵鏈 (hunting_chain)：鼠(Tier 1) -> 狼(Tier 2) -> 熊(Tier 3) 連貫自動晉級與階梯獎勵
"""

import asyncio
import json
import os
import subprocess
import time
import websockets

async def test_loop_decay_and_hunting_chain():
    test_user = "play_loop_tester"
    user_file = f"forgotten-space/data/user/{test_user}.o"
    subprocess.run(f"rm -f {user_file}", shell=True)

    print("🚀 啟動 forgotten-space 伺服器...")
    server = subprocess.Popen(
        ["./bin/fsmud", "-mudlib", "forgotten-space", "-master", "master.c", "-hub", "none"],
        cwd="/home/wade/src/github/mudscript",
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True
    )

    time.sleep(2)
    uri = "ws://localhost:8080/ws"
    print(f"🔌 連線至 {uri}...")

    try:
        # ── 階段一：創角登入（獵戶之子，出生在防獸哨亭） ──
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

            # 創角登入
            await read_until("Selection:")
            await send("2") # 繁體中文
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send("獵荒生")
            await read_until("選擇您的身世背景")
            await send("3") # 獵戶之子 (防獸哨亭)
            await read_until("防獸哨亭")
            print("✅ 成功登入防獸哨亭！")

            await send("quit")
            await asyncio.sleep(0.5)

        # ── 階段二：提權至 Level 5，便於刷怪與完整驗證三階狩獵 ──
        print("\n--- 模擬成長：升級至等級 5 並賦予力量 ---")
        with open(user_file, "r", encoding="utf-8") as f:
            u_data = json.load(f)
        u_data["level"] = 5
        u_data["role"] = "wizard"
        u_data["stat_str"] = 500
        u_data["stat_dex"] = 100
        u_data["stat_con"] = 500
        u_data["hp"] = 9999
        u_data["max_hp"] = 9999
        with open(user_file, "w", encoding="utf-8") as f:
            json.dump(u_data, f, indent=2, ensure_ascii=False)

        # ── 階段三：登入等級 5 角色，進行 Round 1 採礦循環驗證 ──
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

            # 登入等級 5 角色 (在防獸哨亭)
            await read_until("Selection:")
            await send("2")
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("防獸哨亭")
            print("✅ 等級 5 角色成功登入防獸哨亭！")

            # =========================================================
            # PART 1: 驗證「單一循環任務 (mining_loop)」收益遞減與保底物質機制
            # =========================================================
            print("\n--- 檢驗 1: 前往北崖礦道，接取採礦日常循環任務 (mining_loop) ---")
            await send("northwest") # 到街市
            await read_until("青石街市")
            await send("north")     # 到礦洞口
            await read_until("黑石斷崖・古礦道口")

            await send("ask lu about 採礦")
            q_res = await read_until("北崖供礦・工坊生計")
            assert "北崖供礦・工坊生計" in q_res, "應成功接取採礦生計委託"
            print("✅ 成功接取「北崖供礦・工坊生計」！")

            # 查看 tasks 面板展示
            await send("tasks")
            panel_res = await read_until("北崖供礦・工坊生計")
            assert "北崖供礦・工坊生計" in panel_res, "tasks 面板應顯示日常生計委託"
            print("✅ tasks 面板正確收錄日常生計委託！")

            # 第 1 輪交付 (Round 1)：全額收益 (100 exp, 25 pot)
            print("\n--- 檢驗 2: 第 1 輪交付粗鐵礦核（全額經驗與潛能）---")
            await send("clone /clone/item/ore_chunk.c")
            await asyncio.sleep(0.3)
            await send("give ore chunk to lu")
            r1_res = await read_until("恭喜完成歷練", timeout=4)
            assert "獲得 25 點潛能" in r1_res, "第 1 輪應獲得全額 25 點潛能"
            print("✅ 第 1 輪結算完成：獲得全額經驗與潛能！")

            # 登出並將存檔 rounds 設為 5，以便驗證第 6 輪臨界截止
            await send("quit")
            await asyncio.sleep(0.5)

        # ── 階段四：修改 rounds 為 5，登入完成第 6 輪（臨界 cutoff）──
        with open(user_file, "r", encoding="utf-8") as f:
            u_data = json.load(f)
        if "dbase" not in u_data:
            u_data["dbase"] = {}
        u_data["role"] = "wizard"
        u_data["level"] = 5
        u_data["dbase"]["quests/mining_loop/rounds"] = 5
        u_data["dbase"]["quests/mining_loop/step"] = 1
        u_data["dbase"]["quests/mining_loop/state"] = "ACTIVE"
        u_data["dbase"]["quests/mining_loop/stage"] = 1
        with open(user_file, "w", encoding="utf-8") as f:
            json.dump(u_data, f, indent=2, ensure_ascii=False)

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

            # 登入 (直接回到礦道口)
            await read_until("Selection:")
            await send("2")
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("黑石斷崖・古礦道口")
            print("✅ 重新登入古礦道口！")

            print("\n--- 檢驗 3: 驗證達到臨界輪次後經驗歸零、保底純物資材料 ---")
            await send("clone /clone/item/ore_chunk.c")
            await asyncio.sleep(0.3)
            await send("give ore chunk to lu")
            r6_res = await read_until("恭喜完成歷練", timeout=4)
            assert "體悟已達瓶頸（不再獲得經驗與潛能）" in r6_res, "第 6 輪結算應觸發經驗歸零提示"
            assert "獲得 25 點潛能" not in r6_res, "第 6 輪不應再獲得潛能"
            assert "獲得獎勵物品" in r6_res, "保底物質材料獎勵（粗鐵礦核）應正常發放"
            print("✅ 臨界輪次驗證通過：經驗潛能歸零，保底純物質材料生效！")

            # =========================================================
            # PART 2: 驗證「階梯進階式多環狩獵鏈 (hunting_chain)」
            # 鼠(Tier 1) -> 狼(Tier 2) -> 熊(Tier 3)
            # =========================================================
            print("\n--- 檢驗 4: 向趙老獵請領大荒獵戶進階試煉 (hunting_chain) ---")
            await send("south")     # 回街市
            await read_until("青石街市")
            await send("southeast") # 到哨亭
            await read_until("防獸哨亭")

            await send("ask zhao about 獵師")
            h_accept = await read_until("大荒逐獸・獵師之路")
            assert "大荒逐獸・獵師之路" in h_accept, "應成功承接獵師試煉"
            print("✅ 成功接取「大荒逐獸・獵師之路」第一環！")

            # 檢查 tasks 面板第一環展示
            await send("tasks")
            t_res = await read_until("第 1 環：深穴除害")
            assert "第 1 環：深穴除害" in t_res, "tasks 應展示第 1 環"
            print("✅ tasks 正確渲染第 1 環（深穴除害）！")

            # 擊殺 3 隻地穴鼠 (mine_rat) 完成第一環
            print("\n--- 檢驗 5: 第一環（斬殺 3 隻地穴灰鼠）與自動晉級第 2 環 ---")
            await send("northwest") # 回街市
            await read_until("青石街市")
            await send("north")     # 到礦洞口
            await read_until("黑石斷崖・古礦道口")

            # 擊殺 3 隻地穴灰鼠
            for i in range(1, 4):
                await send("clone /clone/npc/mine_rat.c")
                await asyncio.sleep(0.3)
                await send("drop rat")
                await asyncio.sleep(0.3)
                await send("kill rat")
                await asyncio.sleep(0.5)

            # 驗證第一環完成並自動晉級第二環
            t2_unlock = await read_until("荒林伏煞", timeout=5)
            assert "荒林伏煞" in t2_unlock, "第一環達成後應自動晉級第二環（荒林伏煞）"
            print("✅ 第一環圓滿達成，自動解鎖並晉級第二環「荒林伏煞」！")

            # 檢查 tasks 面板晉級狀態
            await send("tasks")
            t2_panel = await read_until("第 2 環：荒林伏煞")
            assert "[✓] 第 1 環：深穴除害" in t2_panel, "第 1 環應標註已完成"
            assert "[▶] 第 2 環：荒林伏煞" in t2_panel, "第 2 環應標註進行中"
            print("✅ tasks 即時更新階梯狀態：第 1 環已完成，第 2 環進行中！")

            # 擊殺 3 隻野狼 (wolf) 完成第二環
            print("\n--- 檢驗 6: 第二環（斬殺 3 隻受煞野狼）與自動晉級第 3 環 ---")
            await send("south")     # 回街市
            await read_until("青石街市")
            await send("southeast") # 哨亭
            await read_until("防獸哨亭")
            await send("south")     # 荒林
            await read_until("大荒外緣・荊棘林口")

            for i in range(1, 4):
                await send("clone /npc/wolf.c")
                await asyncio.sleep(0.3)
                await send("drop wolf")
                await asyncio.sleep(0.3)
                await send("kill wolf")
                await asyncio.sleep(0.5)

            t3_unlock = await read_until("絕嶺擒凶", timeout=5)
            assert "絕嶺擒凶" in t3_unlock, "第二環達成後應自動晉級第三環（絕嶺擒凶）"
            print("✅ 第二環圓滿達成，自動解鎖並晉級第三環「絕嶺擒凶」！")

            # 擊殺 1 隻黑嶺狂暴巨熊 (wild_bear) 完成第三環
            print("\n--- 檢驗 7: 第三環（斬殺黑嶺狂暴巨熊）與全線圓滿榮獲獵師稱號 ---")
            await send("clone /clone/npc/wild_bear.c")
            await asyncio.sleep(0.3)
            await send("drop bear")
            await asyncio.sleep(0.3)
            await send("kill bear")
            bear_res = await read_until("大荒獵師", timeout=5)
            assert "大荒勇士符令" in bear_res, "擊殺巨熊應獲得【大荒勇士符令】"
            print("✅ 第三環圓滿達成：搏殺黑嶺暴熊，獲得【大荒勇士符令】與獵師稱號！")

            # 查看最終全線圓滿狀態
            await send("tasks")
            final_panel = await read_until("全線圓滿", timeout=5)
            assert "全線圓滿" in final_panel, "三環獵人鏈應標註全線圓滿"
            print("✅ tasks 正確標註大荒逐獸獵師鏈【全線圓滿】！")

            await send("quit")

        print("\n=======================================================")
        print("🎉 兩大持續遊玩型態（單一遞減循環 + 三階狩獵鏈）全面驗證通過！")
        print("=======================================================")

    finally:
        print("🛑 關閉伺服器...")
        server.terminate()
        try:
            server.wait(timeout=3)
        except subprocess.TimeoutExpired:
            server.kill()

if __name__ == "__main__":
    asyncio.run(test_loop_decay_and_hunting_chain())
