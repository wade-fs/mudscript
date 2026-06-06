#include <room.h>
inherit ROOM;
#include "grass_msg.c"

void create()
{
        set("short","蒙古草原");
        set("long", (: printf_msg :) );
        set("outdoors", 1);
        set("exits", ([
        "north":__DIR__"grass06",
        "west":__DIR__"grass02",
        "south":__DIR__"grass00",			
        ]) );
  setup();
}


