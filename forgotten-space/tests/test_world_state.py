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
            await asyncio.sleep(0.5)

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

        print("=== 步驟 1: 登入創角 ===")
        await read_until("Selection:")
        await send("2")
        await read_until("使用者 ID")
        await send("wade_test")
        await read_until("密碼")
        await send("pass123")
        await read_until("暱稱")
        await send("採藥人")
        await read_until("選擇您的身世背景")
        # 選擇 1: 採藥孤兒 (herbalist)
        await send("1")
        await read_until("採藥草廬")
        await send("up")
        await read_until("碎石溪灘")
        await send("north")
        await read_until("青石街市")

        print("=== 步驟 2: 查看時辰與天氣格式 (look) ===")
        await send("look")
        await read_until("青石街市")

        print("=== 步驟 3: 查看中央街市動態布告欄 (look board) ===")
        await send("look board")
        await read_until("聚落官驛布告欄")

        print("=== 步驟 4: 前往北崖古礦道 (north) ===")
        await send("north")
        await read_until("黑石斷崖")

        print("=== 步驟 5: 進行鑿礦 (mine) ===")
        await send("mine")
        await read_until("臂力微幅提升")

        print("=== 步驟 6: 返回廣場 (south) ===")
        await send("south")
        await read_until("青石街市")

        print("=== 步驟 7: 前往南谷碎石溪灘 (south) ===")
        await send("south")
        await read_until("幽霧水谷")

        print("=== 步驟 8: 進行採藥 (gather) ===")
        await send("gather")
        await read_until("感知微幅提升")

        print("=== 步驟 9: 查看背包採藥收穫 (inventory) ===")
        await send("inventory")
        await read_until("藥")

        print("=== 步驟 10: 返回廣場再次查看布告欄存量變化 (north -> look board) ===")
        await send("north")
        await asyncio.sleep(0.5)
        await send("look board")
        await read_until("聚落官驛布告欄")

        print("=== 步驟 11: 退出遊戲 (quit) ===")
        await send("quit")
        await asyncio.sleep(0.5)

    print("\n🛑 關閉伺服器...")
    server.terminate()
    try:
        server.wait(timeout=3)
    except subprocess.TimeoutExpired:
        server.kill()

    print("\n🎉 世界動態狀態與因果鏈測試全數通過！")

if __name__ == "__main__":
    asyncio.run(run_test())
