#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "船艙");
  set ("long", @LONG
除了木製的地板上由於受不了你的重量而多出了兩個破洞之外，這裡似乎什麼
東西也沒有，或許你應該往南邊前進吧。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"is15",
  "south" : __DIR__"b_r01",
]));

  setup();
}
