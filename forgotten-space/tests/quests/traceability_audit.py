#!/usr/bin/env python3
"""
《遺忘的世界》雙向可追溯矩陣建立與稽核腳本 (Chapter <-> Quest <-> NPC <-> Room Traceability)

功能：
1. --write : 依現行 article/、quests/、clone/npc/、d/ 與 data/canon_sync_matrix.json
             產生 data/traceability_matrix.json 與 data/traceability_matrix.csv
2. 預設驗證模式（exit 0/1）：
   - 驗證 117/117 任務皆具備 "chapter" 欄位，且所指章節檔真實存在於 article/
   - 驗證 177/177 NPC 皆於檔頭標註 Ch. 章節範圍，且所指章節真實存在
   - 驗證所有任務 location 皆可解析到 d/**/*.c 實房、無斷鏈，並統計房間被任務引用覆蓋率
   - 驗證 data/canon_sync_matrix.json 覆蓋全部任務 (117/117)
   - 驗證 data/traceability_matrix.json 與 .csv 與現行程式碼完全同步
"""
import argparse
import collections
import csv
import glob
import json
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))

CH_RANGE_RE = re.compile(
    r"(?:Ch\.?\s*|第\s*)(\d+)\s*(?:[-–~－、,]\s*(?:Ch\.?\s*)?(\d+))?",
    re.I,
)


def chapter_file_map(root_dir):
    files = {}
    for p in sorted(glob.glob(os.path.join(root_dir, "article", "0*_volume*", "ch*.md"))):
        m = re.search(r"ch(\d+)\.md$", p)
        if m:
            num = int(m.group(1))
            files[num] = os.path.relpath(p, root_dir)
    return files


def parse_chapter_spec(spec):
    if not spec or not isinstance(spec, str):
        return []
    nums = set()
    # Handle comma/slash/space separated parts like "Ch.102-103, Ch.106-111" or "Ch.0001-Ch.0006"
    for m in CH_RANGE_RE.finditer(spec):
        start = int(m.group(1))
        end = int(m.group(2)) if m.group(2) else start
        if end >= start and (end - start) <= 200:
            nums.update(range(start, end + 1))
        else:
            nums.add(start)
            if m.group(2):
                nums.add(end)
    return sorted(nums)


def scan_npcs(root_dir):
    npcs = []
    by_id = collections.defaultdict(list)
    for nf in sorted(glob.glob(os.path.join(root_dir, "clone", "npc", "**", "*.c"), recursive=True)):
        rel = os.path.relpath(nf, root_dir)
        src = open(nf, encoding="utf-8", errors="replace").read()
        top = src[:600]
        # Extract Ch. marker snippet from header lines
        header_lines = [l.strip() for l in src.splitlines()[:5] if l.strip()]
        header_text = " ".join(header_lines)
        marker_m = re.search(r"((?:Ch\.?|第)\s*\d+[^)\n]*)", top, re.I)
        marker = marker_m.group(1).strip() if marker_m else ""
        chapters = parse_chapter_spec(top)

        id_blobs = (
            re.findall(r"set_name\([^;]*?\(\{(.*?)\}\)", src, re.S)
            + re.findall(r"set_id\(\s*\(\{(.*?)\}\)", src, re.S)
            + re.findall(r"add_id\(\s*\(\{(.*?)\}\)", src, re.S)
        )
        ids = {os.path.splitext(os.path.basename(nf))[0].lower()}
        for raw_id in re.findall(r'"([A-Za-z][A-Za-z _]*)"', " ".join(id_blobs)):
            ids.add(raw_id.lower())
        ids = sorted(ids)
        rec = {
            "file": rel,
            "stem": "/" + os.path.splitext(rel)[0],
            "ids": ids,
            "header_ch_marker": marker,
            "chapters": chapters,
            "header_preview": header_text[:120],
        }
        npcs.append(rec)
        for i in ids:
            by_id[i].append(rel)
    return npcs, by_id


def scan_rooms(root_dir, npcs):
    rooms = []
    npc_by_file = {n["file"]: n for n in npcs}
    for rf in sorted(glob.glob(os.path.join(root_dir, "d", "**", "*.c"), recursive=True)):
        rel = os.path.relpath(rf, root_dir)
        rpath = "/" + os.path.splitext(rel)[0]
        src = open(rf, encoding="utf-8", errors="replace").read()
        top = src[:500]
        header_ch = parse_chapter_spec(top)
        hosted_npcs = []
        for n in npcs:
            base = os.path.basename(n["file"])
            if n["stem"] in src or base in src:
                hosted_npcs.append(n["file"])
        rooms.append({
            "room_path": rpath,
            "file": rel,
            "header_chapters": header_ch,
            "hosted_npcs": sorted(set(hosted_npcs)),
        })
    return rooms, npc_by_file


def walk_quest_refs(obj, npc_set, loc_set):
    if isinstance(obj, dict):
        for k, v in obj.items():
            if k in ("start_npc", "target_npc", "from_npc"):
                if isinstance(v, str):
                    npc_set.add(v)
                elif isinstance(v, list):
                    for x in v:
                        if isinstance(x, str):
                            npc_set.add(x)
            elif k == "location" and isinstance(v, str):
                loc_set.add(v)
            else:
                walk_quest_refs(v, npc_set, loc_set)
    elif isinstance(obj, list):
        for x in obj:
            walk_quest_refs(x, npc_set, loc_set)


def build_traceability_data(root_dir):
    ch_files = chapter_file_map(root_dir)
    npcs, npc_by_id = scan_npcs(root_dir)
    rooms, npc_by_file = scan_rooms(root_dir, npcs)
    room_paths = [r["room_path"] for r in rooms]
    room_by_path = {r["room_path"]: r for r in rooms}

    quests = []
    quest_files = sorted(glob.glob(os.path.join(root_dir, "quests", "*", "*.json")))
    npc_to_quests = collections.defaultdict(set)
    room_to_quests = collections.defaultdict(set)
    ch_to_quests = collections.defaultdict(set)

    for qf in quest_files:
        rel = os.path.relpath(qf, root_dir)
        data = json.load(open(qf, encoding="utf-8"))
        qid = data["id"]
        ch_spec = data.get("chapter", "")
        ch_nums = parse_chapter_spec(ch_spec)
        npc_ids = set()
        locs = set()
        walk_quest_refs(data, npc_ids, locs)
        resolved_npc_files = sorted({nf for nid in npc_ids for nf in npc_by_id.get(nid.lower(), [])})
        resolved_rooms = sorted({rp for loc in locs for rp in room_paths if loc in rp})

        for nf in resolved_npc_files:
            npc_to_quests[nf].add(qid)
        for rp in resolved_rooms:
            room_to_quests[rp].add(qid)
        for c in ch_nums:
            ch_to_quests[c].add(qid)

        quests.append({
            "quest_id": qid,
            "name": data.get("name", ""),
            "category": data.get("category", rel.split(os.sep)[1]),
            "region": data.get("region", ""),
            "file": rel,
            "chapter": ch_spec,
            "chapters": ch_nums,
            "chapter_files": [ch_files[c] for c in ch_nums if c in ch_files],
            "npc_ids": sorted(npc_ids),
            "npc_files": resolved_npc_files,
            "locations": sorted(locs),
            "rooms": resolved_rooms,
        })

    # Attach reverse links to NPCs & rooms
    npc_entries = []
    ch_to_npcs = collections.defaultdict(set)
    npc_hosts = collections.defaultdict(set)
    for r in rooms:
        for nf in r["hosted_npcs"]:
            npc_hosts[nf].add(r["room_path"])
    for n in npcs:
        for c in n["chapters"]:
            ch_to_npcs[c].add(n["file"])
        npc_entries.append({
            "file": n["file"],
            "ids": n["ids"],
            "header_ch_marker": n["header_ch_marker"],
            "chapters": n["chapters"],
            "quests": sorted(npc_to_quests.get(n["file"], ())),
            "host_rooms": sorted(npc_hosts.get(n["file"], ())),
        })

    room_entries = []
    ch_to_rooms = collections.defaultdict(set)
    for r in rooms:
        rp = r["room_path"]
        qset = sorted(room_to_quests.get(rp, ()))
        for c in r["header_chapters"]:
            ch_to_rooms[c].add(rp)
        room_entries.append({
            "room_path": rp,
            "file": r["file"],
            "header_chapters": r["header_chapters"],
            "quests": qset,
            "hosted_npcs": r["hosted_npcs"],
            "referenced_by_quest": bool(qset),
        })

    for q in quests:
        for c in q["chapters"]:
            for rp in q["rooms"]:
                ch_to_rooms[c].add(rp)

    chapter_entries = []
    for c in sorted(ch_files):
        vol = 1 if c <= 38 else (2 if c <= 82 else (3 if c <= 126 else 4))
        chapter_entries.append({
            "chapter": f"Ch.{c:04d}",
            "chapter_num": c,
            "volume": vol,
            "file": ch_files[c],
            "quests": sorted(ch_to_quests.get(c, ())),
            "npcs": sorted(ch_to_npcs.get(c, ())),
            "rooms": sorted(ch_to_rooms.get(c, ())),
        })

    summary = {
        "chapters_total": len(chapter_entries),
        "quests_total": len(quests),
        "quests_with_chapter": sum(1 for q in quests if q["chapters"]),
        "npcs_total": len(npc_entries),
        "npcs_with_ch_marker": sum(1 for n in npc_entries if n["header_ch_marker"]),
        "rooms_total": len(room_entries),
        "rooms_referenced_by_quests": sum(1 for r in room_entries if r["referenced_by_quest"]),
        "rooms_non_quest_world_or_transit": sum(1 for r in room_entries if not r["referenced_by_quest"]),
        "rooms_with_hosted_npcs": sum(1 for r in room_entries if r["hosted_npcs"]),
    }

    matrix = {
        "version": "1.0",
        "description": "《遺忘的世界》chapter <-> quest <-> NPC <-> room 雙向可追溯矩陣",
        "summary": summary,
        "chapters": chapter_entries,
        "quests": quests,
        "npcs": npc_entries,
        "rooms": room_entries,
    }

    # Build flat CSV rows sorted by first chapter then quest_id
    csv_rows = []
    for q in sorted(quests, key=lambda x: (x["chapters"][0] if x["chapters"] else 9999, x["quest_id"])):
        all_ch_exist = bool(q["chapters"]) and all(c in ch_files for c in q["chapters"])
        all_npcs_marked = all(
            any(n["file"] == nf and n["header_ch_marker"] for n in npc_entries)
            for nf in q["npc_files"]
        )
        all_rooms_exist = all(rp in room_by_path for rp in q["rooms"])
        csv_rows.append({
            "quest_id": q["quest_id"],
            "category": q["category"],
            "region": q["region"] or "-",
            "chapter": q["chapter"],
            "chapter_count": str(len(q["chapters"])),
            "npc_ids": ";".join(q["npc_ids"]),
            "npc_files": ";".join(q["npc_files"]),
            "rooms": ";".join(q["rooms"]),
            "chapter_files_exist": "YES" if all_ch_exist else "NO",
            "all_npcs_marked": "YES" if all_npcs_marked else "NO",
            "all_rooms_exist": "YES" if all_rooms_exist else "NO",
        })
    return matrix, csv_rows, ch_files


def write_outputs(root_dir, matrix, csv_rows):
    json_path = os.path.join(root_dir, "data", "traceability_matrix.json")
    csv_path = os.path.join(root_dir, "data", "traceability_matrix.csv")
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump(matrix, f, ensure_ascii=False, indent=2)
        f.write("\n")
    fieldnames = [
        "quest_id", "category", "region", "chapter", "chapter_count",
        "npc_ids", "npc_files", "rooms",
        "chapter_files_exist", "all_npcs_marked", "all_rooms_exist",
    ]
    with open(csv_path, "w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        w.writerows(csv_rows)
    print(f"Wrote {os.path.relpath(json_path, root_dir)} and {os.path.relpath(csv_path, root_dir)}")


def audit(root_dir):
    errors = []
    matrix, csv_rows, ch_files = build_traceability_data(root_dir)
    room_set = {r["room_path"] for r in matrix["rooms"]}

    # 1. Quest -> Chapter check
    for q in matrix["quests"]:
        if not q["chapter"] or not q["chapters"]:
            errors.append(f"[quest_chapter] 任務 {q['quest_id']} 缺少有效 chapter 欄位")
            continue
        missing_ch = [c for c in q["chapters"] if c not in ch_files]
        if missing_ch:
            errors.append(f"[quest_chapter] 任務 {q['quest_id']} 參照不存在章節: {missing_ch}")
        for loc in q["locations"]:
            if not any(loc in rp for rp in room_set):
                errors.append(f"[quest_room] 任務 {q['quest_id']} location={loc} 找不到對應房間")

    # 2. NPC -> Ch. marker check
    for n in matrix["npcs"]:
        if not n["header_ch_marker"] or not n["chapters"]:
            errors.append(f"[npc_ch_marker] {n['file']} 檔頭缺少 Ch. 章節標記")
            continue
        missing_ch = [c for c in n["chapters"] if c not in ch_files]
        if missing_ch:
            errors.append(f"[npc_ch_marker] {n['file']} 標記了不存在章節: {missing_ch}")

    # 3. canon_sync_matrix 100% quest coverage
    csm_path = os.path.join(root_dir, "data", "canon_sync_matrix.json")
    if not os.path.exists(csm_path):
        errors.append("[canon_sync_matrix] 缺少 data/canon_sync_matrix.json")
    else:
        csm = json.load(open(csm_path, encoding="utf-8"))
        csm_q = {qid for e in csm.get("mappings", []) for qid in e.get("quests", [])}
        all_q = {q["quest_id"] for q in matrix["quests"]}
        unmapped = sorted(all_q - csm_q)
        if unmapped:
            errors.append(f"[canon_sync_matrix] 仍有 {len(unmapped)} 個任務未納入追蹤矩陣: {unmapped[:10]}")

    # 4. Persisted traceability_matrix.json & .csv sync check
    json_path = os.path.join(root_dir, "data", "traceability_matrix.json")
    csv_path = os.path.join(root_dir, "data", "traceability_matrix.csv")
    if not os.path.exists(json_path):
        errors.append("[matrix_sync] 缺少 data/traceability_matrix.json（請執行 --write）")
    else:
        disk_json = json.load(open(json_path, encoding="utf-8"))
        if disk_json != matrix:
            errors.append("[matrix_sync] data/traceability_matrix.json 與現行檔案狀態不一致（請執行 --write 更新）")

    if not os.path.exists(csv_path):
        errors.append("[matrix_sync] 缺少 data/traceability_matrix.csv（請執行 --write）")
    else:
        disk_rows = list(csv.DictReader(open(csv_path, encoding="utf-8")))
        if disk_rows != csv_rows:
            errors.append("[matrix_sync] data/traceability_matrix.csv 與現行檔案狀態不一致（請執行 --write 更新）")

    s = matrix["summary"]
    print("=" * 72)
    print("《遺忘的世界》雙向可追溯矩陣稽核報告 (Traceability Audit)")
    print("=" * 72)
    print(f"  ・章節總數 (article/)        : {s['chapters_total']} 章")
    print(f"  ・任務章節標註 (quests/)     : {s['quests_with_chapter']}/{s['quests_total']}")
    print(f"  ・NPC 檔頭 Ch. 標記          : {s['npcs_with_ch_marker']}/{s['npcs_total']}")
    print(f"  ・房間分布 (d/)              : {s['rooms_total']} 間（任務直接引用 {s['rooms_referenced_by_quests']} 間｜常駐生態/通道房 {s['rooms_non_quest_world_or_transit']} 間｜含 NPC 駐留 {s['rooms_with_hosted_npcs']} 間）")
    print(f"  ・追蹤矩陣檔案               : data/traceability_matrix.json & .csv")
    print("-" * 72)

    if errors:
        for e in errors:
            print(f"  [FAIL] {e}")
        sys.exit(1)
    print("  [PASS] chapter <-> quest <-> NPC <-> room 雙向可追溯檢查全數通過！")
    print("=" * 72)


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true", help="產生或更新 data/traceability_matrix.{json,csv}")
    args = ap.parse_args()
    if args.write:
        mat, rows, _ = build_traceability_data(ROOT)
        write_outputs(ROOT, mat, rows)
    else:
        audit(ROOT)
