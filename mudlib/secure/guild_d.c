// /secure/guild_d.c
// 公會守護進程 (Guild Daemon)

#include "/include/ansi.h"

mapping guilds;

void create() {
    guilds = ([
        "adventurer": ([
            "name": "冒險者公會",
            "desc": "歡迎所有志在四方的冒險者，這裡是你的第一個家。",
            "ranks": ({ "新手冒險者", "正式冒險者", "資深冒險者", "傳奇冒險者" }),
            "req": ([ "level": 1, "int": 10, "str": 10 ])
        ]),
        "mage": ([
            "name": "魔法師集會",
            "desc": "追求真理與奧法力量的殿堂。",
            "ranks": ({ "魔法學徒", "初級法師", "大法師", "賢者" }),
            "req": ([ "level": 5, "int": 20 ])
        ]),
        "fighter": ([
            "name": "戰士盟約",
            "desc": "力量與榮耀的歸宿，磨練鋼鐵般的意志。",
            "ranks": ({ "見習鬥士", "勇猛戰士", "戰場統帥", "戰神" }),
            "req": ([ "level": 5, "str": 20 ])
        ])
    ]);
}

mapping query_guild_info(string gid) { return guilds[gid]; }

int join_guild(object me, string gid) {
    mapping info = guilds[gid];
    if (!info) return 0;

    if (me->query_guild()) {
        write("你已經有所屬的組織了，必須先退出才能加入新公會。\n");
        return 0;
    }

    mapping req = info["req"];
    if (me->query_level() < req["level"]) {
        write("你的等級不足，無法加入 " + info["name"] + "。\n");
        return 0;
    }
    if (req["int"] && me->query_stat("int") < req["int"]) {
        write("你的智力不足，無法理解 " + info["name"] + " 的深奧教義。\n");
        return 0;
    }
    if (req["str"] && me->query_stat("str") < req["str"]) {
        write("你的力量不足，無法通過 " + info["name"] + " 的體能考驗。\n");
        return 0;
    }

    me->set_guild(gid);
    me->set_guild_rank(info["ranks"][0]);
    me->set_guild_exp(0);
    
    write(HIW("🎉 恭喜！你正式加入了 ") + info["name"] + HIW("！\n"));
    write("你現在的身分是：" + me->query_guild_rank() + "\n");
    me->save();
    return 1;
}

int promote_member(object me) {
    string gid = me->query_guild();
    if (!gid) return 0;
    
    mapping info = guilds[gid];
    string *ranks = info["ranks"];
    
    int current_idx = member_array(me->query_guild_rank(), ranks);
    if (current_idx == -1 || current_idx >= sizeof(ranks) - 1) {
        write("你已經達到了公會的最高職位。\n");
        return 0;
    }

    int req_exp = (current_idx + 1) * 1000;
    if (me->query_guild_exp() < req_exp) {
        write("你的公會貢獻度不足 (需要 " + req_exp + ")，無法晉升。\n");
        return 0;
    }

    string next_rank = ranks[current_idx + 1];
    me->set_guild_rank(next_rank);
    write(HIY("✨ 你的職位提升了！你現在是 ") + next_rank + HIY("。\n"));
    me->save();
    return 1;
}

mapping query_all_guilds() { return guilds; }
