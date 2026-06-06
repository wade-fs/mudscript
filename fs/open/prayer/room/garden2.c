//open/prayer/room/garden2.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園");
        set("long",@LONG

	    濃厚的血腥味撲鼻而來，但你不以為意，
	在這江湖上行走，早就過慣刀口上過活的日子
	，地上足跡非常明顯，這是人血還是怪獸的血
	呢??管它的，只要不是自己的血就好了!!

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/garden6",		//花園
        "west":"/open/prayer/room/garden3",		// "
        ]) );
   setup();
}
