//room:/u/e/eva/village/room/room-36.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create()
{
    set("short","魔界村道路");
    set("long","
    這裡是魔界村的外圍道路, 道路是用碎石子鋪成的, 但是由於長
久使用的結果, 路面十分的平坦, 往來行人中夾雜了幾隻魔物, 令人
大吃一驚, 人與魔竟可和平相處!\n\n");
    set("exits",([
        "north" : __DIR__"room-16",
        "south" : __DIR__"room-37",
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
