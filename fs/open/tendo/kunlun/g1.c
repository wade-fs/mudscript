//七星陣
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "庭園");
	set("long", @LONG
一間裝設典雅的庭院，附近的建材都是以崑
崙山百年老木做成，典雅中帶著幾分樸素。這庭
園中種滿了各式各樣的奇花異草，四周不時還飄
散著淡淡的花香。

LONG
	);
	
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"c8",
	"east" : __DIR__"g2",
	"enter" : "/open/tendo/room/t03",
]));
	set("outdoors", "1");

	setup();
}


