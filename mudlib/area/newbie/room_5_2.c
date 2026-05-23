#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(([
        "en": "South Forest Path Entrance",
        "zh-TW": "南方林道口",
        "zh-CN": "南方林道口"
    ]));
    set_long(([
        "en": "This is a crossroad leading to the southern part of the town. The roadside shrubs are thick and dark, with a few depressions that look like small footprints—goblins love to ambush in places like this.\n",
        "zh-TW": "這裡是通往城鎮南邊的岔路口，路旁的矮林濃密陰暗，有幾個像是小腳印的凹坑——哥布林最愛在這種地方埋伏。\n",
        "zh-CN": "这里是通往城镇南边的岔路口，路旁的矮林浓密阴暗，有几个像是小脚印的凹坑——哥布林最爱在这种地方埋伏。\n"
    ]));
    set_coordinate(5, 2, 0);
    add_exit("east",  "/area/newbie/room_6_2.c");
    add_exit("west",  "/area/newbie/room_4_2.c");
    add_exit("north", "/area/newbie/room_5_3.c");
    add_exit("south", "/area/newbie/room_5_1.c");

    object goblin = clone_object("/npc/creature/forest_goblin.c");
    if (goblin) move_object(goblin, this_object());
}
