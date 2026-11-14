// /d/counties/qinghe/luhuadu_dock.c
// 青河縣 (Qinghe County) 房間 11/14：蘆花渡・漁農草集 (轄下新手村 1)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("蘆花渡・漁農草集");
    set_long("這座掩映在漫天白蘆葦叢中的水鄉村落，是青河縣轄下兩大基礎聚落之一。\n"
             "村人世代以撐船擺渡、水田種稻與採集水生澤瀉為生。木棧橋邊拴著一排排烏篷小船\n"
             "與捕魚竹簍。向東北沿河堤可往【青河縣・漕運碼頭】，往南涉過蘆葦淺水則通往\n"
             "河道拐彎處的【蘆花渡古河床淺灘】。\n");

    set_exits(([
        "northeast": "/d/counties/qinghe/ferry_dock.c",
        "south":     "/d/counties/qinghe/luhuadu_shoal.c",
    ]));

    set_coordinate(-8, 8, 0);
}
