//open/prayer/room/westarea/road25.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	這一整條南北向的道路, 四通八達, 是聖火教的專用公路, 北
	邊可以通往聖火教的總壇. 南邊則是通往中原武林的要道.
LONG);

       	set("outdoors", "/u/r/rence");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 2 */
       	"north":__DIR__"road21",		//街道
	"south":__DIR__"road29",		//街道
	 
        ]) );
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/woman1" : 1,		
        ]) );
        setup();
}
