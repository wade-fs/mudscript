//open/prayer/room/kiyan/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","開陽門大廳");
        set("long",@LONG

	整座大廳充滿了中原人家的風格與景調，特別還有一股
	不屬於聖火教這個門派的氣息．牆上可見許多歷代英雄
	人物的畫像，充分襯托出門主的崇拜偶像心理．廳上所
	站立的是開陽門的左護法．後面是練功房的入口!!

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"8",		//大廳
        "east":__DIR__"4",	        //門主
        "west":__DIR__"23",	        //練功房
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/left" : 1,		//左護法
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if(me->query("class")!="prayer"&&dir=="west")
	return notify_fail("對不起, 裡面是開陽門弟子的練功\之地!!\n");
                      
	return ::valid_leave(me,dir);
}
