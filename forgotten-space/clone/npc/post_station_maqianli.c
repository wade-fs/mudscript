// clone/npc/post_station_maqianli.c
// 馬千里・驛丞 (post_station_maqianli) - 官辦遞鋪驛館

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("馬千里");
    set_short(YEL "府城驛丞" NOR " 馬千里");
    set_long("一位雙腿微曲、顯然常年騎馬奔波的精幹驛官，腰懸八百里加急銅牌。\n"
             "他掌管金石府城至六大外縣的官方公文快郵與快馬換乘。\n");
    set_id(({ "post_station_maqianli", "maqianli", "ma qianli", "postmaster ma", "馬千里", "驛丞" }));

    setup_archetype("A", 15);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "quest_giver", "service", "info" }));
    set("rules", ([ "express_hours_min": 36, "express_hours_max": 48 ]));
    set("schedule", "24h");

    add_response(({ "送信", "加急", "快馬", "六縣", "驛站" }),
        "馬千里拍了拍郵袋道：「本驛館的官府快馬日夜兼程，從府城發往青河、烈礬、盤木、鎮風、濁水、重石六縣，三十六至四十八個時辰內必達！若有緊急公文委託，亦可領取臨時郵差差遣。」");
}
