// /d/routes/west_ridge_trail.c
// 西嶺支脈山道 (seg_qinghe_zhongshi, 160里) 節點 1：霧嶺分水隘

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_qinghe_zhongshi");
    set_node_index(1);
    set_short("西嶺支脈山道・霧嶺分水隘");
    set_long("這條蜿蜒於落龍古脈西翼支脈的山嶺小道，是連結青河水網與重石台地的\n"
             "捷徑。山脊分水嶺常年籠罩在濃重山霧之中，北坡竹林蒼翠、溪水潺潺，南坡則陡然\n"
             "轉為冷硬的青石與重玄岩層。向北下山通往【青河縣・百草坪梯田】，往南直抵【重石縣・北鎮條石關門】。\n");

    set_exits(([
        "north": "/d/counties/qinghe/baicaoping_fields.c",
        "south": "/d/counties/zhongshi/north_gate.c",
    ]));

    set_coordinate(-5, 8, 0);
}
