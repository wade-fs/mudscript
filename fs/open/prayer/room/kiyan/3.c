//open/prayer/room/kiyan/3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","開陽門大廳");
        set("long",@LONG

	整座大廳的裝潢除了充滿莊嚴之外，特別還有一股文人雅士的氣
	息．壁上四處可見大型的潑墨畫，與門主的品味互相融合．廳上
	所站立的是開陽門的右護法．

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

int valid_leave(object me, string dir)
{
        if(dir=="east"&&present("hu-fa right",environment(me)))
return notify_fail("右護法微笑說道:想進書房唸書呀!好好加油呀!!\n");
        return ::valid_leave(me,dir);
}
