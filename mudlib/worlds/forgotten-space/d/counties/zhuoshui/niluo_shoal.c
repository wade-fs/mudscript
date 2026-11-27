// /d/counties/zhuoshui/niluo_shoal.c
// 濁水縣 (Zhuoshui County) 房間 9/15：泥螺灘・淘金棚戶區 (轄下新手村 1)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("泥螺灘・淘金棚戶區");
    set_long("這座搭在赭黃色河灘爛泥上的蘆席棚戶聚落，是濁水縣轄下兩大基礎村落\n"
             "之一。數百名赤腳包頭的淘金客與採螺人終日在泥沼中討生活。向東走上高腳木橋\n"
             "可返【濁水縣・北鎮高腳木樁門】，往北順著山麓暗徑切入通往烈礬縣的【東麓峽谷私梟道】\n"
             "（210 里），往南則是喧囂嘈雜的【水磨篩金淺灘】。\n");

    set_exits(([
        "east":  "/d/counties/zhuoshui/north_gate.c",
        "north": "/d/routes/east_ravine_smuggler.c",
        "south": "/d/counties/zhuoshui/niluo_panning.c",
    ]));

    set_coordinate(5, 7, 0);
}
