// clone/weapon/bamboo_arrow.c
// 重羽破甲竹箭 - 老獵戶趙老獵親手削製、淬了蛇毒的倒刺重箭

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("竹箭", ({ "bamboo arrow", "arrow", "zhujian", "竹箭", "破甲箭" }));
    set_short(GRN "重羽破甲竹箭" NOR);
    set_long("由老獵戶趙老獵親手削製的重羽竹箭。箭頭裹著硬鐵倒刺，鏃尖淬了黑蝮蛇毒與苦艾油，\n"
             "專破大荒猛獸的重皮厚骨。(傷害力: 8)\n");
    set_weight(50);
    set_value(15);
    set("weapon_type", "arrow");
    set("damage", 8);
}
