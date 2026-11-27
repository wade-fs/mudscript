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

    set_touch("default", HIW "鬼門彎墨色亂石鋒利冰涼，積雪凹處留著折斷響箭與擦破護具的碎布條。" NOR);
    set_smell("default", HIR "北荒地煞寒流裹著荒狼身上的野獸腥氣，強催氣血時鼻腔隱隱發熱發酸。" NOR);
    set_listen("default", WHT "窄峽谷風嘯如鬼哭，石堆上方偶爾傳來爪尖刮擦黑岩的輕響與低沉狼嗥。" NOR);

    spawn_npc("/clone/npc/ironback_wolf.c");
}
