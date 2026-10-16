// clone/weapon/boning_knife.c
// 厚背剔骨砍刀 - 張屠戶的隨身利刃，黑石鋪常見的粗鐵劈骨刀

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/weapon.c";

void create() {
    ::create();
    set_name("砍刀", ({ "boning knife", "knife", "blade", "cleaver", "砍刀", "剔骨刀", "剔骨砍刀" }));
    set_short(WHT "厚背剔骨砍刀" NOR);
    set_long("一柄長約尺半、刀背厚逾半指的沉重砍刀。刀身以黑石鋪粗鐵鍛打而成，\n"
             "刀刃鋒利，常年用於劈骨剁肉與荒林防身，刀身上留有幾道在溪灘磨石上反覆摩擦的粗獷凹痕。\n");
    set_weight(1200);
    set_value(60);
    set("weapon_type", "blade");
    set("damage", 12);
}
