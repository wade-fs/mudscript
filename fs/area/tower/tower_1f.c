// mudlib/area/tower/tower_1f.c - 法師塔一樓
#include <globals.h>
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Mage Tower Entrance",
        "zh-TW": "法師塔入口",
        "zh-CN": "法师塔入口"
    ])));
    set("long", select_lang(([
        "en": "You are at the entrance of a mysterious mage tower.
",
        "zh-TW": "你來到了一座神秘法師塔的入口。
",
        "zh-CN": "你来到了一座神秘法师塔的入口。
"
    ])));
    set("coordinate", ({ 0, 5, 0 }));
    set_is_outdoor(0);
    
    set("exits/" + "south", "../newbie/room_0_1.c");
    set("exits/" + "up", "./tower_2f.c");
}
