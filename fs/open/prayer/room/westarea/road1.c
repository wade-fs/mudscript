//open/prayer/room/westarea/road1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華, 往北邊就是
	西域聖火教的總壇所在地了. 路兩旁的棕櫚樹枝, 隨風搖曳
	, 給人一種很舒適的感覺 .
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
       	"north":"/open/prayer/room/1-door2",		//街道
	"south":__DIR__"road9",	//街道
	"east":__DIR__"road2",	//街道
	"west":__DIR__"road3",	//街道
 
        ]) );
        
        set("no_fight", 0);
    setup();
}

