//七星陣
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山崖小徑");
	set("long", @LONG
穿過小徑，來到此處視野大大的遼闊，而不
遠的前方可以看見一座斷橋，更激起了好奇的心
情，加快了腳步前行。

LONG
	);
	
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"g5-1",
	"east" : "/open/tendo/room/tower/bridge1",
]));
	set("outdoors", "1");

	setup();
}


