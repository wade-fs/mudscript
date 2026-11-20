// /d/sects/tiangong/array_drafting_room.c
// 天工閣・陣圖工房 (Ch.95：聞九分段施工圖紙與巨靈神機延長線推演)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工閣・陣圖工房");
    set_long("四壁懸滿了大型羊皮陣盤與結構分段的寬敞石室，長木繪圖桌上整齊碼著炭筆、\n"
             "銅製分規與細麻刻度線。女陣匠聞九正皺眉盯著《巨靈神機護心甲肋》的傳統抄圖——\n"
             "只要拿起炭筆順著斜向支撐鋼樑畫出延長線（指令：trace blueprint），便能窺出此機\n"
             "真實的受力趨向與原初構造。\n"
             "向北走出工房返回【千鍛地火廊暨千機院】。\n");

    set_exits(([
        "north": "/d/sects/tiangong/thousand_mechanisms_hall.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/wenjiu.c");
}

void init() {
    ::init();
    add_action("do_trace", "trace");
}

int do_trace(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "blueprint" && arg != "lines" && arg != "圖紙" && arg != "延長線") {
        notify_fail("你想測繪什麼圖紙？試試：trace blueprint\n");
        return 0;
    }
    message_vision("$N拿起細頭炭筆於羊皮紙上沿斜樑繪出三道受力延長線——驚覺應力全往後下方\n"
                   "基座集中，證明十丈「巨靈神機」原非人形戰偶，而係超巨型船體或平台之推進錨機！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "trace", "target": "blueprint" ]));
    }
    return 1;
}
