// Room: /u/l/lotus/girl/r5.c
#include "/open/open.h"


#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "清爽的房間");
  set ("long", @LONG
一張剛收拾過的大床, 天藍色的幛幕, 垂著流蘇, 地毯也是天藍
色的, 茶几上有一瓶藍色的小花.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : CENTER_ROOM"w3.c",
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"r5.c");
  create_door("south", "雕花木門", "north", DOOR_CLOSED);
  setup();
}
