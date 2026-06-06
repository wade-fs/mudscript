//room:/u/e/eva/village/room/room-38.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村民房");
    set("long","
    一間用磚瓦砌成的普通民房, 屋內放置一些簡單的家具擺\設, 是
魔界村中的一間民房, 屋內竟有一個熔爐, 四周擺\滿了工具, 這裡住
戶一定是一名鑄劍師!\n\n");
    set("objects",([
        V_NPC"lee" : 1,
        ]));
    set("exits",([
        "east" : __DIR__"room-03",
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
