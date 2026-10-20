import asyncio
import json
import subprocess
import time
import websockets

async def run_test():
    # 清理舊的測試存檔
    subprocess.run("rm -f forgotten-space/data/user/tester_b*.o", shell=True)

    print("🚀 啟動 forgotten-space 伺服器...")
    server = subprocess.Popen(
        ["./bin/fsmud", "-mudlib", "forgotten-space", "-master", "master.c", "-hub", "none"],
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True
    )

    time.sleep(2)
    uri = "ws://localhost:8080/ws"

    # 封裝單個角色的流程執行器
    async def run_character_session(username, nickname, background_id, callback):
        print(f"\n==========================================")
        print(f"🎮 測試角色: {nickname} (身世 {background_id})")
        print(f"==========================================")
        async with websockets.connect(uri) as ws:
            async def send(cmd):
                print(f"👉 [發送指令]: {cmd}")
                msg = json.dumps({"type": "cmd", "payload": cmd})
                await ws.send(msg)
                await asyncio.sleep(0.35)

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
                                    print(f"  📩 {line.strip()}")
                            buf += payload
                            if pattern in buf:
                                return buf
                    except asyncio.TimeoutError:
                        if pattern in buf:
                            return buf
                        continue
                if pattern not in buf:
                    raise TimeoutError(f"未能在逾時前找到預期文字: '{pattern}'")
                return buf

            # 登入註冊
            await read_until("Selection:")
            await send("2")
            await read_until("帳號")
            await send(username)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send(nickname)
            await read_until("選擇您的身世背景")
            await send(str(background_id))
            
            # 執行該身世的專屬測試邏輯
            await callback(send, read_until)

            # 登出
            await send("quit")

    # 1. 測試打鐵學徒 (林鐵生)
    async def test_smith(send, read_until):
        await read_until("打鐵爐房")
        print("\n--- [打鐵學徒]: 測試拉風箱 (bellows) ---")
        await send("bellows")
        await read_until("狂風如怒濤般灌入地爐底部")

        print("\n--- [打鐵學徒]: 拾取粗礦並手持舊鐵錘鍛造 (strike) ---")
        await send("get ore chunk")
        await read_until("北崖粗鐵礦核")
        await send("wield hammer")
        await read_until("裝備了")
        await send("strike ore")
        await read_until("一聲巨響震徹工坊")

        print("\n--- [打鐵學徒]: 測試淬火水槽 (quench) ---")
        await send("quench")
        await read_until("整槽淬火水劇烈沸騰")

        print("\n--- [打鐵學徒]: 向師傅阿鐵展示造物 ---")
        await send("ask tie about 不融黑鐵")
        await read_until("黑鐵構件")

    # 2. 測試獵戶之子 (燕隼)
    async def test_hunter(send, read_until):
        await read_until("獵戶哨亭")
        print("\n--- [獵戶之子]: 火塘點苦艾草青煙 (smoke) ---")
        await send("smoke")
        await read_until("艾草青煙升騰而起")

        print("\n--- [獵戶之子]: 拾取重弓與破甲箭 ---")
        await send("get heavy bow")
        await read_until("鐵胎柘木重獸弓")
        await send("get bamboo arrow")
        await read_until("重羽破甲竹箭")

        print("\n--- [獵戶之子]: 進入大荒荒林，調校陷阱 (trap) 與追蹤 (track) ---")
        await send("south")
        await read_until("大荒外緣・荊棘林口")
        await send("trap")
        await read_until("重新調校竹刺彈簧與吊繩套鎖")
        await send("track")
        await read_until("暗紫色的焦灼濁血")
        await read_until("太古戰神獵獸圖騰玄柱")

        print("\n--- [獵戶之子]: 與太古戰神圖騰氣血共鳴 (totem) ---")
        await send("totem")
        await read_until("太古戰祖蠻荒血脈共鳴")

        print("\n--- [獵戶之子]: 撿取染煞異獸皮並交給趙老獵 ---")
        await send("get tainted pelt")
        await read_until("染煞異獸皮")
        await send("north")
        await read_until("獵戶哨亭")
        await send("give tainted pelt to zhao")
        await read_until("這是深山泥沼那頭巨獸蛻下的皮甲")

    # 3. 測試破落道童 (柳清虛)
    async def test_daoist(send, read_until):
        await read_until("三清偏殿")
        print("\n--- [破落道童]: 登上後方迎風殘壇 (up) ---")
        await send("up")
        await read_until("迎風孤岩・荒廢道壇")

        print("\n--- [破落道童]: 孤岩殘壇打坐 (meditate) ---")
        await send("meditate")
        await read_until("靈台漸入空明")

        print("\n--- [破落道童]: 撥開老松盤根與松針 (search pine) ---")
        await send("search pine")
        await read_until("道化晶石殘片")

        print("\n--- [破落道童]: 孤壇巔峰仰觀蒼穹 (stargaze) ---")
        await send("stargaze")
        await read_until("天羅地網！星軌逆行")
        await read_until("堪破蒼穹偽籠至暗真相")

        print("\n--- [破落道童]: 下山進入三清殿將道化晶石交給枯木老道 ---")
        await send("down")
        await read_until("三清偏殿")
        await send("give dao crystal to kumu")
        await read_until("想活命，就別信這片天")

    # 4. 測試流浪乞兒 (沈泥)
    async def test_beggar(send, read_until):
        await read_until("客棧背街・廢柴房")
        print("\n--- [流浪乞兒]: 貼牆偷聽客棧後廚與八方情報 (eavesdrop) ---")
        await send("eavesdrop")
        await read_until("保書路引")

        print("\n--- [流浪乞兒]: 拾取地上的豁口破陶碗 ---")
        await send("get broken bowl")
        await read_until("豁口破陶碗")

        print("\n--- [流浪乞兒]: 翻扒腐爛柴堆掘出鐵盒古令 (search wood) ---")
        await send("search wood")
        await read_until("萬物行商・天門引")

        print("\n--- [流浪乞兒]: 向老丐莫三展示天門引 ---")
        await send("give tianmen token to mo")
        await read_until("真正的九天商道")

    try:
        await run_character_session("tester_b2", "少年林鐵生", 2, test_smith)
        await run_character_session("tester_b3", "少年燕隼", 3, test_hunter)
        await run_character_session("tester_b4", "少年柳清虛", 4, test_daoist)
        await run_character_session("tester_b5", "少年沈泥", 5, test_beggar)
    finally:
        print("\n🛑 關閉伺服器...")
        server.terminate()
        try:
            server.wait(timeout=3)
        except subprocess.TimeoutExpired:
            server.kill()

    print("\n🎉🎉🎉 五大身世故事細節 MUD 系統機制全部驗證通過！🎉🎉🎉")

if __name__ == "__main__":
    asyncio.run(run_test())
