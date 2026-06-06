// Room: /open/dancer/room/r13-1.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","花叢");
  set ("long", @LONG
你發現你的四周滿是花朵，恍如置身花海之中，有些甚至是你從
未看過之品種，令你不禁以為到了世外桃園之中。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/dancer/room/r13-2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/water_girl.c" : 1,
]));
  set("light_up", 1);

  setup();
}
