// /clone/npc/a_si.c
// 阿四・泥途商棧年輕夥計 (a_si) - 泥途商棧 (Ch.101)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("阿四");
    set_short(HIW "泥途商棧夥計" NOR " 阿四");
    set_long("十九歲的結實青年，半個月前剛由邱禾招入泥途商棧幫忙扛貨清點炭袋。\n"
             "他做事手腳勤快，前夜才親手把丹鼎宗送上來比對的兩小包藥渣泥漿碼進前院外庫。\n");
    set_id(({ "a_si", "a si", "asi", "阿四", "夥計" }));

    setup_archetype("D", 28);
    set("class", "mortal");
    set("faction", "mudway_store");
    set("roles", ({ "worker", "clerk" }));
    set("home_room", "/d/yunjin/mudway_store.c");

    add_response(({ "稽查", "藥包", "外庫", "公所" }),
        "阿四緊攥著圍裙角，帶著哭腔卻強撐鎮定：「東家、邱管事！前晚我只是照慣例清點雜貨箱……誰曉得\n"
        "裡面那兩包貼著青紙封條的深紫乾渣和標『丙類廢水樣本』的泥漿沒來得及補辦《特殊礦樣申報單》！\n"
        "太清執法事和萬寶閣的人直接扣了三十袋烈礬炭查封半邊外庫……幸虧東家亮出跨州特等信印保我問訊不出刑！」");
}
