// clone/npc/wu_zhaomeng.c
// 八方武館擂台教頭 鐵臂趙猛 (wu_arena_zhaomeng)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趙猛");
    set_short(HIY "擂台教頭" NOR "「鐵臂」趙猛");
    set_long("一位雙臂粗逾常人大腿、皮膚泛著青黑生鐵光澤的魁梧教頭。\n"
             "他長年以重玄黑鐵砂浸泡雙掌，鐵拳落下開碑裂石，鎮守生死擂台第二關。\n");
    set_id(({ "wu_arena_zhaomeng", "zhaomeng", "zhao meng", "arena instructor", "趙猛", "鐵臂" }));

    setup_archetype("C", 35);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "trainer", "quest_target" }));
    set("schedule", "24h");

    set_skill_to_teach("wu_cuigu", 100);
    set_skill_to_teach("wu_fuhu", 100);
    set_skill_to_teach("wu_panshi", 100);
    set_skill_to_teach("wu_pijia", 100);

    add_response(({ "比試", "考核", "擂台", "試煉", "鐵砂拳" }),
        "趙猛獰笑道：「小子，站穩樁步！受我三拳鐵砂崩拳，若不倒地便算你過關！」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "比試, fight, 考核, test")) {
        object q_engine = load_object(QUEST_ENGINE_D);
        if (q_engine) {
            return q_engine->trigger_quest_event(me, "talk", ({ "wu_arena_zhaomeng", "比試" }));
        }
    }
    return 0;
}
