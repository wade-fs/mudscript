// /d/yunjin/north_road_gate.c
// 雲津仙集・北境商旅入口 (Ch.84)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・北境商旅入口");
    set_long("高大宏偉的青石牌樓下懸著「萬山交匯」四個蒼勁篆字。此處不設大乾府衙捕快，\n"
             "改由身穿鐵甲牌的商埠巡檢丁維持秩序，核驗南來行商的跨州路引與車馬折舊帳。\n"
             "南上通往【青石埡口】，往北步入熱鬧非凡的【雲津萬山廣場】。\n");

    set_exits(([
        "south": "/d/wastes/north_road/qing_pass.c",
        "north": "/d/yunjin/wanshan_square.c",
    ]));

    set("is_outdoor", 1);
}
