inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIC"火神舞幻空"NOR);
	set("long",@LONG
你踏入了石屋內的某一個房間中，四周並沒有牆壁，若硬是要說
是的話，四周那流動的七彩光應該就算是了吧。
LONG);
	set("objects",([
__DIR__"npc/rose_finch":1,
]));
	set("exits",([
"west":__DIR__"t01",
]));
	setup();
}
