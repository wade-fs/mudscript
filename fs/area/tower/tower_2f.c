// mudlib/area/tower/tower_2f.c - 法師塔二樓
#include <globals.h>
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Mage Tower Second Floor",
        "zh-TW": "法師塔二樓",
        "zh-CN": "法师塔二楼"
    ])));
    set("long", select_lang(([
        "en": "You are on the second floor. It is filled with magical books.
",
        "zh-TW": "這裡是二樓，到處都是魔法書籍。
",
        "zh-CN": "这里是二楼，到处都是魔法书籍。
"
    ])));
    set("coordinate", ({ 0, 5, 1 }));
    set_is_outdoor(0);
    set("exits/" + "down", "./tower_1f.c");
}
