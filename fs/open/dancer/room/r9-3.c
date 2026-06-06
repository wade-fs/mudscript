// Room: /open/dancer/room/r9-3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","小路");
  set ("long", @LONG
你正走在山野小路之中，北邊是座小村莊，從這裡你可以開始你
的鏡月之旅，去探索這神秘的土地。小路向東延伸過去。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/dancer/room/r9-4.c",
  "north" : "/open/dancer/room/r8-3.c",
]));

  set("light_up", 1);

  setup();
}
