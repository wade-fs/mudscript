//open/prayer/room/westarea/road41.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 西邊是通往飄渺四
	宮之末的"朱雀宮". 
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 1 */
        	"north":__DIR__"road39",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
