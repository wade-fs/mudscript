//open/prayer/room/garden15.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

不知道從那裡來的濃霧,只見陰氣沉沉,四周不時傳來野獸的叫聲........... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden19",		//花園
        "south":"/open/prayer/room/garden11",		//花園
        "east":"/open/prayer/room/garden14",		// "
        "west":"/open/prayer/room/garden16",			// "
        ]) );
   setup();
}
