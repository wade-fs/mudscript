#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Residential Area",
        "zh-TW": "平民區",
        "zh-CN": "平民区"
    ])));
    set("long", select_lang(([
        "en": "Rows of neat stone houses stand here.\n",
        "zh-TW": "這裡是一排排整齊的石造民居。\n",
        "zh-CN": "这里是一排排整齐的石造民居。\n"
    ])));
    set("coordinate", ({ 2, 0, 0 }));
    set("exits/" + "west", "./room_1_0.c");
    set("exits/" + "east", "./room_3_0.c");
    set("exits/" + "north", "./room_2_1.c");
}
