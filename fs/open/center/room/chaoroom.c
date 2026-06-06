// Room: /u/l/lotus/girl/chaoroom.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "巧心姑娘的房間");
  set ("long", @LONG
簡單雅致的房間, 四處收拾的一塵不染, 漂亮的桌巾椅墊吸引了
你的目光, 鵝黃色的底, 配上些許手工細緻的刺繡, 十分典雅出色,
竹製的家具, 看來格外出塵.
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"f2d.c",
]));
  set("light_up", 1);
  set("file_name", __DIR__"chaoroom.c");
  create_door("west", "雕花木門", "east", DOOR_CLOSED);
  setup();
}
