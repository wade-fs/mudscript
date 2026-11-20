// /d/sects/bahuang/gate.c
// 八荒武山・萬鈞問心谷 (Ch.87：黑山試煉起點)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒武山・萬鈞問心谷");
    set_long("一道彷彿被巨斧劈開的墨色岩谷入口，百丈岩壁滿佈刀劈爪痕與陳年黑血漬。\n"
             "北荒地煞寒氣順著谷風倒灌而來，鐵鏽氣味刺鼻。高台上立著煞血營教頭岳停山與\n"
             "破軍重弓女校尉唐映，冷峻審視著準備闖過黑石峽的考核弟子。\n"
             "東南下山回返【雲津萬山廣場】，向北深入試煉地【黑石峽試煉道】。\n");

    set_exits(([
        "southeast": "/d/yunjin/wanshan_square.c",
        "north":     "/d/sects/bahuang/black_stone_gorge.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/yue_tingshan.c");
    spawn_npc("/clone/npc/tang_ying.c");
}
