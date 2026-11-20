// /d/wastes/north_road/qing_pass.c
// 北境官道・青石埡口 (Ch.83-84：俯瞰雲津峽谷與三大名山輪廓)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北境官道・青石埡口");
    set_long("翻過這道覆滿積雪的青石高埡，兩側千仞絕壁瞬間替行人擋住了外荒暴風。\n"
             "極目遠眺，三座通天名山鼎足環抱著下方雲海峽谷盆地：北側雲頂天柱峰紫霄\n"
             "隱現、西北大黑山黑雲壓城、東側萬仞天工山吞吐地肺白煙。\n"
             "往南可返【斷崖石棚驛站】，順緩坡向北下行十餘里即達【雲津仙集・北境商旅入口】。\n");

    set_exits(([
        "south": "/d/wastes/north_road/post_station.c",
        "north": "/d/yunjin/north_road_gate.c",
    ]));

    set("is_outdoor", 1);
}
