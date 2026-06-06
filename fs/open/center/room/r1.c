// Room: /u/l/lotus/girl/r1.c
#include "/open/open.h"


#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "粉色的房間");
  set ("long", @LONG
一張收拾過的大床, 粉色的幛幕, 垂著流蘇, 茶几上有一瓶裝著
水的薔薇, 粉色的桌巾上也繡了大大小小的薔薇.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : CENTER_ROOM"w1",
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"r1.c");
  create_door("south", "雕花木門", "north", DOOR_CLOSED);
  setup();
}
