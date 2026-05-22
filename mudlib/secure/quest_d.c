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
