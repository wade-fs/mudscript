import asyncio
import json
import subprocess
import time
import websockets

async def test_epic_stage_quest():
    test_user = "stage_tester"
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

            # 1. 創角登入 (乞兒身世，出生在廢柴房)
            await read_until("Selection:")
            await send("2") # 繁體中文
            await read_until("使用者 ID")
            await send(test_user)
            await read_until("密碼")
            await send("pass123")
            await read_until("暱稱")
            await send("小乞兒")
            await read_until("選擇您的身世背景")
            await send("5") # 流浪乞兒 (出生於廢柴房)
            await read_until("廢柴房")
            print("✅ 成功登入客棧背街廢柴房！")

            # 2. 測試 tasks 指令 (應別名正常運作)
            await send("tasks")
            t_res = await read_until("黑石鋪歷練與任務總覽", timeout=3)
            assert "黑石鋪歷練與任務總覽" in t_res, "tasks 指令應成功呼叫任務總覽"
            assert "太古遺脈・天門引" not in t_res, "未觸發前隱藏奇遇不應顯示在總覽中"
            print("✅ tasks 指令支援與未觸發隱密性驗證通過！")

            # 3. 在廢柴房執行 search wood 觸發史詩隱藏任務 Stage 1
            await send("search wood")
            search_res = await read_until("Stage 1", timeout=3)
            assert "奇遇觸發・太古遺脈・天門引" in search_res, "應觸發奇遇"
            assert "Stage 1・黑石蒙塵" in search_res, "應明確提示 Stage 1"
            assert "chapter" not in search_res.lower(), "不可出現 chapter 詞彙"
            print("✅ 成功藉由 search wood 觸發史詩奇遇 Stage 1！")

            # 4. 驗證 tasks 面板中出現 Stage 1 進行中
            await send("tasks")
            panel_res = await read_until("Stage 1/3 進行中", timeout=3)
            assert "Stage 1/3 進行中" in panel_res, "任務狀態應為 Stage 1/3 進行中"
            assert "[▶] Stage 1：黑石蒙塵" in panel_res, "Stage 1 應標記為進行中"
            assert "[▶] 第 2 步：殘令辨識" in panel_res, "應推進到第 2 步"
            assert "[ ] Stage 2：商海暗潮 (待解鎖・需前往 金石城)" in panel_res, "後續 Stage 應標記待解鎖"
            print("✅ tasks 面板 Stage / Step 階梯展示正確！")

            # 5. 測試信物遺失與莫三補領
            await send("drop token")
            await read_until("你丟下了")
            await send("tasks")
            warn_res = await read_until("身上缺少關鍵信物", timeout=3)
            assert "⚠️ 身上缺少關鍵信物" in warn_res, "丟失信物應有醒目警告"
            assert "mo" in warn_res, "應指引向莫三補領"

            # 向莫三補領
            await send("ask mo about 天門引")
            recover_res = await read_until("你重新獲得了關鍵信物", timeout=3)
            assert "那破銅爛鐵也能丟" in recover_res, "莫三應給出專屬對白"
            assert "天門引" in recover_res, "應重新取得信物"
            print("✅ 隱藏任務信物丟失與補領閉環驗證通過！")

            # 6. 前往鐵匠鋪向阿鐵完成 Stage 1
            await send("northeast") # 回青石街市
            await read_until("青石街市")
            await send("east") # 進鐵匠鋪
            await read_until("打鐵爐房")
            
            await send("ask tie about 殘令")
            tie_res = await read_until("階段達成", timeout=3)
            assert "太古九天商盟的引路權杖" in tie_res, "阿鐵應辨識出太古殘令"
            assert "Stage 1・黑石蒙塵）已告一段落" in tie_res, "應提示 Stage 1 已告一段落"
            assert "金石城" in tie_res, "應指引下一目標地為金石城"
            assert "chapter" not in tie_res.lower(), "不可包含 chapter"
            print("✅ 成功完成 Stage 1 並達成跨地圖休眠指引！")

            # 7. 驗證 tasks 面板進入 DORMANT 休眠狀態
            await send("tasks")
            dormant_res = await read_until("Stage 1 達成・靜候天時", timeout=3)
            assert "Stage 1 達成・靜候天時" in dormant_res, "狀態標籤應為 Stage 1 達成・靜候天時"
            assert "[✓] Stage 1：黑石蒙塵 (黑石鋪 - 已完成)" in dormant_res, "Stage 1 應標記為已完成"
            assert "天命指引：此機緣暫時沉寂，待踏入【金石城】" in dormant_res, "應清晰顯示天命指引"
            assert "[ ] Stage 2：商海暗潮 (待解鎖・需前往 金石城)" in dormant_res, "Stage 2 應保持待解鎖"
            print("✅ tasks 面板 Stage 休眠 (Dormant) 與跨地圖待續驗證全數通過！")

            await send("quit")

    finally:
        print("🛑 關閉伺服器...")
        server.terminate()
        server.wait()

if __name__ == "__main__":
    asyncio.run(test_epic_stage_quest())
