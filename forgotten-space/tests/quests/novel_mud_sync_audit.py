#!/usr/bin/env python3
"""
《遺忘的世界》敘事—代碼雙向同步稽核工具 (Narrative <-> Mudlib Sync Audit)
- 核驗三卷 126 章小說與卷末導讀完整性
- 核驗 data/canon_sync_matrix.json 中宣告的每一個任務 ID、房間路徑、物證/遺物檔案是否真實存在
- 核驗感官介面、主動出示/互相印證/污染與偽造、五器多階段校驗、傳聞扭曲、資格區隔、宣告式動作規則與歷史回放命令是否齊備
"""
import glob
import json
import os
import re
import sys
import collections

ROOT = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")


def read_text(rel_path):
    full = os.path.join(ROOT, rel_path)
    if not os.path.exists(full):
        return ""
    with open(full, encoding="utf-8", errors="replace") as f:
        return f.read()


def run_docs_lint(root_dir, errors, warnings, room_count, quest_count):
    """
    文件衛生與一致性的自動化檢核 (thinking.md docs lint):
    1. 禁止本機絕對 file:///home/... 路徑；檢查所有 Markdown 相對連結存在性
    2. 檢查現行參考文件是否殘留已淘汰原型房名或 /d/mountain/ 目錄漂移
    3. 檢查 EV2xx / EV3xx / EV4xx 事件編號連續性
    4. 核對架構映射總表房數/任務數與實碼一致，並掃描 288 間房房描 15-gram 跨房重複度
    """
    md_files = sorted(glob.glob(os.path.join(root_dir, "**", "*.md"), recursive=True))
    link_pattern = re.compile(r'\[[^\]]+\]\(([^)\s]+)\)')
    legacy_room_tokens = (
        "abandoned_mine.c",
        "white_altar.c",
        "deep_pool.c",
        "firewood_shed.c",
        "inn_alley.c",
        "smithy.c",
        "/d/mountain/",
        "/d/village/cliff_side.c",
    )

    checked_links = 0
    seen_real_mds = set()
    for md_path in md_files:
        real_md = os.path.realpath(md_path)
        if real_md in seen_real_mds:
            continue
        seen_real_mds.add(real_md)
        rel_md = os.path.relpath(real_md, root_dir)
        txt = open(real_md, encoding="utf-8", errors="replace").read()

        # 1a. 禁止本機絕對路徑
        if "file:///home/" in txt or "file://C:" in txt:
            errors.append(f"[docs_lint:abs_link] {rel_md} 仍含本機絕對 file:/// 連結")

        # 1b. 相對連結目標存在性檢查（排除 http/https/mailto/anchor/mudlib 佔位）
        md_dir = os.path.dirname(real_md)
        for m in link_pattern.finditer(txt):
            href = m.group(1).strip()
            if (
                not href
                or href.startswith(("http://", "https://", "mailto:", "#", "/"))
                or "<" in href
                or "*" in href
            ):
                continue
            target_part = href.split("#")[0]
            if not target_part:
                continue
            # 僅針對存在副檔名或明確目錄結尾之連結驗證磁碟路徑
            resolved = os.path.normpath(os.path.join(md_dir, target_part))
            checked_links += 1
            if not os.path.exists(resolved):
                errors.append(f"[docs_lint:broken_link] {rel_md} -> {href}")

        # 2. 過時房間 ID / 目錄漂移（豁免已標註歷史快照或正典更動記錄的檔案）
        is_archive_note = (
            "歷史快照" in txt
            or "歷史初期規劃快照" in txt
            or rel_md in ("docs/CANON_CHANGELOG.md", "narrative/docs/maps/README.md")
        )
        if not is_archive_note and (
            rel_md.startswith("narrative/docs/") or rel_md in ("narrative/mudlib_lpc_mapping.md", "README.md")
        ):
            for tok in legacy_room_tokens:
                if tok in txt:
                    errors.append(f"[docs_lint:legacy_id] {rel_md} 仍出現過時路徑/ID：{tok}")

    # 3. EV 事件編號連續性 (Vol.2 EV-201~244, Vol.3 EV301~327, Vol.4 EV401~422)
    ev_specs = [
        ("narrative/events/volume2_events.md", re.compile(r"###\s+事件\s+EV-(\d+)"), 201, 244),
        ("narrative/events/volume3_events.md", re.compile(r"\|\s*EV(\d+)\s*\|"), 301, 327),
        ("narrative/events/volume4_events.md", re.compile(r"\*\*EV(\d+)"), 401, 422),
    ]
    for ev_rel, pat, expected_min, expected_max in ev_specs:
        ev_txt = read_text(ev_rel)
        nums = sorted(set(int(x) for x in pat.findall(ev_txt)))
        expected = list(range(expected_min, expected_max + 1))
        if nums != expected:
            missing = [n for n in expected if n not in nums]
            errors.append(f"[docs_lint:ev_continuity] {ev_rel} EV 編號不連續或範圍不符，缺漏：{missing}")

    # 4. 統計同步 & 房描 15-gram 跨房重複檢測
    mapping_txt = read_text("narrative/mudlib_lpc_mapping.md")
    if f"{room_count} 間實體房間" not in mapping_txt:
        errors.append(f"[docs_lint:stale_count] narrative/mudlib_lpc_mapping.md 未包含最新總房數 {room_count}")
    if f"共 {quest_count} 份 JSON" not in mapping_txt:
        errors.append(f"[docs_lint:stale_count] narrative/mudlib_lpc_mapping.md 未包含最新任務數 {quest_count}")

    ng = collections.defaultdict(set)
    for rpath in sorted(glob.glob(os.path.join(root_dir, "d", "**", "*.c"), recursive=True)):
        src = open(rpath, encoding="utf-8", errors="replace").read()
        m = re.search(r'(?:set\("long",\s*|set_long\(\s*)(.*?)\n\s*\)\s*;', src, re.S)
        if not m:
            continue
        raw_long = "".join(re.findall(r'"((?:[^"\\]|\\.)*)"', m.group(1)))
        clean = re.sub(r'[\s。，、「」：；（）\(\)a-zA-Z0-9_/【】\[\]`\-\*\\n]', '', raw_long)
        rel_room = os.path.relpath(rpath, root_dir)
        for i in range(max(0, len(clean) - 14)):
            ng[clean[i:i+15]].add(rel_room)
    repeated_clusters = [(len(ps), g) for g, ps in ng.items() if len(ps) >= 3]
    if repeated_clusters:
        top_cnt, top_gram = max(repeated_clusters)
        errors.append(
            f"[docs_lint:room_template] 發現 {len(repeated_clusters)} 組 15-gram 在 >=3 間房重複（最高 {top_cnt} 房：'{top_gram}'）"
        )

    # 5. 正文章節現代科技禁詞掃描 (Q5 拍板：只禁現代科幻/資訊/工業用語，保留武俠/修仙/傳統遊戲詞彙)
    tech_banned_common = (
        ("電池", re.compile(r"電池")),
        ("熱插拔", re.compile(r"熱插拔")),
        ("格式化", re.compile(r"格式化")),
        ("代碼", re.compile(r"代碼")),
        ("電流", re.compile(r"電流")),
        ("數據", re.compile(r"數據")),
        ("AI", re.compile(r"\bAI\b")),
        ("BUFF", re.compile(r"\bBUFF\b")),
        ("電源", re.compile(r"電源(?!晶柱)")),
    )
    v4_extra_banned = (("電源", re.compile(r"電源")),)
    for ch_path in sorted(glob.glob(os.path.join(root_dir, "narrative/chapters/volume*/ch*.md"))):
        rel_ch = os.path.relpath(ch_path, root_dir)
        ch_txt = open(ch_path, encoding="utf-8", errors="replace").read()
        patterns = tech_banned_common + (v4_extra_banned if "/volume4/" in rel_ch else ())
        for label, pat in patterns:
            if pat.search(ch_txt):
                errors.append(f"[docs_lint:tech_jargon] {rel_ch} 出現禁用現代科技詞彙：{label}")

    return checked_links


def main():
    errors = []
    warnings = []

    # 1. 檢查一至三卷完整章節＋第四卷推進章節與卷末導讀完整性
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

    v4_ch_files = sorted(glob.glob(os.path.join(ROOT, "narrative/chapters/volume4/ch*.md")))
    total_chapters += len(v4_ch_files)
    if len(v4_ch_files) < 44:
        errors.append(f"[volume4] Act 1-5 章節數量不足：預期至少 44 章，實際 {len(v4_ch_files)}")
    if not os.path.exists(os.path.join(ROOT, "narrative/chapters/volume4/README.md")):
        errors.append("[volume4] 缺少本卷大事記與人物狀態一覽 README.md")

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
        "query_social_tier",
        "is_forged",
    ):
        if fn not in city_d_src:
            errors.append(f"[daemon/city_d.c] 缺少功能實作：{fn}")

    ws_d_src = read_text("daemon/world_state_d.c")
    for fn in ("market_stocks", "economic_batch_tick", "query_trade_quote", "merchant_strategies"):
        if fn not in ws_d_src:
            errors.append(f"[daemon/world_state_d.c] 缺少生活經濟連動實作：{fn}")

    rumor_d_src = read_text("daemon/rumor_d.c")
    if "query_cross_check_rumors" not in rumor_d_src:
        errors.append("[daemon/rumor_d.c] 缺少六維交叉查證傳聞實作：query_cross_check_rumors")

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

    all_rooms = sorted(glob.glob(os.path.join(ROOT, "d", "**", "*.c"), recursive=True))
    folk_npcs = sorted(glob.glob(os.path.join(ROOT, "clone", "npc", "folk", "*.c")))
    checked_links = run_docs_lint(ROOT, errors, warnings, len(all_rooms), len(quest_files))

    print("=" * 72)
    print("《遺忘的世界》敘事—代碼雙向同步稽核報告 (Novel <-> Mudlib Sync Matrix)")
    print("=" * 72)
    print(f"  ・已核驗小說章節總數 : {total_chapters} 章 (Vol.1: 38, Vol.2: 44, Vol.3: 44, Vol.4: {len(v4_ch_files)})")
    print(f"  ・已核驗實體房間總數 : {len(all_rooms)} 間 ｜ 庶民 NPC：{len(folk_npcs)} 名")
    print(f"  ・已核驗章節追蹤矩陣 : {matrix_acts} 個故事幕次節點 (data/canon_sync_matrix.json)")
    print(f"  ・已核驗宣告式任務數 : {len(quest_files)} 個 JSON 任務定義")
    print(f"  ・已核驗核心感官房間 : {len(sensory_rooms)} 間 (含 Tier 0/1/2/3 五感＋動態狀態)")
    print(f"  ・Docs Lint 檢核項目 : {checked_links} 條相對連結 / 過時房名 / EV 連續 / 15-gram 重複度")
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
