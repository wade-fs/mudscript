// area/newbie/forest_trail.c - 新手森林小徑
#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("森林小徑");
    set_long(
        "這是一條蜿蜒穿過稀疏樹林的泥土小徑。\n" +
        "陽光穿透樹葉灑下斑斑點點的光影，偶爾能聽到遠處野獸的叫聲。\n" +
        "這裡是新手冒險者練習戰鬥的好地方。\n"
    );
    add_exit("south", "/area/newbie/entrance.c");
    add_exit("north", "/area/newbie/deep_forest.c");

    // 生成一隻練習用的怪物
    object slime = clone_object("/npc/slime.c");
    move_object(slime, this_object());
}

void init() {
    ::init();
}
