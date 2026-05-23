#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(([
        "en": "Town Hall",
        "zh-TW": "市政廳",
        "zh-CN": "市政厅"
    ]));
    set_long(([
        "en": "This is a solemn building where the town's affairs are handled.\n",
        "zh-TW": "這是一座莊嚴的建築，處理城鎮的大小事務。\n",
        "zh-CN": "这是一座庄严的建筑，处理城镇的大小事务。\n"
    ]));
    set_no_combat(1);
    set_coordinate(3, 3, 0);
    add_exit("west", "/area/newbie/room_2_3.c");
    add_exit("east", "/area/newbie/room_4_3.c");
    add_exit("south", "/area/newbie/room_3_2.c");
    add_exit("north", "/area/newbie/room_3_4.c");
}
