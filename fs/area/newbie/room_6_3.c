#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Town Street",
        "zh-TW": "城鎮街道",
        "zh-CN": "城镇街道"
    ])));
    set("long", select_lang(([
        "en": "This is a quiet street, with occasional residents passing by.\n",
        "zh-TW": "這裡是一條安靜的街道，偶爾有居民走過。\n",
        "zh-CN": "这里是一条安静的街道，偶尔有居民走过。\n"
    ])));
    set("coordinate", ({ 6, 3, 0 }));
    set("exits/" + "west", "./room_5_3.c");
    set("exits/" + "east", "./room_7_3.c");
    set("exits/" + "south", "./room_6_2.c");
    set("exits/" + "north", "./room_6_4.c");
}
