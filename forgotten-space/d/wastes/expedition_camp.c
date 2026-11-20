// /d/wastes/expedition_camp.c
// 北荒裂谷深處三百里・冰脊高地勘探大營（Ch.104, Ch.110-111）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・冰脊高地勘探大營");
    set_long("深入裂谷三百餘里的高寒冰脊營地，黑山營重甲親兵於正營壓陣，赤煉先遣隊重車\n"
             "數日前卻假借「探測東側深層冰脈」悄悄轉往三十里外。子時過後避開巡夜燈籠可往\n"
             "西北摸上【裂谷觀測斷崖】，正西接隱蔽冰槽通往【冰谷窄口】，向南退回【永凍血原】。\n");

    set_exits(([
        "south":     "/d/wastes/frozen_blood_plain.c",
        "northwest": "/d/wastes/rift_watch.c",
        "west":      "/d/wastes/ice_valley_exit.c",
    ]));

    set("is_outdoor", 1);
}
