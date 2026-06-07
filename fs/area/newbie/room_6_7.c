#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Back Garden",
        "zh-TW": "後花園",
        "zh-CN": "后花园"
    ])));
    set("long", select_lang(([
        "en": "A quiet corner at the edge of the town, filled with strange flowers and plants.\n",
        "zh-TW": "城鎮邊緣安靜的角落，種滿了奇異的花草。\n",
        "zh-CN": "城镇边缘安静的角落，种满了奇异的花草。\n"
    ])));
    set("coordinate", ({ 6, 7, 0 }));
    set("exits/" + "west", "./room_5_7.c");
    set("exits/" + "east", "./room_7_7.c");
    set("exits/" + "south", "./room_6_6.c");
}
