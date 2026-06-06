//open/prayer/room/kiyan/12.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	副門主正和弟子在閒話家常, 副門主的和藹可親由此可見一般!!
	門內的擺設除了幾張桌椅之外, 也沒有什麼東西了..房內有許\多
	的教內弟子在站崗, 可見副門主的地位也是非常的重要與高階了
	!!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"11",		//副門主室
	"northeast":__DIR__"9",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/vice-chair" : 1,		
   "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
