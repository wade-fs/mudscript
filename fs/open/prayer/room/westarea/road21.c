//open/prayer/room/westarea/road21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 此處是西域
	的中心, 往北邊走可以到達聖火教的總壇. 四方則分別是聖
	火八天門各門的座落位置..
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"road17",	//街道
	"south":__DIR__"road25",	//街道
	"east":__DIR__"road20",		//街道
	"west":__DIR__"road22",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
