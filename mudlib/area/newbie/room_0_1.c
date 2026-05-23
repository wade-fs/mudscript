#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(([
        "en": "Commoner District",
        "zh-TW": "平民區",
        "zh-CN": "平民区"
    ]));
    set_long(([
        "en": "There are rows of neat stone houses here.\n",
        "zh-TW": "這裡是一排排整齊的石造民居。\n",
        "zh-CN": "这里是一排排整齐的石造民居。\n"
    ]));
    set_coordinate(0, 1, 0);
    add_exit("east", "/area/newbie/room_1_1.c");
    add_exit("south", "/area/newbie/room_0_0.c");
    add_exit("north", "/area/newbie/room_0_2.c");
}
