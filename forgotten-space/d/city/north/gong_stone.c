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

    set_touch("default", WHT "剛鑿開的重玄青石斷口銳利微涼，場內木架與工具表面落著厚厚一層細石粉。" NOR);
    set_smell("default", WHT "乾燥嗆鼻的青石粉塵埃氣、鋼鑿打火的焦鐵味與石工身上的汗味。" NOR);
    set_listen("default", HIY "鋼釬敲擊條石發出「叮！叮！叮！」清越尖銳的回響，讓人耳膜微微發震。" NOR);

    spawn_npc("/clone/npc/gong_stone_hanlaodiao.c");
}
