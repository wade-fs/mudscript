// /d/routes/swamp_causeway.c
// 東南沼澤浮橋道 (seg_city_zhuoshui_land, 350里) 節點 1：腐骨泥塘堤道 (對應卷二 Ch.64)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_zhuoshui_land");
    set_node_index(1);
    set_short("東南沼澤道・腐骨泥塘堤道");
    set_long("自東關向東南下行百里，地勢驟然低陷，化為一望無際的灰黑蘆葦泥沼。\n"
             "官道僅靠碎石與橫木墊起一條丈許寬的堤道，兩側泥塘不時翻起帶著腥臭沼氣的水泡，\n"
             "重型大車稍有不慎便會陷軸傾覆。向西北可返【金石府城・東關城門】，往東南踏上\n"
             "木樁浮橋通往【高腳木樁浮橋・水瘴哨卡】。\n");

    set_exits(([
        "northwest": "/d/city/gate/gate_east.c",
        "southeast": "/d/routes/pontoon_toll_post.c",
    ]));

    set_coordinate(4, 9, 0);
}
