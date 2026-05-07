// area/newbie/entrance.c - 新手村入口廣場
#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("新手村入口廣場");
    set_long(
        "你站在一個熱鬧的石板廣場上。周圍的攤販叫賣著各式各樣的商品，\n" +
        "幾位穿著新奇的冒險者正在打量著彼此。廣場中央有一座巨大的石雕噴泉，\n" +
        "噴出閃閃發光的泉水，據說喝了能增加運氣。\n"
    );
    add_exit("north", "/area/newbie/forest_trail.c");
    add_exit("east",  "/area/newbie/item_shop.c");
    add_item("噴泉",   "這座噴泉由純白大理石雕成，泉水在陽光下閃閃發光。");
    add_item("fountain","這座噴泉由純白大理石雕成，泉水在陽光下閃閃發光。");
}

// 當玩家進入時，提供房間指令
void init() {
    ::init();
}
