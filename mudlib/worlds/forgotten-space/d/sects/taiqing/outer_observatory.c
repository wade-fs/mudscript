// /d/sects/taiqing/outer_observatory.c
// 太清玄天宮・天柱觀星台 (Ch.91：銅渾儀朔望雙向盲測與北境暴雪預警)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清玄天宮・天柱觀星台");
    set_long("天柱峰北緣突出的露風玄石高台，寒風如刀削掠過漢白玉欄杆。平台正中央架著一座\n"
             "須三人合抱的巨大黃銅渾儀與氣壓測風標柱，專門用來在冬至與朔望夜進行雙向盲測，\n"
             "比對實測星芒偏折與《太清正統星曆》間的四分半誤差（指令：observe sphere）。\n"
             "往西退回【周天星律院】，向北沿積雪石階步入後山【清修偏峰】。\n");

    set_exits(([
        "west":  "/d/sects/taiqing/star_law_hall.c",
        "north": "/d/sects/taiqing/quiet_peak.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "觀星台黃銅渾儀與白石欄杆凍得如冰塊般刺骨，表面卻不見半點積塵。" NOR);
    set_smell("default", HIC "高空寒風裡夾著淡淡金屬冷味與雲霧水氣，吸入肺葉清醒透徹。" NOR);
    set_listen("default", WHT "天柱峰頂雲濤翻湧，罡風掠過銅儀環圈發出極低沉的金屬共鳴。" NOR);
}

void init() {
    ::init();
    add_action("do_observe", "observe");
}

int do_observe(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "sphere" && arg != "sky" && arg != "渾儀" && arg != "星軌") {
        notify_fail("你想觀測什麼？試試：observe sphere\n");
        return 0;
    }
    message_vision("$N撥開儀軌浮霜校準黃銅渾儀，將當夜氣壓與角宿星芒偏折填入朔望對照簿。\n"
                   "實證讀數顯示：這道偏移極可能是固定人為參數而非天象偶變。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "observe", "target": "sphere" ]));
    }
    return 1;
}
