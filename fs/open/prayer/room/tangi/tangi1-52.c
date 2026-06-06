//open/prayer/room/tangi/tangi1-52.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主的書房");
        set("long",
"天機門副門主的書房,這裡是副門主處理門務的地方. 副門主是武學的領導者,雖然
武學造詣不及門主的一半,可是細心與耐心是讓門主交予重任的原因!!\n");

        set("exits", ([ /* sizeof() == 1 */
        "west":"/open/prayer/room/tangi/tangi1-50",		//副門主房
       
        ]) );
        set("light_up", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/vice-chair" : 1,		//副門主
  "/open/prayer/npc/puncher" : 1,		//拳師
   		
]));
     
  setup();
}
