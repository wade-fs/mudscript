//open/prayer/room/tangi/tangi1-2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天機門大廳");
	set( "build", 21 );
        set("long",
"整座大廳的裝潢除了充滿莊嚴之外，特別還有一股文人雅士的氣息．壁上四處可見
大型的潑墨畫，與門主的品味互相融合．廳上所站立的是天機門的右護法．右護法後
面是天機門的地牢!\n");
        set("exits", ([ /* sizeof() == 2 */
        "east":"/open/prayer/room/tangi/tangi1-4",		//地牢
        "west":"/open/prayer/room/tangi/tangi1",			//門主
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/right2" : 1,		//右護法
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="up"&&present("hu-fa right",environment(me)))
return notify_fail("右護法雙眼直瞪著你 ,說道:想進地牢,要經過總管同意才行!\n");
        return ::valid_leave(me,dir);
}
