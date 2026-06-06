//open/prayer/room/garden11.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
	set( "build", 20 );
        set("long",@LONG

	    這個花園頗大，往東往西往南往北都是濃
	濃的霧氣，整座花園瀰漫著一種說不出的詭異
	氣氛，時有聽到野獸咆哮的聲音，時而聞到濃
	厚的血腥味道令你不寒而顫。

LONG);
        set("outdoors", "/u/r/rence");
	set("objects", ([ /* sizeof() == 1 */
	"/open/prayer/npc/maker" : 1,  
	]));
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden15",		//花園
        "south":"/open/prayer/room/garden7",		//花園
        "east":"/open/prayer/room/garden10",		// "
        "west":"/open/prayer/room/garden12",		// "
        ]) );
   setup();
}
