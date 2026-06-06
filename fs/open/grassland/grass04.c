#include <room.h>
inherit ROOM;
#include "grass_msg.c"

void create()
{
        set("short","蒙古草原");
        set("long", (: printf_msg :) );
        set("outdoors", 1);
        set("exits", ([
        "south":__DIR__"grass03",
        "north":__DIR__"grass09",
        "east":__DIR__"grass05",		
        ]) );
  setup();
}


