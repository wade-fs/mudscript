#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": HIM("Town General Store"),
        "zh-TW": HIM("城鎮雜貨鋪"),
        "zh-CN": HIM("城镇杂货铺")
    ])));
    set("long", select_lang(([
        "en": "This is a small shop filled with a dazzling array of items. The shelves are piled with all kinds of sundries: torches, ropes, rations, and some unknown small parts. It sells various essentials for travel and adventure.\n",
        "zh-TW": "這是一間琳瑯滿目的小店，貨架上堆滿了各式各樣的雜物：火把、繩索、乾糧、還有一些不知名的小零件。這裡販賣著各種旅行冒險必備的小東西。\n",
        "zh-CN": "这是一间琳琅满目的小店，货架上堆满了各式各样的杂物：火把、绳索、干粮、还有一些不知名的小零件。这里贩卖着各种旅行冒险必备的小东西。\n"
    ])));
    set("no_combat", 1);
    set("coordinate", ({ 5, 5, 0 }));
    set("exits/" + "west", "./room_4_5.c");
    set("exits/" + "south", "./room_5_4.c");
}
