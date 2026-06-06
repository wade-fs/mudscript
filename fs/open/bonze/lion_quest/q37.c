inherit ROOM;
#include "bonze.c"

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
這是一條通往後山的林間小徑。
LONG);

  set("light_up", 1);
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"q38.c",
    "south" : __DIR__"q13.c",
	]));

  setup();
}
