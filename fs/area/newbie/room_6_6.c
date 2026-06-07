// /area/newbie/room_6_6.c
#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": GRN("Green Meadow"),
        "zh-TW": GRN("翠綠草原"),
        "zh-CN": GRN("翠绿草原")
    ])));
    set("long", select_lang(([
        "en": "This is a vast meadow. The breeze blows, and the grass waves. In the distance, several wild horses can be seen grazing leisurely.\n",
        "zh-TW": "這裡是一片廣闊的草原，微風拂過，草浪起伏。\n遠處可以看到幾匹野馬正在悠閒地吃草。\n",
        "zh-CN": "这里是一片广阔的草原，微风拂过，草浪起伏。\n远处可以看到几匹野马正在悠闲地吃草。\n"
    ])));
    set("coordinate", ({ 6, 6, 0 }));
    set("exits/" + "west", "./room_5_6.c");
    set("exits/" + "south", "./room_6_5.c");

    spawn_npc("/npc/horse.c");
}
