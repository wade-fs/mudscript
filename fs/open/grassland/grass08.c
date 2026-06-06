#include <room.h>
inherit ROOM;
#include "grass_msg.c"

void create()
{
        set("short","蒙古草原");
        set("long", (: printf_msg :) );
        set("outdoors", 1);
        set("exits", ([
		"west":__DIR__"grass09",  
        "south":__DIR__"grass05",
        "north":__DIR__"grass11",
		"east":__DIR__"grass07",
        ]) );
		set("objects",([ 
        __DIR__"npc/tiger" : 1,]));
  setup();
}


