//room:/u/e/eva/village/room/room-03.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村道路");
    set("long","
    這裡是魔界村通往市中心的道路, 越接近市中心越可以看到許\多
人聚集, 其中也有不少各式各樣的低等魔物, 不免令你驚奇, 兩旁有
幾幢普通的民房, 不知道住了誰?\n\n");
    set("exits",([
        "north" : __DIR__"room-02",
        "east" : __DIR__"room-39",
        "south" : __DIR__"room-04",
        "west" : __DIR__"room-38",
        ]));
    set("objects",([
        V_NPC"sprite" : 1 ,
        V_NPC"s_genie" : 1,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);  
    setup();
}
