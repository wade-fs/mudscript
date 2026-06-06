//open/prayer/room/tanchun/3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天權門大廳");
        set("long",@LONG

	大廳之四周都是放置武器的架子，整座大聽充滿了兵器所散發出
	來的金屬味．壁上有一幅大型的圖畫，是門主的畫像．廳上所站
	立的是天權門的左護法．!!

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"1",		//門主
        "south":__DIR__"6",	            
        "west":__DIR__"29", 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/left" : 1,		//左護法
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if(me->query("class")!="prayer"&&dir=="west")
	return notify_fail("對不起, 裡面是天權門弟子的練功\之地!!\n");
                      
	return ::valid_leave(me,dir);
}
