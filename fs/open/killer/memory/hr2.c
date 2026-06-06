#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "山林區");
  set ("long", @LONG

   巨大的林木，使得視野並不是很寬廣，但是仍然可以輕易的行走於其間
   但是樹林之間似乎總是有人在窺探著你，難道是隱身於其間的殺手？
   

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3   */
     "northeast" : __DIR__"hr3.c",
     "westsouth" : __DIR__"hr1.c",   
]));
  set("objects",([
  "/open/killer/npc/spy4.c":1,]));
  setup();
}
