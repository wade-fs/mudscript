// Room: /u/f/fire/room/room1-9.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
這是一條相當寬敞的道路，在道路兩旁佇立著用黃銅所鑄成的李
廣大人的銅像，栩栩如生且威風凜凜不禁讓人感到它的神聖威嚴，你
可以看到長沙城此地熱鬧無比。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/sells2.c" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room1-13.c",
  "west" : __DIR__"room1-11.c",
  "south" : __DIR__"room1-8",
  "east" : __DIR__"room1-15.c",
]));

  setup();
}
