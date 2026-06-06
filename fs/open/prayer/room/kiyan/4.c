//open/prayer/room/kiyan/4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","開陽門大廳");
        set("long",@LONG

	西武林中一個勢力龐大的組織，人們統稱她為「聖火教」，又稱
	為明教．此處是明教聖火八天門之一的開陽門，門上所坐的是開
	陽門的門主．開陽門是聖火教排行第六的支門．門主後面是她的
	閨房.

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"1",	//門主房間
        "south":__DIR__"7",	//大廳
        "east":__DIR__"3",	//右護法
        "west":__DIR__"5",	//左護法
 
        ]) );
        set("light_up", 1);
set("valid_startroom", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/kiyan" : 1,		//門主
]));
  setup();
}

void init()
{
  add_action("do_pass","pass");
}

int do_pass()
{
   object me=this_player();
   me->move("/open/ping/room/road3");
   return 1;
}
