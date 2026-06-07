#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "North-South Avenue",
        "zh-TW": "南北大道",
        "zh-CN": "南北大道"
    ])));
    set("long", select_lang(([
        "en": "A clean stone path that runs through the town from north to south.\n",
        "zh-TW": "一條整潔的石板路，貫穿城鎮南北。\n",
        "zh-CN": "一条整洁的石板路，贯穿城镇南北。\n"
    ])));
    set("coordinate", ({ 4, 7, 0 }));
    set("exits/" + "west", "./room_3_7.c");
    set("exits/" + "east", "./room_5_7.c");
    set("exits/" + "south", "./room_4_6.c");
}
