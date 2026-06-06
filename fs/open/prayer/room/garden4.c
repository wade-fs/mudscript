//open/prayer/room/garden4.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    不知道從那裡來的濃霧，只見陰氣沉沉，
	四周不時傳來野獸的叫聲．遠方可以看見一座
	雕像，不過因為濃霧太大了，不能夠清楚地分
	辨出來其真面目!! 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden8",		//花園
        "east":"/open/prayer/room/garden3",		// "
        "west":"/open/prayer/room/garden5",		// "
        ]) );
   setup();
}
