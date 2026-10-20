// clone/npc/gong_stone_hanlaodiao.c
// 韓老雕・老石匠 (gong_stone_hanlaodiao) - 精研石雕坊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("韓老雕");
    set_short(WHT "精研石雕坊匠首" NOR " 韓老雕");
    set_long("一位滿頭白髮沾滿白石粉、手握短柄鶴嘴鑿的老石匠。\n"
             "他一輩子與重石縣運來的重玄石、青石打交道，城牆垛口、護城水閘乃至大戶人家的地宮石槨皆出其手。\n");
    set_id(({ "gong_stone_hanlaodiao", "hanlaodiao", "han laodiao", "stonemason han", "韓老雕", "老石匠" }));

    setup_archetype("E", 30);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "trainer", "info" }));
    set("schedule", "day");

    set_skill_to_teach("gong_analysis", 100);
    set_skill_to_teach("gong_yingli", 100);

    add_response(({ "石雕", "重玄石", "重石縣", "條石", "紋理" }),
        "韓老雕吹了吹石槽裡的粉塵：「重石縣來的重玄石看似堅不可摧，但順著石紋節理下鑿，三錘就能破開千斤巨岩！不懂石性，累斷雙臂也是枉然。」");
}
