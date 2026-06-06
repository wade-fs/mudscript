inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIC"晶樂閣"NOR);
	set("long",@LONG

四周淡藍的水晶波瀾四處遊晃，由淡藍水晶圍繞而成的空間，令人有
種置身世外桃源，寰宇於世外之境。
淡藍水晶猶如走道兩側，筆直佇立於兩旁。

LONG);
	set("exits",([
"north":__DIR__"m02",
"south":__DIR__"m04",
]));
	setup();
}
