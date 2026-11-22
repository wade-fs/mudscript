// d/wastes/frost_hunter_camp.c
// 北荒南沿・凍土牧戶避風棚（與三宗勘探無關的塞外牧民生活點）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒南沿・凍土牧戶避風棚");
    set_long("雪原行腳營地西側背風岩崖下搭著一座用犛牛毛氈與枯柳枝捆成的低矮牧民窩棚。\n"
             "棚外圍著一圈荊棘矮柵欄，裡頭擠著十幾頭耐寒的灰白黃羊正縮成一團躲避雪風。\n"
             "這兒的牧戶祖輩在長城外放牧，既沒見過什麼仙道秘寶，也只希望這場凜冬快些過去。\n"
             "向東穿過雪坡即回【北荒裂谷・雪原行腳營地】。\n");

    set_exits(([
        "east": "/d/wastes/snow_caravan_camp.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", HIW "犛牛毛氈門簾結著細小冰晶，棚裡火塘旁鋪著厚實乾燥的羊皮褥子卻顯得暖和。" NOR);
    set_smell("default", YEL "燒乾牛糞的獨特焦煙、滾熱奶茶奶皮香與羊圈裡的乾燥草料羶味。" NOR);
    set_listen("default", WHT "棚外黑風呼嘯掠過冰崖，棚裡則是老羊偶爾「咩」地叫一聲與茶壺滾水聲。" NOR);

    spawn_npc("/clone/npc/folk/wastes_herder.c");
}
