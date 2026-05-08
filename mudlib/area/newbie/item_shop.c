// area/newbie/item_shop.c - 道具店
#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("道具店「幸運草」");
    set_long(
        "小小的店面裡擺滿了各式各樣的冒險用品。\n" +
        "老闆是位慈眉善目的矮人，正在算術盤上撥動算珠。\n"
    );
    add_exit("west", "/area/newbie/entrance.c");

    // 生成商店裡的道具
    object potion = clone_object("/item/consumable/health_potion.c");
    move_object(potion, this_object());
    object sword = clone_object("/item/weapon/short_sword.c");
    move_object(sword, this_object());
    object armour = clone_object("/item/armour/leather_armour.c");
    move_object(armour, this_object());
}

void init() {
    ::init();
}
