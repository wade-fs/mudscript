
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","蛇寨 地下室");
        set("long",@LONG
繩索由上垂吊而下，除了往上椅外，週遭都是石壁包圍著。
LONG);
        set("no_transmit",1);
        set("exits",([
"up":__DIR__"r-46",
"down":__DIR__"r-44",
]));
        setup();
}
