//open/prayer/room/garden10.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    血紅色的濃霧飄，聞起來有股腥味!!令人
	的意識漸漸模糊......在不遠的地方時而傳來
	類似魔物的咆哮聲，看來你最好還是收起探險
	的心情吧!! 

LONG);
        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden14",		//花園
        "south":"/open/prayer/room/garden6",			// "
        "west":"/open/prayer/room/garden11",			// "
        ]) );
  set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/crab-ox" : 1,
        ]) );
   setup();
}
