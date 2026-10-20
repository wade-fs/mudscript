// d/city/east/wu_plaza.c
// 鎮武軍鎮・大校場 (抱石鎖、力道考核第1階段)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("鎮武軍鎮・大校場");
    set_long("這是一片佔地數十畝的平整黃土大校場，空氣中黃沙漫卷，殺伐震天。\n"
             "數百名精壯武卒正在操練都尉喝令下赤膊對拆、打熬筋骨。\n"
             "場邊整齊擺放著排排沙袋與花崗岩重石鎖 (stone)。\n"
             "凡欲投考八方武館者，需在此抱起百二十斤石鎖 (lift stone)，堅持十息以驗臂力。\n"
             "南面出轅門回到外門，北面大道通往八方武館正堂，\n"
             "東面立著高聳的木質圍欄，直通斷魂生死擂台。\n");

    set_exits(([
        "south": "/d/city/east/wu_gate.c",
        "north": "/d/city/east/wu_hall.c",
        "east":  "/d/city/east/wu_arena.c",
    ]));

    set("is_outdoor", 1);

    spawn_npc("/clone/npc/wu_plaza_colonel.c");
}

void init() {
    ::init();
    add_action("do_lift", "lift");
    add_action("do_lift", "抱石");
    add_action("do_lift", "舉石");
}

int do_lift(string arg) {
    object me = this_player();
    if (!arg || (arg != "stone" && arg != "石鎖" && arg != "重石")) {
        write("你想抱起什麼？(lift stone)\n");
        return 1;
    }

    if (me->query_stat("str") < 8) {
        write("你雙手合抱百二十斤花崗岩重石鎖，只覺沉重如山，臂力不足，險些砸傷雙足！(需要臂力 8)\n");
        return 1;
    }

    write(CYN "你沉腰扎馬，口中爆發一聲雷霆暴喝，粗壯雙臂緊扣花崗岩重石鎖！\n" NOR);
    write(HIY "渾身氣血如大潮奔湧，筋骨齊鳴，你將百二十斤巨石穩穩抱離地面整整十息！\n" NOR);
    write(HIG "【校場操練武卒齊聲暴喝彩聲：「好一條鐵骨漢子！」】\n" NOR);

    object q_engine = load_object(QUEST_ENGINE_D);
    if (q_engine) {
        q_engine->trigger_quest_event(me, "action", ({ "lift", "stone" }));
    }
    return 1;
}
