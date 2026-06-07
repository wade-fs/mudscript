#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Commoner District",
        "zh-TW": "平民區",
        "zh-CN": "平民区"
    ])));
    set("long", select_lang(([
        "en": "There are rows of neat stone houses here.\n",
        "zh-TW": "這裡是一排排整齊的石造民居。\n",
        "zh-CN": "这里是一排排整齐的石造民居。\n"
    ])));
    set("coordinate", ({ 1, 0, 0 }));
    set("exits/" + "west", "./room_0_0.c");
    set("exits/" + "east", "./room_2_0.c");
    set("exits/" + "north", "./room_1_1.c");
    set("exits/" + "southeast", "../water/lake_0_0_0.c");
}
