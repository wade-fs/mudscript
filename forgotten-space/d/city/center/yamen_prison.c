// d/city/center/yamen_prison.c
// 金石府死牢

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("府衙地牢・死牢");
    set_long("厚逾尺許的青黑玄武岩石壁阻絕了一切天光，唯有幾支松明火把跳動著慘淡火苗。\n"
             "空氣中瀰漫著濃烈的霉爛、鐵鏽與血腥臭味。沉重的生鐵鐐銬鎖在深處石壁上，\n"
             "獄頭鐵鐐張斜靠在刑椅上打盹，幾名獄卒正圍著木桶擲骰喝酒。\n"
             "西面穿過鑄鐵牢門可回到府衙正堂。\n");

    set_exits(([
        "west": "/d/city/center/yamen.c",
    ]));

    set("is_outdoor", 0);
}
