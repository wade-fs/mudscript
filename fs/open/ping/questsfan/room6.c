// Room: /u/d/dhk/questsfan/room6
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "後山草叢");
  set ("long", @LONG
這裡就是大理平南城的後山，但是這裡的雜草又高又
長竟比你還高，足足有兩丈長。不過此地的風大的異常，
若不多虧這些草，說不定有被風吹倒的危險呢！

LONG);

  set("out_door", 1);
  set("no_transmit", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "out" : "q
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room5",
  "north" : __DIR__"qroom/room0",
]));

  setup();
}
