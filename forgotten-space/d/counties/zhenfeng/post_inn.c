// /d/counties/zhenfeng/post_inn.c
// 鎮風縣 (Zhenfeng County) 房間 6/14：鎮風縣驛・避風石棧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("鎮風縣驛・避風石棧");
    set_long("這座半地下式的石砌客棧將大半屋體埋入背風山坡，屋頂壓著百斤防風巨石。\n"
             "店內大鐵鍋終日熬著滾燙的羊骨辣湯與燒刀子烈酒，供剛從天風谷或碎冰堡歸來的\n"
             "獵戶與武卒驅寒暖身。向西北走出石門即回【皮甲硬弓邊集】。\n");

    set_exits(([
        "northwest": "/d/counties/zhenfeng/market.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(1, 16, 0);
}
