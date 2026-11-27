// std/json_npc.c - JSON 資料驅動 NPC 基底 (Phase 2 MVVM)
// 從 mapping 資料具現 NPC，支援狀態機 (states)、對話樹與行為

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/npc.c";

mapping _json_data;
mapping npc_states;      // state_name -> state config
string  current_state;   // 當前狀態名稱

void init_from_json(mapping data);
int  set_npc_state(string state_name);

void create() {
    if (mapp(_json_data)) {
        mapping saved = _json_data;
        ::create();
        npc_states = ([]);
        current_state = "";
        init_from_json(saved);
        return;
    }
    ::create();
    npc_states = ([]);
    current_state = "";
}

void init_from_json(mapping data) {
    if (!data) return;
    _json_data = data;

    if (data["name"])  set_name(data["name"], 0);
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

    if (intp(data["level"]))       level = data["level"];
    if (intp(data["stat_str"]))    stat_str = data["stat_str"];
    if (intp(data["stat_con"]))    stat_con = data["stat_con"];
    if (intp(data["stat_int"]))    stat_int = data["stat_int"];
    if (intp(data["stat_spi"]))    stat_spi = data["stat_spi"];
    if (intp(data["stat_dex"]))    stat_dex = data["stat_dex"];
    if (intp(data["stat_per"]))    stat_per = data["stat_per"];
    if (intp(data["exp_reward"]))  set_exp_reward(data["exp_reward"]);
    if (intp(data["gold_reward"])) set_gold_reward(data["gold_reward"]);

    if (intp(data["aggressive"]))    set_aggressive(data["aggressive"]);
    if (intp(data["wander_chance"])) wander_chance = data["wander_chance"];
    if (stringp(data["home_room"]))  set_home_room(data["home_room"]);

    if (mapp(data["dialogue"])) {
        set_dialogue_tree(data["dialogue"]);
    } else if (stringp(data["dialogue_file"])) {
        dialogue_id = data["dialogue_file"];
    }

    if (arrayp(data["drops"])) set_drop_list(data["drops"]);

    if (mapp(data["states"])) {
        npc_states = data["states"];
        string init_st = stringp(data["initial_state"]) ? data["initial_state"] : "";
        if (init_st != "" && npc_states[init_st]) {
            set_npc_state(init_st);
        }
    }

    recalc_stats();
    hp = max_hp;
    mp = max_mp;
    sp = max_sp;
}

// ── NPC 狀態機 ───────────────────────────────────────────
string query_npc_state() { return current_state ? current_state : ""; }
mapping query_npc_states() { return npc_states ? npc_states : ([]); }

int set_npc_state(string state_name) {
    if (!npc_states || !mapp(npc_states[state_name])) return 0;
    current_state = state_name;
    mapping st = npc_states[state_name];
    if (st["short"]) set_short(st["short"]);
    if (st["long"])  set_long(st["long"]);
    if (mapp(st["dialogue"])) {
        // 合併或覆寫狀態專屬對話
        if (!mapp(dialogue_tree)) dialogue_tree = ([]);
        string *dk = keys(st["dialogue"]);
        for (int i = 0; i < sizeof(dk); i++) {
            dialogue_tree[dk[i]] = st["dialogue"][dk[i]];
        }
    }
    return 1;
}

int transition_state(string event_key) {
    if (!npc_states || current_state == "" || !mapp(npc_states[current_state])) return 0;
    mapping cur = npc_states[current_state];
    if (!mapp(cur["transitions"]) || !stringp(cur["transitions"][event_key])) return 0;
    return set_npc_state(cur["transitions"][event_key]);
}

// ── 對話系統 ─────────────────────────────────────────────
mapping ensure_dialogue() {
    if (mapp(dialogue_tree) && sizeof(dialogue_tree) > 0) return dialogue_tree;
    if (dialogue_id && dialogue_id != "") {
        string path = dialogue_id;
        if (file_size(path + ".json") > 0) path = path + ".json";
        if (file_size(path) > 0) {
            string raw = read_file(path);
            if (raw && raw != "") {
                mixed parsed = json_decode(raw);
                if (mapp(parsed)) {
                    dialogue_tree = parsed;
                    return dialogue_tree;
                }
            }
        }
    }
    return ([]);
}

mixed query_dialogue(string topic) {
    mapping tree = ensure_dialogue();
    if (!tree) return 0;
    if (tree[topic]) return tree[topic];
    if (topic == "" && tree["default"]) return tree["default"];
    return 0;
}

// 執行對話節點並處理選擇/任務/狀態副作用
string talk_to(object who, string topic) {
    if (!topic || topic == "") topic = "default";
    mixed node = query_dialogue(topic);
    if (!node) {
        node = query_dialogue("default");
        if (!node) return to_string(query_name()) + " 看著你，沒有多說什麼。";
    }

    if (stringp(node)) return node;
    if (!mapp(node)) return to_string(node);

    // 若是純多語系字串 mapping
    if (!node["text"] && (node["zh-TW"] || node["en"] || node["zh-CN"])) {
        return select_lang(node);
    }

    // 檢查前置旗標
    if (who && stringp(node["require_flag"])) {
        if (!who->query_quest_flag(node["require_flag"])) {
            if (node["fail_text"]) return select_lang(node["fail_text"]);
            return to_string(query_name()) + " 搖搖頭：「現在還不是時候。」";
        }
    }

    string out = node["text"] ? select_lang(node["text"]) : "";

    // 套用玩家旗標
    if (who && mapp(node["set_flag"])) {
        string *fk = keys(node["set_flag"]);
        for (int i = 0; i < sizeof(fk); i++) {
            who->set_quest_flag(fk[i], node["set_flag"][fk[i]]);
        }
    }

    // 切換 NPC 狀態
    if (stringp(node["set_state"]) && node["set_state"] != "") {
        set_npc_state(node["set_state"]);
    }
    if (stringp(node["transition"]) && node["transition"] != "") {
        transition_state(node["transition"]);
    }

    // 接取 / 推進 / 分支任務
    object qed = find_object("/daemon/quest_engine_d.c");
    if (!qed) qed = load_object("/daemon/quest_engine_d.c");
    if (who && qed) {
        if (stringp(node["accept_quest"]) && node["accept_quest"] != "") {
            qed->accept_quest(who, node["accept_quest"]);
        }
        if (mapp(node["advance_quest"]) && stringp(node["advance_quest"]["id"])) {
            qed->advance_stage(who, node["advance_quest"]["id"], node["advance_quest"]["data"]);
        }
        if (mapp(node["choose_quest"]) && stringp(node["choose_quest"]["id"])) {
            qed->choose_branch(who, node["choose_quest"]["id"], node["choose_quest"]["choice"]);
        }
    }

    // 贈予金幣或道具
    if (who && intp(node["give_money"]) && node["give_money"] > 0) {
        who->add_money(node["give_money"]);
    }
    if (who && stringp(node["give_item"]) && node["give_item"] != "") {
        object it = clone_object(node["give_item"]);
        if (it) move_object(it, who);
    }

    // 附加選項提示
    if (arrayp(node["choices"]) && sizeof(node["choices"]) > 0) {
        out += "\n";
        mixed *ch = node["choices"];
        for (int i = 0; i < sizeof(ch); i++) {
            if (!mapp(ch[i])) continue;
            string lbl = ch[i]["label"] ? select_lang(ch[i]["label"]) : ch[i]["topic"];
            string tpc = ch[i]["topic"] ? ch[i]["topic"] : "";
            out += "  - [" + lbl + "|talk " + query_id()[0] + " " + tpc + "]\n";
        }
    }

    return out;
}

void heart_beat() {
    if (wander_chance <= 0) return;
    if (random(100) >= wander_chance) return;

    object room = environment(this_object());
    if (!room) return;
    mapping ex = room->query_exits();
    if (!ex || sizeof(ex) == 0) return;

    string *dirs = keys(ex);
    string chosen = dirs[random(sizeof(dirs))];
    string dest = ex[chosen];
    if (!dest) return;

    object next_room = load_object(dest);
    if (next_room) move_object(this_object(), next_room);
}

mapping query_json_data() { return _json_data; }
