// Room: /open/dancer/room/r3-3.c :cgy
//關閉路徑 by blazakira 2011/9/11

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "樹林");
  set ("long", @LONG
你身處在樹林之中，所見之處幾乎都是樹木，但是並非十分茂盛
，四周事物仍清悉可見。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 3 */
//    "north" : "/open/clan/wind/room/room61.c", //幫派已未開放 故關閉之 by blazakira
    "east" : __DIR__"r3-4.c",
    "west" : __DIR__"r3-2.c",
  ]));

  setup();
}
