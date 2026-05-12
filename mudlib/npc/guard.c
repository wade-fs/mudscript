#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("守衛 葛羅格");
    set_short(RED("強壯的獸人守衛") + " 葛羅格");
    set_long("這個獸人皮膚粗糙，獠牙外露，手裡握著一柄沉重的巨斧。\n雖然看起來很兇，但他正忠實地執行著巡邏任務。\n");
    set_id(({"grog", "guard", "orc", "守衛"}));
    set_race("orc");
    set_level(15);
    set_stat(STAT_STR, 28);
    set_stat(STAT_CON, 22);
    recalc_stats();
    hp = max_hp;
}
