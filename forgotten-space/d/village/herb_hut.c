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

void init() {
    ::init();
    add_action("do_herb_recover", "drink");
    add_action("do_herb_recover", "inhale");
    add_action("do_herb_recover", "聞藥");
    add_action("do_herb_recover", "飲湯");
}

int do_herb_recover(string arg) {
    object me = this_player();
    write("你湊近泥爐上咕嘟冒泡的粗陶藥罐，深深吸了一口濃郁甘苦的草木藥氣，並淺啜了半碗溫熱藥湯。\n");
    write(HIG "溫潤醇厚的草木靈氣順著經絡化開，淤積的暗傷與疲勞迅速消融，只覺神清氣爽！\n" NOR);
    me->add(VITAL_KEE, 30);
    me->add(VITAL_SEN, 20);
    me->add(VITAL_SP, 20);
    write(HIG "【藥氣浸潤，你的氣血 +30、神識 +20、精力 +20！】\n" NOR);
    return 1;
}

