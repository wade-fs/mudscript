//open/prayer/room/zhenche/11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        陣勢門每天公務都很繁忙, 因此有幾個弟子每天都要來
        幫忙. 不過看他們專心工作的情形, 好像一點抱怨也沒
        有. 完全服從上級的指示!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"12",            //副門主室
        "southeast":__DIR__"10",                
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee2" : 1,             //弟子
   "/open/prayer/npc/trainee3" : 1,             //弟子
                
]));
     
  setup();
}
