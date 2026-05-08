// area/newbie/deep_forest.c - 深林
#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("幽暗的深林");
    set_long(
        "深林中光線昏暗，參天古木遮天蔽日。\n" +
        "地上落葉層層疊疊，偶有怪物的腳步聲在四周迴響。\n" +
        "一個寶箱靜靜地放在一棵老樹旁。\n"
    );
    add_exit("south", "/area/newbie/forest_trail.c");
    add_item("寶箱",  "這是一個看起來年代久遠的木製寶箱，鎖頭已經鏽蝕了。");
    add_item("chest", "這是一個看起來年代久遠的木製寶箱，鎖頭已經鏽蝕了。");

    // 生成兩隻稍強的怪物與一把武器
    object wolf = clone_object("/npc/wolf.c");
    move_object(wolf, this_object());

    object sword = clone_object("/item/weapon/short_sword.c");
    move_object(sword, this_object());
}

void init() {
    ::init();
}
