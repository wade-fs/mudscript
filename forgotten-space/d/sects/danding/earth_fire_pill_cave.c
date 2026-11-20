// /d/sects/danding/earth_fire_pill_cave.c
// 丹鼎宗・地肺丹火窟 (Ch.96：丙字火區與通風暗隙窺見丙字柒號秘密煉丹)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("丹鼎宗・地肺丹火窟");
    set_long("深入地下三百丈黑玄武岩鑿就的燥熱岩窟，數十個地肺火眼噴吐青中帶紅的熾烈地火。\n"
             "外圍為丙字一至六號常規丹爐區；三丈高處鑿有狹窄的主排煙通風石夾層，其內側隱有\n"
             "僅容兩指寬的通風暗隙（須戴甘草口罩清理排煙硫磺結晶並窺測：peek flue），正對著\n"
             "掛有鶴壽大長老禁牌之「丙字柒號秘密內窟」，旁連一條幽暗「丙柒暗道」。\n"
             "向上沿螺旋石階返【百草谷】，向北循暗道出口可潛抵【廢丹崖】底層。\n");

    set_exits(([
        "up":    "/d/sects/danding/herb_garden.c",
        "north": "/d/sects/danding/discarded_pill_cliff.c",
    ]));

    set("is_outdoor", 0);
}

void init() {
    ::init();
    add_action("do_peek", "peek");
}

int do_peek(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "flue" && arg != "cave" && arg != "暗隙" && arg != "排煙道") {
        notify_fail("你想清理並探查哪裡？試試：peek flue\n");
        return 0;
    }
    message_vision("$N戴穩泡過甘草冷水的厚棉口罩爬上三丈通風夾層，敲通被硫磺堵住的主排煙道暗隙——\n"
                   "下室竟見鶴壽真人與太清雷紋銅印、天工測溫棒兩名無標記灰袍密使清點標有「萬山乙零四・\n"
                   "南十三」之三十塊含汞雜質血精晶錠，以烈礬耐火白泥封爐煉製十二顆逆道延命血丹！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "peek", "target": "flue" ]));
    }
    return 1;
}
