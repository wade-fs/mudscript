// clone/armour/wu_iron_belt.c
// 八方黑鐵腰牌束帶 - 八方武館外門弟子腰帶

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/armour.c";

void create() {
    ::create();
    set_name("八方黑鐵腰牌束帶", ({ "iron belt", "belt", "wu belt", "黑鐵腰牌", "束帶", "腰帶" }));
    set_short(HIY "八方黑鐵腰牌束帶" NOR);
    set_long("八方行省武館正式外門弟子的身份標識。\n"
             "以厚實的三層硬牛皮混雜生鐵絲編織而成，腰際正中鑲嵌一方沉重的玄黑重鐵牌，\n"
             "刻有咆哮猛虎與「八方鎮武」四個粗獷篆字。具備極強的護腰與抵禦鈍擊效果。\n");
    set_slot(SLOT_WAIST);
    set_defence(12);
    set_weight(2500);
    set_value(1500);
    set_armour_class("medium");
    set("is_class_badge", 1);
    set("class_req", "wu_initiate");
}
