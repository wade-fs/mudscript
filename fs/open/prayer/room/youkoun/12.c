//open/prayer/room/youkoun/12.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

        這裡站著兩個保鑣, 從你進來時就一直不懷好意地看著你
        . 看到這個小書房竟然有這麼多保鑣, 你不禁為瑤光門的
        人事編制感到不以為然..

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"15",        //總管房
        "south":__DIR__"13",            //總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/paltoon1" : 1,                //保鑣
        "/open/prayer/npc/paltoon2" : 1,                //保鑣
                
]));
     
  setup();
}
