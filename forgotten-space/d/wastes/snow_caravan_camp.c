// /d/wastes/snow_caravan_camp.c
// 雪原行腳營地（Ch.102：過此營地後人煙徹底消失之最後整備點）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・雪原行腳營地");
    set_long("北荒南沿最後一處尚有人煙火塘的紮營谷地，此後再往北便徹底踏入荒無人煙的\n"
             "外荒大裂谷。二十四輛泥途輜重雪橇在此檢查防滑鐵齒與防寒乾糧，十丈外可見赤煉\n"
             "親信提燈巡哨（檢視重車轍深與防滑鐵齒：inspect sleighs）。東側帳篷掛著紅十字布條\n"
             "通往【北荒前哨醫所】，西側背風坡則是塞外牧民的【凍土牧戶避風棚】，向北進發【永凍血原】，往南返回【北荒南沿入口】。\n");

    set_exits(([
        "south": "/d/wastes/south_approach.c",
        "east":  "/d/wastes/north_outpost_infirmary.c",
        "west":  "/d/wastes/frost_hunter_camp.c",
        "north": "/d/wastes/frozen_blood_plain.c",
    ]));

    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_inspect", "inspect");
}

int do_inspect(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "sleighs" && arg != "caravan" && arg != "雪橇" && arg != "重車") {
        notify_fail("你想檢視什麼？試試：inspect sleighs\n");
        return 0;
    }
    message_vision("$N藉檢修輜重雪橇防滑鐵齒之機以星盤測算隊尾三輛雙層黑布重車磁偏角，\n"
                   "確定車內暗藏拆解後的重型鑽山機部件，隊伍正被暗中帶向北偏東核心裂谷。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "inspect", "target": "sleighs" ]));
    }
    return 1;
}
