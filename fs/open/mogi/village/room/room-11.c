//room:/u/e/eva/village/room/room-11.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村");
    set("long","
    這裡是魔界村, 魔界村是個由結界保護的村落, 僅有低等魔物及
人類可進出, 向東方望去便是魔界村的中心廣場, 看起來相當的熱鬧
, 兩旁的道路則是環繞村子圍牆的道路, 往西走可以出魔界村.\n\n");
    set("exits",([
        "north" : __DIR__"room-25",
        "east" : __DIR__"room-12",
        "south" : __DIR__"room-34",
        "west" : __DIR__"room-10",
        ]));
    set("objects",([
        V_NPC"s_man_a" : 1,
        V_NPC"s_woman_a" : 1,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);  
    setup();
}
