// Room: /u/l/lotus/girl/w4.c
#include "/open/open.h"

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "後院");
  set ("long", @LONG
放了很多雜七雜八的東西, 舊的蒸籠, 破損的椅子, 歪斜又缺角
的桌子 ....
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r7.c",
  "west" : __DIR__"w5.c",
  "east" : __DIR__"tin2",
]));
  set("outdoors", "/u/l");
  set("file_name", __DIR__"w4.c");
  create_door("east", "木門", "west", DOOR_CLOSED);
  setup();
}
