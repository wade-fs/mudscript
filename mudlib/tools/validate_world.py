#!/usr/bin/env python3
"""Validate manifest, schema, rooms/exits, NPCs, items, and quests for a world."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

from world_utils import (
    iter_json_files,
    load_json,
    load_manifest,
    resolve_world_dir,
    virtual_path_exists,
)


def validate_world(world_id: str) -> tuple[list[str], list[str]]:
    errors: list[str] = []
    warnings: list[str] = []

    world_dir = resolve_world_dir(world_id)
    manifest = load_manifest(world_dir)

    for key in ("world_id", "name", "start_room"):
        if not manifest.get(key):
            errors.append(f"manifest.json missing required field '{key}'")

    if manifest.get("world_id") and manifest["world_id"] != world_id:
        errors.append(
            f"manifest.json world_id '{manifest['world_id']}' != directory '{world_id}'"
        )

    start_room = manifest.get("start_room", "")
    if start_room and not virtual_path_exists(world_dir, start_room):
        errors.append(f"manifest.json start_room not found: {start_room}")

    # Load rooms and check exits / NPCs / items
    rooms: dict[str, dict] = {}
    for rf in iter_json_files(world_dir / "rooms"):
        try:
            data = load_json(rf)
        except Exception as exc:
            errors.append(f"Invalid JSON in {rf.relative_to(world_dir)}: {exc}")
            continue
        if not isinstance(data, dict):
            errors.append(f"Room JSON must be object: {rf.relative_to(world_dir)}")
            continue
        vpath = "/" + rf.relative_to(world_dir).with_suffix("").as_posix()
        rooms[vpath] = data

    for vpath, rdata in rooms.items():
        if not rdata.get("short"):
            errors.append(f"Room {vpath} missing 'short'")
        exits = rdata.get("exits") or {}
        if not isinstance(exits, dict):
            errors.append(f"Room {vpath} 'exits' must be an object")
            continue
        for direction, dest in exits.items():
            if not virtual_path_exists(world_dir, dest):
                errors.append(f"Room {vpath} exit '{direction}' -> missing target '{dest}'")
            elif dest in rooms:
                dest_exits = rooms[dest].get("exits") or {}
                if vpath not in dest_exits.values() and not (rdata.get("flags") or {}).get("one_way"):
                    warnings.append(
                        f"One-way exit: {vpath} [{direction}] -> {dest} (no return exit)"
                    )

        for npc_ref in rdata.get("npcs") or []:
            npath = npc_ref.get("path") if isinstance(npc_ref, dict) else npc_ref
            if not virtual_path_exists(world_dir, str(npath)):
                errors.append(f"Room {vpath} references missing NPC: {npath}")

        for item_ref in rdata.get("items_spawn") or []:
            ipath = item_ref.get("path") if isinstance(item_ref, dict) else item_ref
            if not virtual_path_exists(world_dir, str(ipath)):
                errors.append(f"Room {vpath} references missing item: {ipath}")

    # Validate NPCs
    for nf in iter_json_files(world_dir / "npcs"):
        try:
            ndata = load_json(nf)
        except Exception as exc:
            errors.append(f"Invalid JSON in {nf.relative_to(world_dir)}: {exc}")
            continue
        if not isinstance(ndata, dict) or not ndata.get("name"):
            errors.append(f"NPC {nf.relative_to(world_dir)} missing 'name'")
        home = ndata.get("home_room")
        if home and not virtual_path_exists(world_dir, home):
            errors.append(f"NPC {nf.relative_to(world_dir)} missing home_room: {home}")

    # Validate Items
    for itf in iter_json_files(world_dir / "items"):
        try:
            idata = load_json(itf)
        except Exception as exc:
            errors.append(f"Invalid JSON in {itf.relative_to(world_dir)}: {exc}")
            continue
        if not isinstance(idata, dict) or not idata.get("name"):
            errors.append(f"Item {itf.relative_to(world_dir)} missing 'name'")

    # Validate Quests
    quests: dict[str, dict] = {}
    for qf in iter_json_files(world_dir / "quests"):
        try:
            qdata = load_json(qf)
        except Exception as exc:
            errors.append(f"Invalid JSON in {qf.relative_to(world_dir)}: {exc}")
            continue
        if not isinstance(qdata, dict):
            errors.append(f"Quest must be object: {qf.relative_to(world_dir)}")
            continue
        qid = qdata.get("id") or qf.stem
        quests[qid] = qdata

    for qid, qdata in quests.items():
        for req in qdata.get("requires") or []:
            if req not in quests:
                errors.append(f"Quest '{qid}' requires unknown quest '{req}'")
        for st in qdata.get("stages") or []:
            choices = st.get("choices")
            if isinstance(choices, dict):
                for cid, cdef in choices.items():
                    for item_path in cdef.get("items") or []:
                        if not virtual_path_exists(world_dir, item_path):
                            errors.append(
                                f"Quest '{qid}' choice '{cid}' references missing item '{item_path}'"
                            )
        for item_path in (qdata.get("rewards") or {}).get("items") or []:
            if not virtual_path_exists(world_dir, item_path):
                errors.append(f"Quest '{qid}' reward references missing item '{item_path}'")

    # Validate Schemas
    for sf in iter_json_files(world_dir / "schema"):
        try:
            sdata = load_json(sf)
        except Exception as exc:
            errors.append(f"Invalid JSON in {sf.relative_to(world_dir)}: {exc}")
            continue
        if not isinstance(sdata, dict) or not sdata.get("type"):
            errors.append(f"Schema {sf.relative_to(world_dir)} missing 'type'")

    return errors, warnings


def main() -> int:
    parser = argparse.ArgumentParser(description="Validate a MudScript world directory.")
    parser.add_argument("world_id", help="World directory name under mudlib/worlds/")
    args = parser.parse_args()

    errors, warnings = validate_world(args.world_id)
    for w in warnings:
        print(f"[WARN] {w}")
    for e in errors:
        print(f"[ERROR] {e}", file=sys.stderr)

    if errors:
        print(f"Validation FAILED for '{args.world_id}': {len(errors)} error(s), {len(warnings)} warning(s)")
        return 1
    print(f"Validation PASSED for '{args.world_id}' ({len(warnings)} warning(s))")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
