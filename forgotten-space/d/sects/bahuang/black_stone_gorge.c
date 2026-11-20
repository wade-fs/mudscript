// /d/sects/bahuang/black_stone_gorge.c
// 八荒武山・黑石峽試煉道 (Ch.87：鐵背荒狼群與鬼門彎伏擊點)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒武山・黑石峽試煉道");
    set_long("兩側墨色峭壁夾成狹窄的「鬼門彎」亂石灘，北荒地煞寒流如刀刮過，稍催\n"
             "燥火氣血便覺得肺腑發燙。亂石堆上方棲息著狡猾兇殘的二階缺耳鐵背荒狼頭狼。\n"
             "不遠處積雪石凹裡似乎留有兩名受傷考生遺落的求救響箭與護具痕跡。\n"
             "向南退回【萬鈞問心谷】，向北穿過峽谷抵達【黑山煞血營】。\n");

    set_exits(([
        "south": "/d/sects/bahuang/gate.c",
        "north": "/d/sects/bahuang/black_mountain_camp.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/ironback_wolf.c");
}
