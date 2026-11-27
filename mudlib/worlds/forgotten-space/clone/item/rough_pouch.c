// clone/item/rough_pouch.c
// 粗布口袋 - 流浪乞兒隨身攜帶的乾糧破袋

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("布袋", ({ "rough pouch", "pouch", "bag", "布袋" }));
    set_short("破舊粗布口袋");
    set_long("一個洗得發白、打著補丁的粗麻布袋，邊角塞著幾塊乾硬的窩頭碎渣。\n"
             "雖然襤褸，卻是浪跡天涯時唯一的隨身之物。\n");
    set_weight(150);
    set_value(5);
}
