inherit ROOM;
#include <ansi.h>
void create ()
{
set("short",YEL"幽冥道"NOR);
set("long",@LONG
一陣寒冷的陰風緩緩吹過, 四周的景象十分的
詭異, 似乎不像是在人間一般, 彷彿置身在某種生
物的體內...
LONG);
set("exits",([
"east":__DIR__"g-r02",
]));
set("no_transmit",1);
setup();
}
