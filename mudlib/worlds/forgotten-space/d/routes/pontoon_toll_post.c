// /d/routes/pontoon_toll_post.c
// 東南沼澤浮橋道 (seg_city_zhuoshui_land, 350里) 節點 2：高腳木樁浮橋・水瘴哨卡 (對應卷二 Ch.64)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_zhuoshui_land");
    set_node_index(2);
    set_short("高腳木樁浮橋・水瘴哨卡");
    set_long("數百根浸泡過桐油的鐵木長樁深深打入赭黃色的濁水河沼之中，上方以鐵索\n"
             "串聯起搖晃不已的長木浮橋。橋頭吊腳哨樓上掛著防瘴艾草囊，幾名眼神精悍的水路\n"
             "哨卒正盯著往來挑夫的背簍。向西北退回【腐骨泥塘堤道】，往東南過橋即入【濁水縣・北鎮高腳木樁門】。\n");

    set_exits(([
        "northwest": "/d/routes/swamp_causeway.c",
        "southeast": "/d/counties/zhuoshui/north_gate.c",
    ]));

    set_coordinate(5, 8, 0);
}
