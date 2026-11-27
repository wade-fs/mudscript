// d/city/north/gong_fireworks.c
// 硝火作 (官禁火器雷管要地)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・硝火作");
    set_long("這是一間深挖入地下的厚石防爆工坊，四壁貼滿了厚厚黃泥與生鐵夾板。\n"
             "空氣中瀰漫著刺鼻的高純度硫磺與烈礬硝石氣味，地上鋪滿細砂以防碰撞火花。\n"
             "火藥督造官嚴厲注視著每一道封裝工序，專門配製開山雷管與守城火毬。\n"
             "向東推開沉重鐵門可回到千錘地爐坊。\n");

    set_exits(([
        "east": "/d/city/north/gong_forge.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", YEL "地上鋪滿吸震乾燥細砂，木質藥篩輕巧絕緣，絕不敢碰觸半點鐵器。" NOR);
    set_smell("default", HIR "強烈刺鼻的高純度硫磺、烈礬硝石粉末氣味，吸一口便令人眉心微緊。" NOR);
    set_listen("default", WHT "督造官嚴厲盯場之下無人敢高聲語，只有竹勺輕輕舀砂與紙筒封蠟的細碎聲響。" NOR);

    spawn_npc("/clone/npc/gong_fireworks_master.c");
}
