//open/prayer/room/tangi/tangi1-3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天機門大廳");
        set("long",
"整座大廳的裝潢除了充滿莊嚴之外，特別還有一股文人雅士的氣息．壁上四處可見
大型的潑墨畫，與門主的品味互相融合．廳上所站立的是天機門的左護法．後面是一
道鐵門，但是不知道它通往何處?\n");
        set("exits", ([ /* sizeof() == 2 */
        "east":"/open/prayer/room/tangi/tangi1",		//堂主
        "west":"/open/prayer/room/garden4",      
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/left" : 1,		//左護法
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="west"&&present("hu-fa left",environment(me)))
return notify_fail("左護法厲聲喝道:沒有門主的令牌,休想走進一步!\n");
        return ::valid_leave(me,dir);
}
