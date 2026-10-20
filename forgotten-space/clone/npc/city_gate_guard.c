// clone/npc/city_gate_guard.c
// 金石府城城防精銳衛士 (gate_north_guard)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("城防衛士");
    set_short(WHT "金石城防" NOR " 精銳衛士");
    set_long("一位頭戴鐵盔、手持沉重鐵戟的城防精銳衛士，身披厚重皮鐵甲，警惕巡查往來人流。\n");
    set_id(({ "gate_north_guard", "gate_guard", "guard", "soldier", "城防衛士", "精銳衛士", "衛士" }));

    setup_archetype("B", 20);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "guard" }));
    set("schedule", "24h");

    add_response(({ "盤查", "入城", "路引", "規矩" }),
        "衛士按戟喝道：「入關自覺出示路引或文牒！無牌無錢者，一律逐回驛道！」");
}
