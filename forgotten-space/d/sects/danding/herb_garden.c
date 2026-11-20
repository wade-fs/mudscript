// /d/sects/danding/herb_garden.c
// 丹鼎宗・百毒試藥谷暨百草谷 (Ch.89：變異寒髓草與雪線苔溫火冷萃)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("丹鼎宗・百毒試藥谷暨百草谷");
    set_long("層層梯田順著山谷鋪展，田旁一排十個青瓷藥盤裡躺著根莖發黑、葉片泛起\n"
             "紫紅斑紋的變異「寒髓草」。石台邊架著文火炭爐與小陶壺，細觀寒髓草根鬚末端，\n"
             "隱見泛著冰藍光澤的共生「雪線苔」（指令：extract moss）。驗藥席前立著白鶴年、\n"
             "葉青枝，以及在遠處負手觀考的大長老鶴壽。\n"
             "往西南退回【百草丹門】，向北步入【醫理院暨病案封存室】，西北山背石道通往【廢丹崖】，\n"
             "順螺旋石階向下可入地下三百丈【地肺丹火窟】。\n");

    set_exits(([
        "southwest": "/d/sects/danding/gate.c",
        "north":     "/d/sects/danding/medical_archive.c",
        "northwest": "/d/sects/danding/discarded_pill_cliff.c",
        "down":      "/d/sects/danding/earth_fire_pill_cave.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/bai_henian.c");
    spawn_npc("/clone/npc/ye_qingzhi.c");
    spawn_npc("/clone/npc/he_shou.c");
}

void init() {
    ::init();
    add_action("do_extract", "extract");
}

int do_extract(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "moss" && arg != "雪線苔" && arg != "herb") {
        notify_fail("你想冷萃什麼？試試：extract moss\n");
        return 0;
    }
    message_vision("$N未用烈陽猛火硬焚紫斑，而是保留寒髓草根鬚寄生的冰藍雪線苔一併入冷泉\n"
                   "文火冷萃，竟精準吸附中和了地煞濁氣，析出一碗清香純淨的辟煞散！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "extract", "target": "moss" ]));
    }
    return 1;
}
