// /d/yunjin/stone_arch_quarantine.c
// 問道天台山道・石牌坊迎風口暨甲區隔離線（Ch.117, Ch.119：百五十步石牌坊、白鶴年營帳與十丈生石灰線）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津天台山道・石牌坊迎風口");
    set_long("距離問道天台下方正好一百五十步的山道轉角，石牌坊高聳在迎風口上。\n"
             "毒變爆發時下方數千名觀禮弟子順階疏散於此，下風口側翼紮起白鶴年與顧玄分診的\n"
             "隔離營帳——凡吸入青霧指尖發僵或咳血者悉數圈入「甲區」，外沿撒出一道十丈寬\n"
             "生石灰線，配合二十口大鐵鍋熬配「百草中和隔離霧」遏止孢子侵襲盆地（指令：spread lime）。\n"
             "向南下返【雲津萬山廣場】，往北仰登【問道天台・三宗質證高台】，向西通往【西街無毒回收廠】。\n");

    set_exits(([
        "southdown": "/d/yunjin/wanshan_square.c",
        "northup":   "/d/yunjin/hearing_hall.c",
        "west":      "/d/yunjin/west_street_recycling.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "迎風石牌坊表面結著一層冷冽冰霜，地上撒出的生石灰線乾燥澀手。" NOR);
    set_smell("default", HIG "二十口大鐵鍋熬配『百草中和隔離霧』散出的濃烈辛苦草藥白霧，混著生石灰粉塵味。" NOR);
    set_listen("default", CYN "迎風口北風呼嘯不絕，鐵鍋滾水咕嘟沸響與守衛喊停查驗的喝令聲清脆傳開。" NOR);
}

void init() {
    ::init();
    add_action("do_spread", "spread");
}

int do_spread(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "lime" && arg != "mist" && arg != "石灰" && arg != "隔離霧") {
        notify_fail("你想布設什麼防疫隔離措施？試試：spread lime\n");
        return 0;
    }
    message_vision("$N配合二十口大鐵鍋熬起濕潤「百草中和隔離霧」，沿石牌坊下十丈撒開生石灰防線，\n"
                   "將高台下壓之結晶孢子硬生生遏止在距雲津盆地半里處，並護住甲區三十餘輕重傷員。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "spread", "target": "lime" ]));
    }
    return 1;
}
