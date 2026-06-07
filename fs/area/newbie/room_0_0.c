#include <globals.h>
#include "/include/ansi.h"
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Newbie Village Gate",
        "zh-TW": "新手村大門",
        "zh-CN": "新手村大门"
    ])));
    set("long", select_lang(([
        "en": "This is the entrance to the Newbie Village. A tall stone gate stands here, and beyond it is the safe and peaceful village.\nThere is a sign pointing outside.\n",
        "zh-TW": "這裡是新手村的入口。一座高大的石門矗立在此，門後是安全寧靜的村莊。\n旁邊有一塊指路牌指向村外。\n",
        "zh-CN": "这里是新手村的入口。一座高大的石门矗立在此，门后是安全宁静的村庄。\n旁边有一块指路牌指向村外。\n"
    ])));
    set("coordinate", ({ 0, 0, 0 }));
    set("no_combat", 1);
    set("exits/" + "east", "./room_1_0.c");
    set("exits/" + "north", "./room_0_1.c");
    set("exits/" + "out", "./room_4_4.c");
    set("exits/" + "down", "../cave/cave_0_0_minus1.c");
}
