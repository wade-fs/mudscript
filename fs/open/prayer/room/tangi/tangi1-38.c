//open/prayer/room/tangi/tangi1-38.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","廚房");
        set("long",
"天機門的廚房,廚師的工作就是負責填滿全門上下所有門人的肚皮. 他正在悠閒地料
理著等會要開飯的菜色哩!!\n");

        set("exits", ([ /* sizeof() == 1 */
        "north":"/open/prayer/room/tangi/tangi1-36",		//廚房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/cooker" : 1,		//廚師
   		
]));
     
  setup();
}
