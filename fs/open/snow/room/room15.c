#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
	set("short","走廊");
          set("long",@LONG
這裡是雪蒼派的內廳﹐裡頭的裝飾看起來有一段歷史了﹐由於
這裡是雪蒼派的根據地﹐這兒的建築有兩百多年﹐相傳雪蒼派
開山祖師當年開派時似乎有建造一些暗室密門之類的。
LONG);
        set("exits", ([
	"south":__DIR__"room13",
	"west":__DIR__"room16.c",
        ]) );
	set("objects",([
		SNOW_NPC"snow_guard":1,
	]));
	set("light_up",1);
        setup();
}
