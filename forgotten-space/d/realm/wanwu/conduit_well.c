// /d/realm/wanwu/conduit_well.c
// 萬物主機城・地下一級能量匯流井 (Ch.162 林鐵生帶壓活榫換栓處)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("萬物主機城・一級能量匯流井");
    set_long("熱浪翻湧的地下巨型管廊井心，七條粗如水缸的導流母管在此交匯於強制收割總閥。\n"
             "此處無法熄爐硬停，否則整座主機城取暖與淨水皆將爆管；須在滾燙金屬蒸氣下\n"
             "以烏金錘與黑鐵母牙完成帶壓活榫操作，拔出收割閥並嵌入三元分流總栓（swap valve）。\n"
             "向北沿維護暗管返【外環廢料回收場】。\n");

    set_exits(([
        "north" : "/d/realm/wanwu/scrap_ring.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", HIR "井欄鐵扶手燙得驚人，管壁隨高壓流體穿行而不斷劇烈震顫。" NOR);
    set_smell("default", RED "高溫蒸汽、焦枯麻布濕氣與合金襯套燒熔前的刺鼻金屬味。" NOR);
    set_listen("default", HIY "粗大母管內部流體奔湧如雷，夾雜著安全閥被死死卡住的尖銳嘶鳴。" NOR);
}

void init() {
    ::init();
    add_action("do_swap_valve", "swap");
}

int do_swap_valve(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "valve" && arg != "總栓" && arg != "總閥") {
        notify_fail("你要替換什麼？試試：swap valve\n");
        return 0;
    }

    tell_object(me, HIR "你裹著浸濕粗麻布頂住熱爆衝入井心，舉錘一擊震退卡死多年的強制收割總閥——\n" NOR);
    tell_object(me, HIC
        "【帶壓活榫換栓成功（EV418）】\n"
        "你反手將【三元過載分流總栓】沿黑鐵母牙活榫槽滑入咬死！轟鳴頓轉平穩嗡鳴，\n"
        "強制收割迴路徹底改道為民生供熱與信標儲能，代價是右護臂熔毀且太古焊料近乎耗盡！\n" NOR);
    say(me->query_name() + " 在不斷流高熱中完成帶壓活榫操作，成功拔除強制收割總閥換上三元分流總栓！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "swap", "target": "valve" ]));
    }
    return 1;
}
