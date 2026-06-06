//open/prayer/room/tanchun/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天權門大廳");
        set("long",@LONG

	整座大廳的擺設不外乎是兵器方面的事物，特別是在西邊牆上的
	那一把擎天神戟．這把擎天戟由精鋼鑄成，整把兵器重有三百斤
	，與門主的膂力互相配合後, 使將起來其威力足可開石劈柱．廳
	上所站立的是天權門的右護法．

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"4",		//大廳
        "west":__DIR__"2",		//門主
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/right" : 1,		//右護法
]));
  setup();
}

