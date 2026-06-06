//open/prayer/room/tangi/tangi1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天機門大廳");
        set("long",@LONG

	西武林中一個勢力龐大的組織, 人們統稱她為「聖火教」
	, 又稱為明教. 此處是明教分部之一的天機門, 門上所坐
	的是天機門的門主. 天機門是聖火教最大的支門．北邊是
	天機門主的書房!!

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1-1",		//門主的房間
        "south":"/open/prayer/room/tangi/tangi1-12",		//大廳
        "east":"/open/prayer/room/tangi/tangi1-2",		//右護法
        "west":"/open/prayer/room/tangi/tangi1-3",		//左護法
 
        ]) );
        set("light_up", 1);
	set("valid_startroom", 1);
        set("objects",([ /* sizeof() == 1 */
	"/open/prayer/npc/tangi" : 1,		//門主
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if(me->query("class")!="prayer"&&dir=="north")
	return notify_fail("對不起, 裡面是天機門弟子的聚會之地!!\n");
                      
	return ::valid_leave(me,dir);
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
