// /clone/item/two_way_beacon_token.c
// 《兩界微光家書囊》(Ch.166-167)：限重半斤、三息微光往返雲津之輕量信物與三十年前內堂底單

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    set_name("兩界微光家書囊");
    set_short(HIY "兩界微光家書囊" NOR);
    set_long("一隻焦黑卻無半分損傷的三寸細鐵筒連著極輕的耐震蠟封布囊。\n"
             "裡頭既有沈泥手書與【雲記棗木茶牌拓印】、燕山雙羽鷹記箭羽，\n"
             "更夾帶著蘇凝霜自雲津逆傳回來的兩頁薄紙：《三十年前金石內堂簽字底單暨萬仞山赤煉暗道線索》。\n");
    set_id(({ "two_way_beacon_token", "beacon_token", "兩界微光家書囊", "家書囊" }));
    set("value", 200);
    set("weight", 5);
}
