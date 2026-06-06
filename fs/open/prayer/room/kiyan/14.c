//open/prayer/room/kiyan/14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	此處是明教分部之一的開陽門的練武場, 練武場上總教頭正嚴厲地
	指導著門生們努力練功。往北是開陽門的玄關, 進入後則是大廳。
	西邊與東邊兩側的走廊是分別通往總管與副門主的辦公房.

LONG);

        set("outdoors", "/open/prayer");
        set("no_fight", 0);
	set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"1-door",	//玄關
	"south":__DIR__"21",		//練武場
	"east":__DIR__"13",		//走廊
	"west":__DIR__"16",		//走廊
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general-officer" : 1,		//總教頭
   		
]));
        
          setup();
}
