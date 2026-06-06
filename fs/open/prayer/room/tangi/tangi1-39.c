//open/prayer/room/tangi/tangi1-39.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",
"天機門總管的書房,這裡是總管處理門務的地方.總管是門主以下與副門主同一職等的
幹部..專門負責門內事務的處理.東邊是往走廊的方向.\n");

        set("exits", ([ /* sizeof() == 1 */
        "east":"/open/prayer/room/tangi/tangi1-41",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/general-manager" : 1,		//總管
  "/open/prayer/npc/foreman" : 1,			//鑣頭
   		
]));
     
  setup();
}
