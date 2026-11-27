// std/json_room.c - JSON 資料驅動房間基底 (Phase 2 MVVM)
// 從 mapping 資料具現房間，實現零 .c stub

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/room.c";

mapping _json_data;
nosave int _spawned;

void init_from_json(mapping data);

void create() {
    if (mapp(_json_data)) {
        mapping saved = _json_data;
        ::create();
        _spawned = 0;
        init_from_json(saved);
        return;
    }
    ::create();
    _spawned = 0;
}

void init_from_json(mapping data) {
    if (!data) return;
    _json_data = data;

    if (data["short"]) set_short(data["short"]);
    if (data["long"])  set_long(data["long"]);
    if (data["name"])  set_name(data["name"], 0);

    if (mapp(data["exits"])) {
        exits = ([]);
        string *dirs = keys(data["exits"]);
        for (int i = 0; i < sizeof(dirs); i++) {
            set_exit(dirs[i], data["exits"][dirs[i]]);
        }
    }

    if (intp(data["x"])) x = data["x"];
    if (intp(data["y"])) y = data["y"];
    if (intp(data["z"])) z = data["z"];

    if (mapp(data["flags"])) {
        room_flags = data["flags"];
        if (room_flags["no_combat"]) no_combat = 1;
    }

    if (mapp(data["items"]))   item_ids        = data["items"];
    if (mapp(data["hidden"]))  hidden_elements = data["hidden"];
    if (mapp(data["touch"]))   touch_descs     = data["touch"];
    if (mapp(data["smell"]))   smell_descs     = data["smell"];
    if (mapp(data["listen"]))  listen_descs    = data["listen"];
    if (mapp(data["actions"])) action_rules    = data["actions"];

    if (!_spawned) {
        if (arrayp(data["npcs"]) && sizeof(data["npcs"]) > 0) {
            _spawned = 1;
            call_out("spawn_npcs", 0);
        }
        if (arrayp(data["items_spawn"]) && sizeof(data["items_spawn"]) > 0) {
            _spawned = 1;
            call_out("spawn_items", 0);
        }
    }
}

void spawn_npcs() {
    if (!_json_data || !arrayp(_json_data["npcs"])) return;
    mixed *npc_list = _json_data["npcs"];
    for (int i = 0; i < sizeof(npc_list); i++) {
        string npc_path = "";
        if (stringp(npc_list[i])) {
            npc_path = npc_list[i];
        } else if (mapp(npc_list[i]) && stringp(npc_list[i]["path"])) {
            npc_path = npc_list[i]["path"];
        }
        if (!npc_path || npc_path == "") continue;

        object npc = 0;
        if (file_size(npc_path + ".json") > 0) {
            object nf = find_object("/daemon/npc_factory_d.c");
            if (!nf) nf = load_object("/daemon/npc_factory_d.c");
            if (nf) npc = nf->spawn_npc(npc_path);
        }
        if (!npc && (file_size(npc_path + ".c") > 0 || file_size(npc_path) > 0)) {
            npc = clone_object(npc_path);
        }
        if (npc) move_object(npc, this_object());
    }
}

void spawn_items() {
    if (!_json_data || !arrayp(_json_data["items_spawn"])) return;
    mixed *item_list = _json_data["items_spawn"];
    for (int i = 0; i < sizeof(item_list); i++) {
        string item_path = "";
        if (stringp(item_list[i])) {
            item_path = item_list[i];
        } else if (mapp(item_list[i]) && stringp(item_list[i]["path"])) {
            item_path = item_list[i]["path"];
        }
        if (!item_path || item_path == "") continue;

        object it = 0;
        if (file_size(item_path + ".json") > 0) {
            object itf = find_object("/daemon/item_factory_d.c");
            if (!itf) itf = load_object("/daemon/item_factory_d.c");
            if (itf) it = itf->spawn_item(item_path);
        }
        if (!it && (file_size(item_path + ".c") > 0 || file_size(item_path) > 0)) {
            it = clone_object(item_path);
        }
        if (it) move_object(it, this_object());
    }
}

mapping query_json_data() { return _json_data; }
