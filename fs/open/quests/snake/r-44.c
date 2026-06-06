inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","蛇寨 地下室");
	set("long",@LONG
牆上的火把將這裡給照亮了許多，你身後有一座蛇型雕刻的門扇
，不過門扇已經關閉了，而眼前又有一個繩索，由上垂吊而下，似乎
是通往地面唯一的方法。
LONG);
	set("no_transmit",1);
	set("exits",([
"up":__DIR__"r-45",
]));
	setup();
}
