// clone/weapon/armor_piercing_arrow.c
// 精鋼三棱破甲錐 - 阿鐵鋪子百煉精鋼打造的重型獵狼破甲箭 (小說第7、8、10章)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/weapon.c";

void create() {
    ::create();
    set_name("破甲錐", ({ "armor piercing arrow", "arrow", "破甲錐", "箭", "三棱箭" }));
    set_short(HIC "精鋼三棱破甲錐" NOR);
    set_long("一枚長達三尺、箭鏃以深冷精鋼鍛打成三棱倒刺狀的重型戰箭。\n"
             "血槽深邃，鋒芒森寒，專為破穿大荒猛獸厚甲與軍用重鎧而生，百步之內能生生洞穿生鐵！\n"
             "(傷害力: 30，附帶無視部分護甲效果)\n");
    set_weight(200);
    set_value(60);
    set("weapon_type", "arrow");
    set("damage", 30);
    set("armor_penetration", 15);
}
