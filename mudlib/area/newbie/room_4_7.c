#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(([
        "en": "North-South Avenue",
        "zh-TW": "南北大道",
        "zh-CN": "南北大道"
    ]));
    set_long(([
        "en": "A clean stone path that runs through the town from north to south.\n",
        "zh-TW": "一條整潔的石板路，貫穿城鎮南北。\n",
        "zh-CN": "一条整洁的石板路，贯穿城镇南北。\n"
    ]));
    set_coordinate(4, 7, 0);
    add_exit("west", "/area/newbie/room_3_7.c");
    add_exit("east", "/area/newbie/room_5_7.c");
    add_exit("south", "/area/newbie/room_4_6.c");
}
