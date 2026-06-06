// Room: /open/dancer/room/r9-5.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","山林");
  set ("build", 12 );
  set ("long", @LONG
你身處在山丘之上，在你的西邊隱約可看見一條小路，然而你卻
無法由西邊穿越樹林，東邊則是陡峭的山崗。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/dancer/room/r8-5.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/poison_girl.c" : 1,
]));
  set("light_up", 1);

  setup();
}
