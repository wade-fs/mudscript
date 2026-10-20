// clone/npc/square_watchman.c
// 李遊徼・巡街遊徼 (square_watchman) - 中央青石廣場

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("李遊徼");
    set_short(WHT "中央廣場巡街遊徼" NOR " 李遊徼");
    set_long("一位手提銅鑼與捕人鐵叉的巡街治安官差，時刻盯著廣場上往來的流民與武夫。\n");
    set_id(({ "square_watchman", "li youjiao", "watchman", "李遊徼", "巡街遊徼", "遊徼" }));

    setup_archetype("B", 12);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "guard", "patrol", "info" }));
    set("schedule", "24h");

    add_response(({ "私鬥", "治安", "三日通牒", "度牒" }),
        "李遊徼敲了一記銅鑼喝道：「都城十字街口，嚴禁私鬥行兇！無牌流民滿三日未領青衿、短褐或藥囊者，休怪官差鎖拿驅逐！」");
}
