#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU"死靈幽谷"NOR);
set("long",@LONG 
在冰冷的岩壁旁, 坐著一個十頹廢的老人, 一動也
不動的與你對視, 他那空洞的眼神讓你有種冰冷的感覺
, 地上都是他的排泄物, 看來他似乎沒有離開過這裡, 
也似乎也沒有離開這裡的打算...
LONG);
set("outside",1);
set("objects",([
__DIR__"npc/oldman":1,
]));
set("exits",([
"west":__DIR__"g-h08",
]));
set("no_transmit",1);
setup();
}
