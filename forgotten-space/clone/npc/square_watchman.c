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

    add_response(({ "傳聞", "消息", "風聲" }), (: call_other, "/daemon/rumor_d.c", "query_random_rumor", 0 :));
}

void init() {
    ::init();
    object me = this_player();
    if (!me || !userp(me)) return;

    object city_d = find_object(CITY_D);
    if (!city_d) city_d = load_object(CITY_D);
    if (city_d) {
        mapping res = city_d->check_user_residency(me);
        if (res && res["status"] == "unregistered_vagrant") {
            tell_object(me, HIR "李遊徼用鐵叉攔住你厲聲喝道：「站住！你入城已逾七十二小時，既無道途立籍，又無學塾、醫館或車馬大院保書！速速去辦理，否則定拿你問罪！」\n" NOR);
        }
    }
}
