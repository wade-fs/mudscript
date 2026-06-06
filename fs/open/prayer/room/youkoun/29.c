//open/prayer/room/youkoun/29.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","牢房");
        set("long",@LONG

        裡面有一位男子, 身形雖然高大, 可是被困於此
	長年累月下來也會變得駝背了!!手上套著鐵鍊,
	再加上全身傷痕累累, 行動頗為不便!!
		
LONG);

        set("exits", ([ /* sizeof() == 1 */
        "up":__DIR__"26",    
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/youkoun-man" : 1,           //燕十一
        ]));
                
  setup();
}

