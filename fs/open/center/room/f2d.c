// Room: /u/l/lotus/girl/f2c.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
掛了兩盞明晃晃的花燈, 煞是好看西面有一扇大窗, 你可以看到
外面的景色, 東面有一扇雕花木門
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f2c.c",
  "east" : __DIR__"chaoroom.c",
]));
  set("light_up", 1);
  create_door("east", "雕花木門", "west", DOOR_CLOSED);
  setup();
}
