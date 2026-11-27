// daemon/npc_factory_d.c - JSON NPC 工廠守護進程 (Phase 2 MVVM)
// 依 JSON 動態具現 NPC，支援狀態機與對話樹

#include "/include/config.h"

inherit "/std/object.c";

mapping npc_index;   // virtualPath -> json_data

void preload_npcs();

void create() {
    ::create();
    npc_index = ([]);
    preload_npcs();
}

object compile_virtual(string path) {
    if (!path || path == "") return 0;

    string json_path = 0;
    if (file_size(path + ".json") > 0) {
        json_path = path + ".json";
    } else if (strlen(path) >= 5 && path[sizeof(path)-5..] == ".json" && file_size(path) > 0) {
        json_path = path;
    }
    if (!json_path) return 0;

    string raw = read_file(json_path);
    if (!raw || raw == "") return 0;
    mixed data = json_decode(raw);
    if (!mapp(data)) return 0;

    string dtype = data["type"] ? data["type"] : "";
    if (dtype != "npc") return 0;

    object npc = clone_object("/std/json_npc.c");
    if (!npc) return 0;
    npc->init_from_json(data);
    npc_index[path] = data;
    return npc;
}

object spawn_npc(string path) {
    return compile_virtual(path);
}

void scan_npc_dir(string dir) {
    mixed *files = get_dir(dir, -1);
    if (!arrayp(files)) return;
    for (int i = 0; i < sizeof(files); i++) {
        mixed f = files[i];
        string fname = arrayp(f) ? f[0] : f;
        int fsize = arrayp(f) && sizeof(f) > 1 ? f[1] : 0;
        if (!stringp(fname) || fname == "." || fname == "..") continue;
        if (fsize == -2) {
            scan_npc_dir(dir + fname + "/");
            continue;
        }
        if (strlen(fname) < 6) continue;
        if (fname[sizeof(fname)-5..] != ".json") continue;
        string fpath = dir + fname;
        string raw = read_file(fpath);
        if (!raw || raw == "") continue;
        mixed data = json_decode(raw);
        if (!mapp(data) || data["type"] != "npc") continue;
        string vpath = fpath[..sizeof(fpath)-6];
        npc_index[vpath] = data;
    }
}

void preload_npcs() {
    scan_npc_dir("/npcs/");
}

mapping query_npc_data(string vpath)  { return npc_index ? npc_index[vpath] : 0; }
string *query_npc_paths()             { return npc_index ? keys(npc_index) : ({}); }

void reload() {
    npc_index = ([]);
    preload_npcs();
    write("[npc_factory_d] 已重新索引 " + sizeof(keys(npc_index)) + " 個 NPC\n");
}
