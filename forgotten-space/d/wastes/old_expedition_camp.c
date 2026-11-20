// /d/wastes/old_expedition_camp.c
// 黑冰斷谷・舊勘探隊營地廢墟（Ch.104：帆布塌帳、岩石凹槽、走山隊名冊殘頁與燕山羊皮血書）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑冰斷谷・舊勘探隊營地廢墟");
    set_long("淺冰層上十幾個腐朽塌陷的帆布帳篷殘骸，距斥候遺骨十步外有個半塌岩石凹槽：\n"
             "槽裡壓著砸扁的鐵皮水壺、刻鷹翅刮痕的斷裂狼牙重箭、藏於生牛皮箭筒夾層的殘缺名冊\n"
             "以及半片脆化舊羊皮血書（不可徒手硬撕，須以防風油燈微溫並用細竹夾取樣：search alcove）。\n"
             "向東返回【黑冰斷谷】主遺址，往北摸索半里深處高聳冰壁下的【荒古戰神巨石遺塚】。\n");

    set_exits(([
        "east":  "/d/wastes/black_ice_valley.c",
        "north": "/d/wastes/war_god_tomb.c",
    ]));

    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_search", "search");
}

int do_search(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "alcove" && arg != "camp" && arg != "凹槽" && arg != "血書") {
        notify_fail("你想仔細搜檢哪裡？試試：search alcove\n");
        return 0;
    }
    message_vision("$N借防風油燈微溫與極細竹夾小心剝離半片羊皮血書，與生牛皮箭筒內的殘缺名冊\n"
                   "一併畫圖登記後納入雙層封存木匣——血書末角留有『山』字與『雷……非……』殘筆。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "search", "target": "alcove" ]));
    }
    return 1;
}
