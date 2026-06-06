///open/prayer/room/tanchun/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	這裡是天權門的議事廳，往南則是玄關, 你可以打開木雕門(open 
	 door)．大廳出去後是天權門的練武場．往北則是到門主的寶座．
	兩旁站著許多教頭級以上的幹部，個個面無表情! 

LONG );
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"5",		//議事廳
        "south":__DIR__"1-door",	//玄關
        "east":__DIR__"7",		//議事廳
        "west":__DIR__"9",		//議事廳
        ]) );

        set("light_up", 1);
        create_door("south","聖火刻紋木雕門", "north",DOOR_CLOSED);
   setup();
}
