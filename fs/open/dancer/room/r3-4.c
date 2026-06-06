// Room: /open/dancer/room/r3-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你的四周是一片樹林，而放眼望去東邊則是陡峭的山丘，山丘上
同樣是密佈的樹林。心中不由開始害怕，不知會不會有野獸跑下山來
。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/dancer/room/r4-4.c",
  "north" : "/open/dancer/room/r2-4.c",
  "west" : "/open/dancer/room/r3-3.c",
]));

  set("light_up", 1);

  setup();
}
