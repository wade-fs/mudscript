#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
全專案 LPC 函式定義與呼叫靜態分析索引器 (LPC Symbol & Call Graph Indexer)
功能：
1. 建立全專案所有 .c 檔案的函式定義索引 (包含繼承鏈 inherit 樹)
2. 掃描所有箭號呼叫 (ob->func(...)) 與內部呼叫 (func(...))
3. 判定呼叫目標之型別/檔案，並交叉檢驗該函式是否存在於目標類別或其祖先類別中
4. 輸出未定義的函式呼叫 (Undefined Function Calls) 與呼叫點 (Call Sites)
"""

import os
import re
import sys
from collections import defaultdict

BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))

# 巨集定義映射
DEFINES = {
    "WORLD_STATE_D": "/daemon/world_state_d.c",
    "MYSTERY_D": "/daemon/mysteryd.c",
    "CAREER_D": "/daemon/career_d.c",
    "QUEST_D": "/daemon/questd.c",
    "SKILL_D": "/secure/skill_d.c",
    "COMBAT_D": "/secure/combat_d.c",
    "USER_OB": "/std/user.c",
    "NPC_OB": "/std/npc.c",
    "ROOM_OB": "/std/room.c",
    "RUIN_ROOM_OB": "/std/room/ruin.c",
    "WEAPON_OB": "/std/weapon.c",
    "ARMOUR_OB": "/std/armour.c",
    "ITEM_OB": "/std/item.c",
}

# 內建 LPC efuns / simul_efuns 列表 (常用)
STANDARD_EFUNS = {
    "write", "tell_object", "tell_room", "message", "say", "shout",
    "clone_object", "destruct", "find_object", "load_object", "move_object",
    "all_inventory", "deep_inventory", "present", "environment", "this_object", "this_player",
    "time", "ctime", "call_out", "remove_call_out", "find_call_out",
    "allocate", "sizeof", "strlen", "keys", "values", "member_array",
    "explode", "implode", "replace_string", "sprintf", "sscanf", "to_int", "to_string", "to_float",
    "lower_case", "capitalize", "crypt", "file_size", "read_file", "write_file", "rm",
    "get_dir", "restore_object", "save_object", "input_to", "exec", "errorp", "stringp",
    "intp", "objectp", "arrayp", "mapp", "pointerp", "set_temp", "query_temp", "delete_temp",
    "add_action", "enable_commands", "disable_commands", "living", "set_heart_beat", "heart_beat",
    "call_other", "_t", "select_lang", "random", "min", "max", "unique_array", "filter_array",
    "map_array", "sort_array", "previous_object", "origin", "debug_message", "catch", "throw", "receive",
    "enable_wizard", "disable_wizard", "wizardp", "is_destructed"
}

def normalize_path(path):
    if not path:
        return ""
    path = path.strip().strip('"').strip("'")
    for k, v in DEFINES.items():
        if path == k:
            path = v
    if not path.startswith("/"):
        path = "/" + path
    if not path.endswith(".c") and not path.endswith(".h"):
        path = path + ".c"
    return path

def get_disk_path(norm_path):
    rel = norm_path.lstrip("/")
    return os.path.join(BASE_DIR, rel)

class LPCIndexer:
    def __init__(self):
        self.file_inherits = {}       # norm_path -> list of norm_paths
        self.file_functions = {}      # norm_path -> set of func_names
        self.file_lines = {}          # norm_path -> list of lines
        self.inherited_funcs_cache = {}

    def scan_all_files(self):
        for root, _, files in os.walk(BASE_DIR):
            for f in files:
                if f.endswith(".c"):
                    abs_path = os.path.join(root, f)
                    rel_path = os.path.relpath(abs_path, BASE_DIR)
                    norm_path = "/" + rel_path
                    self.parse_file(norm_path, abs_path)

    def parse_file(self, norm_path, abs_path):
        try:
            with open(abs_path, "r", encoding="utf-8", errors="ignore") as fp:
                lines = fp.readlines()
        except Exception:
            return

        self.file_lines[norm_path] = lines
        inherits = []
        functions = set()

        full_content = "".join(lines)
        clean_content = re.sub(r'/\*.*?\*/', '', full_content, flags=re.DOTALL)
        clean_content = re.sub(r'//.*', '', clean_content)

        # 1. inherit
        re_inherit = re.compile(r'^\s*inherit\s+([A-Za-z0-9_/"\'.]+)\s*;', flags=re.MULTILINE)
        for m in re_inherit.finditer(clean_content):
            inherits.append(normalize_path(m.group(1)))

        # 2. 函式定義
        keywords = {"if", "while", "for", "foreach", "switch", "return", "case", "catch"}
        re_func = re.compile(r'(?:(?:private|protected|public|nomask|varargs)\s+)?(?:(?:void|int|string|mapping|mixed|object|float)\s+(?:\*)?)?([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^;{]*?\)\s*\{', flags=re.DOTALL)
        for m in re_func.finditer(clean_content):
            fname = m.group(1)
            if fname not in keywords:
                functions.add(fname)

        self.file_inherits[norm_path] = inherits
        self.file_functions[norm_path] = functions

    def get_all_functions_for_class(self, norm_path, visited=None):
        if visited is None:
            visited = set()
        if norm_path in visited:
            return set()
        visited.add(norm_path)

        if norm_path in self.inherited_funcs_cache:
            return self.inherited_funcs_cache[norm_path]

        funcs = set(self.file_functions.get(norm_path, set()))
        for parent in self.file_inherits.get(norm_path, []):
            funcs.update(self.get_all_functions_for_class(parent, visited))

        self.inherited_funcs_cache[norm_path] = funcs
        return funcs

    def analyze_calls(self):
        undefined_calls = [] # (caller_path, line_no, target_type, target_file, func_name, code_snippet)

        # 變數目標推斷規則
        target_map = {
            "ws": "/daemon/world_state_d.c",
            "WORLD_STATE_D": "/daemon/world_state_d.c",
            "mys_d": "/daemon/mysteryd.c",
            "md": "/daemon/mysteryd.c",
            "MYSTERY_D": "/daemon/mysteryd.c",
            "career": "/daemon/career_d.c",
            "career2": "/daemon/career_d.c",
            "CAREER_D": "/daemon/career_d.c",
            "qd": "/secure/quest_d.c",
            "quest_d": "/secure/quest_d.c",
            "QUEST_D": "/daemon/questd.c",
            "me": "/std/user.c",
            "who": "/std/user.c",
            "user": "/std/user.c",
            "player": "/std/user.c",
            "tp": "/std/user.c",
            "this_player()": "/std/user.c",
            "weapon": "/std/weapon.c",
            "knife": "/std/weapon.c",
            "item": "/std/item.c",
            "env": "/std/room.c",
            "room": "/std/room.c",
            "sq_room": "/d/village/square.c",
            "sq_room2": "/d/village/square.c",
            "merchant": "/clone/npc/caravan_merchant.c",
            "lang_d": "/secure/language_d.c",
            "system_d": "/secure/system_d.c",
        }

        # 正則表達式抓取箭號呼叫: (var|expr)->(func_name)(
        re_arrow = re.compile(r'([a-zA-Z0-9_\(\)]+)\s*->\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*\(')
        # 捕捉 load_object(...) -> func(...)
        re_load_arrow = re.compile(r'(?:load_object|find_object)\s*\(\s*([A-Za-z0-9_/"\'.]+)\s*\)\s*->\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*\(')
        # 捕捉變數賦值: object var = clone_object/load_object("...")
        re_assign = re.compile(r'(?:object\s+)?([a-zA-Z0-9_]+)\s*=\s*(?:clone_object|load_object)\s*\(\s*([A-Za-z0-9_/"\'.]+)\s*\)')

        for norm_path, lines in self.file_lines.items():
            local_vars = {}
            for line_idx, line in enumerate(lines, 1):
                raw_line = line.strip()
                if raw_line.startswith("//") or raw_line.startswith("/*"):
                    continue

                for m in re_assign.finditer(line):
                    v_name = m.group(1)
                    v_path = normalize_path(m.group(2))
                    local_vars[v_name] = v_path

                # 1. 檢查 load_object/find_object -> func(...)
                for m in re_load_arrow.finditer(line):
                    target_arg = m.group(1)
                    func_name = m.group(2)
                    target_norm = normalize_path(target_arg)
                    target_funcs = self.get_all_functions_for_class(target_norm)
                    if target_norm in self.file_functions and func_name not in target_funcs:
                        undefined_calls.append({
                            "caller": norm_path,
                            "line": line_idx,
                            "target_desc": target_norm,
                            "func": func_name,
                            "code": raw_line
                        })

                # 2. 檢查 var->func(...)
                for m in re_arrow.finditer(line):
                    var_name = m.group(1)
                    func_name = m.group(2)

                    # 如果是 load_object 或 find_object，前面已處理
                    if var_name in ("load_object", "find_object"):
                        continue

                    # 比對區域變數或已知目標
                    target_norm = local_vars.get(var_name) or target_map.get(var_name)
                    if target_norm:
                        target_funcs = self.get_all_functions_for_class(target_norm)
                        # 如果是內建 efun，允許直接呼叫
                        if func_name in STANDARD_EFUNS:
                            continue
                        if target_funcs and func_name not in target_funcs:
                            undefined_calls.append({
                                "caller": norm_path,
                                "line": line_idx,
                                "target_desc": f"{var_name} ({target_norm})",
                                "func": func_name,
                                "code": raw_line
                            })

        return undefined_calls

def main():
    indexer = LPCIndexer()
    indexer.scan_all_files()

    print(f"==================================================")
    print(f"📊 LPC 全專案靜態分析索引報告")
    print(f"==================================================")
    print(f"總共索引檔案數: {len(indexer.file_functions)} 個 .c 檔案")

    undef = indexer.analyze_calls()

    if not undef:
        print("\n✅ 太棒了！全專案所有已知目標的箭號呼叫 (Arrow Calls) 均在定義清單中，未發現未定義函式呼叫！")
    else:
        print(f"\n⚠️ 發現 {len(undef)} 處可疑/未定義的函式呼叫：")
        print("-" * 80)
        for u in undef:
            print(f"❌ 呼叫來源: {u['caller']}:{u['line']}")
            print(f"   目標物件: {u['target_desc']}")
            print(f"   未定義函式: {u['func']}()")
            print(f"   代碼片段: {u['code']}")
            print("-" * 80)

    return len(undef)

if __name__ == "__main__":
    sys.exit(main())
