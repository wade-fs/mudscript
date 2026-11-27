// /d/routes/alum_canyon_post.c
// 紅石斷脈山道 (seg_city_liefan, 320里) 節點 2：礬石峽谷・苦泉茶棚 (對應卷二 Ch.63)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_liefan");
    set_node_index(2);
    set_short("礬石峽谷・苦泉茶棚");
    set_long("這條切穿天然明礬與赤銅礦脈的大峽谷兩側，岩壁閃爍著灰白與暗紅交錯\n"
             "的結晶光澤。谷口搭著一座簡易石砌茶棚，以甘草與綠豆熬水，供押運生銅與耐火泥\n"
             "的腳夫解暑祛毒。向西南退回【紅石斷脈山道・硫煙坡】，往東北出谷即抵【烈礬縣・西迎赤石關門】。\n");

    set_exits(([
        "southwest": "/d/routes/red_stone_pass.c",
        "northeast": "/d/counties/liefan/west_gate.c",
    ]));

    set_coordinate(5, 12, 0);
}
