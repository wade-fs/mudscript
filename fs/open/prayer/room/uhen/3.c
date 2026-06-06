//open/prayer/room/uhen/3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","玉衡門大廳");
        set("long",@LONG

        整座大廳上除了放些武器外. 牆上也掛著一些畫, 畫
        中的景物主要都是一些飛禽在天空飛翔的圖畫. 看來
        門主似乎對於這方面有特別的喜愛..
	廳上所站立的是玉衡門的右護法．

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"6",	//大廳
        "east":__DIR__"2",		//書房
        "west":__DIR__"4",		//門主
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/right" : 1,		//右護法
]));
  setup();
}

