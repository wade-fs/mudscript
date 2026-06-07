#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "South Forest Path Entrance",
        "zh-TW": "南方林道口",
        "zh-CN": "南方林道口"
    ])));
    set("long", select_lang(([
        "en": "This is a crossroad leading to the southern part of the town. The roadside shrubs are thick and dark, with a few depressions that look like small footprints—goblins love to ambush in places like this.\n",
        "zh-TW": "這裡是通往城鎮南邊的岔路口，路旁的矮林濃密陰暗，有幾個像是小腳印的凹坑——哥布林最愛在這種地方埋伏。\n",
        "zh-CN": "这里是通往城镇南边的岔路口，路旁的矮林浓密阴暗，有几个像是小脚印的凹坑——哥布林最爱在这种地方埋伏。\n"
    ])));
    set("coordinate", ({ 5, 2, 0 }));
    set("exits/" + "east", "./room_6_2.c");
    set("exits/" + "west", "./room_4_2.c");
    set("exits/" + "north", "./room_5_3.c");
    set("exits/" + "south", "./room_5_1.c");

    spawn_npc("/npc/creature/forest_goblin.c");
}
