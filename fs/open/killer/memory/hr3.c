#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "山林區");
  set ("long", @LONG

   巨大的林木，使得視野並不是很寬廣，但是仍然可以輕易的行走於其間
   但是樹林之間似乎總是有人在窺探著你，難道是隱身於其間的殺手？
   前方似乎看來似乎傳來湖光水色...........
   

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3   */
     "north" : __DIR__"lk6.c",
     "westsouth" : __DIR__"hr2.c",   
]));
  set("objects",([
  "/open/killer/npc/magnpc1.c":2,]));
  setup();
}
