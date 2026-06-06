//七星陣
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "庭園小徑");
	set("long", @LONG
西邊是通往庭園，東邊則是走往更荒涼的一
條小徑，兩旁的荒草已經長的比人還要高了，可
見平常已經鮮少人經過這裡。

LONG
	);
	
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"g2",
	"east" : __DIR__"g4",
]));
	set("outdoors", "1");

	setup();
}


