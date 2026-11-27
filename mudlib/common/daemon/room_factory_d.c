// daemon/room_factory_d.c - JSON 房間工廠守護進程 (Phase 2 MVVM)
// 依 JSON 動態具現或索引房間、出口與環境互動
// 實現 compile_object() 的零 .c stub 機制

#include "/include/config.h"

inherit "/std/object.c";

mapping room_index;    // virtualPath -> json_data

void preload_rooms();

void create() {
    ::create();
    room_index = ([]);
    preload_rooms();
}

int is_json_room_exists(string path) {
    if (!path || path == "") return 0;
    if (file_size(path + ".json") > 0) return 1;
    if (strlen(path) >= 5 && path[sizeof(path)-5..] == ".json" && file_size(path) > 0) return 1;
    return 0;
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

    string dtype = data["type"] ? data["type"] : "room";
    if (dtype != "room") return 0;

    object room = clone_object("/std/json_room.c");
    if (!room) return 0;

    room->init_from_json(data);
    room_index[path] = data;

    return room;
}

void scan_room_dir(string dir) {
    mixed *files = get_dir(dir, -1);
    if (!arrayp(files)) return;
    for (int i = 0; i < sizeof(files); i++) {
        mixed f = files[i];
        string fname = arrayp(f) ? f[0] : f;
        int fsize = arrayp(f) && sizeof(f) > 1 ? f[1] : 0;
        if (!stringp(fname) || fname == "." || fname == "..") continue;
        if (fsize == -2) {
            scan_room_dir(dir + fname + "/");
            continue;
        }
        if (strlen(fname) < 6) continue;
        if (fname[sizeof(fname)-5..] != ".json") continue;

        string fpath = dir + fname;
        string raw = read_file(fpath);
        if (!raw || raw == "") continue;
        mixed data = json_decode(raw);
        if (!mapp(data)) continue;
        string dtype = data["type"] ? data["type"] : "room";
        if (dtype != "room") continue;
        string vpath = fpath[..sizeof(fpath)-6];
        room_index[vpath] = data;
    }
}

void preload_rooms() {
    scan_room_dir("/rooms/");
}

mapping query_room_data(string vpath) {
    return room_index ? room_index[vpath] : 0;
}

string *query_room_paths() {
    return room_index ? keys(room_index) : ({});
}

void reload() {
    room_index = ([]);
    preload_rooms();
    write("[room_factory_d] 已重新索引 " + sizeof(keys(room_index)) + " 個房間\n");
}
