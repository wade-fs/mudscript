// Room: /open/dancer/room/r10-5.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","山林");
  set ("long", @LONG
你身處在山丘之上，除了西邊之外四周乃是一大片的樹林幾乎將你的
視線完全擋住，你心中不禁感到毛骨悚然。


LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/dancer/room/r10-4.c",
]));

  set("light_up", 0);

  setup();
}
