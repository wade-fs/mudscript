//open/prayer/room/westarea/road10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華, 西邊是聖火
	教麾下最大的分部--"天機門". 聽說天機門的門主司馬錦在
	年少時曾經救過教主的性命呢!!南邊與北邊各是人來人往的
	街道.
LONG);

       	set("outdoors", "/open/prayer/room");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road5",		//街道
	"south":__DIR__"road15",	//街道
	"west":"/open/prayer/room/tangi/tangi1-34",		//大門
 
        ]) );
        setup();
}
