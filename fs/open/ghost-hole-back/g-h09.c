#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU"死靈幽谷"NOR);
set("long",@LONG
地上堆滿了許多的食物與茶, 這裡可能是居住在
這裡人的食物儲藏室, 這裡的空氣似乎比其他的地方
還來的冷, 難怪會被選作儲藏食物的地方...
LONG);
set("outside",1);
set("exits",([
"east":__DIR__"g-h08",
]));
set("objects",([
"/obj/example/chicken_leg":1,
"/open/capital/obj/tea":1,
]));
set("no_transmit",1);
setup();
}
