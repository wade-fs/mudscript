// clone/item/road_pass.c
// 金石城官辦保書路引 - 黑石關流民商隊入城憑證

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("保書路引", ({ "road pass", "pass", "baoshu", "路引", "保書", "保書路引" }));
    set_short(YEL "金石城官辦保書路引" NOR);
    set_long("一張以堅韌厚黃麻紙印製的官方通關公牒，上面蓋有金石城宣撫司與城防軍的鮮紅硃砂大印。\n"
             "自黑石關設卡封道以來，此類通行保書在黑市上已被炒至整整八十兩雪花銀，尋常流民百姓若無路引，\n"
             "靠近城關半步即被城防重弩射殺。\n");
    set_weight(50);
    set_value(8000); // 80両
    set("is_road_pass", 1);
}
