// /d/routes/east_ravine_smuggler.c
// 東麓峽谷私梟道 (seg_liefan_zhuoshui, 210里) 節點 1：硫瘴交界澗

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_liefan_zhuoshui");
    set_node_index(1);
    set_short("東麓峽谷私梟道・硫瘴交界澗");
    set_long("這條隱蔽於黑石山脈東麓斷崖間的崎嶇峽谷小徑，北接烈礬紅砂礦區，南通\n"
             "濁水泥螺灘。谷底溪水一邊是北方流下的酸苦明礬硫水，一邊是南方漫上的渾濁沼氣，\n"
             "兩股毒水交匯處白霧翻湧。紅砂坳礦主私煉的無印赤銅與私硝多經此道偷運往濁水黑市。\n"
             "向北攀上【烈礬縣・紅砂坳】，往南下坡即入【濁水縣・泥螺灘】。\n");

    set_exits(([
        "north": "/d/counties/liefan/hongsha_hollow.c",
        "south": "/d/counties/zhuoshui/niluo_shoal.c",
    ]));

    set_coordinate(6, 10, 0);
}
