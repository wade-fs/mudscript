// item/armour/magic_ring.c - 魔法戒指（戒指槽，魔抗）
#include "/include/config.h"
inherit "/std/armour.c";
void create() {
    ::create();
    set_short("一枚發光的魔法戒指");
    set_long("這枚戒指鑲嵌著淡藍色寶石，戴上後能感受到一股暖意包圍全身，對魔法傷害有一定抵抗力。\n");
    set_id(({"ring", "magic ring", "魔法戒指", "戒指"}));
    set_defence(1);
    set_magic_resist(15);
    set_slot(SLOT_RING);
    set_armour_class("accessory");
    set_magic_level(2);
    set_weight(50);
    set_value(350);
}
