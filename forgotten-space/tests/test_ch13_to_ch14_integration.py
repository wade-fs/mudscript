import asyncio
import json
import subprocess
import time
import websockets

async def test_integration():
    test_user = "ch13_14_tester"
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
            await send("破壁俠")
            await read_until("選擇您的身世背景")
            await send("5") # 流浪乞兒
            await read_until("廢柴房")

            # 2. 測試 1: 蘇凝霜的天字救援委託與太古採掘殘圖
            print("\n=== [測試 1]: 蘇凝霜天字緊急委託與《太古採掘殘圖》 ===")
            await send("ask su about 委託")
            res = await read_until("特等緊急救援委託")
            assert "特等緊急救援委託" in res or "大印" in res, "蘇凝霜應發布天字甲級委託！"

            await send("ask su about 殘圖")
            res = await read_until("太古玄煞採掘舊志殘圖")
            assert "殘圖" in res, "應獲得《太古採掘殘圖》！"

            await send("read blueprint")
            res = await read_until("避風穹頂")
            assert "避風穹頂" in res and "斷龍卡隼石" in res, "殘圖內容應指引地脈機要！"

            # 3. 測試 2: 前往鐵匠鋪向阿鐵索取【百煉破煞玄鐵鋼鑿】
            print("\n=== [測試 2]: 老鐵匠阿鐵與【百煉破煞玄鐵鋼鑿】 ===")
            await send("north") # 到 dark_alley
            await read_until("青石暗巷")
            await send("east") # 到 square
            await read_until("青石街市")
            await send("east") # 到 forge
            await read_until("老鐵匠鋪")

            await send("ask tie about 鋼鑿")
            res = await read_until("百煉破煞玄鐵鋼鑿")
            assert "百煉破煞玄鐵鋼鑿" in res, "阿鐵應贈予百煉破煞玄鐵鋼鑿！"

            # 4. 測試 3: 前往採藥草廬向瘋郎中葛半仙索取【雄黃辟煞烈血酒】
            print("\n=== [測試 3]: 瘋郎中葛半仙與【雄黃辟煞烈血酒】 ===")
            await send("west") # 返回 square
            await read_until("青石街市")
            await send("south") # 到 stream
            await read_until("碎石溪灘")
            await send("down") # 到 herb_hut
            await read_until("採藥草廬")

            await send("ask ge about 避毒")
            res = await read_until("雄黃辟煞烈血酒")
            assert "雄黃辟煞烈血酒" in res, "瘋郎中應給予雄黃辟煞烈血酒！"

            await send("drink wine")
            res = await read_until("四肢百骸氣血如沸")
            assert "氣血" in res or "純陽" in res, "飲下藥酒應有辟煞回血特效！"

            # 5. 測試 4: 前往道觀向瞎老道索取【太上定脈鎮山符】
            print("\n=== [測試 4]: 瞎老道與【太上定脈鎮山符】 ===")
            await send("up") # 回 stream
            await read_until("碎石溪灘")
            await send("north") # 回 square
            await read_until("青石街市")
            await send("west") # 到 daoist_temple
            await read_until("三清古觀")

            await send("ask kumu about 定脈")
            res = await read_until("太上定脈鎮山符")
            assert "太上定脈鎮山符" in res, "老道士應給予太上定脈鎮山符！"

            # 6. 測試 5: 前往北崖古礦口與地下崩塌深層坑道
            print("\n=== [測試 5]: 前往地下崩塌坑道、伏地聽風與破石開道 ===")
            await send("east") # 回 square
            await read_until("青石街市")
            await send("north") # 到 mine
            res = await read_until("黑石斷崖・古礦道口")
            assert "古礦道口" in res, "應抵達北崖礦道口！"

            await send("down") # 進入地下深層坑道
            res = await read_until("斷龍卡隼石")
            assert "斷龍卡隼石" in res, "應進入地下百米崩塌坑道！"

            await send("listen")
            res = await read_until("三長兩短")
            assert "三長兩短" in res and "魯大山" in res, "聽風應能辨得老礦工敲軌暗號！"

            await send("strike stone")
            res = await read_until("卡隼石轟然爆碎")
            assert "爆碎" in res or "暗道" in res, "百煉鋼鑿應能擊碎石眼開闢暗道！"

            # 7. 測試 6: 攀回礦道口
            print("\n=== [測試 6]: 順索攀回礦道口 ===")
            await send("up")
            res = await read_until("黑石斷崖")
            assert "黑石斷崖" in res or "古礦道口" in res, "應能順利攀回地面！"

            print("\n🎉 【全數通過！】第 13-14 章 MUD 房間、NPC、信物、地圖與深坑破石互動完美整合！")

    finally:
        print("🛑 關閉伺服器...")
        server.terminate()
        server.wait()
        subprocess.run(f"rm -f forgotten-space/data/user/{test_user}.o", shell=True)

if __name__ == "__main__":
    asyncio.run(test_integration())
