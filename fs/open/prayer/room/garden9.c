//open/prayer/room/garden9.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	聖火教總壇的花園,走到此處忽然驚覺四處邪氣陣陣,煙霧迷漫...... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden13",		//花園
        "south":"/open/prayer/room/garden5",			// "
        "east":"/open/prayer/room/garden8",			// "
        ]) );
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/gardener" : 1,
        ]) );
   setup();
}
