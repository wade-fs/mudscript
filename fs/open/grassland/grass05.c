#include <room.h>
inherit ROOM;
#include "grass_msg.c"

void create()
{
        set("short","蒙古草原");
        set("long", (: printf_msg :) );
        set("outdoors", 1);
        set("exits", ([
		"west":__DIR__"grass04",  
        "south":__DIR__"grass02",
        "north":__DIR__"grass08",
        "east":__DIR__"grass06",		
        ]) );
  setup();
}


