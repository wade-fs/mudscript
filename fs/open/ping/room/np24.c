#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "後堂");
  set ("long", @LONG
走進這裡, 是一間偏廳, 往回則通往大廳, 兩旁各有一條走道,
長廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"np28",
  "east" : __DIR__"np23",
]));
  set("light_up", 1);

  setup();
  replace_program(ROOM);
}
