// /clone/npc/bastion_young_hunter.c
// 石堡年輕獵手・石柱 (Ch.133)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("石柱");
    set_short(RED "石堡年輕獵手" NOR " 石柱");
    set_long("一名背著粗鐵骨矛、雙眼時刻警惕盯著西南焦土濃霧的石堡年輕獵手，\n"
             "熟悉高原玄武岩盲區與戰祖骨哨巡邏換班間隔。\n");
    set_id(({ "bastion_young_hunter", "young hunter", "shizhu", "石柱", "年輕獵手" }));

    setup_archetype("D", 68);
    set("class", "mortal");
    set("faction", "edge_bastion");
    set("roles", ({ "scout", "quest", "info" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/edge/scorch_border.c");

    add_response(({ "異獸", "心核", "骨號", "焦土" }),
        "石柱壓低聲音指著谷底：「這半個月戰祖監軍韓石不知發什麼瘋，把荒獸心核死期配額\n"
        "硬生生加徵了三成！逼得外營獵奴天天往深谷趕獸，連砂蜥和焦岩野犬都慌著往北逃。」");

    add_response(({ "鷹記", "刻痕", "燕山" }),
        "石柱指向下方赤黑岩縫：「前頭背風赤岩底面有道很新的左撇刻痕，不似此地獵手手筆，\n"
        "要看清就趕緊去拓下來（rub mark），巡邏骨旗快轉回來了！」");
}
