
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "血魔堡二樓");
  set ("long", @LONG
此地為血魔堡二樓，由於越來越接近血魔主城，故地上殘骸
也比一樓多出許多，可見當年大戰之慘狀。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room1/blood/room2/r5.c",
  "south" : "/open/gsword/room1/blood/room2/r9.c",
  "east" : "/open/gsword/room1/blood/room2/r7.c",
  "west" : "/open/gsword/room1/blood/room2/r3.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  setup();
}
