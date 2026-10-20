// clone/npc/wu_armory_quartermaster.c
// 武守備・司庫典軍 (wu_armory_quartermaster) - 披甲兵器庫

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("武守備");
    set_short(CYN "兵器庫司庫典軍" NOR " 武守備");
    set_long("一位手持軍械出入令牌的老典軍，身旁磨刀匠正飛快打磨著重弓與玄鐵板甲。\n");
    set_id(({ "wu_armory_quartermaster", "wu_armory_sharpener", "wu shoubei", "quartermaster", "sharpener", "武守備", "司庫典軍", "典軍" }));

    setup_archetype("B", 20);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "service", "shop", "info" }));
    set("schedule", "24h");

    add_response(({ "兵器", "板甲", "軍備", "保養", "重弓" }),
        "武守備撫摸著架上的百煉斬馬刀：「軍鎮甲冑兵刃皆由百工總會千錘地爐坊與鎮風縣匠作特供，凡持黑鐵腰牌之外門弟子，皆可在此申領制式兵甲或修繕刀弓！」");
}
