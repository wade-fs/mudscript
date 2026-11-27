// daemon/ui_bridge_d.c - UI Bridge 守護進程 (Phase 2 MVVM)
// 將房間/任務/角色狀態打包為結構化 ViewModel DTO（供 Web + ANSI 使用）

#include "/include/config.h"
#include "/include/mvvm_protocol.h"

inherit "/std/object.c";

void create() {
    ::create();
}

// ── 房間 ViewModel ─────────────────────────────────────────
mapping build_room_view(object room, object viewer) {
    if (!room) return ([]);

    mapping view = ([
        "type":         "room",
        "path":         base_name(room),
        "short":        to_string(room->query_short()),
        "long":         to_string(room->query_long()),
        "exits":        ([ ]),
        "npcs":         ({ }),
        "items":        ({ }),
        "inspectables": ({ }),
        "actions":      ({ }),
        "sensory":      ([ ]),
        "flags":        function_exists("query_flags", room) ? room->query_flags() : ([])
    ]);

    object rf = find_object(ROOM_FACTORY_D);
    mapping exits = room->query_exits();
    if (mapp(exits)) {
        string *dirs = keys(exits);
        for (int i = 0; i < sizeof(dirs); i++) {
            string d = dirs[i];
            string dest = exits[d];
            string dest_short = "";
            object dest_ob = find_object(dest);
            if (dest_ob) {
                dest_short = to_string(dest_ob->query_short());
            } else if (rf) {
                mapping rdata = rf->query_room_data(dest);
                if (mapp(rdata) && rdata["short"]) dest_short = to_string(select_lang(rdata["short"]));
            }
            view["exits"][d] = ([
                "direction": d,
                "dest":      dest,
                "short":     dest_short
            ]);
        }
    }

    object *inv = all_inventory(room);
    for (int i = 0; i < sizeof(inv); i++) {
        object ob = inv[i];
        if (ob == viewer) continue;
        mixed ids = ob->query_id();
        string key_id = (arrayp(ids) && sizeof(ids) > 0) ? to_string(ids[0]) : base_name(ob);
        mapping ob_view = ([
            "short": to_string(ob->query_short()),
            "id":    key_id,
            "path":  base_name(ob)
        ]);
        if (living(ob)) {
            if (function_exists("query_npc_state", ob)) {
                ob_view["state"] = ob->query_npc_state();
            }
            if (function_exists("query_dialogue", ob)) {
                mixed def_node = ob->query_dialogue("default");
                if (mapp(def_node) && arrayp(def_node["choices"])) {
                    ob_view["choices"] = def_node["choices"];
                }
            }
            view["npcs"] += ({ ob_view });
        } else {
            view["items"] += ({ ob_view });
        }
    }

    if (function_exists("query_item_ids", room)) {
        mapping item_ids = room->query_item_ids();
        if (mapp(item_ids) && sizeof(item_ids) > 0) {
            view["inspectables"] = keys(item_ids);
        }
    }

    if (function_exists("query_action_rules", room)) {
        mapping rules = room->query_action_rules();
        if (mapp(rules) && sizeof(rules) > 0) {
            string *verbs = keys(rules);
            for (int i = 0; i < sizeof(verbs); i++) {
                string v = verbs[i];
                mapping r = rules[v];
                if (!mapp(r)) continue;
                string lbl = r["label"] ? to_string(select_lang(r["label"])) : v;
                mixed targets = arrayp(r["targets"]) ? r["targets"] : ({});
                view["actions"] += ({ ([
                    "verb":    v,
                    "label":   lbl,
                    "targets": targets
                ]) });
            }
        }
    }

    if (function_exists("query_hidden_elements", room)) {
        mapping h = room->query_hidden_elements();
        if (mapp(h) && sizeof(h) > 0) view["sensory"]["search"] = keys(h);
    }
    if (function_exists("query_touch_descs", room)) {
        mapping t = room->query_touch_descs();
        if (mapp(t) && sizeof(t) > 0) view["sensory"]["touch"] = keys(t);
    }
    if (function_exists("query_smell_descs", room)) {
        mapping s = room->query_smell_descs();
        if (mapp(s) && sizeof(s) > 0) view["sensory"]["smell"] = keys(s);
    }
    if (function_exists("query_listen_descs", room)) {
        mapping l = room->query_listen_descs();
        if (mapp(l) && sizeof(l) > 0) view["sensory"]["listen"] = keys(l);
    }

    return view;
}

int read_stat(object who, string stat_key) {
    if (!who || !stat_key || stat_key == "") return 0;
    string fn = "query_stat_" + stat_key;
    if (function_exists(fn, who)) {
        return to_int(call_other(who, fn));
    }
    if (function_exists("query_stat", who)) {
        return to_int(who->query_stat(stat_key));
    }
    if (function_exists("query", who)) {
        return to_int(who->query(stat_key));
    }
    return 0;
}

// ── 角色 ViewModel ─────────────────────────────────────────
mapping build_char_view(object who) {
    if (!who) return ([]);

    object sd = find_object(SCHEMA_D);
    if (!sd) sd = load_object(SCHEMA_D);

    int lv = who->query_level();
    int money_raw = who->query_money();
    string money_fmt = sd ? sd->format_money(money_raw) : (money_raw + " 元");
    string realm = sd ? sd->query_realm_for_level("", lv) : ("Lv." + lv);
    mapping labels = sd ? sd->query_stat_labels("") : ([]);

    int sp_val = function_exists("query_sp", who) ? who->query_sp() : 0;
    int max_sp_val = function_exists("query_max_sp", who) ? who->query_max_sp() : 0;
    string guild_val = function_exists("query_guild", who) ? to_string(who->query_guild()) : "";

    return ([
        "type":        "character",
        "id":          to_string(function_exists("query_id", who) ? who->query_id() : who->get_id()),
        "name":        to_string(who->query_short()),
        "level":       lv,
        "realm":       realm,
        "hp":          who->query_hp(),
        "max_hp":      who->query_max_hp(),
        "mp":          who->query_mp(),
        "max_mp":      who->query_max_mp(),
        "sp":          sp_val,
        "max_sp":      max_sp_val,
        "atk":         who->query_attack(),
        "def":         who->query_defence(),
        "str":         read_stat(who, "str"),
        "con":         read_stat(who, "con"),
        "int":         read_stat(who, "int"),
        "spi":         read_stat(who, "spi"),
        "dex":         read_stat(who, "dex"),
        "per":         read_stat(who, "per"),
        "wis":         read_stat(who, "wis"),
        "cha":         read_stat(who, "cha"),
        "stat_labels": labels,
        "money":       money_fmt,
        "money_raw":   money_raw,
        "guild":       guild_val,
        "race":        to_string(who->query_race())
    ]);
}

// ── 任務清單 ViewModel ────────────────────────────────────
mapping build_quest_list(object who) {
    if (!who) return ([ "type": "quest_list", "quests": ({}) ]);
    mapping quests = who->query_quests();
    if (!mapp(quests)) return ([ "type": "quest_list", "quests": ({}) ]);

    mapping view = ([ "type": "quest_list", "quests": ({}) ]);

    object qed = find_object(QUEST_ENGINE_D);
    string *qids = keys(quests);
    for (int i = 0; i < sizeof(qids); i++) {
        string qid = qids[i];
        mixed  pq  = quests[qid];
        if (!mapp(pq)) continue;

        mapping qdef = qed ? qed->query_quest(qid) : 0;
        string qname = (qdef && qdef["name"]) ? qdef["name"] : qid;
        string qdesc = (qdef && qdef["desc"]) ? qdef["desc"] : "";
        string status = pq["status"] ? pq["status"] : "unknown";
        int cur_stage = pq["stage"] ? pq["stage"] : 0;

        string stage_desc = "";
        mixed *choice_list = ({});
        if (status == "active" && mapp(qdef) && arrayp(qdef["stages"])) {
            mixed *stages = qdef["stages"];
            if (cur_stage >= 0 && cur_stage < sizeof(stages) && mapp(stages[cur_stage])) {
                mapping st = stages[cur_stage];
                if (st["desc"]) stage_desc = to_string(select_lang(st["desc"]));
                mixed st_choices = st["choices"];
                if (mapp(st_choices)) {
                    string *ckeys = keys(st_choices);
                    for (int j = 0; j < sizeof(ckeys); j++) {
                        string cid = ckeys[j];
                        mapping cdef = st_choices[cid];
                        if (!mapp(cdef)) continue;
                        if (stringp(cdef["require_flag"]) && !who->query_quest_flag(cdef["require_flag"])) continue;
                        string clbl = cdef["label"] ? to_string(select_lang(cdef["label"])) : cid;
                        choice_list += ({ ([ "id": cid, "label": clbl ]) });
                    }
                } else if (arrayp(st_choices)) {
                    for (int j = 0; j < sizeof(st_choices); j++) {
                        mapping cdef = st_choices[j];
                        if (!mapp(cdef) || !stringp(cdef["id"])) continue;
                        if (stringp(cdef["require_flag"]) && !who->query_quest_flag(cdef["require_flag"])) continue;
                        string clbl = cdef["label"] ? to_string(select_lang(cdef["label"])) : cdef["id"];
                        choice_list += ({ ([ "id": cdef["id"], "label": clbl ]) });
                    }
                }
            }
        }

        view["quests"] += ({ ([
            "id":         qid,
            "name":       qname,
            "desc":       qdesc,
            "status":     status,
            "stage":      cur_stage,
            "stage_desc": stage_desc,
            "choices":    choice_list
        ]) });
    }
    return view;
}

// ── 推送到玩家 ─────────────────────────────────────────────
void push_room_view(object who) {
    if (!who) return;
    object room = environment(who);
    if (!room) return;
    mapping view = build_room_view(room, who);
    tell_object(who, sprintf("{\"ui\": \"%s\", \"data\": %s}", UI_ROOM_VIEW, json_encode(view)));
}

void push_char_view(object who) {
    if (!who) return;
    mapping view = build_char_view(who);
    tell_object(who, sprintf("{\"ui\": \"%s\", \"data\": %s}", UI_CHAR_VIEW, json_encode(view)));
}

void push_quest_list(object who) {
    if (!who) return;
    mapping view = build_quest_list(who);
    tell_object(who, sprintf("{\"ui\": \"%s\", \"data\": %s}", UI_QUEST_LIST, json_encode(view)));
}
