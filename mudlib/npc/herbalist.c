#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("藥劑師 艾拉");
    set_short(GRN("優雅的精靈藥劑師") + " 艾拉");
    set_long("這位精靈女性有著一頭金色的長髮，舉手投足間充滿了優雅。\n她正在細心地調配一種散發著微光的藥劑。\n");
    set_id(({"aela", "herbalist", "elf", "藥劑師"}));
    set_race("elf");
    set_level(20);
    set_stat(STAT_INT, 25);
    set_stat(STAT_WIS, 25);
    recalc_stats();
    hp = max_hp;
}
