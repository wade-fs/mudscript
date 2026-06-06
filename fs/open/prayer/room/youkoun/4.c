///open/prayer/room/youkoun/4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

	此處是瑤光門成員討論問題的所在，往南則是瑤光門
	的玄關．出去大廳後便是瑤光門的練武場．往北則是
	到門主的寶座．兩旁站著許多高階的幹部，個個面無
	表情!

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"2",		//門主
        "south":__DIR__"10",		//練武場
        "northeast":__DIR__"1",			
        "northwest":__DIR__"3",			
        ]) );

        set("light_up", 1);
   setup();
}
