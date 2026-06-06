#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "迴廊");
  set ("long", @LONG
走進這裡, 是一條迴廊, 往前通往前庭及大廳, 而往兩旁也各有
一條走道, 迴廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"np3",
  "north" : __DIR__"np4",
    "out" : __DIR__"pingking",
  "east" : __DIR__"np2",
]));
  set("light_up", 1);

  setup();
}
