// Room: /open/dancer/room/r4-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","草原");
  set ("long", @LONG
你身處一處草原之中，你的東邊是一條小路，北方是一大片森林
，而南方看來是一座山丘，不過由於茂密的樹林所阻擋，你無法由此
爬上山丘。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/dancer/room/r4-3.c",
  "north" : "/open/dancer/room/r3-2.c",
]));

  set("light_up", 1);

  setup();
}
