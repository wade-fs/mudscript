#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "迴廊");
  set ("long", @LONG
走進這裡, 是一條長廊, 往西通往大師兄柳毅風的住處, 往南則
是前庭及迴廊, 迴廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"np17",
  "west" : __DIR__"np21",
  "east" : __DIR__"np13",
]));
  set("light_up", 1);

  setup();
}
