// /secure/quest_d.c
// 任務守護進程 (Quest Daemon)

#include "/include/ansi.h"

inherit "/std/object";

mapping quest_list;

void create() {
    ::create();
    quest_list = ([
        "pass_village_ceremony": ([
            "name": ([ "en": "Village Exit Permit", "zh-TW": "出鄉文牒考驗", "zh-CN": "出乡文牒考验" ]),
            "desc": ([ "en": "Reach level 10 and obtain road pass to Jinshi City.", "zh-TW": "等級達到 10 級，向聚落長者證明實力，取得前往金石城的官辦保書路引。", "zh-CN": "等级达到 10 级，向聚落长者证明实力，取得前往金石城的官办保书路引。" ]),
            "level": 10,
            "reward": ([
                "exp": 1000,
                "gold": 500,
                "item": "/clone/item/road_pass.c"
            ])
        ]),
        "newbie_badge": ([
            "name": ([ "en": "Blackstone Trial", "zh-TW": "黑石聚落試煉", "zh-CN": "黑石聚落试炼" ]),
            "desc": ([ "en": "Prove your basic survival skills in Blackstone Hamlet.", "zh-TW": "在黑石鋪完成基礎生存歷練。", "zh-CN": "在黑石铺完成基础生存历练。" ]),
            "level": 1,
            "reward": ([
                "exp": 100,
                "gold": 50
            ])
        ]),
        "wolf_hunter": ([
            "name": ([ "en": "East Forest Threat", "zh-TW": "東林獵狼平煞", "zh-CN": "东林猎狼平煞" ]),
            "desc": ([ "en": "Eliminate 3 tainted wolves in the east forest.", "zh-TW": "前往東林荒林消滅 3 隻受地煞侵蝕的狂暴野狼。", "zh-CN": "前往东林荒林消灭 3 只受地煞侵蚀的狂暴野狼。" ]),
            "level": 3,
            "goal": ([ "type": "kill", "target": "wolf", "count": 3 ]),
            "reward": ([
                "exp": 500,
                "gold": 200
            ])
        ])
    ]);
}

mapping query_quest_info(string qid) {
    return quest_list[qid];
}

int accept_quest(object me, string qid) {
    mapping info = query_quest_info(qid);
    if (!info) return 0;

    if (me->query_level() < info["level"]) {
        write(to_string(_t("level_low_err")) + "\n");
        return 0;
    }

    if (me->query_quest(qid)) {
        write(to_string(_t("quest_already_accepted")) + "\n");
        return 0;
    }

    me->set_quest(qid, ([
        "status": "active",
        "start_time": time(),
        "progress": ([ "count": 0 ])
    ]));
    
    string accept_msg = to_string(_t("quest_accept"));
    accept_msg = replace_string(accept_msg, "$quest", to_string(select_lang(info["name"])));
    write("$HIG$" + accept_msg + "$NOR$" + "\n");
    
    string desc_msg = to_string(_t("quest_desc"));
    desc_msg = replace_string(desc_msg, "$desc", to_string(select_lang(info["desc"])));
    write(desc_msg + "\n");
    
    me->save();
    return 1;
}

int complete_quest(object me, string qid) {
    mapping qdata = me->query_quest(qid);
    if (!qdata || qdata["status"] != "active") return 0;

    mapping info = query_quest_info(qid);
    
    // 🚀 如果是蒐集任務，檢查並扣除物品
    if (info["goal"] && info["goal"]["type"] == "item") {
        string target_name = info["goal"]["target"];
        int req_count = info["goal"]["count"];
        
        object *inv = all_inventory(me);
        object *found = ({});
        foreach (object ob in inv) {
            if (ob->query_name() == target_name) found += ({ ob });
        }
        
        if (sizeof(found) < req_count) {
            string err = to_string(_t("quest_item_missing"));
            err = replace_string(err, "$item", to_string(target_name));
            err = replace_string(err, "$got", sprintf("%d", sizeof(found)));
            err = replace_string(err, "$req", sprintf("%d", req_count));
            write(err + "\n");
            return 0;
        }
        
        // 扣除物品
        for (int i = 0; i < req_count; i++) {
            destruct(found[i]);
        }
        string give_msg = to_string(_t("quest_item_give"));
        give_msg = replace_string(give_msg, "$count", sprintf("%d", req_count));
        give_msg = replace_string(give_msg, "$item", to_string(target_name));
        write(give_msg + "\n");
    }

    // 給予獎勵
    mapping reward = info["reward"];
    if (reward["exp"]) me->gain_exp(reward["exp"]);
    if (reward["gold"]) me->gain_gold(reward["gold"]);
    
    // 🚀 新增：公會貢獻獎勵
    if (me->query_guild()) {
        int gexp = reward["exp"] / 5; // 預設貢獻度為經驗值的 20%
        if (gexp < 1) gexp = 1;
        me->add_guild_exp(gexp);
        tell_object(me, "$HIG$" + sprintf("%s%d\n", to_string(_t("guild_exp_gain")), gexp) + "$NOR$");
    }

    if (reward["badge"]) {
        object badge = clone_object(reward["badge"]);
        if (badge) {
            string msg = to_string(_t("quest_reward_get"));
            if (msg == "quest_reward_get") msg = "你獲得了 $item！";
            msg = replace_string(msg, "$item", to_string(badge->query_short()));
            write(msg + "\n");
            move_object(badge, me);
        }
    }
    if (reward["item"]) {
        object ob = clone_object(reward["item"]);
        if (ob) {
            string msg = to_string(_t("quest_reward_item"));
            if (msg == "quest_reward_item") msg = "你獲得了獎勵物品：$item！";
            msg = replace_string(msg, "$item", to_string(ob->query_short()));
            write(msg + "\n");
            if (!move_object(ob, me)) move_object(ob, environment(me));
        }
    }

    qdata["status"] = "completed";
    qdata["end_time"] = time();
    me->set_quest(qid, qdata);
    
    string complete_msg = to_string(_t("quest_complete"));
    complete_msg = replace_string(complete_msg, "$quest", to_string(select_lang(info["name"])));
    write("$HIY$" + complete_msg + "$NOR$" + "\n");
    
    me->save();
    return 1;
}

// 🚀 新增：檢查殺怪進度
void check_kill_progress(object me, string monster_file) {
    mapping quests = me->query_quests();
    if (!quests) return;

    mixed ks = keys(quests);
    foreach (string qid in ks) {
        mapping qdata = quests[qid];
        if (qdata["status"] != "active") continue;

        mapping info = quest_list[qid];
        if (!info["goal"] || info["goal"]["type"] != "kill") continue;

        // 檢查是否為目標怪物 (支援 partial path 匹配)
        if (strsrch(monster_file, info["goal"]["target"]) != -1) {
            int current = qdata["progress"]["count"] + 1;
            int total = info["goal"]["count"];
            
            me->update_quest_progress(qid, "count", current);
            string progress_msg = to_string(_t("quest_progress"));
            if (progress_msg == "quest_progress") progress_msg = "$HIG$【任務進度】$NOR$" + "$quest：$current / $total";
            progress_msg = replace_string(progress_msg, "$quest", to_string(select_lang(info["name"])));
            progress_msg = replace_string(progress_msg, "$current", sprintf("%d", current));
            progress_msg = replace_string(progress_msg, "$total", sprintf("%d", total));
            tell_object(me, progress_msg + "\n");

            if (current >= total) {
                tell_object(me, "$HIY$" + to_string(_t("quest_goal_met")) + "\n$NOR$");
            }
        }
    }
}

mapping query_all_quests() {
    return quest_list;
}
