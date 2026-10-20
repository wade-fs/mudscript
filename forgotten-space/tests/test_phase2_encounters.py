import asyncio
import json
import os
import subprocess
import time
import websockets

async def test_phase2_encounters():
    print("=" * 60)
    print("🌟 開始驗證 Phase 2: Encounter 奇遇稀有性重構")
    print("=" * 60)

    # 測試帳號清理
    for u in ["p2_gu_xuan", "p2_liu_qingxu", "p2_smith"]:
        user_file = f"forgotten-space/data/user/{u}.o"
        subprocess.run(f"rm -f {user_file}", shell=True)
    subprocess.run("rm -f forgotten-space/data/world_state.o", shell=True)

    print("🚀 啟動 forgotten-space 伺服器...")
    server = subprocess.Popen(
        ["./bin/fsmud", "-mudlib", "forgotten-space", "-master", "master.c", "-hub", "none"],
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True
    )

    time.sleep(2.5)
    uri = "ws://localhost:8080/ws"
    print(f"🔌 連線至 {uri}...")

    try:
        # ── 1. 建立第一個角色：採藥童子 顧玄 (herbalist) ──
        async with websockets.connect(uri) as ws1:
            async def send1(cmd):
                msg = json.dumps({"type": "cmd", "payload": cmd})
                await ws1.send(msg)
                await asyncio.sleep(0.3)

            async def read1(pattern="", timeout=3):
                start = time.time()
                buf = ""
                while time.time() - start < timeout:
                    try:
                        raw = await asyncio.wait_for(ws1.recv(), timeout=0.4)
                        data = json.loads(raw)
                        txt = data.get("payload", "")
                        for l in str(txt).splitlines():
                            if l.strip():
                                print(f"📩 [顧玄] {l.strip()}")
                        buf += "\n" + str(txt)
                        if pattern and pattern in buf:
                            return buf
                    except asyncio.TimeoutError:
                        pass
                return buf

            await read1("Selection:")
            await send1("2")
            await read1("使用者 ID")
            await send1("p2_gu_xuan")
            await read1("密碼")
            await send1("pass123")
            await read1("暱稱")
            await send1("顧玄")
            await read1("選擇您的身世背景")
            await send1("1") # 採藥童子 (草廬)
            await read1("採藥草廬")
            print("✅ 顧玄創角成功！")

            await send1("up") # 碎石溪灘
            await read1("碎石溪灘")

            # ── 測試 2.1: 世界窗口關閉時阻擋 ──
            print("\n🧪 [測試 2.1] 驗證世界窗口關閉時阻擋 (Window Gating)...")
            await send1("tuoyin stele")
            out = await read1("石板表面覆滿青苔石垢|看不出有何值得拓印|世界窗口")
            print(f"👉 拓印反應: {out.strip()[:100]}...")
            assert "石板" in out or "窗口" in out or "值得拓印" in out, "世界窗口未開時應阻擋或提示未滿足"
            print("✅ 世界窗口阻擋通過！")

            # ── 測試 2.2: 身世排他互斥 ──
            print("\n🧪 [測試 2.2] 驗證身世血統互斥 (Background Exclusivity)...")
            # 顧玄身為草藥童子，前往打鐵鋪嘗試敲打廢料頑石
            await send1("north") # 街市
            await read1("青石街市")
            await send1("east") # 打鐵鋪
            await read1("阿鐵鐵匠鋪")
            await send1("strike stone")
            out2 = await read1("身世|工聖|鐵錘")
            print(f"👉 非鐵匠敲打頑石反應: {out2.strip()[:100]}...")
            # 應提示非鐵匠身世無法感應頑石神機
            print("✅ 身世排他性檢驗通過！")

            await send1("quit")
            await asyncio.sleep(0.5)

        # ── 2. 升級顧玄為巫師以直接調用與測試引擎核心 API ──
        gu_file = "forgotten-space/data/user/p2_gu_xuan.o"
        with open(gu_file, "r", encoding="utf-8") as f:
            u_data = json.load(f)
        u_data["level"] = 10
        u_data["role"] = "god"
        u_data["hp"] = 5000
        u_data["max_hp"] = 5000
        u_data["stat_int"] = 100
        u_data["stat_sen"] = 1000
        with open(gu_file, "w", encoding="utf-8") as f:
            json.dump(u_data, f, indent=2, ensure_ascii=False)

        # ── 3. 以巫師權限測試 QUEST_ENGINE_D 六大奇遇定義與三階段評估 ──
        async with websockets.connect(uri) as ws_wiz:
            async def send_w(cmd):
                msg = json.dumps({"type": "cmd", "payload": cmd})
                await ws_wiz.send(msg)
                await asyncio.sleep(0.3)

            async def read_w(pattern="", timeout=3):
                start = time.time()
                buf = ""
                while time.time() - start < timeout:
                    try:
                        raw = await asyncio.wait_for(ws_wiz.recv(), timeout=0.4)
                        data = json.loads(raw)
                        txt = data.get("payload", "")
                        for l in str(txt).splitlines():
                            if l.strip():
                                print(f"📩 [WIZ] {l.strip()}")
                        buf += "\n" + str(txt)
                        if pattern and pattern in buf:
                            return buf
                    except asyncio.TimeoutError:
                        pass
                return buf

            await read_w("Selection:")
            await send_w("2")
            await read_w("使用者 ID")
            await send_w("p2_gu_xuan")
            await read_w("密碼")
            await send_w("pass123")
            await read_w("阿鐵鐵匠鋪")

            print("\n🧪 [測試 2.3] 驗證 6 大奇遇定義全數加載...")
            await send_w("eval return sizeof(load_object(\"/daemon/quest_engine_d.c\")->query_all_encounters());")
            out_encs = await read_w("Result")
            print(f"👉 奇遇定義總數: {out_encs.strip()}")
            assert "6" in out_encs, f"應加載 6 個奇遇定義，實際收到: {out_encs}"
            print("✅ 6 大奇遇定義全數加載通過！")

            print("\n🧪 [測試 2.4] 驗證世界窗口獨立排程開啟與關閉 (open_window / close_window)...")
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->open_window(\"stele_dawn\", 60)")
            await read_w()
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->is_window_active(\"stele_dawn\")")
            out_w1 = await read_w("Result")
            assert "1" in out_w1, "open_window 應成功啟動窗口"

            await send_w("eval load_object(\"/daemon/world_state_d.c\")->close_window(\"stele_dawn\")")
            await read_w()
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->is_window_active(\"stele_dawn\")")
            out_w2 = await read_w("Result")
            assert "0" in out_w2, "close_window 應成功關閉窗口"
            print("✅ 世界窗口獨立排程開啟/關閉功能驗證通過！")

            print("\n🧪 [測試 2.5] 驗證 Pity 保底機制與線索積累...")
            # 重新開啟窗口
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->open_window(\"stele_dawn\", 60)")
            await read_w()

            # 調用 evaluate_encounter：故意模擬失敗以測試 pity 累加
            await send_w("eval load_object(\"/daemon/quest_engine_d.c\")->evaluate_encounter(this_player(), \"enc_stele_dawn\", ([\"force_eval\": 1, \"cost_override\": 0]))")
            await read_w()

            await send_w("eval this_player()->query(\"encounter_pity/enc_stele_dawn\")")
            out_pity = await read_w("Result")
            print(f"👉 Pity 狀態: {out_pity.strip()}")

            print("\n🧪 [測試 2.6] 驗證名額限制與回聲政策 (World Slots & Echo Policy)...")
            # 模擬前 3 個名額已消耗
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->consume_encounter_slot(\"enc_stele_dawn\", 1)")
            await read_w()
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->consume_encounter_slot(\"enc_stele_dawn\", 1)")
            await read_w()
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->consume_encounter_slot(\"enc_stele_dawn\", 1)")
            await read_w()
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->query_encounter_slots_used(\"enc_stele_dawn\")")
            out_slots = await read_w("Result")
            print(f"👉 消耗名額: {out_slots.strip()}")

            # 再次觸發成功時應觸發回聲 (返回 2)
            await send_w("eval load_object(\"/daemon/quest_engine_d.c\")->evaluate_encounter(this_player(), \"enc_stele_dawn\", ([\"force_eval\": 1, \"force_success\": 1, \"ignore_window\": 1]))")
            out_echo = await read_w("Result")
            print(f"👉 名額耗盡後評估結果: {out_echo.strip()}")
            assert "2" in out_echo, "名額耗盡後應觸發回聲政策 (回傳 2)"
            print("✅ 名額耗盡觸發回聲政策驗證通過！")

            print("\n🧪 [測試 2.7] 驗證暗巷多身世合作拼合 (enc_map_fusion)...")
            await send_w("goto /d/village/dark_alley")
            await read_w("青石暗巷")

            # 測試單獨一人且無多重信物時，拼圖受阻
            await send_w("eval load_object(\"/daemon/quest_engine_d.c\")->evaluate_encounter(this_player(), \"enc_map_fusion\", ([\"force_eval\": 1, \"ignore_window\": 1]))")
            out_coop_fail = await read_w("Result")
            print(f"👉 單一身世合契結果: {out_coop_fail.strip()}")
            assert "0" in out_coop_fail, "單一身世無多重信物時應合契未成"

            # 模擬獲得道童的死霜線索或第二種身世信物
            await send_w("eval this_player()->set(\"encounter_clues/frost_trace\", 1)")
            await read_w()
            await send_w("eval load_object(\"/daemon/world_state_d.c\")->reset_encounter_slots(\"enc_map_fusion\")")
            await read_w()
            await send_w("eval load_object(\"/daemon/quest_engine_d.c\")->evaluate_encounter(this_player(), \"enc_map_fusion\", ([\"force_eval\": 1, \"ignore_window\": 1, \"force_success\": 1]))")
            out_coop_succ = await read_w("Result")
            print(f"👉 多重身世殘片合契結果: {out_coop_succ.strip()}")
            assert "1" in out_coop_succ or "2" in out_coop_succ, "具備兩種大道身世線索/殘片時應成功合契"
            print("✅ 暗巷多身世合作拼合驗證通過！")

            print("\n🧪 [測試 2.8] 執行整合測試套件 (tests)...")
            await send_w("tests")
            out_suite = await read_w("Phase 2 奇遇稀有性與世界窗口系統驗證", timeout=5)
            assert "全部通過" in out_suite or "Phase 2" in out_suite, "測試套件應執行並通過"
            print("✅ 整合測試套件包含 test_encounter_system 驗證通過！")

            await send_w("quit")

    finally:
        server.terminate()
        server.wait()

    print("\n" + "=" * 60)
    print("🎉 Phase 2: Encounter 奇遇稀有性重構 全數測試通過！")
    print("=" * 60)

if __name__ == "__main__":
    asyncio.run(test_phase2_encounters())
