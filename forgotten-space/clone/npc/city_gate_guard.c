// clone/npc/city_gate_guard.c
// 金石府城城防衛士

#include "/include/ansi.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("城防衛士");
    set_short(WHT "金石城防" NOR " 披甲衛士");
    set_long("一位頭戴鐵盔、手持沉重鐵戟的城防精銳衛士，身披厚重皮鐵甲，警惕巡查往來人流。\n");
    set_id(({ "gate_guard", "guard", "soldier", "城防衛士", "衛士", "武卒" }));

    set_level(20);
    set_stat("str", 26);
    set_stat("con", 28);
    recalc_stats();

    add_response(({ "盤查", "入城", "路引", "規矩" }),
        "衛士按戟喝道：「入關自覺出示路引或文牒！無牌無錢者，一律逐回驛道！」");
}
