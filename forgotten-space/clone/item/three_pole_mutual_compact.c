// /clone/item/three_pole_mutual_compact.c
// 《三極維護工役互助密約》 (Ch.146 三極底層聯合盟約)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("三極互助密約", ({ "three_pole_mutual_compact", "mutual compact", "互助密約", "密約" }));
    set_short(HIW "三方指印・三極維護工役互助密約" NOR);
    set_long("一份寫於厚韌桑皮紙上的地下互助盟約，蓋有外環二十四站維修工、十二鹽晶寮採工\n"
             "與戰祖西南獵營代表之指印，約定校準前七日集體依章停工斷供、彼此兜底糧藥。\n");
    set_weight(40);
    set_value(0);
    set("is_credential", 1);
}
