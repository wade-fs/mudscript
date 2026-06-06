//open/prayer/room/tanchun/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天權門大廳");
        set("long",@LONG

	西武林中一個勢力龐大的組織, 人們統稱她為「聖火教」, 又稱
	為明教. 此處是明教聖火八天門之一的天權門, 廳上所坐的是天
	權門的門主--司徒榮. 天權門是聖火教排行第三的支門．

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"30",		//練功房
        "south":__DIR__"5",		//大廳
        "east":__DIR__"1",		//右護法
        "west":__DIR__"3",		//左護法
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/tanchun" : 1,		//門主
]));
  setup();
}

int valid_leave(object me, string dir)
{
    if(dir=="north" && !me->query("can_study",1) )
        return notify_fail("這是門主私人的練功\房!!非請勿入!!\n");
        
   return 1;
}

