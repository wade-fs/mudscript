//room:/u/e/eva/village/room/room-16.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村");
    set("long","
    這裡是魔界村, 魔界村是個由結界保護的村落, 僅有低等魔物及
人類可進出, 向西方望去便是魔界村的中心廣場, 看起來相當的熱鬧
, 兩旁的道路則是環繞村子圍牆的道路, 往東走可以出魔界村.\n\n");
    set("exits",([
        "north" : __DIR__"room-27",
        "east" : __DIR__"room-17",
        "south" : __DIR__"room-36",
        "west" : __DIR__"room-15",
        ]));
    set("objects",([
         V_NPC"s_genie" : 2 ,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);  
    setup();
}
