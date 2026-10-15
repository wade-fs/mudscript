// d/village/herb_hut.c
// 黑石鋪・南面懸崖峭壁・採藥草廬 (採藥孤兒出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("懸崖峭壁・採藥草廬");
    set_long("這是一間半懸於水谷峭壁凹槽中的簡陋竹草茅廬。窗外長年瀰漫著清冷濕潤的\n"
             "水霧，幾根粗大的攀岩麻藤自柴門邊垂落，順著濕滑崖壁通往上方的溪灘。\n"
             "草廬內壁懸掛著數副竹木藥篩與半乾的草藥根莖，濃郁甘苦的草木氣息撲面\n"
             "而來。角落的木几上散亂堆放著碾藥石臼、泛黃的土偏方，以及你從小隨身\n"
             "背負的竹編藥簍。\n");

    set_exits(([
        "up": "/d/village/stream.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/ge_doctor.c");
}
