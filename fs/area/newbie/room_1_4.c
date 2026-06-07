#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "East-West Avenue",
        "zh-TW": "東西大道",
        "zh-CN": "东西大道"
    ])));
    set("long", select_lang(([
        "en": "The broad street is lined with various small shops.\n",
        "zh-TW": "寬闊的街道兩旁開滿了各式小店。\n",
        "zh-CN": "宽阔的街道两旁开满了各式小店。\n"
    ])));
    set("coordinate", ({ 1, 4, 0 }));
    set("exits/" + "west", "./room_0_4.c");
    set("exits/" + "east", "./room_2_4.c");
    set("exits/" + "south", "./room_1_3.c");
    set("exits/" + "north", "./room_1_5.c");
}
