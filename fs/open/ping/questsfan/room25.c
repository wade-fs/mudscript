// Room: /u/d/dhk/questsfan/room25
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "圓晶層");
  set ("long", @LONG
這一區的結晶依然沒有顏色，但是卻非常特別的滿
地均是一顆顆渾圓剔透，光滑有緻的圓晶，若此時有另
一堆世界上最棒，評價最高的的珍珠與之相比。仍會遜
色許多。這正是善集天下奇珍異寶的天堂呀！如果天天
在此與這些圓晶對望，都不會感到厭煩呢！若硬要形容
它，那我只能用〝麗〞這一個字來形容。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room24",
  "westup" : __DIR__"room26",
]));

  setup();
}
