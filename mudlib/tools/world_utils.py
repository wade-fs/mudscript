"""Shared helpers for mudlib/tools CLI scripts."""

from __future__ import annotations

import json
from pathlib import Path
from typing import Any

TOOLS_DIR = Path(__file__).resolve().parent
MUDLIB_DIR = TOOLS_DIR.parent
WORLDS_DIR = MUDLIB_DIR / "worlds"
COMMON_DIR = MUDLIB_DIR / "common"


def resolve_world_dir(world_id: str) -> Path:
    world_dir = (WORLDS_DIR / world_id).resolve()
    if not world_dir.is_dir() or world_dir.parent != WORLDS_DIR.resolve():
        raise FileNotFoundError(f"World directory not found: {world_id} ({world_dir})")
    return world_dir


def load_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def load_manifest(world_dir: Path) -> dict[str, Any]:
    mf_path = world_dir / "manifest.json"
    if not mf_path.is_file():
        raise FileNotFoundError(f"Missing manifest.json in {world_dir}")
    data = load_json(mf_path)
    if not isinstance(data, dict):
        raise ValueError(f"manifest.json must be a JSON object: {mf_path}")
    return data


def iter_json_files(directory: Path) -> list[Path]:
    if not directory.is_dir():
        return []
    return sorted(p for p in directory.rglob("*.json") if p.is_file())


def virtual_path_exists(world_dir: Path, vpath: str) -> bool:
    """Check whether a MudScript virtual path exists as .json or .c in world or common."""
    if not isinstance(vpath, str) or not vpath.startswith("/"):
        return False
    rel = vpath.lstrip("/")
    candidates = [rel]
    if not rel.endswith(".json") and not rel.endswith(".c"):
        candidates.extend([f"{rel}.json", f"{rel}.c"])
    for root in (world_dir, COMMON_DIR):
        for cand in candidates:
            target = (root / cand).resolve()
            try:
                target.relative_to(root.resolve())
            except ValueError:
                continue
            if target.is_file():
                return True
    return False
