// clone/npc/gate_west_inspector.c
// 盧緝私・水關緝私吏 (gate_west_inspector) - 西水門與西關

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("盧緝私");
    set_short(CYN "水關緝私吏" NOR " 盧緝私");
    set_long("一位手持長柄探針鐵鉤、眼神銳利的緝私官吏，專門登船開箱查驗水路暗格。\n");
    set_id(({ "gate_west_inspector", "lu jisi", "water inspector", "盧緝私", "水關緝私吏", "緝私吏" }));

    setup_archetype("A", 15);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "guard", "info" }));
    set("rules", ([ "contraband": "corrupted_mud_and_poison" ]));
    set("schedule", "day");

    add_response(({ "緝私", "違禁", "劇毒", "腐濁泥", "開箱" }),
        "盧緝私晃了晃手中探針：「西水門稅率雖輕，但誰敢在藥船底艙私藏濁水劇毒或落龍口腐濁泥，休怪本吏這根鐵探針無情！」");
}
