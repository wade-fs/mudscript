//__DIR__"16.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的休息室");
        set("long",@LONG

	玉衡門總管的休息室, 這裡是總管休息的地方. 
        平常總管如果辦公累了. 就會來這裏休息, 四周
        的擺設看來相當典雅. 讓人看了覺得相當舒服.
LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southeast":__DIR__"19",		//總管房
        "south":__DIR__"17",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/paltoon1" : 1,		//保鑣
        "/open/prayer/npc/paltoon2" : 1,		//保鑣
   		
]));
     
  setup();
}
