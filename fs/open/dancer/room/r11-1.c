// Room: /open/dancer/room/r11-1.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你身處在楓林之中，放眼望去盡是一片樹海，茂密的樹木幾乎將
陽光完全阻擋，只有些許光線由樹縫中射入。然而你耳邊卻清悉可聞
海浪之聲，你心想也許是快到海邊了吧。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/dancer/room/r11-2.c",
]));

  set("light_up", 0);

  setup();
}
