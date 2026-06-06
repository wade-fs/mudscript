// Room: /open/ping/room/p5
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG
這兒是段王爺特別撥出來的一間房間, 作為段家子弟休息的房間, 
因此除了段家的人以外, 別的人是進不來的。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"p2",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan3" : 1,
]));
  set("no_magic", 1);

  setup();
}
