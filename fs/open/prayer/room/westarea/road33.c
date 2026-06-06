//open/prayer/room/westarea/road33.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
	set( "build", 12 );
        set("long",@LONG
	聖火教南北向的快速道路, 北邊可以通往聖火教的總壇. 南邊
	是往中原武林的道路. 中原武林與西域唯一進出的路線只有這
	個[ 花菶丘陵 ]!!此一丘陵地勢呈凹字型, 是一個狹隘的通道
	, 除了西域的板車外, 很難在有其它的交通工具能通行無礙!!
LONG);

       	set("outdoors", "/u/r/rence");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"road29",		//街道
	"south":__DIR__"road37",		//街道
	 
        ]) );
          set("objects", ([ /* sizeof() == 1 */
          "/open/prayer/npc/vendor" : 1,
]));

        setup();
}
