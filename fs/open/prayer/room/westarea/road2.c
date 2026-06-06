//open/prayer/room/westarea/road2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 北邊的小山
	丘是總壇的所在地, 紅瓦層層, 在陽光的照耀下, 看起來就
	像是一座紅色的火山........
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road4",		//街道
        "west":__DIR__"road1",		//街道
 
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
