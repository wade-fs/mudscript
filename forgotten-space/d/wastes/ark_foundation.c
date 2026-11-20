// /d/wastes/ark_foundation.c
// 太古破界方舟・北荒主引擎冷卻管線艙段（Ch.106：十里巨鯨遺構、血精母脈池實質化驗）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("地底數百丈・方舟主引擎冷卻艙段");
    set_long("順著合金斜坡下行兩里後豁然開朗的驚世巨構——百丈萬年幽藍堅冰之下，密佈著\n"
             "直徑逾五丈的漆黑幾何合金鋼架，整座方圓數十里的傾覆巨鯨艙體側壁佈滿熔毀痕跡。\n"
             "三丈高的圓柱形主導管台裸露出破損閥門與斷裂傳動軸，與不融黑鐵齒輪及天工閣\n"
             "【巨靈神機】分毫同源；下方則是散發腥甜硫磺熱氣的暗血紫色半凝固生物質礦池\n"
             "（以小銀勺採樣滴入雪線苔液檢驗：test coolant）。往西返【荒古戰神巨石遺塚】，\n"
             "向北登三丈高【八角形核心圓台】，往東赴三里外【方舟東側冷卻豁口】。\n");

    set_exits(([
        "west":  "/d/wastes/war_god_tomb.c",
        "north": "/d/wastes/ark_core_chamber.c",
        "east":  "/d/wastes/ark_cooling_breach.c",
    ]));

    set("is_outdoor", 0);
}

void init() {
    ::init();
    add_action("do_test", "test");
}

int do_test(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "coolant" && arg != "sample" && arg != "matrix" && arg != "母脈" && arg != "冷卻液") {
        notify_fail("你想檢測什麼？試試：test coolant\n");
        return 0;
    }
    message_vision("$N戴上雙層鹿皮手套與浸藥口罩，以小銀勺刮取礦池凝膠滴入一滴雪線苔提取液，\n"
                   "僅三息即析出高能生物質與冷卻水銀結晶——又以阿鐵精鋼卡尺比對主導管斷軸：\n"
                   "所謂「血精母脈」，實係方舟冷卻安全閥破裂廢液，抽空它將引爆北境半壁地脈陸沉！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "test", "target": "coolant" ]));
    }
    return 1;
}
