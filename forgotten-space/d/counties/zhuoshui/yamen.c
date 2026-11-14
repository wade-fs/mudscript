// /d/counties/zhuoshui/yamen.c
// 濁水縣 (Zhuoshui County) 房間 3/15：濁水縣署・河防緝私堂

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("濁水縣署・河防緝私堂");
    set_long("架設在巨石台基與鐵木樁上的濁水縣署，大堂外停泊著數艘配有鐵爪鉤的\n"
             "緝私快船。由於濁水河沼溶洞密佈、淘金幫勢大，縣署官差名為查緝無印私銅與違禁\n"
             "劇毒，實則常在浮橋抽成牟利。向東回【浮橋金砂水集】，往北登階則是【濁水鎮水祠】。\n");

    set_exits(([
        "east":  "/d/counties/zhuoshui/market.c",
        "north": "/d/counties/zhuoshui/miasma_shrine.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(5, 6, 0);
}
