// /clone/npc/zhao_lie.c
// 趙烈・天工閣赤煉首徒 (zhao_lie) - 問道天台百工器試台 (Ch.113)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趙烈");
    set_short(HIR "天工赤煉首徒" NOR " 趙烈");
    set_long("二十四歲的天工閣內門天驕，眼白隱泛狂躁紅絲、呼吸粗重如拉風箱，一身赤紅勁服站上\n"
             "百工器試台，身前矗立著丈二高「煞火魔偶」——據稱能單臂舉起千五百斤生鐵連挨二十重錘。\n");
    set_id(({ "zhao_lie", "zhao lie", "zhaolie", "趙烈", "首徒" }));

    setup_archetype("E", 84);
    set("class", "gong");
    set("faction", "tiangong");
    set("roles", ({ "challenger", "artisan" }));
    set("home_room", "/d/yunjin/tournament_craft_arena.c");

    add_response(({ "煞火魔偶", "晶柱", "脆化", "比試" }),
        "趙烈在煞火魔偶被烏金長柄鍛錘三錘定軸停機後臉色白如死灰，喘息不止：\n"
        "「不可能……師尊給的『高熱穩壓晶柱』明明能讓玄鐵傳動軸硬抗三階威能……怎……怎麼會在高頻疊震下\n"
        "從軸承內壁自個兒脆碎成暗紫色？！」");
}
