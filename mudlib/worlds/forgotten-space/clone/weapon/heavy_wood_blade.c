// clone/weapon/heavy_wood_blade.c
// 加厚開山柴刀 - 阿鐵鋪子加厚淬火打製的重型劈砍戰刃 (小說第7、8、10章)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/weapon.c";

void create() {
    ::create();
    set_name("加厚開山刀", ({ "heavy blade", "blade", "刀", "加厚柴刀", "開山刀" }));
    set_short(HIW "加厚開山柴刀" NOR);
    set_long("一柄由老鐵匠阿鐵精心鍛打、通體以生鐵母料加厚淬火的重型戰刃。\n"
             "刀背厚達半寸，刃口冷冽深邃，重達兩千克。揮動時帶著開山裂石的沉雄破風聲，\n"
             "非天生神力者極難長久駕馭。(需要力量: 12，傷害力: 26)\n");
    set_weight(2000);
    set_value(260);
    set("weapon_type", "blade");
    set("damage", 26);
    set("require_str", 12);
}
