// Room: /u/l/lotus/girl/w2.c
#include "/open/open.h"

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
掛了兩盞明晃晃的花燈, 煞是好看。南面和北面各有一道雕花木
門。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r4.c",
  "north" : __DIR__"r3.c",
  "west" : __DIR__"w3.c",
  "east" : __DIR__"w1.c",
]));
  set("light_up", 1);
  create_door("south", "雕花木門", "north", DOOR_CLOSED);
  create_door("north", "雕花木門", "south", DOOR_CLOSED);
  setup();
}
