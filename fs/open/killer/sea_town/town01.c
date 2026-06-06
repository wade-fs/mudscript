inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "南村門");
  set ("long", @LONG
這裡是南村門!!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beach08.c",
]));

  setup();
}
