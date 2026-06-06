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
    "east" : __DIR__"q33.c",
    "west" : __DIR__"q14.c",
	]));

  setup();
}
