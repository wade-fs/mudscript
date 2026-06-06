// Room: /open/dancer/room/r11-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你身處在楓樹林之中，所見之處幾乎都是楓樹，但是並非十分茂
盛，四周事物仍清悉可見。四周的楓樹每到秋天，那滿天火紅想必十
分壯麗吧。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/dancer/room/r10-2.c",
  "west" : "/open/dancer/room/r11-1.c",
  "east" : "/open/dancer/room/r11-3.c",
]));

  set("light_up", 1);

  setup();
}
