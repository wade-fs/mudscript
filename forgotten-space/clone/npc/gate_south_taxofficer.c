// clone/npc/gate_south_taxofficer.c
// 宋算子・南關稅吏 (gate_south_taxofficer) - 金石南關城門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("宋算子");
    set_short(CYN "南關稅吏" NOR " 宋算子");
    set_long("一位鼻樑上架著銅框老花鏡、手提長桿地磅秤錘的精明稅吏。\n"
             "他專司金石南關重型木石大車過磅課稅與黑石鋪逃難鄉民的戶籍查驗。\n");
    set_id(({ "gate_south_taxofficer", "song suanzi", "taxofficer", "south taxofficer", "宋算子", "南關稅吏", "稅吏" }));

    setup_archetype("A", 12);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "gatekeeper", "tax", "info" }));
    set("rules", ([ "heavy_cart_tax_min": 50, "heavy_cart_tax_max": 100, "exempt": "blackstone_household" ]));
    set("schedule", "day");

    add_response(({ "稅則", "重車", "過磅", "黑石鋪", "免稅" }),
        "宋算子撥了撥算盤道：「南關重車按木石毛重徵五十至一百文過磅稅！若是黑石鋪逃難來的鄉民，憑舊戶籍路引免入城稅，但大木夾層裡敢私藏硝石私鹽者，一律充公下獄！」");
}
