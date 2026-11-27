#!/usr/bin/env python3
"""Audit JSON fields across a world to prevent unconsumed ghost fields."""

from __future__ import annotations

import argparse
import sys

from world_utils import iter_json_files, load_json, load_manifest, resolve_world_dir

CONSUMED_FIELDS: dict[str, set[str]] = {
    "room": {
        "type", "id", "name", "short", "long", "exits", "x", "y", "z",
        "flags", "items", "hidden", "touch", "smell", "listen", "actions",
        "npcs", "items_spawn", "chapters", "canon_refs",
    },
    "npc": {
        "type", "id", "id_list", "name", "short", "long", "level",
        "stat_str", "stat_con", "stat_int", "stat_spi", "stat_dex", "stat_per",
        "exp_reward", "gold_reward", "aggressive", "wander_chance", "home_room",
        "dialogue", "dialogue_file", "drops", "states", "initial_state",
        "chapters", "canon_refs",
    },
    "item": {
        "type", "id", "id_list", "name", "short", "long", "item_type",
        "value", "weight", "stackable", "no_get", "no_drop", "props",
        "chapters", "canon_refs",
    },
    "quest": {
        "id", "name", "desc", "requires", "stages", "branches",
        "rewards", "complete_msg", "event_trigger", "chapters", "canon_refs",
    },
    "schema:power_system": {"type", "id", "name", "stat_labels", "realms"},
    "schema:currency": {"type", "id", "name", "primary", "unit", "denominations"},
    "schema:stat_formula": {"type", "id", "name", "base", "primary_stat", "multiplier"},
    "schema:phase_schedule": {"type", "id", "schedules"},
    "schema:world_state": {"type", "id", "initial_vars"},
}


def audit_schema_usage(world_id: str) -> list[str]:
    world_dir = resolve_world_dir(world_id)
    manifest = load_manifest(world_dir)
    custom = manifest.get("custom_fields") or {}
    ghosts: list[str] = []

    checks = [
        ("rooms", "room"),
        ("npcs", "npc"),
        ("items", "item"),
        ("quests", "quest"),
    ]
    for subdir, kind in checks:
        allowed = CONSUMED_FIELDS[kind] | set(custom.get(kind, []))
        for jf in iter_json_files(world_dir / subdir):
            data = load_json(jf)
            if not isinstance(data, dict):
                continue
            unknown = sorted(set(data.keys()) - allowed)
            for key in unknown:
                ghosts.append(f"{jf.relative_to(world_dir)}: unconsumed field '{key}' (kind={kind})")

    for sf in iter_json_files(world_dir / "schema"):
        data = load_json(sf)
        if not isinstance(data, dict):
            continue
        stype = data.get("type", "")
        key_name = f"schema:{stype}"
        if key_name not in CONSUMED_FIELDS:
            if stype not in custom.get("schema_types", []):
                ghosts.append(f"{sf.relative_to(world_dir)}: unknown schema type '{stype}'")
            continue
        allowed = CONSUMED_FIELDS[key_name] | set(custom.get(key_name, []))
        for key in sorted(set(data.keys()) - allowed):
            ghosts.append(f"{sf.relative_to(world_dir)}: unconsumed schema field '{key}'")

    return ghosts


def main() -> int:
    parser = argparse.ArgumentParser(description="Audit JSON schema field consumption.")
    parser.add_argument("world_id", help="World directory name under mudlib/worlds/")
    args = parser.parse_args()

    ghosts = audit_schema_usage(args.world_id)
    for g in ghosts:
        print(f"[GHOST] {g}", file=sys.stderr)
    if ghosts:
        print(f"Schema audit FAILED for '{args.world_id}': {len(ghosts)} unconsumed field(s)")
        return 1
    print(f"Schema audit PASSED for '{args.world_id}': 0 ghost fields")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
