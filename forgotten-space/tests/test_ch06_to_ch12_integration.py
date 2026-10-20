import asyncio
import json
import subprocess
import time
import websockets

async def test_integration():
    test_user = "ch6_12_tester"
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

            # 1. 創角登入 (乞兒身世，出生於廢柴房)
            await read_until("Selection:")
            await send("2") # 繁體中文
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send("測試客")
            await read_until("選擇您的身世背景")
            await send("5") # 流浪乞兒
            await read_until("廢柴房")

            # 2. 驗證廢柴房中的蘇凝霜
            print("\n=== [測試 1]: 廢柴房中的蘇凝霜 NPC 與對話 ===")
            await send("look")
            res = await read_until("蘇凝霜")
            assert "蘇凝霜" in res, "廢柴房中應有蘇凝霜 NPC！"

            await send("ask su about 父親")
            res = await read_until("家父蘇遠山")
            assert "蘇遠山" in res or "腐骨七步散" in res, "蘇凝霜應回應父親被害真相！"

            await send("ask su about 神機密匙")
            res = await read_until("太古神機密匙")
            assert "太古神機密匙" in res or "採掘站" in res, "蘇凝霜應提及神機密匙！"

            # 3. 前往青石暗巷 (dark_alley)
            print("\n=== [測試 2]: 前往青石暗巷與搜查破甲箭 ===")
            await send("north")
            res = await read_until("黑甲弩衛")
            assert "青石暗巷" in res, "應進入青石暗巷！"
            assert "黑甲弩衛" in res, "暗巷中應有城防軍黑甲弩衛！"

            await send("search boards")
            res = await read_until("精鋼三棱破甲錐")
            assert "破甲錐" in res, "搜查木板應拾獲精鋼三棱破甲錐！"

            # 4. 前往街市 -> 水谷 -> 南谷墜龍瀑布 (falls)
            print("\n=== [測試 3]: 前往南谷墜龍瀑布與瀑布鍛體、採石膽苔 ===")
            await send("east")
            await read_until("青石街市")
            await send("south")
            await read_until("碎石溪灘")
            await send("south")
            res = await read_until("趙四")
            assert "墜龍瀑布" in res, "應進入南谷墜龍瀑布！"
            assert "趙四" in res, "瀑布前應遭遇兵痞趙四！"

            await send("gather moss")
            res = await read_until("生石膽苔")
            assert "生石膽苔" in res, "採藥應獲得生石膽苔！"

            await send("train_falls")
            res = await read_until("鍛體")
            assert "鍛體" in res or "急流" in res, "應能進行瀑布鍛體！"

            # 5. 返回水谷 -> 懸崖草廬 (herb_hut) 驗證百煉雙耳鋼碾
            print("\n=== [測試 4]: 採藥草廬與百煉雙耳鋼碾 ===")
            await send("north")
            await read_until("碎石溪灘")
            await send("down")
            res = await read_until("百煉雙耳鋼碾")
            assert "採藥草廬" in res, "應進入採藥草廬！"
            assert "百煉雙耳鋼碾" in res, "草廬中應擺放百煉雙耳鋼碾！"

            print("\n🎉 【全數通過！】第 6-12 章 MUD 房間、NPC、物品、對話與動作完美整合！")

    finally:
        server.terminate()
        try:
            server.wait(timeout=3)
        except Exception:
            server.kill()

if __name__ == "__main__":
    asyncio.run(test_integration())
