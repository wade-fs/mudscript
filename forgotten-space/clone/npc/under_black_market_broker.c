// clone/npc/under_black_market_broker.c
// 鬼見愁・黑市牙商 (under_black_market_broker) - 地下鬼市暗街

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鬼見愁");
    set_short(MAG "地下黑市牙商" NOR " 鬼見愁");
    set_long("一位戴著青銅半臉鬼面、披著寬大黑斗篷的神秘牙商，在磷火搖曳的地下鬼市收售違禁毒藥、無印生銅與黑貨。\n");
    set_id(({ "under_black_market_broker", "guijianchou", "gui jianchou", "black market broker", "鬼見愁", "黑市牙商", "牙商" }));

    setup_archetype("I", 25);
    set("class", "mortal");
    set("faction", "jianghu");
    set("roles", ({ "shop", "broker", "info" }));
    set("schedule", "24h");

    add_response(({ "黑貨", "銷贓", "血精", "無印生銅", "毒藥" }),
        "鬼見愁發出夜梟般的低笑：「地面上四關查得再嚴又如何？濁水縣的黑水蟾毒、烈礬縣未打官印的私銅、乃至北崖流出來的地煞血精晶錠，只要你有銀子或暗號，鬼市裡應有盡有！」");
}
