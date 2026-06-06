// Room: /open/dancer/room/r12-3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","樹林");
  set ("long", @LONG
你身處在楓樹林之中，放眼望去盡是一片樹海，茂密的樹木幾乎
將陽光完全阻擋，只有些許光線由樹縫中射入。不禁令你懷疑是否走
到了與世隔絕之地。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/dancer/room/r13-3.c",
  "north" : "/open/dancer/room/r11-3.c",
  "west" : "/open/dancer/room/r12-2.c",
]));

  set("light_up", 0);

  setup();
}
