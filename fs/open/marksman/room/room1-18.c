// Room: /u/f/fire/room/room1-18.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"

void create ()
{
  set ("short", "天龍客棧二樓");
  set ("long", @LONG
這裡是天龍客棧的二樓，給過路的旅客們歇歇腳用的。在這裡你
可以遇到武林人士。靠窗臺的地方擺了約莫七、八副桌椅，擦得光亮
鑑。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/small-two" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"room1-17",
  "enter" : __DIR__"room3-1",
]));

  setup();
}
