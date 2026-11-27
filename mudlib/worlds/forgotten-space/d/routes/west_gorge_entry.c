// /d/routes/west_gorge_entry.c
// 西線第一段 (seg_blackstone_zhongshi, 180里) 節點 1：落龍西谷棧道口・限重木柵
// 嚴格執行「禁行重型大車 (heavy_wagon_days == 0)」之世界規則

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_blackstone_zhongshi");
    set_node_index(1);
    set_short("落龍西谷棧道口・限重木柵");
    set_long("這裡是自黑石鋪西北方切入落龍山脈西谷的險要山口。一條僅容單騎與輕裝\n"
             "步卒通行的古棧道懸掛在百丈絕壁之上，棧道入口豎立著百工總會與重石縣衙合立的\n"
             "巨型鐵木限寬樁與石碑，上刻：「落龍西谷懸崖飛棧，全長百八十里直通重石縣；\n"
             "棧木承重有限，嚴禁重型大車與大宗礦石輜重通行，重車請繞行東線虎跳峽盤木道！」\n"
             "往東南可返【黑石鋪】青石街市，向北踏上棧道則進入【落龍西谷・懸崖飛棧】。\n");

    set_exits(([
        "southeast": "/d/village/square.c",
        "north":     "/d/routes/cliff_broken_plank.c",
    ]));

    set_coordinate(-2, 2, 0);
}
