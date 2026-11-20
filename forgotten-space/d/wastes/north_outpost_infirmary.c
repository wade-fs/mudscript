// /d/wastes/north_outpost_infirmary.c
// 北荒前哨醫所（Ch.102-103：白岩駐守、半寸雪線續脈膏對照實驗與採冰礦肺病簿）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒前哨醫所");
    set_long("拉起雙層羊毛氈門簾與紅十字白布條的北荒前哨臨時醫帳，火盆旁擺著粗陶藥碗、\n"
             "冰凍傷員病例簿與對照封存架（可施行半寸凍傷對照敷藥或試液：test poultice）。\n"
             "駐守老醫師白岩正緊盯著腳夫凍紫的腳腕與北邊採冰礦散修肺部紫黑硬斑紀錄。\n"
             "向西掀簾回到【雪原行腳營地】。\n");

    set_exits(([
        "west": "/d/wastes/snow_caravan_camp.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/bai_yan.c");
}

void init() {
    ::init();
    add_action("do_test", "test");
}

int do_test(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "poultice" && arg != "experiment" && arg != "對照" && arg != "藥膏") {
        notify_fail("你想施作哪項實測對照？試試：test poultice\n");
        return 0;
    }
    message_vision("$N在摔裂膝蓋車夫左腳腕塗上半寸「雪線續脈膏」與右腕原方凍傷膏作雙盲對照：\n"
                   "一夜過後左腕紅腫消退七成而右腕仍呈暗紫，白岩點頭將肺部染煞病例簿攤開共同歸檔。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "test", "target": "poultice" ]));
    }
    return 1;
}
