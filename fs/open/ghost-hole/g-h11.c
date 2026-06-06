#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU + "死靈幽谷" + HIW + "€白洞€" + NOR);
set("long",@LONG
你下定決心的來到了死靈骨魔的領地, 四周的
岩壁都不見了, 取而代之的是光亮的空間, 周圍亮
光四射, 景色彷彿一片白晝, 無限的向四周延伸, 
一片白亮....
LONG);
set("exits",([
"north":__DIR__"g-h12",
"south":__DIR__"g-h12",
"east":__DIR__"g-h12",
"west":__DIR__"g-h12",
]));
set("no_transmit",1);
setup();
}
