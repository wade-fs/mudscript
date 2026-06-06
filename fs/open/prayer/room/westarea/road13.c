//open/prayer/room/westarea/road13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	這裡是一個十字路口, 往北邊走可以到達聖火教的總壇. 往西
	走可以到天機, 天璇門. 北邊有一間商店, 往東去是一條邪氣
	漫漫的高聳山脈!!
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
       	"north":__DIR__"road9",		//街道
	"south":__DIR__"road17",	//街道
	"east":__DIR__"road12",		//街道
	"west":__DIR__"road14",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
