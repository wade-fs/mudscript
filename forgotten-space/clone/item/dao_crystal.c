// clone/item/dao_crystal.c
// 道化晶石殘片 - 古修士以身合道反遭天罰、肉身神魂徹底晶石化的太古遺骸碎塊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("晶石殘片", ({ "dao crystal", "crystal", "daohua", "晶石", "道化晶石", "晶石殘片" }));
    set_short(HIW "道化晶石殘片" NOR);
    set_long("一塊自西崖迎風殘壇老松盤根下玉化古修遺骸上剝落的奇異晶片。\n"
             "通體半透明如灰白冷玉，入手徹骨冰寒，內部封凍著一縷古修士被天道反噬後的死寂死氣。\n"
             "（可攜帶向盲眼老道枯木詢問探尋道化之謎）\n");
    set_weight(300);
    set_value(200);
    set("is_dao_crystal", 1);
}
