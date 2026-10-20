// d/city/north/gong_stone.c
// 官造石作場 (韓老雕)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・官造石作場");
    set_long("這座露天石匠大工棚內到處堆滿了來自重石縣的重玄巨石與花崗岩條石。\n"
             "空氣中瀰漫著濃重的青石石粉塵埃，鋼鑿打磨條石的尖銳鑿擊聲此起彼伏。\n"
             "老石匠韓老雕手持鋼釬，正在精細雕琢城門地磅承重座。\n"
             "西面推開木柵門可回到千錘地爐坊。\n");

    set_exits(([
        "west": "/d/city/north/gong_forge.c",
    ]));

    set("is_outdoor", 1);

    spawn_npc("/clone/npc/gong_stone_hanlaodiao.c");
}
