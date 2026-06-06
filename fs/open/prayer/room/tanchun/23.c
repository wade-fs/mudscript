//open/prayer/room/tanchun/23.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	天權門總管的書房, 這裡是總管處理門務的地方. 總管不喜歡男
	性進入其辦公房, 所以會要求守衛的保鑣確實執行此一命令..北
	邊是往走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"18",		//總管房
        "south":__DIR__"28",		//總管房
        "east":__DIR__"22",		//總管房
        "west":__DIR__"24",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon2" : 1,		//保鑣
   		
]));
     
  setup();
}
