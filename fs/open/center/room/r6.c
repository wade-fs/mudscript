// Room: /u/l/lotus/girl/r6.c
#include <room.h>

#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "紫色的房間");
  set ("long", @LONG
一張收拾過的大床, 淡紫色的幛幕, 垂著流蘇, 茶几上有一大瓶
盛放天堂鳥, 整個房間給人一種熱情如火, 透不過氣來的感覺.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : CENTER_ROOM"w3.c",
]));
  set("light_up", 1);

  create_door("north", "雕花木門", "south", DOOR_CLOSED);
  setup();
}
