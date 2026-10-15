import asyncio
import json
import subprocess
import time
import websockets

async def run_test():
    # 清理舊的測試存檔
    subprocess.run("rm -f forgotten-space/data/user/tester_ch1.o", shell=True)

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

        print("\n=== 步驟 1: 登入 (獵戶之子，攜生鏽柴刀起手) ===")
        await read_until("Selection:")
        await send("2")
        await read_until("帳號")
        await send("tester_ch1")
        await read_until("密碼")
        await send("pass123")
        await read_until("暱稱")
        await send("少年顧玄")
        await read_until("選擇您的身世背景")
        # 3 是獵戶之子 (自帶生鏽柴刀)
        await send("3")
        await read_until("獵戶哨亭")

        print("\n=== 步驟 2: 前往中央街市並南下溪灘 ===")
        await send("west")
        await read_until("青石街市")
        await send("south")
        await read_until("幽霧水谷・碎石溪灘")

        print("\n=== 步驟 3: 驗證張屠戶在場與剔骨砍刀對話 ===")
        await read_until("張屠戶")
        await send("ask 張屠戶 about 磨刀")
        await read_until("大青石上磨刀")

        print("\n=== 步驟 4: 詢問商隊粗鹽情報 ===")
        await send("ask 張屠戶 about 商隊")
        await read_until("粗鹽可就要見底了")

        print("\n=== 步驟 5: 執行洗臉掬水動作 (wash) ===")
        await send("wash")
        await read_until("靈台空明")

        print("\n=== 步驟 6: 在洗衣石板上磨利生鏽柴刀 (sharpen) ===")
        await send("sharpen blade")
        await read_until("雪亮刺目的森森精鋼寒芒")
        # 同時驗證磨刀震落青苔石垢
        await read_until("震落了厚厚石垢")

        print("\n=== 步驟 7: 攀入懸崖草廬 (down) ===")
        await send("down")
        await read_until("採藥草廬")
        await read_until("葛半仙")

        print("\n=== 步驟 8: 採集帶露晨露草並交給葛半仙 (gather -> give) ===")
        await send("up")
        await read_until("碎石溪灘")
        await send("gather")
        await read_until("草")
        await send("down")
        await read_until("採藥草廬")
        await send("give herb to ge")
        await read_until("葛半仙")

        print("\n=== 步驟 9: 爬回溪灘拓印 (tuoyin stele) ===")
        await send("up")
        await read_until("碎石溪灘")
        await send("tuoyin stele")
        await read_until("殘缺星圖拓片")

        await send("quit")

    print("\n🛑 關閉伺服器...")
    server.terminate()
    try:
        server.wait(timeout=3)
    except subprocess.TimeoutExpired:
        server.kill()

    print("\n🎉🎉🎉 小說第一章細節打磨（張屠戶、剔骨刀、磨刀去鏽破石垢、掬水洗臉、給予草藥、拓印）全部驗證通過！🎉🎉🎉")

if __name__ == "__main__":
    asyncio.run(run_test())
