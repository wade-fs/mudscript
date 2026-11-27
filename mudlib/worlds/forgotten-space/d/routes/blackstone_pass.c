// /d/routes/blackstone_pass.c
// 東線第一段 (seg_blackstone_panmu, 190里) 節點 1：黑石關・邊山稅卡
// 連接黑石鋪 (southwest) 與虎跳峽便道 (northeast)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_blackstone_panmu");
    set_node_index(1);
    set_short("黑石關・邊山稅卡");
    set_long("這裡是黑石鋪出山通往盤木縣的咽喉山隘。兩側黑青色山崖如刀削般夾峙，\n"
             "關口橫設著粗重的鐵木拒馬與驗貨木棚。自從胡百戶倒台後，北關新派來的暫代\n"
             "巡檢在此巧立「邊山修路捐」名目，對往來背負南山青石與山貨的鄉民腳夫層層\n"
             "盤剝。往西南下坡可退回【黑石鋪】青石街市，向東北穿過關門則進入險峻的\n"
             "【虎跳峽便道】（東線官道，全程經盤木縣赴金石府城共 450 里，可通重載大車）。\n");

    set_exits(([
        "southwest": "/d/village/square.c",
        "northeast": "/d/routes/tiger_leap_gorge.c",
    ]));

    set_coordinate(2, 2, 0);
}
