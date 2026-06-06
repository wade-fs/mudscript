#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU + "死靈幽谷" + NOR);
set("long",@LONG
四周岩壁給了你一種壓迫感，你摸黑著四周並無
發現任何奇特的出入口，除了往上的通道跟往下的路
外，你似乎也無所選擇了。
LONG);
set("exits",([
"up":__DIR__"g-h02",
"down":__DIR__"g-h04",
]));
set("no_transmit",1);
setup();
}
