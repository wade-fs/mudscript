// Room: /open/center/room/r10.c
#include "/open/open.h"

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "樂器房");
  set ("long", @LONG
收藏了巧心姑娘的樂器, 丫嬛蘋兒正逐一擦拭, 不時的拿起樂器
把玩. 蘋兒看見你闖了進來, 吃驚的看著你.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tin4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  CENTER_NPC"ping.c" : 1,
]));
  set("light_up", 1);
  create_door("north", "雕花木門", "south", DOOR_CLOSED);
  setup();
}
