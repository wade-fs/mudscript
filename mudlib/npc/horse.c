// /npc/horse.c
#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("野馬");
    set_short("一匹健壯的野馬");
    set_long("這是一匹毛色亮麗的野馬，肌肉發達，眼神中透著一絲野性。\n");
    set_id(({"horse", "wild horse", "野馬", "馬"}));

    level    = 5;
    stat_str = 15;
    stat_dex = 20;
    stat_con = 15;
    recalc_stats();
    hp = max_hp;

    set_tamable(1); // 🚀 設定為可馴服
    set_respawn(120);
}
