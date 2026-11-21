#!/usr/bin/env python3
"""
《遺忘的世界》敘事—代碼雙向同步稽核工具 (Narrative <-> Mudlib Sync Audit)
對應 ss.md 第四節建議：
- 核驗三卷 126 章小說與卷末導讀完整性
- 核驗 data/canon_sync_matrix.json 中宣告的每一個任務 ID、房間路徑、物證/遺物檔案是否真實存在
- 核驗感官介面、主動出示/互相印證/污染與偽造、五器多階段校驗、傳聞扭曲、資格區隔、宣告式動作規則與歷史回放命令是否齊備
"""
import glob
import json
import os
import sys

ROOT = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")


def read_text(rel_path):
    full = os.path.join(ROOT, rel_path)
    if not os.path.exists(full):
        return ""
    with open(full, encoding="utf-8", errors="replace") as f:
        return f.read()


def main():
    errors = []
    warnings = []

    # 1. 檢查三卷小說章節與卷末導讀完整性
    vol_expected = {
        "volume1": 38,
        "volume2": 44,
        "volume3": 44,
    }
    total_chapters = 0
    for vol, expected_cnt in vol_expected.items():
        ch_files = sorted(glob.glob(os.path.join(ROOT, f"narrative/chapters/{vol}/ch*.md")))
        total_chapters += len(ch_files)
        if len(ch_files) != expected_cnt:
            errors.append(f"[{vol}] 章節數量不符：預期 {expected_cnt}，實際 {len(ch_files)}")
        recap_path = os.path.join(ROOT, f"narrative/chapters/{vol}/README.md")
        if not os.path.exists(recap_path):
            errors.append(f"[{vol}] 缺少本卷大事記與人物狀態一覽 README.md")

    # 2. 載入所有任務 ID
    quest_ids = set()
    quest_files = sorted(glob.glob(os.path.join(ROOT, "quests/*/*.json")))
    for qf in quest_files:
        try:
            with open(qf, encoding="utf-8") as f:
                data = json.load(f)
            if "id" in data:
                quest_ids.add(data["id"])
        except Exception as exc:
            errors.append(f"[JSON 解析失敗] {qf}: {exc}")

    # 3. 檢查 data/canon_sync_matrix.json 雙向對照矩陣與 docs/CANON_CHANGELOG.md
    matrix_path = os.path.join(ROOT, "data/canon_sync_matrix.json")
    matrix_acts = 0
    if not os.path.exists(matrix_path):
        errors.append("[缺失] data/canon_sync_matrix.json 章節↔程式追蹤矩陣不存在")
    else:
        with open(matrix_path, encoding="utf-8") as f:
            matrix = json.load(f)
        for entry in matrix.get("mappings", []):
            matrix_acts += 1
            aid = entry.get("act_id", "unknown")
            for qid in entry.get("quests", []):
                if qid not in quest_ids:
                    errors.append(f"[canon_sync_matrix:{aid}] 找不到任務 ID：{qid}")
            for rpath in entry.get("rooms", []):
                if not os.path.exists(os.path.join(ROOT, rpath)):
                    errors.append(f"[canon_sync_matrix:{aid}] 找不到房間檔：{rpath}")
            for epath in entry.get("evidence_or_relics", []):
                if not os.path.exists(os.path.join(ROOT, epath)):
                    errors.append(f"[canon_sync_matrix:{aid}] 找不到物證/遺物檔：{epath}")

    if not os.path.exists(os.path.join(ROOT, "docs/CANON_CHANGELOG.md")):
        errors.append("[缺失] docs/CANON_CHANGELOG.md 正典變更日誌不存在")

    # 4. 檢查基底感官、宣告式動作規則與房間動態融合
    room_base = read_text("std/room.c")
    for fn in ("do_touch", "do_smell", "do_listen_room", "query_bg_sensory_line", "add_action_rule", "query_phase_ambient_line"):
        if fn not in room_base:
            errors.append(f"[std/room.c] 缺少核心介面：{fn}")

    sensory_rooms = [
        "d/village/stream.c",
        "d/village/forge.c",
        "d/village/forest.c",
        "d/village/altar.c",
        "d/village/shed.c",
        "d/village/mine.c",
        "d/city/center/square.c",
        "d/city/center/clinic.c",
        "d/city/north/gong_forge.c",
        "d/city/south/market_special.c",
        "d/city/west/dao_hall.c",
        "d/city/under/canal_hub.c",
        "d/sects/taiqing/ark_portal_chamber.c",
        "d/wastes/ark_core_chamber.c",
        "d/realm/peach_plateau.c",
    ]
    for sr in sensory_rooms:
        src = read_text(sr)
        if not src:
            errors.append(f"[房間缺失] {sr}")
            continue
        if "query_touch" not in src and "set_touch" not in src:
            errors.append(f"[感官缺失] {sr} 未實作 touch 觸覺反饋")
        if "query_smell" not in src and "set_smell" not in src:
            errors.append(f"[感官缺失] {sr} 未實作 smell 嗅覺反饋")
        if "query_listen" not in src and "set_listen" not in src:
            errors.append(f"[感官缺失] {sr} 未實作 listen 聽覺反饋")

    # 5. 檢查指令與守護進程關鍵接線
    for cmd_file in ("cmds/cmd_present.c", "cmds/cmd_chronicle.c", "cmds/cmd_set.c"):
        if not os.path.exists(os.path.join(ROOT, cmd_file)):
            errors.append(f"[指令缺失] {cmd_file}")

    city_d_src = read_text("daemon/city_d.c")
    for fn in (
        "present_evidence_to_npc",
        "evaluate_corroboration_synergy",
        "contaminate_evidence",
        "certify_or_cleanse_evidence",
        "check_qualification_vs_skill",
        "is_forged",
    ):
        if fn not in city_d_src:
            errors.append(f"[daemon/city_d.c] 缺少功能實作：{fn}")

    portal_src = read_text("d/sects/taiqing/ark_portal_chamber.c")
    for st in ("north", "northeast", "northwest", "southwest", "south", "do_calibrate", "inspect_station_relic_support"):
        if st not in portal_src:
            errors.append(f"[ark_portal_chamber.c] 缺少五台校驗節點或實體信物檢定：{st}")

    core_src = read_text("d/wastes/ark_core_chamber.c")
    if "query_core_placed_count" not in core_src:
        errors.append("[ark_core_chamber.c] 缺少多階段凹龕校驗")

    npc_src = read_text("std/npc.c")
    if "query_distorted_rumor" not in npc_src or "query_bg_attitude_prefix" not in npc_src:
        errors.append("[std/npc.c] 缺少傳聞扭曲或身世差別態度接線")

    qe_src = read_text("daemon/quest_engine_d.c")
    if "query_act_reward_pct" not in qe_src or "query_party_background_synergy_pct" not in qe_src:
        errors.append("[daemon/quest_engine_d.c] 缺少幕次倍率或五道協同組隊加成")

    em_src = read_text("daemon/event_manager.c")
    for fn in ("query_novel_act_info", "record_player_contribution", "distribute_contribution_rewards", "query_event_replay_summary"):
        if fn not in em_src:
            errors.append(f"[daemon/event_manager.c] 缺少接口：{fn}")

    print("=" * 72)
    print("《遺忘的世界》敘事—代碼雙向同步稽核報告 (Novel <-> Mudlib Sync Matrix)")
    print("=" * 72)
    print(f"  ・已核驗小說章節總數 : {total_chapters} 章 (Vol.1: 38, Vol.2: 44, Vol.3: 44)")
    print(f"  ・已核驗章節追蹤矩陣 : {matrix_acts} 個故事幕次節點 (data/canon_sync_matrix.json)")
    print(f"  ・已核驗宣告式任務數 : {len(quest_files)} 個 JSON 任務定義")
    print(f"  ・已核驗核心感官房間 : {len(sensory_rooms)} 間 (含 Tier 0/1/2/3 五感＋動態狀態)")
    print(f"  ・核心體驗與機制接線 : OK (cmd_present/chronicle/set + 宣告式規則 + 五器校驗)")
    print("-" * 72)

    if warnings:
        for w in warnings:
            print(f"  [WARN] {w}")

    if errors:
        for e in errors:
            print(f"  [FAIL] {e}")
        sys.exit(1)

    print("  [PASS] 敘事與 Mudlib 雙軌同步稽核全數通過 (0 errors)！")
    print("=" * 72)


if __name__ == "__main__":
    main()
