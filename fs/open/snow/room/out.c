#include <room.h>

inherit ROOM;

void create()
{
        set("short","洞穴外");
         set("long","這裡是洞穴的外面﹐似乎這裡已不在蜀中城內﹐在前方不遠處可以看一座雪蒼山。\n");
        set("exits", ([
		"south":__DIR__"hole3",
        ]) );
	set("light_up",1);
        setup();
}
