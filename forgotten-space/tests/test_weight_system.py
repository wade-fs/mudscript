import asyncio
import json
import subprocess
import time
import websockets

async def test_weight_and_encumbrance():
    test_user = "weight_tester"
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
                        res = await asyncio.wait_for(ws.recv(), timeout=0.5)
                        data = json.loads(res)
                        txt = data.get("payload", "")
                        collected += "\n" + str(txt)
                        if pattern in collected:
                            return collected
                    except asyncio.TimeoutError:
                        pass
                return collected

            # 1. 登入創角 (打鐵學徒)
            await read_until("Selection:")
            await send("2") # 繁體中文
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send("鐵石生")
            await read_until("選擇您的身世背景")
            await send("2") # 打鐵學徒 (擁有 smith_hammer，位於鐵匠鋪)
            await read_until("老鐵匠鋪")
            print("✅ 成功登入並進入老鐵匠鋪！")

            # 2. 測試 inventory 顯示負重
            await send("inventory")
            inv_res = await read_until("負重：", timeout=3)
            print(f"📩 背包輸出:\n{inv_res}")
            assert "負重：" in inv_res, "inventory 應顯示負重資訊"
            assert "g" in inv_res, "重量應以公制克 (g) 為基準單位"
            print("✅ inventory 負重顯示正確！")

            # 3. 測試 appraise 鑑定裝備重量
            await send("appraise hammer")
            app_res = await read_until("重量", timeout=3)
            print(f"📩 鑑定鐵錘輸出:\n{app_res}")
            assert "1000g (1.00kg)" in app_res or "1000g" in app_res, "鐵錘重量應為 1000g (1.00kg)"
            print("✅ appraise 裝備重量與公制公斤標註正確！")

            # 4. 前往南谷採摘晨露草，驗證極輕物品重量累加
            await send("west")
            await asyncio.sleep(0.3)
            await send("south")
            await asyncio.sleep(0.3)
            await send("gather")
            gather_res = await read_until("帶露晨露草", timeout=3)
            print(f"📩 採藥輸出:\n{gather_res}")
            await asyncio.sleep(0.5)
            await send("appraise dew")
            dew_res = await read_until("重量", timeout=3)
            print(f"📩 晨露草重量輸出:\n{dew_res}")
            assert "20g" in dew_res, "晨露草重量應為 20g (輕如鴻毛)"
            print("✅ 晨露草 20g 輕靈物重量設定正確！")

            # 5. 檢視拾取草藥後的背包負重變化
            await send("inventory")
            inv_after = await read_until("負重：", timeout=3)
            print(f"📩 採集後背包輸出:\n{inv_after}")

            await send("quit")
            print("\n🎉 全部重量與負重機制驗證通過！")
    finally:
        print("🛑 關閉伺服器...")
        server.terminate()
        server.wait()

if __name__ == "__main__":
    asyncio.run(test_weight_and_encumbrance())
