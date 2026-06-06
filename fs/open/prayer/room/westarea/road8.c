//open/prayer/room/westarea/road8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 東邊是聖火八天
	門之一的"天樞門", 門主葛輝乃是西域人士, 為教派付出心力頗
	多, 故成為教主最倚重的人物!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road4",		//街道
	"south":__DIR__"road11",	//街道
	
     "east":"/open/prayer/room/tanshu/2-door",       //街道
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
