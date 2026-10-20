// clone/npc/gate_west_helmsman.c
// 江平波・西水門守舵官 (gate_west_helmsman) - 西水門與西關

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("江平波");
    set_short(HIB "西水門守舵官" NOR " 江平波");
    set_long("一位熟悉水性與漕運章程的水關官吏，手持水牌站在西水門鐵柵閘口旁。\n"
             "他負責開啟水閘放行青河縣順流而下的藥船與糧船，核算優惠水路關稅。\n");
    set_id(({ "gate_west_helmsman", "jiang pingbo", "helmsman", "江平波", "西水門守舵官", "守舵官" }));

    setup_archetype("A", 20);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "gatekeeper", "tax", "info" }));
    set("rules", ([ "water_tax_ratio": 5, "herb_subsidy": 1 ]));
    set("schedule", "day");

    add_response(({ "水路", "青河", "藥材", "平糶", "輕稅" }),
        "江平波指著水閘道：「青河水路乃全府糧藥命脈！凡經西水門入城之正當漕貨，僅徵二十抽一（5%）輕稅；青河靈草與定神藥材進口更享府衙平糶補貼！」");
}
