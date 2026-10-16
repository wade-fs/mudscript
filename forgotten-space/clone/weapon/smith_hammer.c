// clone/weapon/smith_hammer.c
// 粗鐵小錘 - 打鐵學徒的起手工具與鈍擊兵器

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/weapon.c";

void create() {
    ::create();
    set_name("鐵錘", ({ "smith hammer", "hammer", "tiechui", "鐵錘" }));
    set_short("粗鐵小錘");
    set_long("一把鐵匠鋪學徒用來敲打鐵渣的小鍛錘，柄木被手汗磨得油亮，沉甸甸的。\n");
    set_weight(1000);
    set_value(20);
    set("weapon_type", "hammer");
    set("damage", 6);
}
