import asyncio
import json
import subprocess
import time
import websockets

BACKGROUND_TESTS = [
    {
        "id": "hero_herb",
        "nick": "雲靈",
        "bg_choice": "1",
        "bg_name": "採藥孤兒",
        "room_name": "懸崖峭壁・採藥草廬",
        "npc_name": "葛半仙",
        "ask_topic": "身世",
        "expected_response": "南谷溪灘的大石板上啼哭",
        "nav_cmds": [
            ("up", "幽霧水谷・碎石溪灘"),
            ("north", "黑石鋪・青石街市"),
            ("south", "幽霧水谷・碎石溪灘"),
            ("down", "懸崖峭壁・採藥草廬"),
        ]
    },
    {
        "id": "hero_smith",
        "nick": "鐵心",
        "bg_choice": "2",
        "bg_name": "打鐵學徒",
        "room_name": "老鐵匠鋪・打鐵爐房",
        "npc_name": "阿鐵",
        "ask_topic": "身世",
        "expected_response": "廢鐵堆裡揀出來的",
        "nav_cmds": [
            ("west", "黑石鋪・青石街市"),
            ("east", "老鐵匠鋪・打鐵爐房"),
        ]
    },
    {
        "id": "hero_hunt",
        "nick": "驚鴻",
        "bg_choice": "3",
        "bg_name": "獵戶之子",
        "room_name": "林邊茅屋・獵戶哨亭",
        "npc_name": "趙老獵",
        "ask_topic": "身世",
        "expected_response": "生鏽柴刀",
        "nav_cmds": [
            ("south", "大荒外緣・荊棘林口"),
            ("north", "林邊茅屋・獵戶哨亭"),
            ("west", "黑石鋪・青石街市"),
            ("southeast", "林邊茅屋・獵戶哨亭"),
        ]
    },
    {
        "id": "hero_dao",
        "nick": "清風",
        "bg_choice": "4",
        "bg_name": "破落道童",
        "room_name": "破落道觀・三清偏殿",
        "npc_name": "枯木",
        "ask_topic": "身世",
        "expected_response": "殘觀雖漏風飄雨",
        "nav_cmds": [
            ("up", "迎風孤岩・荒廢道壇"),
            ("down", "破落道觀・三清偏殿"),
            ("east", "黑石鋪・青石街市"),
            ("west", "破落道觀・三清偏殿"),
        ]
    },
    {
        "id": "hero_beggar",
        "nick": "九指",
        "bg_choice": "5",
        "bg_name": "流浪乞兒",
        "room_name": "客棧背街・廢柴房",
        "npc_name": "莫三",
        "ask_topic": "身世",
        "expected_response": "粗布乾糧袋",
        "nav_cmds": [
            ("northeast", "黑石鋪・青石街市"),
            ("southwest", "客棧背街・廢柴房"),
        ]
    },
]

async def test_single_background(t, uri):
    print(f"\n==========================================")
    print(f"🌲 測試身世 [{t['bg_choice']}]: {t['bg_name']} ({t['id']})")
    print(f"==========================================")

    async with websockets.connect(uri) as ws:
        async def send(cmd):
            print(f"👉 [{t['id']}]: {cmd}")
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

        # 語系與帳密
        await read_until("Selection:")
        await send("2")
        await read_until("帳號")
        await send(t["id"])
        await read_until("密碼")
        await send("pass123")
        await read_until("暱稱")
        await send(t["nick"])

        # 選擇身世
        await read_until("選擇您的身世背景")
        await send(t["bg_choice"])

        # 驗證降臨專屬房間
        print(f"🎯 檢查降臨房間: {t['room_name']}")
        await read_until(t["room_name"])

        # 檢查該房間有導師 NPC
        print(f"🎯 檢查導師 NPC 存在: {t['npc_name']}")
        await read_until(t["npc_name"])

        # 與導師對話
        print(f"🎯 詢問導師背景: ask about {t['ask_topic']}")
        await send(f"ask {t['npc_name']} about {t['ask_topic']}")
        await read_until(t["expected_response"])

        # 測試雙向導航
        for cmd, expected_room in t["nav_cmds"]:
            print(f"🚶 移動: {cmd} -> 期望抵達: {expected_room}")
            await send(cmd)
            await read_until(expected_room)

        print(f"✅ 身世 [{t['bg_name']}] 出生地、導師對話與連通導航全數通過！")
        await send("quit")

async def run_all_tests():
    # 清理舊的測試存檔
    subprocess.run("rm -f forgotten-space/data/user/hero_*.o", shell=True)

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
        for t in BACKGROUND_TESTS:
            await test_single_background(t, uri)
        print("\n🎉🎉🎉 五大身世出生地、導師與新手村十房間互通測試全部通過！🎉🎉🎉")
    finally:
        print("\n🛑 關閉伺服器...")
        server.terminate()
        try:
            server.wait(timeout=3)
        except subprocess.TimeoutExpired:
            server.kill()

if __name__ == "__main__":
    asyncio.run(run_all_tests())
