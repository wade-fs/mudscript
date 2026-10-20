// clone/npc/outer_post_depot_laowang.c
// 老王・馬伕 (outer_post_depot_laowang) - 外城大車馬店

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老王");
    set_short(YEL "車馬店老馬伕" NOR " 老王");
    set_long("一位手拿竹柄馬刷、身上帶著濃重乾草與馬汗氣息的老馬伕。\n"
             "他精於相馬與調配精料，外城大車馬店數百匹遠行挽馬與駝獸皆由他照料。\n");
    set_id(({ "outer_post_depot_laowang", "laowang", "lao wang", "groom wang", "老王", "馬伕" }));

    setup_archetype("J", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "service", "info" }));
    set("schedule", "24h");

    add_response(({ "牲口", "草料", "挽馬", "車馬店" }),
        "老王拍著一匹健馬的脖頸道：「跑長途官道的挽馬最忌諱喝生冷濁水！在這外城車馬店餵足了鎮風燕麥和青河苜蓿，拉上千斤大車跑五百里都不掉膘！」");
}
