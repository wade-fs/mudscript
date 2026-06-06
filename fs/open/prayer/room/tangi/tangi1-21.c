//open/prayer/room/tangi/tangi1-21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",
"此處是明教分部之一的天機門的練武場,練武場上總教頭正嚴厲地指導著門生們努
力練功\. 往北是天機門的玄關,進入後則是大廳.兩側的走廊是分別通往總管與副門
主的辦公房.\n");

        	set("outdoors", "/u/r/rence");
        	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 4 */
        	"north":"/open/prayer/room/tangi/tangi1-17",		//玄關
	"south":"/open/prayer/room/tangi/tangi1-26",		//練武場
	"east":"/open/prayer/room/tangi/tangi1-22",		//走廊
	"west":"/open/prayer/room/tangi/tangi1-20",		//走廊
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general-officer" : 1,		//總教頭
   		
]));
        
          setup();
}
