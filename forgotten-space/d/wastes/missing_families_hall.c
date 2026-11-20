// /d/wastes/missing_families_hall.c
// 失蹤者家屬互助所（Ch.102, Ch.111：距黑山關外三百步草頂木棚，韓素守駐處）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒關外・失蹤者家屬互助所");
    set_long("黑山長城北門外側三百步雪地邊幾間勉強遮風的草頂木棚，棚簷下掛滿用粗麻繩串起的\n"
             "木牌，上面刻著失蹤親人的姓名與天興年間出發年份。木桌邊燒著半盆冷炭火，記錄人韓素\n"
             "正一頁頁護著翻毛了頁角的《北荒失蹤者登記簿》（可交驗銅哨與遺址名錄：log missing）。\n"
             "向東踏雪返回【黑山長城北關雪道】。\n");

    set_exits(([
        "east": "/d/wastes/black_mountain_pass.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/han_su.c");
}

void init() {
    ::init();
    add_action("do_log", "log");
}

int do_log(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "missing" && arg != "records" && arg != "名冊" && arg != "登記") {
        notify_fail("你想登錄什麼？試試：log missing\n");
        return 0;
    }
    message_vision("$N將黑冰斷谷實測方位圖、隊員遺物編號與「北線斥候・乙十七」銅哨證據逐筆\n"
                   "登錄進《北荒失蹤者登記簿》，並依規將未見遺骸之燕山維持「失蹤待查」原狀。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "log", "target": "missing" ]));
    }
    return 1;
}
