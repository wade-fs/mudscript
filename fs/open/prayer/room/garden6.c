//open/prayer/room/garden6.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	邪氣愈來愈濃,四周不時傳來野獸的叫聲........... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden10",		//花園
        "east":"/open/prayer/room/garden2",			// "
        "west":"/open/prayer/room/garden7",		// "
        ]) );
   setup();
}
