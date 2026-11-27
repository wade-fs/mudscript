// /d/routes/tiger_leap_gorge.c
// 東線第一段 (seg_blackstone_panmu, 190里) 節點 2：虎跳峽便道・凍融險段

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_blackstone_panmu");
    set_node_index(2);
    set_short("虎跳峽便道・凍融險段");
    set_long("山道在此緊貼著奔騰咆哮的峽谷激流蜿蜒向前。先前北崖塌方與山洪衝垮了\n"
             "半邊舊官道，百工匠人與鄉民用碗口粗的鐵木巨樁在崖壁外側搶搭出這段臨時便道。\n"
             "每逢初冬凍融或春雨季節，上方岩縫便不時滾落碎石，路旁散落著被落石砸斷的\n"
             "車輪殘骸。向西南可退回【黑石關】，往北穿出峽谷便是盤木縣境內的【盤木前驛站】。\n");

    set_exits(([
        "southwest": "/d/routes/blackstone_pass.c",
        "north":     "/d/routes/panmu_post_approach.c",
    ]));

    set_coordinate(3, 3, 0);
}
