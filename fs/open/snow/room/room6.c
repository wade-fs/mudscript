#include <room.h>

inherit ROOM;

void create()
{
            set("short","內廳");
	set( "build", 12 );
          set("long",@LONG
這裡是雪蒼派的內廳，裡頭的裝飾看起來有一段歷史了，由於這
裡是雪蒼派的根據地，這兒的建築有兩百多年，相傳雪蒼派開山祖師
當年開派時似乎有建造一些暗室密門之類的。
LONG);
        set("exits", ([
		"south":__DIR__"room2",
		"west":__DIR__"den_room",
		"east":__DIR__"room7",
		"north":__DIR__"room8",
        ]) );
	set("light_up",1);
        setup();
}
