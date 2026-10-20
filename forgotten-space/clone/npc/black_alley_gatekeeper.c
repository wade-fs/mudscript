// clone/npc/black_alley_gatekeeper.c
// 疤臉刀・守門疤臉漢 (black_alley_gatekeeper) - 鬼市暗巷入口

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("疤臉刀");
    set_short(RED "暗巷守門漢" NOR " 疤臉刀");
    set_long("一位左臉從眉骨到嘴角橫貫一道猙獰刀疤的精悍漢子，雙手抱胸斜靠在枯井石欄旁。\n"
             "他守著通往城下地下鬼市的隱秘入口，眼神陰冷地審視每一個靠近暗巷的人。\n");
    set_id(({ "black_alley_gatekeeper", "balian dao", "scarface", "alley gatekeeper", "疤臉刀", "守門疤臉漢", "疤臉漢" }));

    setup_archetype("I", 22);
    set("class", "mortal");
    set("faction", "jianghu");
    set("roles", ({ "gatekeeper", "info" }));
    set("schedule", "24h");

    add_response(({ "鬼市", "黑市", "暗號", "信物", "枯井" }),
        "疤臉刀咧嘴露出黃牙，指了指腳邊幽深的枯井：「想下城底鬼市？懂規矩的亮出當鋪牙印或黑市暗號，順著枯井鐵索往下爬 (down) 便是！到了底下法網管不著，死活自負！」");
}
