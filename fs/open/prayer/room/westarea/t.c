//open/prayer/room/westarea/road5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
西武林自成一格的街道,四通八達,處處繁華.北邊是白虎宮的入口處.南邊則是到達
天機門.此處是一個三叉口!!行人眾多,好不熱鬧.LONG);

        	set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        	"north":"/open/prayer/room/westarea/road7",		//街道
	"south":"/open/prayer/room/westarea/road10",	//街道
	"west":"/open/prayer/room/westarea/road3",		//街道
 
        ]) );
          set("objects", ([ /* sizeof() == 1 */
          "/open/prayer/npc/vendor" : 1,
        ]) );
        
        set("no_fight", 0);
    setup();
}
