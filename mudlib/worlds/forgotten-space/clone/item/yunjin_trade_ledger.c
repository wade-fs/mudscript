// /clone/item/yunjin_trade_ledger.c
// 泥途商棧雙聯朔望貨單（第三卷 Ch.84 / Ch.90 五子朔望暗網憑證）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("泥途朔望雙聯貨單", ({ "yunjin_trade_ledger", "trade ledger", "ledger", "泥途朔望雙聯貨單", "雙聯貨單" }));
    set_short(HIW "泥途商棧・朔望雙聯貨單" NOR);
    set_long("一疊裝訂嚴謹的粗麻雙聯交割單，上記烈礬耐火炭、青河抗寒草藥與雪橇鐵件的真實\n"
             "過磅數額與賠償履約紀錄；左下角極不起眼處劃有微細炭筆刻度，並附有三道單結麻繩暗記。\n");
    set_weight(80);
    set_value(0);
    set("is_credential", 1);
}
