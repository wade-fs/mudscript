//open/prayer/room/kiyan/10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	開陽門副門主的辦公房. 門內的擺設除了幾張桌椅之外, 也沒有什
	麼東西了..房內有許\多的教內弟子在站崗, 可見副門主的地位也是
	非常的重要與高階了!!

LONG);

        set("exits", ([ /* sizeof() == 2 */
            "south":__DIR__"11",		//副門主室
	"southeast":__DIR__"9",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee2" : 1,		//弟子
   "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
