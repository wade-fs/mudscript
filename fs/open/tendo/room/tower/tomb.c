inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "葬劍亭");
	set("long", @LONG
你現在來到一個山腰靠近山頂的亭子，亭子前立著一個兩丈多高的
石碑，從亭子裡遠眺北方連綿不盡的大山，使你不禁感到胸臆之間一股
英雄情懷油然而生，葬劍亭據說每到夏日夜晚，野風吹過，會產生一陣
陣嗚嗚的哭泣聲。
LONG
	);
	
                          
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/tendo/room/tower/water",
  "south" : "/open/tendo/room/tower/tree3",
  "up" : "/open/tendo/room/tower/make1",
]));
	set("no_clean_up", 0);
        set("outdoors",1);
	setup();
}


