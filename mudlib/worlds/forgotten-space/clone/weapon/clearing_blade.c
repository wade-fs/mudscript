// clone/weapon/clearing_blade.c
// 大荒開山柴刀 - 金石商隊指名訂購、老鐵匠阿鐵親手鍛造的重型開路刀

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/weapon.c";

void create() {
    ::create();
    set_name("開山刀", ({ "clearing blade", "blade", "knife", "開山刀", "柴刀", "開山柴刀" }));
    set_short(WHT "大荒開山柴刀" NOR);
    set_long("一柄專為大荒商隊與採藥人打造的重型開山柴刀。刀背厚重平直，刃口經過多次精細淬火，\n"
             "劈砍荊棘灌木與防身禦獸皆極為稱手。(傷害力: 15)\n");
    set_weight(1500);
    set_value(80);
    set("weapon_type", "blade");
    set("damage", 15);
}
