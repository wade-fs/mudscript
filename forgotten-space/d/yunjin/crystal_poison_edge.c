// /d/yunjin/crystal_poison_edge.c
// 半山結晶毒域・東側副陣柱救護區暨維修井暗門（Ch.117：鶴壽母液逆反、陸觀瀾壓偏星煞、鋼釺搶箱）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("問道高台邊緣・結晶毒域救援區");
    set_long("被兩位掌門外圍封鎖大陣勉強壓制於百丈方圓內的半山毒域邊線！青石板上結滿\n"
             "泛著微弱青芒的冰晶苔蘚，東北角兩根星宿石柱已然炸毀，能見度不足三步。\n"
             "東側半傾的兩根副陣眼引流閥門邊尚留著陸觀瀾以半邊經絡搶偏星煞三尺的雪堆血痕，\n"
             "十丈碎石堆旁正壓著保護證物木箱的兩名執劍衛士（攜護喉噴霧鋼釺救援並壓柱：brace pillar）。\n"
             "側席牆角可見一扇被赤煉遺下披風暨煙霧彈殼撞開之暗門向下通往【天工閣・萬機地窟】，\n"
             "向南退返【問道天台質證高台】。\n");

    set_exits(([
        "south": "/d/yunjin/hearing_hall.c",
        "down":  "/d/sects/tiangong/machinery_depths.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIC "青石板表層結著針刺般的淡青冰晶苔蘚，觸碰副陣眼閥門能感到針扎似的星煞麻痺感。" NOR);
    set_smell("default", MAG "半傾陣眼滲出的刺鼻礦酸寒霧味與雪堆血跡淡淡的鐵鏽腥氣。" NOR);
    set_listen("default", WHT "被大陣壓制在百丈內的狂暴冰風呼嘯，偶爾傳來石塊崩落與鋼釺撞擊閥門的清響。" NOR);
}

void init() {
    ::init();
    add_action("do_brace", "brace");
}

int do_brace(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "pillar" && arg != "rescue" && arg != "陣柱" && arg != "救援") {
        notify_fail("你想協同處置哪一項救援？試試：brace pillar\n");
        return 0;
    }
    message_vision("$N按雪線苔濕布巾及護喉噴霧衝入能見度不足三步的毒霧區，接住重傷跌入雪堆的\n"
                   "陸觀瀾交予宋知微急救，同時二十息內用鋼釺撬開碎石將兩名護箱執劍衛士連同\n"
                   "四線物證木箱完整搶出——側角維修井暗門內唯餘一件焦黑赤紅披風與冒煙彈殼。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "brace", "target": "pillar" ]));
    }
    return 1;
}
