//open/prayer/room/garden17.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    這個花園頗大，往東往西往南都是濃濃的
	霧氣，整座花園瀰漫著一種說不出的詭異氣氛
	，時有聽到野獸咆哮的聲音，時而聞到濃厚的
	血腥味道令你不寒而顫。

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden21",		//花園
        "south":"/open/prayer/room/garden13",			// "
        "east":"/open/prayer/room/garden16",			// "
        ]) );
  set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/ditail-snake2" : 1,
        ]) );

   setup();
}
