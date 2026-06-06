// Room: /open/dancer/room/r13-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","花叢");
  set ("build", 12 );
  set ("long", @LONG
你發現你的四周滿是花朵，恍如置身花海之中，有些甚至是你從
未看過之品種，令你不禁以為到了世外桃園之中。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/r12-2.c",
  "west" : "/open/dancer/room/r13-1.c",
]));

  set("light_up", 1);

  setup();
}
