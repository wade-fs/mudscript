#include <room.h>
inherit ROOM;
#include "grass_msg.c"

void create()
{
        set("short","蒙古草原");
        set("long", (: printf_msg :) );
        set("outdoors", 1);
        set("exits", ([
        "south":__DIR__"grass12",
        "north":__DIR__"grass18",
		"west":__DIR__"grass14",
        ]) );
  setup();
}


