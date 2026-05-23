// mudlib/area/water/lake_0_0_0.c - 湖邊
#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(([
        "en": "Lake Shore",
        "zh-TW": "湖邊",
        "zh-CN": "湖边"
    ]));
    set_long(([
        "en": "The water is calm and clear.
",
        "zh-TW": "湖水寧靜而清澈。
",
        "zh-CN": "湖水宁静而清澈。
"
    ]));
    set_coordinate(10, 0, 0);
    
    add_exit("west", "/area/newbie/room_1_0.c");
}

void reset() {
    ::reset();
    if (!present("water spirit", this_object())) {
        clone_object("/npc/water/water_spirit.c")->move(this_object());
    }
}
