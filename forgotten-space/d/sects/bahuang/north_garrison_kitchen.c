// /d/sects/bahuang/north_garrison_kitchen.c
// 八荒武山・北線軍寨炊事後勤區 (Ch.94：阿滿與《天興十九年失蹤者與未寄家書簿》)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑山營・北線軍寨炊事後勤區");
    set_long("靠近兵營後坡的石砌炊事大棚，三口厚鐵大鍋正咕嘟冒著熱氣，牆邊堆著冰凍肉乾\n"
             "與一袋袋粗糧。炊事婦人阿滿守在碗櫃旁核點各哨排缺糧實數，櫃底暗格子裡壓著一本\n"
             "記載天興十九年五年前走山隊與兩名接應斥候失蹤改判的舊簿與一沓寄不出去的家書。\n"
             "向西跨出伙房返回【黑山煞血營】。\n");

    set_exits(([
        "west": "/d/sects/bahuang/black_mountain_camp.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/a_man.c");
}
