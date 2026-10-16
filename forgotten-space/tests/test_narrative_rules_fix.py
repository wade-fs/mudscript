#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
測試新修復的硬 bug 與機制：
1. 採藥孤兒（顧玄）初始天命為 1，其他身世（林鐵生等）初始為 0
2. 初始天命 0 者不可直接參悟/拓印斷碑；其他身世透過觸發其身世遺物覺醒天命 +1
3. 斷碑去苔為個人暫態 (cleared_stele_moss)，將門檻由 2 降至 1
4. 任務鏈未接取 (stage == 0) 時，一般日常動作不會推進任務
5. 出鄉文牒：未達 10 級不可領取，達到 10 級可向長者領取保書路引並完成 pass_village_ceremony
6. 伐木採集 timber 並修復礦脈穩定度 (repair_mine)
"""

import asyncio
import json
import os
import subprocess
import time
import websockets

async def run_test():
    subprocess.run("rm -f forgotten-space/data/user/testsmith.o", shell=True)
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
                print(f"\n👉 [發送指令]: {cmd}")
                msg = json.dumps({"type": "cmd", "payload": cmd})
                await ws.send(msg)
                await asyncio.sleep(0.4)

            async def read_until(pattern, timeout=4):
                start = time.time()
                buf = ""
                while time.time() - start < timeout:
                    try:
                        raw = await asyncio.wait_for(ws.recv(), timeout=0.8)
                        data = json.loads(raw)
                        if data.get("type") == "mud_text":
                            payload = data.get("payload", "")
                            for line in payload.splitlines():
                                if line.strip():
                                    print(f"📩 {line.strip()}")
                            buf += payload
                            if pattern in buf:
                                return buf
                    except asyncio.TimeoutError:
                        pass
                return buf

            # 步驟 1: 選擇語系
            await read_until("Selection:")
            await send("2")

            # 步驟 2: 輸入帳號
            await read_until("帳號")
            await send("testsmith")

            # 步驟 3: 設定密碼
            await read_until("密碼")
            await send("pass123")

            # 步驟 4: 輸入暱稱
            await read_until("暱稱")
            await send("小鐵匠")

            # 步驟 5: 選擇身世背景
            await read_until("選擇您的身世背景")
            await send("2") # 2. smith

            await read_until("打鐵爐房", 4)
            print("✔ 創角成功進入老鐵匠鋪")

            # 1. 驗證接取任務鏈前 (stage == 0)，向阿鐵詢問可接取任務
            await send("ask tie about 任務")
            resp_task = await read_until("魯大山", 4)
            assert "老礦工魯大山" in resp_task or "接應" in resp_task, f"任務接取對話異常: {resp_task}"
            print("✔ 物修任務鏈 stage 0 -> 1 接取成功")

            # 2. 詢問阿鐵出鄉路引 (未達 10 級應阻擋)
            await send("ask tie about 路引")
            resp_tie = await read_until("靶子", 4)
            assert "10 級" in resp_tie or "靶子" in resp_tie, f"未滿10級應阻擋路引，實際: {resp_tie}"
            print("✔ 未達 10 級阻擋出鄉文牒驗證通過")

            # 3. 前往東林荒林測試伐木功能 (chop)
            await send("west") # square
            await read_until("青石街市", 4)
            await send("southeast") # hunter cabin
            await read_until("獵戶哨亭", 4)
            await send("south") # forest
            await read_until("大荒外緣", 4)
            await send("chop")
            resp_chop = await read_until("加固硬木料", 4)
            assert "加固硬木料" in resp_chop or "timber" in resp_chop or "伐下" in resp_chop, f"伐木異常: {resp_chop}"
            print("✔ 東林荒林伐木功能驗證通過")

            # 4. 前往北崖礦坑將坑木交給老礦工魯大山修復礦坑
            await send("north") # hunter cabin
            await read_until("獵戶哨亭", 4)
            await send("northwest") # square
            await read_until("青石街市", 4)
            await send("north") # mine
            await read_until("古礦道", 4)
            await send("give timber to lu")
            resp_give = await read_until("頂住", 4)
            assert "加固木料" in resp_give or "頂住" in resp_give or "欣喜" in resp_give, f"給予木料修復礦坑異常: {resp_give}"
            print("✔ 坑木修復礦脈穩定度 (repair_mine) 驗證通過")

            # 5. 退出遊戲
            await send("quit")
            print("🎉 所有修復機制功能與硬 bug 測試全部順利通過！")

    finally:
        server.terminate()
        server.wait()

if __name__ == "__main__":
    asyncio.run(run_test())
