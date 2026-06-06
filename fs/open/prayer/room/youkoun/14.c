//open/prayer/room/youkoun/14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

        在書房的南方, 有個保鑣正在偷空休息, 畢竟日以繼夜地
        看守書房還是很累人的! 因此在沒有重大事情的時候, 難
        免要找機會補充一下精神.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "northwest":__DIR__"15",                //總管房
        "north":__DIR__"13",            //總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/paltoon1" : 1,                //保鑣
                
]));
     
  setup();
}
