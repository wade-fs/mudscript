// Room: /open/dancer/room/r12-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你的四周是一片楓樹林，而放眼望去東邊則是陡峭的山丘，山丘
上同樣是密佈的楓樹。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/dancer/room/r11-4.c",
]));

  set("light_up", 1);

  setup();
}
