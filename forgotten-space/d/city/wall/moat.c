// d/city/wall/moat.c
// 金石府護城深河段

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石府城・護城深河");
    set_long("圍繞金石都城流淌的護城深河寬達十丈、深逾兩丈，水勢湍急洶湧。\n"
             "河岸兩側築有青石護坡，岸邊幾名披蓑戴笠的老翁正垂釣水草叢邊。\n"
             "夜間偶有黑市水鬼借木筏潛渡，此處處於絕靈法網盲區，多有江湖死鬥傳聞。\n"
             "向南沿土坡可繞行至城西近郊青禾田。\n");

    set_exits(([
        "east": "/d/city/outer/farmland_w.c",
    ]));

    set("is_outdoor", 1);
}
