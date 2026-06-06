#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU + "死靈幽谷" + NOR);
set("long",@LONG
黑暗的空間與周圍的岩壁一直給你一種無法言喻的
壓迫感, 再加上這裡的岩壁似乎特別的潮濕, 讓你有一
種揮之不去的厭惡感...
LONG);
set("exits",([
"down":__DIR__"g-h07",
]));
set("no_transmit",1);
setup();
}
