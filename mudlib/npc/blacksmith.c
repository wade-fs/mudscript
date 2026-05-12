#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鐵匠 索林");
    set_short(YEL("粗壯的矮人鐵匠") + " 索林");
    set_long("這是一位典型的矮人，紅色的鬍鬚紮成辮子，手臂肌肉隆起。\n他正滿頭大汗地敲打著一塊通紅的生鐵。\n");
    set_id(({"thorin", "blacksmith", "dwarf", "鐵匠"}));
    set_race("dwarf");
    set_level(25);
    set_stat(STAT_STR, 30);
    set_stat(STAT_CON, 30);
    recalc_stats();
    hp = max_hp;
}
