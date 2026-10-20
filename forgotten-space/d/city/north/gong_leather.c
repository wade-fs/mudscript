// d/city/north/gong_leather.c
// 熟皮鞣革坊 (溫娘子)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・熟皮鞣革坊");
    set_long("坊內整齊晾曬著數百張自盤木縣與鎮風要塞運抵的粗獷獸皮與生筋。\n"
             "空氣中散發著濃烈的硝水與動物油脂氣息。鞣皮名匠溫娘子手戴皮手套，\n"
             "正指點著幾名女工以特製明礬水刮洗熟化硬甲皮革。\n"
             "向西走出皮坊回到天工木作大棚。\n");

    set_exits(([
        "west": "/d/city/north/gong_wood.c",
    ]));

    set("is_outdoor", 0);
}
