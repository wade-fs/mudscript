// Room: /open/dancer/room/r5-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","山丘");
  set ("long", @LONG
你身處在山丘之上，在你的東邊是一條小路，北方是草原而南方
則可遠遠看到村莊，西方數里外則是海洋了。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/dancer/room/r5-3.c",
]));

  set("light_up", 1);

  setup();
}
