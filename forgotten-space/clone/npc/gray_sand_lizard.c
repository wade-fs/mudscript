// /clone/npc/gray_sand_lizard.c
// 灰甲砂蜥 (Ch.128 啃毀灰燼石堡蓄水槽的洞天食腐荒獸)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("灰甲砂蜥");
    set_short(YEL "啃岩荒獸" NOR " 灰甲砂蜥");
    set_long("一頭體長近丈、背脊覆滿厚重灰褐鈣質鱗甲的荒原砂蜥，口角不斷滴落微帶酸臭的黃涎。\n"
             "原本只敢伏在鹽礫深溝食腐，近來受西南荒獸騷動擠壓才冒險摸近石堡。\n");
    set_id(({ "gray_sand_lizard", "sand lizard", "lizard", "灰甲砂蜥", "砂蜥" }));

    setup_archetype("K", 65);
    set("class", "beast");
    set("path", "li");
    set("faction", "realm_wild");
    set("no_auto_attack", 1);
    set("home_room", "/d/realm/edge/basalt_ridge.c");
}
