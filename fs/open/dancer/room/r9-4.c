// Room: /open/dancer/room/r9-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","小路");
  set ("long", @LONG
你正走在山野小路之中，這裡離村莊較遠了，你的南方是一大片
的草原，遠方則是一片森林。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/dancer/room/r10-4.c",
  "west" : "/open/dancer/room/r9-3.c",
]));

  set("light_up", 1);

  setup();
}
