//七星陣
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "荒草小徑");
	set("long", @LONG
小徑的小旁盡是長的比人還高的芒草，已漸
漸的分不清路的方向，神秘的氣息由東邊的方向
傳來，讓你忍不住好奇的心情想要一探究竟。

LONG
	);
	
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"g3",
	"east" : __DIR__"g5",
]));
	set("outdoors", "1");

	setup();
}


