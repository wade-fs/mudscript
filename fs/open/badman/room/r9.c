// Room: /open/badman/room/r9

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "金庫內部");
  set ("long", @LONG
還沒想到....:b

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r8",
]));
  create_door("north", "鐵門", "south", DOOR_LOCKED);

  setup();
}
