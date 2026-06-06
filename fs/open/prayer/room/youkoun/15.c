//open/prayer/room/youkoun/15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

        這裡是總管處理門務的地方. 總管是門主以下與副門主同
        一職等的幹部..專門負責門內事務的處理. 從這一直往東
        走可到達練武場.

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northeast":__DIR__"12",        //總管房
        "southeast":__DIR__"14",        //總管房
        "east":__DIR__"13",             //總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-manager" : 1,         //總管
                
]));
     
  setup();
}
