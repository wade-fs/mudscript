// Room: /u/l/lotus/girl/tin2.c
#include "/open/open.h"

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "後院門口");
  set ("long", @LONG
東面客人喝花酒喧鬧的聲音一陣一陣傳來, 西面有一道門通往後
院。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"tin1.c",
  "west" : __DIR__"w4.c",
  "east" : __DIR__"guest4.c",
]));
  set("light_up", 1);
  create_door("west", "木門", "east", DOOR_CLOSED);
  setup();
}
