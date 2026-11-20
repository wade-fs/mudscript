// /d/yunjin/three_sect_market.c
// 雲津仙集・三宗物資交易街 (Ch.90, Ch.98, Ch.101)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・三宗物資交易街");
    set_long("雲津仙集最熱鬧的長街，街道兩旁擺滿朱砂符紙鋪、青河苦參乾草行、烈礬耐火炭垛\n"
             "與精鐵鑄軸貨攤。城南幾家專做北境邊貨的商棧挑簾透出昏黃燈火，偶有身著各脈外門\n"
             "服色的弟子低聲核對初七、廿二批次的靈石票。\n"
             "向北回到【西街貨棧區】，向南步入車轍縱橫的【山道車馬行】。\n");

    set_exits(([
        "north": "/d/yunjin/western_warehouse_street.c",
        "south": "/d/yunjin/mountain_caravan_yard.c",
    ]));

    set("is_outdoor", 1);
}
