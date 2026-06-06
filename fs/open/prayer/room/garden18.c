//open/prayer/room/garden18.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

聖火教總壇的花園,走到此處忽然驚覺四處邪氣陣陣,煙霧迷漫........... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/garden14",		//花園
        "west":"/open/prayer/room/garden19",		// "
        ]) );
   setup();
}
