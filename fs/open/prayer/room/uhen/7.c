//open/prayer/room/uhen/7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	此處是玉衡門成員討論問題的所在，往南則是玉衡門的
	玄關 (open door)．出去大廳後便是玉衡門的練武場．
	往北則是到門主的寶座．兩旁站著許多高階的幹部，個
	個面無表情!

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"4",		//門主
        "south":__DIR__"1-door",		//玄關
        "east":__DIR__"6",			//議事廳
        "west":__DIR__"8",			//議事廳
        ]) );

        set("light_up", 1);
        create_door("south","聖火刻紋木雕門", "north",DOOR_CLOSED);
   setup();
}
