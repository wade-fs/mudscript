//open/prayer/room/youkoun/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主書房");
        set("long",@LONG

        這裡是瑤光門副門主的書房, 有個女弟子正在打掃房間.
        書架上是一排排的書, 想來副門主也是個飽讀詩書之人.
        往西一直走出去就是練武場.

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"6",         //副門主室
        "southwest":__DIR__"8",         //副門主室
        "west":__DIR__"7",              
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
