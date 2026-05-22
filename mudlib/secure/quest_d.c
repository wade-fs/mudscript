// /secure/quest_d.c
// 任務守護進程 (Quest Daemon)

#include "/include/ansi.h"

mapping quest_list;

void create() {
    quest_list = ([
        "newbie_badge": ([
            "name": "新手證明",
            "desc": "向公會會長證明你的勇氣。",
            "level": 1,
            "reward": ([
                "exp": 100,
                "gold": 50,
                "badge": "/item/badge_newbie.c"
            ])
        ]),
        "wolf_hunter": ([
            "name": "獵狼行動",
            "desc": "消滅 3 隻飢餓的野狼。",
            "level": 3,
            "goal": ([ "type": "kill", "target": "wolf", "count": 3 ]),
            "reward": ([
                "exp": 500,
                "gold": 200
            ])
        ]),
        "collect_fur": ([
            "name": "毛皮需求",
            "desc": "收集 3 張狼皮交給防具店老闆。",
            "level": 3,
            "goal": ([ "type": "item", "target": "狼皮", "count": 3 ]),
            "reward": ([
                "exp": 300,
                "gold": 150,
                "item": "/item/armour/leather_belt.c"
            ])
        ]),
        "slime_medicine": ([
            "name": "藥劑材料",
            "desc": "收集 5 團史萊姆黏液交給藥劑師。",
            "level": 1,
            "goal": ([ "type": "item", "target": "史萊姆黏液", "count": 5 ]),
            "reward": ([
                "exp": 200,
                "gold": 80
            ])
        ]),
        "crab_armour": ([
            "name": "加固甲殼",
            "desc": "收集 2 塊螃蟹殼交給鐵匠。",
            "level": 2,
            "goal": ([ "type": "item", "target": "螃蟹殼", "count": 2 ]),
            "reward": ([
                "exp": 250,
                "gold": 100
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
        write("你的等級不足，無法承接此任務。\n");
        return 0;
    }

    if (me->query_quest(qid)) {
        write("你已經承接過這個任務了。\n");
        return 0;
    }

    me->set_quest(qid, ([
        "status": "active",
        "start_time": time(),
        "progress": ([ "count": 0 ])
    ]));
    
    write(HIG("你承接了任務：") + info["name"] + "\n");
    write("任務描述：" + info["desc"] + "\n");
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
            write("你身上的 " + target_name + " 數量不足 (" + sizeof(found) + "/" + req_count + ")。\n");
            return 0;
        }
        
        // 扣除物品
        for (int i = 0; i < req_count; i++) {
            destruct(found[i]);
        }
        write("你交出了 " + req_count + " 個 " + target_name + "。\n");
    }

    // 給予獎勵
    mapping reward = info["reward"];
    if (reward["exp"]) me->gain_exp(reward["exp"]);
    if (reward["gold"]) me->gain_gold(reward["gold"]);
    if (reward["badge"]) {
        object badge = clone_object(reward["badge"]);
        if (badge) {
            write("你獲得了 " + badge->query_short() + "！\n");
            move_object(badge, me);
        }
    }
    if (reward["item"]) {
        object ob = clone_object(reward["item"]);
        if (ob) {
            write("你獲得了獎勵物品：" + ob->query_short() + "！\n");
            if (!move_object(ob, me)) move_object(ob, environment(me));
        }
    }

    qdata["status"] = "completed";
    qdata["end_time"] = time();
    me->set_quest(qid, qdata);
    
    write(HIY("✨ 任務完成：") + info["name"] + "！\n");
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
            tell_object(me, HIG("【任務進度】") + info["name"] + "：" + current + " / " + total + "\n");

            if (current >= total) {
                tell_object(me, HIY("你已經達成了任務目標，快回去回報吧！\n"));
            }
        }
    }
}

mapping query_all_quests() {
    return quest_list;
}
