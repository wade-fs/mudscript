// /clone/npc/zhanzu_packmaster_tuo.c
// 拓跋重（戰祖魔殿・西南骨哨獵隊百夫長）(Ch.139-140, 146, 156, 159)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("拓跋重");
    set_short(RED "西南骨哨百夫長" NOR " 拓跋重");
    set_long("一名身披破損巨獸肩甲、左手缺了兩指的戰祖外營百夫長，腰間掛著一串骨哨與換防木帳。\n"
             "他表面對傷殘獵奴呵斥鞭打，實則暗中少劃耗損並掩護燕山，對監軍韓石剋扣獸髓早已積怨極深。\n");
    set_id(({ "zhanzu_packmaster_tuo", "packmaster tuo", "tuo", "拓跋重", "百夫長" }));

    setup_archetype("K", 87);
    set("class", "wu");
    set("path", "li");
    set("faction", "zhanzu_camp");
    set("roles", ({ "captain", "quest", "info" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/zhanzu/hunting_camp.c");

    add_response(({ "心核", "韓石", "假帳", "藥膏" }),
        "拓跋重背對哨崗低聲道：「韓石那狗官自己剋扣獸髓拿去買功，卻逼全營三日補齊九具三階心核！\n"
        "想讓我把部落拒徵單與換防帳交出來，先替營裡射倒前面那頭狂暴熔岩骨鬣獸（hunt beast），再備好緩衝傷藥。」");
}
