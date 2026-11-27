// std/json_item.c - JSON 資料驅動道具基底 (Phase 2 MVVM)

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/item.c";

mapping _json_data;

void init_from_json(mapping data);

void create() {
    if (mapp(_json_data)) {
        mapping saved = _json_data;
        ::create();
        init_from_json(saved);
        return;
    }
    ::create();
}

void init_from_json(mapping data) {
    if (!data) return;
    _json_data = data;

    if (data["name"]) set_name(data["name"], 0);
    if (data["short"]) set_short(data["short"]);
    if (data["long"])  set_long(data["long"]);

    mixed *merged_ids = ({});
    if (stringp(data["id"])) merged_ids += ({ data["id"] });
    else if (arrayp(data["id"])) merged_ids += data["id"];
    if (arrayp(data["id_list"])) {
        for (int i = 0; i < sizeof(data["id_list"]); i++) {
            if (member_array(data["id_list"][i], merged_ids) == -1) {
                merged_ids += ({ data["id_list"][i] });
            }
        }
    }
    if (sizeof(merged_ids) > 0) set_id(merged_ids);

    if (stringp(data["item_type"])) set_item_type(data["item_type"]);
    if (intp(data["value"]))        set_value(data["value"]);
    if (intp(data["weight"]))       set_weight(data["weight"]);
    if (intp(data["stackable"]))    set_stackable(data["stackable"]);
    if (intp(data["no_get"]))       set_no_get(data["no_get"]);
    if (intp(data["no_drop"]))      set_no_drop(data["no_drop"]);
    if (mapp(data["props"])) {
        string *pk = keys(data["props"]);
        for (int i = 0; i < sizeof(pk); i++) {
            set(pk[i], data["props"][pk[i]]);
        }
    }
}

mapping query_json_data() { return _json_data; }
