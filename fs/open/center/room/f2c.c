// Room: /u/l/lotus/girl/f2c.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
掛了兩盞明晃晃的花燈, 煞是好看, 西面有一扇大窗, 你可以看
到外面的景色, 東面有一扇雕花木門.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"f2d.c",
  "south" : __DIR__"f2b",
  "east" : __DIR__"deyroom.c",
]));
  set("light_up", 1);
  create_door("east", "雕花木門", "west", DOOR_CLOSED);
  setup();
}
