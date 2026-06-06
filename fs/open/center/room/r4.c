// Room: /u/l/lotus/girl/r4.c
#include "/open/open.h"


#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "翠綠色的房間");
  set ("long", @LONG
一張收拾過的大床, 翠綠色的幛幕, 垂著流蘇, 茶几上有一瓶萬
年青. 靠牆邊有一個架子, 放了一對綠玉獅子, 和一個青磁花瓶.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : CENTER_ROOM"w2.c",
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"r4.c");
  create_door("north", "雕花木門", "south", DOOR_CLOSED);
  setup();
}
