//open/prayer/room/garden21.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    整座花園的奇獸得確是非常的怪異，可是
	教主到底是如何抓到這裡來的呢??難道這裡面
	有什麼對外的密道不成??

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/garden17",		//花園
        "east":"/open/prayer/room/garden20",		// "
        ]) );

   setup();
}
