// Room: /u/l/lotus/girl/r9.c

#include <room.h>
#include "/open/open.h"


inherit ROOM;

void create ()
{
  set ("short", "柴房");
  set ("long", @LONG
堆放柴火的房間, 一個小女孩哭哭啼啼的坐在地上, 看起來有些
狼狽。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"w6.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  CENTER_NPC"nini.c" : 1,
]));
  create_door("north", "雕花木門", "south", DOOR_CLOSED);
  setup();
}
