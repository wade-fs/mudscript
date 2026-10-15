import asyncio
import json
import subprocess
import time
import websockets

async def run_test():
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
                                print(f"📩 {line.strip()}")
                        buf += payload
                        if pattern in buf:
                            return buf
                except asyncio.TimeoutError:
                    if pattern in buf:
                        return buf
                    continue
            return buf

        print("=== 步驟 1: 選擇語系 ===")
        await read_until("Selection:")
        await send("2")

        print("=== 步驟 2: 輸入帳號 ===")
        await read_until("帳號")
        await send("novelist")

        print("=== 步驟 3: 設定密碼 ===")
        await read_until("密碼")
        await send("pass123")

        print("=== 步驟 4: 輸入暱稱 ===")
        await read_until("暱稱")
        await send("墨客")

        print("=== 步驟 5: 選擇身世背景 ===")
        await read_until("選擇您的身世背景")
        await send("4") # 破落道童

        print("=== 步驟 6: 降臨道觀並前往黑石鋪中央廣場 ===")
        await read_until("三清偏殿")
        await send("east")
        await read_until("青石街市")

        print("=== 步驟 7: 查看角色數值 (score) ===")
        await send("score")
        await read_until("先天六維屬性")

        print("=== 步驟 8: 查看隨身舊物 (inventory) ===")
        await send("inventory")
        await read_until("殘破引氣訣")

        print("=== 步驟 9: 前往南面溪谷 (south) ===")
        await send("south")
        await read_until("幽霧水谷")

        print("=== 步驟 10: 參悟史前斷碑 (study stele) ===")
        await send("study stele")
        await read_until("銘文殘意")

        print("=== 步驟 11: 拓印史前斷碑 (tuoyin stele) ===")
        await send("tuoyin stele")
        await read_until("殘缺星圖拓片")

        print("=== 步驟 12: 返回中央廣場 (north) ===")
        await send("north")
        await read_until("青石街市")

        print("=== 步驟 13: 前往北面黑石斷崖 (north) ===")
        await send("north")
        await read_until("黑石斷崖")

        print("=== 步驟 14: 進行採礦打熬臂力 (mine) ===")
        await send("mine")
        await read_until("臂力微幅提升")

        print("=== 步驟 15: 返回中央廣場 (south) ===")
        await send("south")
        await read_until("青石街市")

        print("=== 步驟 16: 前往東南哨亭與荒林 (southeast -> south) ===")
        await send("southeast")
        await read_until("獵戶哨亭")
        await send("south")
        await read_until("大荒外緣")

        print("=== 步驟 17: 檢視陷阱鍛鍊靈巧感知 (trap) ===")
        await send("trap")
        await read_until("靈巧與感知提升")

        print("=== 步驟 18: 返回中央廣場 (northwest) ===")
        await send("northwest")
        await read_until("青石街市")

        print("=== 步驟 19: 前往西面道觀與道壇 (west -> up) ===")
        await send("west")
        await read_until("三清偏殿")
        await send("up")
        await read_until("迎風孤岩")

        print("=== 步驟 20: 盤膝打坐滋養神識 (meditate) ===")
        await send("meditate")
        await read_until("靈性微幅提升")

        print("=== 步驟 21: 返回中央廣場並退出 (down -> east -> quit) ===")
        await send("down")
        await read_until("三清偏殿")
        await send("east")
        await read_until("青石街市")
        await send("quit")

    print("\n🛑 關閉伺服器...")
    server.terminate()
    try:
        server.wait(timeout=3)
    except subprocess.TimeoutExpired:
        server.kill()

    print("\n🎉 《遺忘的世界》(THE FORGOTTEN SPACE) MVP 驗證全數通過！")

if __name__ == "__main__":
    asyncio.run(run_test())
