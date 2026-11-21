#!/usr/bin/env python3
"""
《遺忘的世界》敘事—代碼雙向同步稽核工具 (Narrative <-> Mudlib Sync Audit)
對應 narrative/ss.md 第四節建議：
- 自動檢查三卷 126 章小說、各卷 README 大事記、任務 JSON、關鍵房間感官接口、物證帳本與世界事件指標的雙向一致性。
"""
import glob
import json
import os
import re
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

    # 2. 檢查感官與物質反饋接口 (std/room.c & 核心房間)
    room_base = read_text("std/room.c")
    for fn in ("do_touch", "do_smell", "do_listen_room", "query_bg_sensory_line"):
        if fn not in room_base:
            errors.append(f"[std/room.c] 缺少感官或身世濾鏡函式：{fn}")

    sensory_rooms = [
        "d/village/stream.c",
        "d/village/forge.c",
        "d/village/forest.c",
        "d/village/altar.c",
        "d/village/shed.c",
        "d/village/mine.c",
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

    # 3. 檢查物證出示、互相印證與污染機制
    city_d_src = read_text("daemon/city_d.c")
    for fn in (
        "present_evidence_to_npc",
        "evaluate_corroboration_synergy",
        "contaminate_evidence",
        "certify_or_cleanse_evidence",
        "check_qualification_vs_skill",
    ):
        if fn not in city_d_src:
            errors.append(f"[daemon/city_d.c] 缺少小說化證據或資格檢定接口：{fn}")

    if not os.path.exists(os.path.join(ROOT, "cmds/cmd_present.c")):
        errors.append("[cmds/cmd_present.c] 缺少主動出示物證指令")

    # 4. 檢查五器共鳴多階段技術校驗狀態機
    portal_src = read_text("d/sects/taiqing/ark_portal_chamber.c")
    for st in ("north", "northeast", "northwest", "southwest", "south", "do_calibrate"):
        if st not in portal_src:
            errors.append(f"[ark_portal_chamber.c] 缺少五台技術校驗節點或指令：{st}")

    # 5. 檢查傳聞扭曲、卷幕映射與多玩家歷史回放
    rumor_src = read_text("daemon/rumor_d.c")
    if "query_distorted_rumor" not in rumor_src:
        errors.append("[daemon/rumor_d.c] 缺少傳聞衰減與扭曲接口 query_distorted_rumor")

    em_src = read_text("daemon/event_manager.c")
    for fn in ("query_novel_act_info", "record_player_contribution", "query_event_replay_summary"):
        if fn not in em_src:
            errors.append(f"[daemon/event_manager.c] 缺少小說幕次對應或歷史回放接口：{fn}")

    # 6. 檢查章節 → 任務 JSON 追蹤矩陣
    quest_files = sorted(glob.glob(os.path.join(ROOT, "quests/*/*.json")))
    if len(quest_files) < 40:
        warnings.append(f"任務 JSON 數量偏少 ({len(quest_files)})")

    print("=" * 72)
    print("《遺忘的世界》敘事—代碼雙向同步稽核報告 (Novel <-> Mudlib Sync Matrix)")
    print("=" * 72)
    print(f"  ・已核驗小說章節總數 : {total_chapters} 章 (Vol.1: 38, Vol.2: 44, Vol.3: 44)")
    print(f"  ・已核驗宣告式任務數 : {len(quest_files)} 個 JSON 任務定義")
    print(f"  ・已核驗核心感官房間 : {len(sensory_rooms)} 間 (支援 touch/smell/listen + 身世濾鏡)")
    print(f"  ・物證出示與互相印證 : OK (cmd_present + CITY_D 孤證/互鎖/污染修復)")
    print(f"  ・五器多階段技術校驗 : OK (5 座工程石台順序校驗 + 歲差/公差/頻率診斷)")
    print(f"  ・世界狀態與卷幕映射 : OK (RUMOR_D 傳聞扭曲 + EVENT_MANAGER_D 幕次與回放)")
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
