#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    ::create();
    set_short(([
        "en": GRN("Apothecary"),
        "zh-TW": GRN("藥劑店"),
        "zh-CN": GRN("药剂店")
    ]));
    set_long(([
        "en": "This is a cozy little wooden hut, and the room is filled with a faint fragrance of herbs.\nElla is busy here, and there are several bottles of brightly colored potions on the counter.\n",
        "zh-TW": "這是一間溫馨的小木屋，屋子裡瀰漫著淡淡的草藥清香。\n艾拉正在這裡忙碌著，櫃檯上擺放著幾瓶顏色鮮豔的藥劑。\n",
        "zh-CN": "这是一间温馨的小木屋，屋子里弥漫着淡淡的草药清香。\n艾拉正在这里忙碌着，柜台上摆放着几瓶颜色鲜艳的药剂。\n"
    ]));
    set_no_combat(1);
    set_has_lab(1);
    set_is_outdoor(0);
    set_coordinate(2, 2, 0);
    add_exit("east",  "./room_3_2.c");
    add_exit("west",  "./room_1_2.c");
    add_exit("north", "./room_2_3.c");
    add_exit("south", "./room_2_1.c");

    // 產生老闆
    spawn_npc("/npc/herbalist.c");
}
