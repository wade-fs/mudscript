inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",YEL + "乾坤八卦塔" + NOR);
	set( "build", 12 );
	set("long",@LONG
一座筆直通雲霄的高塔，紅色的高頂和漆黑剝落的牆壁，正八角
個圍繞著中心，彷彿一座寶塔一般。
LONG);
	set("exits",([
"west":"/open/main/room/s18",
//"enter":__DIR__"p01",
]));
	setup();
}
