import asyncio
import json
import subprocess
import time
import websockets

class CareerStateMachine:
    def __init__(self):
        self.transitions = []
        self.states = {
            "wu": 0,
            "li": 0,
            "fa": 0
        }

    def record_transition(self, chain, from_state, event, to_state, note=""):
        self.transitions.append({
            "chain": chain,
            "from": from_state,
            "event": event,
            "to": to_state,
            "note": note
        })
        self.states[chain] = to_state
        print(f"🔄 [狀態轉移] {chain.upper()} 鏈: 狀態 {from_state} --({event})--> 狀態 {to_state} | {note}")

    def print_summary(self):
        print("\n" + "=" * 75)
        print("📊 三大道統任務鏈狀態機執行報告")
        print("=" * 75)
        for t in self.transitions:
            print(f"  ● [{t['chain'].upper():2s}] S{t['from']} -> S{t['to']} | 事件: {t['event']:<28s} | {t['note']}")
        print("=" * 75)
        print("🎉 所有狀態轉移均符合狀態機規格，三大道統閉環驗證全數通過！\n")

async def run_state_machine_test():
    sm = CareerStateMachine()
    test_user = "career_tester"
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

        print("\n=== 步驟 1: 登入創角 (打鐵學徒，起始於鐵匠鋪) ===")
        await read_until("Selection:")
        await send("2") # 繁體中文
        await read_until("使用者 ID")
        await send(test_user)
        await read_until("密碼")
        await send("pass123")
        await read_until("暱稱")
        await send("鐵石生")
        await read_until("選擇您的身世背景")
        await send("2") # 打鐵學徒 (獲得 smith_hammer，起始於老鐵匠鋪)
        await read_until("老鐵匠鋪")

        print("\n=== 步驟 2: 查詢初始任務狀態 ===")
        await send("quest")
        res = await read_until("三大道統", timeout=2)
        assert "物修之鏈" in res and "力修之鏈" in res and "法修之鏈" in res

        # ---------------------------------------------------------
        # 物修之鏈 (WU) 狀態機實測
        # ---------------------------------------------------------
        print("\n" + "=" * 50)
        print("🔨 開始執行【物修之鏈・百工互生環】狀態機")
        print("=" * 50)

        # S0 -> S1: 鐵匠鋪內向老鐵匠阿鐵接取
        await send("ask tie about 任務")
        res = await read_until("第 1 階", timeout=3)
        assert "魯大山" in res or "第 1 階" in res
        sm.record_transition("wu", 0, "ask tie about 任務", 1, "阿鐵指派接應北崖老礦工魯大山")

        # S1 -> S2: 前往北崖礦道 (west -> north) 向魯大山詢問
        await send("west")
        await send("north")
        await send("ask lu about 任務")
        res = await read_until("第 2 階", timeout=3)
        assert "粗礦核" in res or "第 2 階" in res
        sm.record_transition("wu", 1, "ask lu about 任務", 2, "魯大山交付粗礦核，囑咐配製活絡散")

        # S2 -> S3: 前往南谷溪灘採藥，下草廬交給葛半仙 (south -> south -> gather -> down -> give)
        await send("south")
        await send("south")
        await send("gather")
        await read_until("晨露草", timeout=3)
        await send("down")
        await send("give dew herb to ge")
        res = await read_until("第 3 階", timeout=3)
        assert "葛氏活絡散" in res or "第 3 階" in res
        sm.record_transition("wu", 2, "gather + give herb to ge", 3, "葛半仙收下晨露草並調配葛氏活絡散")

        # S3 -> S4: 送藥回北崖老礦工魯大山 (up -> north -> north -> give san to lu)
        await send("up")
        await send("north")
        await send("north")
        await send("give san to lu")
        res = await read_until("第 4 階", timeout=3)
        assert "開爐" in res or "第 4 階" in res
        sm.record_transition("wu", 3, "give san to lu", 4, "魯大山服下藥散，傷勢痊癒交代開爐")

        # S4 -> S0 (閉環結算): 返回鐵匠鋪鍛造開爐 (south -> east -> wield -> strike)
        await send("south")
        await send("east")
        await send("wield smith hammer")
        await send("strike ore")
        res = await read_until("恭喜完成一整輪「物修之鏈・百工互生環」歷練", timeout=4)
        assert "恭喜完成一整輪" in res
        sm.record_transition("wu", 4, "wield hammer + strike ore", 0, "開爐鍛造成功，百工閉環結算親和度+10")

        # 驗證物修進度
        await send("quest")
        res = await read_until("物修之鏈", timeout=2)
        assert "傳承親和: 10，已完成輪次: 1" in res

        # ---------------------------------------------------------
        # 力修之鏈 (LI) 狀態機實測
        # ---------------------------------------------------------
        print("\n" + "=" * 50)
        print("🏹 開始執行【力修之鏈・血戰生機環】狀態機")
        print("=" * 50)

        # S0 -> S2: 前往哨亭向趙老獵接取 (west -> southeast -> ask zhao about 任務)
        await send("west")
        await send("southeast")
        await send("ask zhao about 任務")
        res = await read_until("第 2 階", timeout=3)
        assert "陷阱" in res or "第 2 階" in res
        sm.record_transition("li", 0, "ask zhao about 任務", 2, "趙老獵指派荒林戒備與追蹤濁血")

        # S2 -> S3: 前往東林撿拾染煞獸皮並調校陷阱 (south -> get tainted pelt -> trap)
        await send("south") # 從哨亭向南進入荒林
        await send("get tainted pelt")
        await send("trap")
        res = await read_until("第 3 階", timeout=3)
        assert "躁動度" in res or "第 3 階" in res
        sm.record_transition("li", 2, "get pelt + trap", 3, "調校防獸陷阱，拾得染煞異獸皮")

        # S3 -> S4: 前往南谷溪灘磨刀抗煞 (northwest -> south -> sharpen blade)
        await send("northwest") # 從荒林西北返回廣場
        await send("south")     # 向南進入碎石溪灘
        await send("wield blade")
        await send("sharpen blade")
        res = await read_until("第 4 階", timeout=3)
        assert "磨" in res or "第 4 階" in res
        sm.record_transition("li", 3, "sharpen blade", 4, "溪灘巨石磨利鋼刃柴刀，淬礪殺煞意志")

        # S4 -> S0 (閉環結算): 返回哨亭上繳染煞獸皮 (north -> southeast -> give tainted pelt to zhao)
        await send("north")
        await send("southeast")
        await send("give tainted pelt to zhao")
        res = await read_until("恭喜完成一整輪「力修之鏈・血戰生機環」歷練", timeout=4)
        assert "恭喜完成一整輪" in res
        sm.record_transition("li", 4, "give tainted pelt to zhao", 0, "趙老獵檢驗異獸皮，血戰閉環結算親和度+10")

        # 驗證力修進度
        await send("quest")
        res = await read_until("力修之鏈", timeout=2)
        assert "傳承親和: 10，已完成輪次: 1" in res

        # ---------------------------------------------------------
        # 法修之鏈 (FA) 狀態機實測
        # ---------------------------------------------------------
        print("\n" + "=" * 50)
        print("☯️ 開始執行【法修之鏈・天人共鳴環】狀態機")
        print("=" * 50)

        # S0 -> S2: 前往道觀向枯木老道接取 (northwest -> west -> ask kumu about 任務)
        await send("northwest")
        await send("west")
        await send("ask kumu about 任務")
        res = await read_until("第 2 階", timeout=3)
        assert "洗心" in res or "第 2 階" in res
        sm.record_transition("fa", 0, "ask kumu about 任務", 2, "枯木老道指派排查水脈陰煞")

        # S2 -> S3: 前往南谷溪灘掬水洗心 (east -> south -> wash)
        await send("east")
        await send("south")
        await send("wash")
        res = await read_until("第 3 階", timeout=3)
        assert "澄澈" in res or "第 3 階" in res
        sm.record_transition("fa", 2, "wash", 3, "南谷溪灘掬水洗心，澄澈靈台神識")

        # S3 -> S4: 前往道觀後山孤壇仰觀星軌 (north -> west -> up -> stargaze)
        await send("north")
        await send("west")
        await send("up")
        await send("stargaze")
        res = await read_until("第 4 階", timeout=3)
        assert "天羅地網" in res or "第 4 階" in res
        sm.record_transition("fa", 3, "stargaze", 4, "孤岩道壇仰觀天象，堪破偽籠星軌")

        # S4 -> S0 (閉環結算): 返回三清殿向枯木老道回報 (down -> ask kumu about 任務)
        await send("down")
        await send("ask kumu about 任務")
        res = await read_until("恭喜完成一整輪「法修之鏈・天人共鳴環」歷練", timeout=4)
        assert "恭喜完成一整輪" in res
        sm.record_transition("fa", 4, "ask kumu about 任務", 0, "枯木老道撫頂點化，天人共鳴閉環結算親和度+10")

        # ---------------------------------------------------------
        # 最終驗證三大道統成果 (quest & score)
        # ---------------------------------------------------------
        print("\n=== 步驟 3: 驗證三大道統最終成果 (quest & score) ===")
        await send("quest")
        res = await read_until("=======================================", timeout=3)
        print(res)

        await send("score")
        await read_until("潛能", timeout=2)

        await send("quit")

    print("\n🛑 關閉伺服器...")
    server.terminate()
    sm.print_summary()

if __name__ == "__main__":
    asyncio.run(run_state_machine_test())
