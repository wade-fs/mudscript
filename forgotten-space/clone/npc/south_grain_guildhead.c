// clone/npc/south_grain_guildhead.c
// 米萬倉・糧行會首 (south_grain_guildhead) - 官辦糧食市集

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("米萬倉");
    set_short(HIY "金石糧行會首" NOR " 米萬倉");
    set_long("一位手捧金算盤、身寬體胖的米行大掌櫃，每日盯著青河縣漕船到港數量掛出全城糧價牌。\n");
    set_id(({ "south_grain_guildhead", "mi wancang", "grain guildhead", "米萬倉", "糧行會首" }));

    setup_archetype("H", 22);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "shop", "broker", "info" }));
    set("schedule", "day");

    add_response(({ "糧價", "青河", "米市", "波動", "存糧" }),
        "米萬倉搓著胖手道：「全府七成精米與菜油都指望青河縣水路！若是青河連陰雨歉收，或是西水門水閘淤塞，咱這糧市掛牌價可是一天三跳啊！」");
}
