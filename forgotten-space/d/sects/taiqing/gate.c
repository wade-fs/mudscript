// /d/sects/taiqing/gate.c
// 太清玄天宮・登天雲梯山門 (Ch.86：千丈登天雲梯與太清問心陣實測)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清玄天宮・登天雲梯山門");
    set_long("穿過霧凇松林，一道寬約丈餘的漢白玉石階直插雲海深處，共三百六十五階主陣眼。\n"
             "雲梯上方懸著一面朦朧青銅問心鏡，九天星煞威壓無聲垂落；兩側每隔三十丈立有一根\n"
             "青銅測星柱。懂得實證心算之人，可於石階側緣測算陣眼星力滯後公差（指令：measure ladder）。\n"
             "向南下山可返【雲津萬山廣場】，向北登頂進入【太清外門雲舍】。\n");

    set_exits(([
        "south": "/d/yunjin/wanshan_square.c",
        "north": "/d/sects/taiqing/outer_court.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/lu_guanlan.c");
}

void init() {
    ::init();
    add_action("do_measure", "measure");
}

int do_measure(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "ladder" && arg != "雲梯" && arg != "陣眼") {
        notify_fail("你想測算什麼？試試：measure ladder\n");
        return 0;
    }
    message_vision("$N沒有像旁人般叩首求饒，反而屏息閉目心算三十六息週期，精準量出東北側\n"
                   "測星柱傳導星力固定滯後千分之三息的結構公差，並沿縫隙穩步踏上雲頂。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "measure", "target": "ladder" ]));
    }
    return 1;
}
