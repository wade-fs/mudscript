// /clone/npc/han_cang.c
// 韓蒼・太清玄冥首徒 (han_cang) - 問道天台八柱雷網台 (Ch.114)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("韓蒼");
    set_short(HIC "太清玄冥首徒" NOR " 韓蒼");
    set_long("二十六歲二階九十重（Lv.90）的太清內門首席天才，眉心始終貼著一枚青光濛濛的\n"
             "遮光青玉佩，眼神卻隱隱泛著毫無生氣的淡青無機質微光。\n"
             "他視實測歲差模型如草芥，出手即是十六道紫霄雷網與三十二道破空雷矛。\n");
    set_id(({ "han_cang", "han cang", "hancang", "韓蒼", "首徒" }));

    setup_archetype("G", 90);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "challenger", "mage" }));
    set("home_room", "/d/yunjin/tournament_combat_arena.c");

    set_exp_reward(2100);
    set_gold_reward(450);
    set_respawn(120);
    add_response(({ "紫霄神雷", "青玉佩", "結晶", "左眼" }),
        "韓蒼眉心遮光青玉佩被一指點碎後抱額跪倒在地，左眼瞳孔已凝成半顆淡青玉珠，嘶啞低喃：\n"
        "「別看……別看我的眼睛……執法師父說只要奪魁拿到足夠靈石換藥壓住……明年就會好的……」");
}
