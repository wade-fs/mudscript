//open/prayer/room/garden16.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	  行走到這裡，眼前似乎有片煙霧四處擴散，
	不知哪來那麼多煙霧，五尺內景像皆看的矇矓
	不切........... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden20",		//花園
        "south":"/open/prayer/room/garden12",		//花園
        "east":"/open/prayer/room/garden15",		// "
        "west":"/open/prayer/room/garden17",		// "
        ]) );
   setup();
}
