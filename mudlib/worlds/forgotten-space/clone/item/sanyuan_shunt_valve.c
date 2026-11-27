// /clone/item/sanyuan_shunt_valve.c
// 三元過載分流總栓 (Ch.162 帶壓活榫替換強制收割閥)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("三元分流總栓", ({ "sanyuan_shunt_valve", "shunt valve", "分流總栓", "總栓" }));
    set_short(HIC "熟鐵母榫・三元過載分流總栓" NOR);
    set_long("林鐵生拆毀三座石堡暖爐並結合太古不融黑鐵公差熔鍛而成的雙向帶壓活榫總閥，\n"
             "能直接切斷萬物匯流井的強制收割迴路，將餘能引向民生供熱與信標儲備。\n");
    set_weight(500);
    set_value(0);
    set("is_craft_part", 1);
}
