#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU + "死靈幽谷" + NOR);
set("long",@LONG
四周的岩壁不斷的流出冰冷的泉水, 你稍微嚐了
一下, 泉水裡面挾帶著許多的砂石, 根本不能喝, 隱
隱約約之間, 你彷彿聽到了人的哀嚎聲, 真不敢相信
這裡會有人居住!!
LONG);
set("exits",([
"up":__DIR__"g-h05",
"down":__DIR__"g-h08",
]));
set("no_transmit",1);
setup();
}
