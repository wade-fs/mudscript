//open/prayer/room/garden13.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

血紅色的濃霧飄來,聞起來有股腥味!!令人的意識漸漸模糊....... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden17",		//花園
        "south":"/open/prayer/room/garden9",			// "
        "east":"/open/prayer/room/garden12",			// "
        ]) );
   setup();
}
