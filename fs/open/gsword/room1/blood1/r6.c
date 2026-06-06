#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "血魔堡");
  set ("long", @LONG
眼前所見為血魔新造的城堡，四周所見皆為血色，此地的道路也與一般道路不同
隱隱透出難以掩護的魔氣，不過在你眼裡確覺得格外舒服。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room1/blood1/r3.c",
  "south" : "/open/gsword/room1/blood1/r8.c",
//  "east" : "/open/gsword/room1/blood1/r8.c",
  "west" : "/open/gsword/room1/blood1/r2.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  setup();
}
