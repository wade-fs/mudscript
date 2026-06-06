//open/prayer/room/garden5.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    這個花園頗大，往東往北都是濃濃的霧氣
	，整座花園瀰漫著一種說不出的詭異氣氛，時
	時有聽到野獸咆哮的聲音，時而聞到濃厚的血
	腥味道，令你不寒而顫。哇哇!!這裡有隻怪物
	呀!!

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/garden9",		//花園
        "east":"/open/prayer/room/garden4",			// "
        ]) );
  set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/bird" : 1,
        ]) );
   setup();
}
