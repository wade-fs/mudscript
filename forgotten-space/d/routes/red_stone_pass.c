// /d/routes/red_stone_pass.c
// 紅石斷脈山道 (seg_city_liefan, 320里) 節點 1：硫煙坡 (對應卷二 Ch.63)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_liefan");
    set_node_index(1);
    set_short("紅石斷脈山道・硫煙坡");
    set_long("自金石東關向東北折入群山，腳下的土石逐漸轉為燥熱的赤紅之色。路旁\n"
             "岩縫不時冒出絲絲縷縷帶著酸苦硫磺味的白煙，品物夏歲暑熱時節行路尤為酷烈。\n"
             "向西南可返回【金石府城・東關城門】，往東北順山脊深入則達【礬石峽谷・苦泉茶棚】。\n");

    set_exits(([
        "southwest": "/d/city/gate/gate_east.c",
        "northeast": "/d/routes/alum_canyon_post.c",
    ]));

    set_coordinate(4, 11, 0);
}
