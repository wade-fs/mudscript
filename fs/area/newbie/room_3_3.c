#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Town Hall",
        "zh-TW": "市政廳",
        "zh-CN": "市政厅"
    ])));
    set("long", select_lang(([
        "en": "This is a solemn building where the town's affairs are handled.\n",
        "zh-TW": "這是一座莊嚴的建築，處理城鎮的大小事務。\n",
        "zh-CN": "这是一座庄严的建筑，处理城镇的大小事务。\n"
    ])));
    set("no_combat", 1);
    set("coordinate", ({ 3, 3, 0 }));
    set("exits/" + "west", "./room_2_3.c");
    set("exits/" + "east", "./room_4_3.c");
    set("exits/" + "south", "./room_3_2.c");
    set("exits/" + "north", "./room_3_4.c");
}
