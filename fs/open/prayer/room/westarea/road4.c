//open/prayer/room/westarea/road4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG

	西武林自成一格的街道, 四通八達, 處處繁華. 北邊
	是"青龍宮"的座落處, 左面環山, 右面倚丘, 是個難
	攻易守的戰略地點.

LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road6",		//街道
	"south":__DIR__"road8",		//街道
	"west":__DIR__"road2",		//街道
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/youkoun-woman" : 1,		
        ]) );
        
  setup();
}
