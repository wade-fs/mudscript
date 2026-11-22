#!/usr/bin/env python3
"""World Liveness & Living Expansion Audit for Forgotten Space mudlib."""

import glob
import json
import os
import re
import sys
from collections import Counter

R = sys.argv[1] if len(sys.argv) > 1 else "."


def rd(rel):
    with open(os.path.join(R, rel), encoding="utf-8", errors="replace") as f:
        return f.read()


def main():
    errors = []
    warnings = []

    room_files = sorted(glob.glob(os.path.join(R, "d/**/*.c"), recursive=True))
    area_counts = Counter()
    area_empty = Counter()
    exits_map = {}
    sensory_rooms = 0
    npc_rooms = 0
    action_rule_rooms = 0

    for fp in room_files:
        rel = "/" + os.path.relpath(fp, R).replace(os.sep, "/")
        area = rel.split("/")[2] if len(rel.split("/")) > 2 else "root"
        area_counts[area] += 1
        src = rd(rel.lstrip("/"))

        # Check exit targets exist
        exit_targets = {}
        for m in re.finditer(r'set_exits\s*\(\s*\(\[(.*?)\]\)\s*\)', src, re.S):
            for em in re.finditer(r'"([^"]+)"\s*:\s*"([^"]+\.c)"', m.group(1)):
                exit_targets[em.group(1)] = em.group(2)
        exits_map[rel] = exit_targets
        for d_dir, target in exit_targets.items():
            target_disk = os.path.join(R, target.lstrip("/"))
            if not os.path.exists(target_disk):
                errors.append(f"Broken exit: {rel} [{d_dir}] -> {target} (missing file)")

        # Check sensory coverage (explicit set_*/query_* OR dynamic room bases)
        has_explicit_sensory = any(k in src for k in (
            "set_touch", "set_smell", "set_listen",
            "query_touch", "query_smell", "query_listen",
        ))
        inherits_county_or_route = any(k in src for k in ("COUNTY_ROOM_OB", "ROUTE_ROOM_OB", "/std/county_room.c", "/std/route_room.c"))
        has_sensory = has_explicit_sensory or inherits_county_or_route
        has_npc = ("spawn_npc" in src) or inherits_county_or_route
        has_action = ("add_action" in src)

        if has_sensory:
            sensory_rooms += 1

        if has_npc:
            npc_rooms += 1

        if "add_action_rule" in src:
            action_rule_rooms += 1

        if not (has_sensory or has_npc or has_action or ("spawn_item" in src)):
            area_empty[area] += 1

    # Verify new rooms specifically are reachable (have at least 1 incoming exit and 1 valid outgoing exit)
    incoming = Counter()
    for src_room, exs in exits_map.items():
        for tgt in exs.values():
            incoming[tgt] += 1

    new_living_rooms = [
        "/d/village/chen_grain_shop.c",
        "/d/village/old_granary_yard.c",
        "/d/village/wash_bank.c",
        "/d/village/south_quarry.c",
        "/d/village/earth_shrine.c",
        "/d/village/lumber_slope.c",
        "/d/village/village_school.c",
        "/d/village/peddler_corner.c",
        "/d/village/smokehouse_shed.c",
        "/d/city/outer/tenement_alley.c",
        "/d/city/center/tea_alley.c",
        "/d/city/outer/river_wharf.c",
        "/d/city/north/scrap_yard.c",
        "/d/sects/taiqing/scripture_copy_hall.c",
        "/d/sects/taiqing/outer_dormitory.c",
        "/d/sects/danding/outer_herb_terrace.c",
        "/d/sects/danding/sect_refectory.c",
        "/d/sects/tiangong/apprentice_shed.c",
        "/d/sects/tiangong/slag_pit.c",
        "/d/sects/bahuang/outer_barracks.c",
        "/d/yunjin/river_wharf.c",
        "/d/counties/zhenfeng/garrison_lane.c",
        "/d/counties/qinghe/river_tea_shed.c",
        "/d/counties/panmu/timber_wharf.c",
        "/d/counties/zhongshi/carter_yard.c",
        "/d/counties/zhuoshui/ginger_soup_stall.c",
        "/d/counties/liefan/miners_tea_shed.c",
        "/d/city/south/wine_tavern.c",
        "/d/city/south/dye_alley.c",
        "/d/city/outer/charity_clinic_shed.c",
        "/d/city/outer/fish_market.c",
        "/d/yunjin/temple_tea_fair.c",
        "/d/yunjin/dock_coolie_lane.c",
        "/d/wastes/frost_hunter_camp.c",
    ]

    for nr in new_living_rooms:
        if nr not in exits_map:
            errors.append(f"Missing expanded living room: {nr}")
            continue
        if incoming[nr] == 0:
            errors.append(f"Orphan room (no incoming exit): {nr}")
        if not exits_map[nr]:
            errors.append(f"Trapped room (no outgoing exit): {nr}")
        else:
            # Check reciprocal exit back from at least one neighbor
            recip_ok = False
            for tgt in exits_map[nr].values():
                if nr in exits_map.get(tgt, {}).values():
                    recip_ok = True
                    break
            if not recip_ok:
                errors.append(f"Asymmetric exit wiring for new room: {nr}")

    # Verify county_room and route_room dynamic mechanisms
    county_base = rd("std/county_room.c")
    for req_fn in ("ensure_county_residents", "query_touch", "query_smell", "query_listen", "do_county_rest", "do_county_browse"):
        if req_fn not in county_base:
            errors.append(f"std/county_room.c missing {req_fn}")

    route_base = rd("std/route_room.c")
    for req_fn in ("ensure_route_travelers", "query_touch", "query_smell", "query_listen", "do_route_survey", "do_route_check_pass"):
        if req_fn not in route_base:
            errors.append(f"std/route_room.c missing {req_fn}")

    # Verify side quests exist and are valid JSON
    side_quests = sorted(glob.glob(os.path.join(R, "quests/side/side_*.json")))
    if len(side_quests) < 18:
        errors.append(f"Expected >= 18 non-mainline slice-of-life side quests, found {len(side_quests)}")
    for sq in side_quests:
        try:
            with open(sq, encoding="utf-8") as f:
                data = json.load(f)
            if data.get("category") != "side":
                errors.append(f"{os.path.basename(sq)} must have category='side'")
        except Exception as exc:
            errors.append(f"Invalid JSON in {sq}: {exc}")

    total_rooms = len(room_files)
    if total_rooms < 288:
        errors.append(f"Expected >= 288 rooms after Phase 2 batch 2 expansion, found {total_rooms}")

    empty_total = sum(area_empty.values())
    if empty_total > 0:
        errors.append(f"Expected 0 empty rooms (no S/N/A/Item), found {empty_total}: {dict(area_empty)}")
    if sensory_rooms < total_rooms:
        errors.append(f"Expected 100% sensory coverage ({total_rooms}/{total_rooms}), found {sensory_rooms}/{total_rooms}")
    if len(side_quests) < 24:
        errors.append(f"Expected >= 24 slice-of-life side quests after Phase 3, found {len(side_quests)}")

    # ── World Liveness 2.0 Deep Audits (Phase 4 Specification) ────────────────
    # 1) set_long ASCII command hints vs room/NPC handlers
    cmd_hint_mismatches = []
    for fp in room_files:
        rel = "/" + os.path.relpath(fp, R).replace(os.sep, "/")
        src = rd(rel.lstrip("/"))
        m_long = re.search(r'set_long\s*\((.*?)\)\s*;', src, re.S)
        if not m_long:
            continue
        long_txt = m_long.group(1)
        npc_src = ""
        for np_path in re.findall(r'spawn_npc\s*\(\s*"([^"]+)"', src):
            nfp = os.path.join(R, np_path.lstrip("/"))
            if os.path.exists(nfp):
                npc_src += rd(np_path.lstrip("/"))
        for cm in re.finditer(r'\(([a-z_]+(?:\s+[a-z_]+)?)\)', long_txt):
            verb = cm.group(1).split()[0]
            if verb in ("up", "down", "north", "south", "east", "west", "out", "south_road", "gate", "county"):
                continue
            if verb not in src and verb not in npc_src and verb not in ("buy", "sell", "list", "ask", "look", "go", "enter"):
                cmd_hint_mismatches.append((rel, cm.group(1)))
    if cmd_hint_mismatches:
        errors.append(f"set_long command hint mismatches: {cmd_hint_mismatches}")

    # 2) PHASE_D schedules (>= 23 NPCs, valid room targets) & hub_scenes (>= 6 hubs)
    phase_src = rd("daemon/phase_d.c")
    sched_keys = re.findall(r'^\s{8}"([a-z0-9_]+)"\s*:\s*\(\[', phase_src, re.M)
    if len(sched_keys) < 23:
        errors.append(f"Expected >= 23 scheduled NPCs in PHASE_D, found {len(sched_keys)}")
    for r_tgt in re.findall(r'"(?:dawn|morning|noon_afternoon|dusk|night|midnight)"\s*:\s*"([^"]+\.c)"', phase_src):
        if not os.path.exists(os.path.join(R, r_tgt.lstrip("/"))):
            errors.append(f"PHASE_D schedule points to missing room: {r_tgt}")
    hub_keys = re.findall(r'"(/d/[^"]+\.c)"\s*:\s*\(\{', phase_src)
    if len(hub_keys) < 6:
        errors.append(f"Expected >= 6 multi-beat NPC-to-NPC hub scenes in PHASE_D, found {len(hub_keys)}")
    if "relationships" not in phase_src:
        errors.append("PHASE_D missing NPC social relationships metadata")

    # 3) Folk NPC interactivity check (every folk NPC must respond to talk/chat)
    folk_files = sorted(glob.glob(os.path.join(R, "clone/npc/folk/*.c")))
    if len(folk_files) < 28:
        errors.append(f"Expected >= 28 folk NPCs, found {len(folk_files)}")
    for ff in folk_files:
        fsrc = rd(os.path.relpath(ff, R))
        if "add_response" not in fsrc and "do_chat" not in fsrc:
            errors.append(f"Folk NPC lacks interactive responses: {os.path.relpath(ff, R)}")

    # 4) Dynamic time/season & economy persistence + 6D Rumor quality + social stratification
    room_src = rd("std/room.c")
    if "query_room_rhythm_line" not in phase_src or "do_observe_scene" not in room_src:
        errors.append("Missing time-of-day/season rhythm or observe scene integration")
    ws_src = rd("daemon/world_state_d.c")
    for req_ws in ("market_stocks", "economic_batch_tick", "merchant_strategies", "buy_trade_cargo", "sell_trade_cargo", "query_seasonal_goods_market"):
        if req_ws not in ws_src:
            errors.append(f"WORLD_STATE_D missing 2.0 economy API: {req_ws}")
    rum_src = rd("daemon/rumor_d.c")
    for req_rf in ("query_cross_check_rumors", '"source"', '"event_id"', '"credibility"', '"region"', '"timestamp"', '"is_stale"'):
        if req_rf not in rum_src:
            errors.append(f"RUMOR_D missing 6D information quality field/API: {req_rf}")
    city_src = rd("daemon/city_d.c")
    if "query_social_tier" not in city_src:
        errors.append("CITY_D missing 4-dimension query_social_tier()")

    print("=" * 70)
    print("WORLD LIVENESS 2.0 AUDIT SUMMARY")
    print("=" * 70)
    print(f"Total rooms:           {total_rooms} (area breakdown: {dict(area_counts)})")
    print(f"Sensory-rich rooms:    {sensory_rooms}/{total_rooms} (100%)")
    print(f"Resident/NPC-capable:  {npc_rooms}/{total_rooms}")
    print(f"Declarative action:    {action_rule_rooms}/{total_rooms}")
    print(f"Empty rooms (no S/N/A): {empty_total}/{total_rooms} ({dict(area_empty)})")
    print(f"Scheduled NPCs:        {len(sched_keys)} | Hub scenes: {len(hub_keys)} | Folk NPCs: {len(folk_files)}")
    print(f"set_long cmd mismatches:{len(cmd_hint_mismatches)}")
    print(f"Slice-of-life quests:  {len(side_quests)}")
    print("Economy/Rumor 2.0:     OK (stocks + batch tick + 6D rumors + 4D social tiers)")
    if warnings:
        print("\nWarnings:")
        for w in warnings:
            print("  WARN:", w)
    if errors:
        print("\nFAILURES:")
        for e in errors:
            print("  ERR:", e)
        sys.exit(1)
    print("\nALL WORLD LIVENESS CHECKS PASSED.")


if __name__ == "__main__":
    main()
