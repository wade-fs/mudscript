#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit SHOP;

void create()
{
    set("short","魔界村商店");
	set( "build", 73 );
    set("long","
    這裡是魔界村的商店, 由於魔界村特殊的地理位置及特殊的歷史
背景, 所以常常有奇奇怪怪的物品在此流通, 也許\有你所需要的東東
也說不一定!?
    看看有啥東東(list),賣物品(sell),估價(value)\n\n");
    set("exits",([
        "out" : __DIR__"room-47.c",
        ]));
    set("objects",([
        V_NPC"s_boss" : 1 ,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
