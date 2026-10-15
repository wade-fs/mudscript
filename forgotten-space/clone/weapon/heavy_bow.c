// clone/weapon/heavy_bow.c
// 鐵胎柘木重獸弓 - 老獵戶趙老獵懸掛在哨亭樑上的百斤強弓

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/weapon.c";

void create() {
    ::create();
    set_name("重獸弓", ({ "heavy bow", "bow", "zhemu bow", "獸弓", "重弓" }));
    set_short(YEL "鐵胎柘木重獸弓" NOR);
    set_long("一柄以百年硬柘木與生鐵薄胎複合壓製的百斤重獸弓。弓梢粗壯，弓弦由荒原巨狼大筋絞合塗油製成，\n"
             "非雙臂具備千鈞神力者難以拉滿。(傷害力: 18)\n");
    set_weight(3500);
    set_value(120);
    set("weapon_type", "bow");
    set("damage", 18);
}
