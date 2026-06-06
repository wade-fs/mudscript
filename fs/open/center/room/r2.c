// Room: /u/l/lotus/girl/r2.c
#include "/open/open.h"


#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "橙色的房間");
  set ("long", @LONG
一張收拾過的大床, 橙色的幛幕, 垂著流蘇. 桌子上有一大瓶梔
子花. 戶外的陽光透過橙色的窗簾射進來,令你有一種十分溫馨的感
覺.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : CENTER_ROOM"w1.c",
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"r2.c");
  create_door("north", "雕花木門", "south", DOOR_CLOSED);
  setup();
}
