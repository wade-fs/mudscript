// daemon/quest_engine_d.c - 通用任務引擎守護進程 (World-Agnostic, Phase 2 MVVM)
// 支援 /quests/*.json、多階段狀態機、選擇分支與後果 (choices/consequences) 與 .json 存在性檢查

#include "/include/config.h"

inherit "/std/object.c";

mapping quest_defs;     // qid -> mapping

string query_save_file() { return "/data/quest_engine_d"; }

void load_all_quests();
int complete_quest(object who, string qid);
int complete_quest_with_status(object who, string qid, string status, mapping custom_rewards);

void create() {
    ::create();
    quest_defs = ([]);
    load_all_quests();
}

// ── .json / .c 通用存在性檢查 ─────────────────────────────
int file_exists_any(string path) {
    if (!path || path == "") return 0;
    if (file_size(path) > 0) return 1;
    if (file_size(path + ".c") > 0) return 1;
    if (file_size(path + ".json") > 0) return 1;
    return 0;
}

object spawn_reward_item(string item_path) {
    if (!item_path || item_path == "") return 0;
    if (file_size(item_path + ".json") > 0) {
        object itf = find_object("/daemon/item_factory_d.c");
        if (!itf) itf = load_object("/daemon/item_factory_d.c");
        if (itf) return itf->spawn_item(item_path);
    }
    if (file_exists_any(item_path)) {
        return clone_object(item_path);
    }
    return 0;
}

void scan_quest_dir(string dir) {
    mixed *files = get_dir(dir, -1);
    if (!arrayp(files)) return;

    for (int i = 0; i < sizeof(files); i++) {
        mixed f = files[i];
        string fname = arrayp(f) ? f[0] : f;
        int fsize = arrayp(f) && sizeof(f) > 1 ? f[1] : 0;
        if (!stringp(fname) || fname == "." || fname == "..") continue;
        if (fsize == -2) {
            scan_quest_dir(dir + fname + "/");
            continue;
        }
        if (strlen(fname) < 6) continue;
        if (fname[sizeof(fname)-5..] != ".json") continue;

        string fpath = dir + fname;
        if (file_size(fpath) <= 0) continue;

        string raw = read_file(fpath);
        if (!raw || raw == "") continue;
        mixed data = json_decode(raw);
        if (!mapp(data)) continue;

        string qid = fname[..sizeof(fname)-6];
        if (stringp(data["id"]) && data["id"] != "") qid = data["id"];
        quest_defs[qid] = data;
    }
}

void load_all_quests() {
    if (!quest_defs) quest_defs = ([]);
    scan_quest_dir("/quests/");
}

mapping query_quest(string qid) {
    return quest_defs ? quest_defs[qid] : 0;
}

mapping query_all_quests() { return quest_defs ? quest_defs : ([]); }

// ── 任務接受 ─────────────────────────────────────────────
int accept_quest(object who, string qid) {
    if (!who || !qid) return 0;
    mapping q = quest_defs[qid];
    if (!q) {
        write("[quest_engine] 任務不存在: " + qid + "\n");
        return 0;
    }

    mixed player_quest = who->query_quest(qid);
    if (player_quest) {
        write("你已接受過這個任務了。\n");
        return 0;
    }

    if (q["requires"] && arrayp(q["requires"])) {
        mixed *reqs = q["requires"];
        for (int i = 0; i < sizeof(reqs); i++) {
            mixed req_pq = who->query_quest(reqs[i]);
            if (!req_pq || (mapp(req_pq) && req_pq["status"] == "active")) {
                write("你尚未完成前置任務：" + reqs[i] + "\n");
                return 0;
            }
        }
    }

    who->set_quest(qid, ([
        "status": "active",
        "stage":  0,
        "started": time(),
        "choices": ({}),
        "data":   ([])
    ]));

    string qname = q["name"] ? q["name"] : qid;
    write("{GRN}【任務】你接受了任務：" + qname + "{NOR}\n");
    if (q["desc"]) write(q["desc"] + "\n");

    object ui = find_object("/daemon/ui_bridge_d.c");
    if (ui) {
        ui->push_quest_list(who);
        ui->push_char_view(who);
    }
    return 1;
}

// ── 套用獎懲與副作用 ──────────────────────────────────────
void apply_rewards_and_effects(object who, mapping rw) {
    if (!who || !mapp(rw)) return;

    if (intp(rw["exp"]) && rw["exp"] > 0) {
        who->gain_exp(rw["exp"]);
        write("  獲得 " + rw["exp"] + " 點經驗值。\n");
    }
    if (intp(rw["money"]) && rw["money"] != 0) {
        who->add_money(rw["money"]);
        if (rw["money"] > 0) write("  獲得 " + rw["money"] + " 元。\n");
        else write("  失去 " + (-rw["money"]) + " 元。\n");
    }
    if (arrayp(rw["items"])) {
        mixed *ritems = rw["items"];
        for (int i = 0; i < sizeof(ritems); i++) {
            object it = spawn_reward_item(ritems[i]);
            if (it) {
                move_object(it, who);
                write("  獲得物品：" + to_string(it->query_short()) + "\n");
            }
        }
    }
    if (mapp(rw["set_flags"])) {
        string *fk = keys(rw["set_flags"]);
        for (int i = 0; i < sizeof(fk); i++) {
            who->set_quest_flag(fk[i], rw["set_flags"][fk[i]]);
        }
    }
    if (mapp(rw["world_vars"])) {
        object wsd = find_object("/daemon/world_state_d.c");
        if (!wsd) wsd = load_object("/daemon/world_state_d.c");
        if (wsd) {
            string *wk = keys(rw["world_vars"]);
            for (int i = 0; i < sizeof(wk); i++) {
                mixed v = rw["world_vars"][wk[i]];
                if (intp(v)) {
                    wsd->add_var(wk[i], v);
                } else if (mapp(v) && !undefinedp(v["set"])) {
                    wsd->set_var(wk[i], v["set"]);
                }
            }
        }
    }
    if (stringp(rw["fire_event"]) && rw["fire_event"] != "") {
        object wsd = find_object("/daemon/world_state_d.c");
        if (!wsd) wsd = load_object("/daemon/world_state_d.c");
        if (wsd) wsd->fire_event(rw["fire_event"], mapp(rw["event_data"]) ? rw["event_data"] : ([]));
    }
}

// ── 選擇分支與後果 (Phase 2 Choice Branching) ───────────────
int choose_branch(object who, string qid, string choice_id) {
    if (!who || !qid || !choice_id || choice_id == "") return 0;
    mapping q = quest_defs[qid];
    if (!q) return 0;

    mixed pq = who->query_quest(qid);
    if (!pq || !mapp(pq) || pq["status"] != "active") {
        write("你目前沒有進行中的任務：" + qid + "\n");
        return 0;
    }

    int cur_stage = pq["stage"] ? pq["stage"] : 0;
    mixed *stages = arrayp(q["stages"]) ? q["stages"] : ({});
    mapping choice_def = 0;

    // 先查當前階段的 choices
    if (cur_stage < sizeof(stages) && mapp(stages[cur_stage])) {
        mixed st_choices = stages[cur_stage]["choices"];
        if (mapp(st_choices) && mapp(st_choices[choice_id])) {
            choice_def = st_choices[choice_id];
        } else if (arrayp(st_choices)) {
            for (int i = 0; i < sizeof(st_choices); i++) {
                if (mapp(st_choices[i]) && st_choices[i]["id"] == choice_id) {
                    choice_def = st_choices[i];
                    break;
                }
            }
        }
    }

    // 再查頂層 branches
    if (!choice_def && mapp(q["branches"]) && mapp(q["branches"][choice_id])) {
        choice_def = q["branches"][choice_id];
    }

    if (!choice_def) {
        write("無效的抉擇選項：" + choice_id + "\n");
        return 0;
    }

    // 檢查選擇條件
    if (stringp(choice_def["require_flag"]) && !who->query_quest_flag(choice_def["require_flag"])) {
        write("你尚未滿足此選項的條件。\n");
        return 0;
    }

    // 記錄選擇歷史
    if (!arrayp(pq["choices"])) pq["choices"] = ({});
    pq["choices"] += ({ choice_id });
    if (!mapp(pq["data"])) pq["data"] = ([]);
    pq["data"]["last_choice"] = choice_id;

    if (choice_def["message"]) {
        write("{CYN}【抉擇】" + choice_def["message"] + "{NOR}\n");
    }

    // 套用後果
    if (mapp(choice_def["consequences"])) {
        apply_rewards_and_effects(who, choice_def["consequences"]);
    }
    apply_rewards_and_effects(who, choice_def);

    // 決定下一階段或結算狀態
    string end_status = stringp(choice_def["complete_status"]) ? choice_def["complete_status"] : "";
    if (end_status != "") {
        who->set_quest(qid, pq);
        return complete_quest_with_status(who, qid, end_status, choice_def["rewards"]);
    }

    if (intp(choice_def["next_stage"])) {
        pq["stage"] = choice_def["next_stage"];
    } else {
        pq["stage"] = cur_stage + 1;
    }
    who->set_quest(qid, pq);

    if (pq["stage"] >= sizeof(stages)) {
        return complete_quest_with_status(who, qid, "completed", choice_def["rewards"]);
    }

    object ui = find_object("/daemon/ui_bridge_d.c");
    if (ui) {
        ui->push_quest_list(who);
        ui->push_char_view(who);
    }
    return 1;
}

// ── 推進階段 ─────────────────────────────────────────────
int advance_stage(object who, string qid, mapping extra_data) {
    if (!who || !qid) return 0;
    mapping q = quest_defs[qid];
    if (!q) return 0;

    mixed pq = who->query_quest(qid);
    if (!pq || !mapp(pq)) return 0;
    if (pq["status"] != "active") return 0;

    int cur_stage = pq["stage"] ? pq["stage"] : 0;
    mixed *stages = arrayp(q["stages"]) ? q["stages"] : ({});
    int total = sizeof(stages);

    if (cur_stage >= total) {
        return complete_quest(who, qid);
    }

    mapping stage_def = stages[cur_stage];
    if (mapp(stage_def) && stage_def["condition"]) {
        string cond_key = stage_def["condition"];
        if (!extra_data || !extra_data[cond_key]) {
            return 0;
        }
    }

    pq["stage"] = cur_stage + 1;
    if (mapp(extra_data) && mapp(pq["data"])) {
        string *ekeys = keys(extra_data);
        for (int i = 0; i < sizeof(ekeys); i++) {
            pq["data"][ekeys[i]] = extra_data[ekeys[i]];
        }
    }
    who->set_quest(qid, pq);

    if (mapp(stage_def) && stage_def["progress_msg"]) {
        write("{CYN}【任務】" + stage_def["progress_msg"] + "{NOR}\n");
    }

    if (pq["stage"] >= total) {
        return complete_quest(who, qid);
    }

    mapping next_stage = stages[pq["stage"]];
    if (mapp(next_stage) && next_stage["desc"]) {
        write("{YEL}【任務目標】" + next_stage["desc"] + "{NOR}\n");
    }

    object ui = find_object("/daemon/ui_bridge_d.c");
    if (ui) {
        ui->push_quest_list(who);
        ui->push_char_view(who);
    }
    return 1;
}

// ── 完成任務 ─────────────────────────────────────────────
int complete_quest_with_status(object who, string qid, string status, mapping custom_rewards) {
    if (!who || !qid) return 0;
    mapping q = quest_defs[qid];
    if (!q) return 0;

    mixed pq = who->query_quest(qid);
    if (!pq || !mapp(pq)) return 0;

    pq["status"]    = (status && status != "") ? status : "completed";
    pq["completed"] = time();
    who->set_quest(qid, pq);

    string qname = q["name"] ? q["name"] : qid;
    write("{HIW}{GRN}【任務結算】" + qname + "（" + pq["status"] + "）！{NOR}\n");
    if (q["complete_msg"] && pq["status"] == "completed") {
        write(q["complete_msg"] + "\n");
    }

    if (mapp(custom_rewards)) {
        apply_rewards_and_effects(who, custom_rewards);
    } else if (mapp(q["rewards"]) && pq["status"] != "failed") {
        apply_rewards_and_effects(who, q["rewards"]);
    }

    who->do_save();

    object ui = find_object("/daemon/ui_bridge_d.c");
    if (ui) {
        ui->push_quest_list(who);
        ui->push_char_view(who);
    }
    return 1;
}

int complete_quest(object who, string qid) {
    return complete_quest_with_status(who, qid, "completed", 0);
}

void trigger_quest_event(object who, string event_type, mapping data) {
    if (!who || !event_type) return;
    string *qids = keys(quest_defs);
    for (int i = 0; i < sizeof(qids); i++) {
        string qid = qids[i];
        mapping q  = quest_defs[qid];
        if (!q || !q["event_trigger"]) continue;
        if (q["event_trigger"] != event_type) continue;

        mixed pq = who->query_quest(qid);
        if (!pq || !mapp(pq) || pq["status"] != "active") continue;

        advance_stage(who, qid, data);
    }
}

mapping query_player_quests(object who) {
    if (!who) return ([]);
    return who->query_quests();
}

void reload() {
    quest_defs = ([]);
    load_all_quests();
    write("[quest_engine_d] 已重新載入 " + sizeof(keys(quest_defs)) + " 個任務\n");
}
