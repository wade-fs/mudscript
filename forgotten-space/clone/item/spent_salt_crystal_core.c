// /clone/item/spent_salt_crystal_core.c
// 報廢鹽晶蓄能柱 (Ch.129, 132)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("報廢鹽晶蓄能柱", ({ "spent_salt_crystal_core", "salt core", "crystal core", "報廢鹽晶蓄能柱", "蓄能柱" }));
    set_short(WHT "封蠟銅箍・報廢鹽晶蓄能柱" NOR);
    set_long("一截從萬物主機城外環流出的半截灰白晶柱，兩端箍著一次成型咬死的偏心青銅鎖套，\n"
             "內膽結滿灰白鹽渣，看似報廢卻可藉精鋼卡尺尋得退刀縫拆解改製。\n");
    set_weight(300);
    set_value(10);
    set("material_type", "salt_crystal_core");
}
