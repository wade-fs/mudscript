//七星陣
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山崖小徑");
	set("long", @LONG
撥開重重的芒草之後，來到此處可以見到兩
旁已經漸漸的被高聳的峭壁給取代了，前方只剩
下唯一的一條小路可以通行。

LONG
	);
	
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"g5",
	"east" : __DIR__"g5-1",
]));
	set("outdoors", "1");

	setup();
}


