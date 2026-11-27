// /d/counties/zhuoshui/niluo_panning.c
// 濁水縣 (Zhuoshui County) 房間 10/15：泥螺灘・水磨篩金淺灘 (30天時間線 Stage 1 現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("泥螺灘・水磨篩金淺灘");
    set_long("湍急的濁水河支流在此沖積出一大片富含重晶石與粗金砂的沙洲。數十架\n"
             "水力搖床與竹編淘金盤日夜不停地篩洗河沙。自從黑石鋪北崖古礦炸塌後，偶有自\n"
             "上游暗河沖刷或走私客偷運而來的殘碎【丙字柒號】青銅構件與私煉晶錠在此現蹤。\n"
             "往北可返回【泥螺灘・淘金棚戶區】。\n");

    set_stage_desc(1, "大量來歷不明的【丙字柒號】殘碎銅件與私煉晶錠流入泥螺灘，淘金幫正坐地起價收取三成過道費。");

    set_exits(([
        "north": "/d/counties/zhuoshui/niluo_shoal.c",
    ]));

    set_coordinate(5, 6, 0);
}
