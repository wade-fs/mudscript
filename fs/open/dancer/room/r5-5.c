// Room: /open/dancer/room/r5-5.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","山林");
  set ("long", @LONG
你身處在山丘之上，四周乃是一大片的樹林幾乎將你的視線完全
擋住，你心中不禁感到毛骨悚然。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/dancer/room/r5-4.c",

]));

  set("light_up", 0);

  setup();
}
