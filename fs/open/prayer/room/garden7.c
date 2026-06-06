//open/prayer/room/garden7.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    不知道從那裡來的濃霧，只見陰氣沉沉，
	四周不時傳來野獸的叫聲，打從你走進來後就
	一直聞到一股薰人的惡臭，地上一堆一堆的骷
	髏還有屍體，讓你不知道這些人到底是怪物的
	食物還是他們是因為走不出去的關係??

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden11",		//花園
        "south":"/open/prayer/room/garden3",		//花園
        "east":"/open/prayer/room/garden6",		// "
        "west":"/open/prayer/room/garden8",			// "
        ]) );
   setup();
}
