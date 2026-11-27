#!/usr/bin/env python3
"""Bidirectional traceability audit: chapters <-> quests <-> NPCs <-> rooms."""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

from world_utils import iter_json_files, load_json, load_manifest, resolve_world_dir


def run_traceability_audit(world_id: str) -> dict:
    world_dir = resolve_world_dir(world_id)
    manifest = load_manifest(world_dir)
    chapters_rel = manifest.get("chapters_dir", "chapters/")
    chapters_dir = (world_dir / chapters_rel).resolve()

    chapter_files: set[str] = set()
    if chapters_dir.is_dir():
        for p in sorted(chapters_dir.rglob("*")):
            if p.is_file() and p.suffix in {".md", ".txt"}:
                chapter_files.add(p.relative_to(chapters_dir).as_posix())
                chapter_files.add(p.stem)

    missing_refs: list[str] = []
    entity_refs: dict[str, list[str]] = {}

    for kind in ("quests", "npcs", "rooms"):
        for jf in iter_json_files(world_dir / kind):
            data = load_json(jf)
            if not isinstance(data, dict):
                continue
            refs = []
            for key in ("chapters", "canon_refs"):
                val = data.get(key)
                if isinstance(val, list):
                    refs.extend(str(x) for x in val)
                elif isinstance(val, str) and val:
                    refs.append(val)
            rel_name = jf.relative_to(world_dir).as_posix()
            entity_refs[rel_name] = refs
            for ref in refs:
                if chapter_files and ref not in chapter_files:
                    missing_refs.append(f"{rel_name} references missing chapter '{ref}'")

    return {
        "world_id": world_id,
        "chapters_dir": str(chapters_dir),
        "chapter_count": len([c for c in chapter_files if "." in c]),
        "entities_checked": len(entity_refs),
        "entities_with_chapter_refs": sum(1 for v in entity_refs.values() if v),
        "missing_chapter_refs": missing_refs,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description="Run chapter/entity traceability audit.")
    parser.add_argument("world_id", help="World directory name under mudlib/worlds/")
    parser.add_argument("--json", action="store_true", help="Output JSON report")
    args = parser.parse_args()

    report = run_traceability_audit(args.world_id)
    if args.json:
        print(json.dumps(report, ensure_ascii=False, indent=2))
    else:
        print(
            f"Traceability '{report['world_id']}': "
            f"{report['chapter_count']} chapter(s), "
            f"{report['entities_checked']} entities checked, "
            f"{report['entities_with_chapter_refs']} with canon refs"
        )
        for m in report["missing_chapter_refs"]:
            print(f"[ERROR] {m}", file=sys.stderr)

    return 1 if report["missing_chapter_refs"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
