#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
       set("long","一個陰森森的洞穴內﹐在這裡只有極微弱的光線﹐你勉強可以看到出口。\n");
        set("exits", ([
		"north":__DIR__"room3",
        ]) );
	set("light_up",1);
        setup();
}
