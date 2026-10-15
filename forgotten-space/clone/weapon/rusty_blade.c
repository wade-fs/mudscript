// clone/weapon/rusty_blade.c
// 生鏽柴刀 - 獵戶之子的起手防身工具

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/weapon.c";

void create() {
    ::create();
    set_name("柴刀", ({ "rusty blade", "blade", "chaidao", "柴刀" }));
    set_short("生鏽柴刀");
    set_long("一把獵戶家中代代傳承的厚背柴刀，刃口生了暗紅鏽斑，但刀背厚重，\n"
             "砍柴防狼勉強湊合。\n");
    set_weight(1500);
    set_value(10);
    set("weapon_type", "blade");
    set("damage", 5);
}
