#!/usr/bin/env python3
"""Scaffold a new novel world under mudlib/worlds/<world_id>/ from _template."""

from __future__ import annotations

import argparse
import json
import re
import shutil
import sys
from pathlib import Path

from world_utils import WORLDS_DIR


def create_world(world_id: str, name: str | None = None) -> Path:
    if not re.fullmatch(r"[a-z0-9][a-z0-9_-]*", world_id) or world_id.startswith("_"):
        raise ValueError("world_id must match ^[a-z0-9][a-z0-9_-]*$ and not start with '_'")

    template_dir = WORLDS_DIR / "_template"
    if not template_dir.is_dir():
        raise FileNotFoundError(f"Missing template directory: {template_dir}")

    target_dir = WORLDS_DIR / world_id
    if target_dir.exists():
        raise FileExistsError(f"World already exists: {target_dir}")

    def ignore_runtime(_src: str, names: list[str]) -> list[str]:
        return [n for n in names if n.endswith(".o")]

    shutil.copytree(template_dir, target_dir, ignore=ignore_runtime)

    display_name = name or world_id
    mf_path = target_dir / "manifest.json"
    mf = json.loads(mf_path.read_text(encoding="utf-8"))
    mf["world_id"] = world_id
    mf["name"] = display_name
    mf_path.write_text(json.dumps(mf, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    theme_mf = target_dir / "web" / "theme" / "manifest.json"
    if theme_mf.is_file():
        tm = json.loads(theme_mf.read_text(encoding="utf-8"))
        tm["title"] = f"{display_name} — MudScript"
        theme_mf.write_text(json.dumps(tm, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    return target_dir


def main() -> int:
    parser = argparse.ArgumentParser(description="Create a new world skeleton from _template.")
    parser.add_argument("world_id", help="New world ID (lowercase letters, digits, '-' or '_')")
    parser.add_argument("--name", help="Human-readable world title", default=None)
    args = parser.parse_args()

    try:
        dest = create_world(args.world_id, args.name)
    except Exception as exc:
        print(f"[ERROR] {exc}", file=sys.stderr)
        return 1

    print(f"Created world '{args.world_id}' at {dest}")
    print(
        f"Start with: ./bin/mudscript -common mudlib/common -mudlib mudlib/worlds/{args.world_id} -master master.c"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
