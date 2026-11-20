// /d/wastes/frozen_blood_plain.c
// 永凍血原・北荒大裂谷第二層（Ch.103：雙頭霜甲地龍伏擊與沸血雄黃煙）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・永凍血原");
    set_long("鐵銹色暗紫暮光籠罩下的第二層裂谷，兩側高逾千仞的墨色冰崖夾著寬約數里的\n"
             "平坦冰原，地底萬年凍冰厚逾兩尺且表面泛著微弱紫褐血霜。左側兩輛綁滿石壓箱的重車\n"
             "與一塊萬斤凍岩正是牽制「雙頭霜甲地龍」的死錨陣位（可投擲沸血雄黃煙：throw smoke）。\n"
             "向南退返【雪原行腳營地】，向北推進至裂谷深處三百里【冰脊高地勘探大營】。\n");

    set_exits(([
        "south": "/d/wastes/snow_caravan_camp.c",
        "north": "/d/wastes/expedition_camp.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/shuangtou_dilong.c");
}

void init() {
    ::init();
    add_action("do_throw", "throw");
}

int do_throw(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "smoke" && arg != "realgar" && arg != "雄黃煙" && arg != "煙彈") {
        notify_fail("你想投擲什麼戰術藥彈？試試：throw smoke\n");
        return 0;
    }
    message_vision("$N躲於兩輛雪橇夾角閃身拋出三枚特製皮革「沸血雄黃煙」，爆開三丈濃煙封住地龍\n"
                   "左首白霧兩息；側風卻瞬間將藥煙倒灌嗆咳自己人，將極寒低壓禁忌狠狠記進藥錄。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "throw", "target": "smoke" ]));
    }
    return 1;
}
