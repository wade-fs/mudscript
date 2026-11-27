// daemon/item_factory_d.c - JSON 道具工廠守護進程 (Phase 2 MVVM)
// 依 JSON 動態具現道具，支援 compile_object() 零 .c stub

#include "/include/config.h"

inherit "/std/object.c";

mapping item_index;   // virtualPath -> json_data

void preload_items();

void create() {
    ::create();
    item_index = ([]);
    preload_items();
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
    if (dtype != "item") return 0;

    object it = clone_object("/std/json_item.c");
    if (!it) return 0;
    it->init_from_json(data);
    item_index[path] = data;
    return it;
}

object spawn_item(string path) {
    return compile_virtual(path);
}

void scan_item_dir(string dir) {
    mixed *files = get_dir(dir, -1);
    if (!arrayp(files)) return;
    for (int i = 0; i < sizeof(files); i++) {
        mixed f = files[i];
        string fname = arrayp(f) ? f[0] : f;
        int fsize = arrayp(f) && sizeof(f) > 1 ? f[1] : 0;
        if (!stringp(fname) || fname == "." || fname == "..") continue;
        if (fsize == -2) {
            scan_item_dir(dir + fname + "/");
            continue;
        }
        if (strlen(fname) < 6) continue;
        if (fname[sizeof(fname)-5..] != ".json") continue;
        string fpath = dir + fname;
        string raw = read_file(fpath);
        if (!raw || raw == "") continue;
        mixed data = json_decode(raw);
        if (!mapp(data) || data["type"] != "item") continue;
        string vpath = fpath[..sizeof(fpath)-6];
        item_index[vpath] = data;
    }
}

void preload_items() {
    scan_item_dir("/items/");
}

mapping query_item_data(string vpath) { return item_index ? item_index[vpath] : 0; }
string *query_item_paths()            { return item_index ? keys(item_index) : ({}); }

void reload() {
    item_index = ([]);
    preload_items();
    write("[item_factory_d] 已重新索引 " + sizeof(keys(item_index)) + " 個道具\n");
}
