//open/prayer/room/garden12.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    突然有陣陣的香味傳來，原來是南方進去
	    聖火教總壇的花園，裡面的樹木都長的奇
	形怪狀的，真是令人丈二金剛摸不著頭腦!!走
	到此處你忽然驚覺四處邪氣陣陣，整個人的毛
	孔都有點豎立起來了........... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden16",		//花園
        "south":"/open/prayer/room/garden8",		//花園
        "east":"/open/prayer/room/garden11",		// "
        "west":"/open/prayer/room/garden13",			// "
        ]) );
        set("objects", ([ /* sizeof() == 1 */
        "/open/prayer/npc/lion" :1,		
        ]) );
   setup();
}
