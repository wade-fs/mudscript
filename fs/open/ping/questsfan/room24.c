// Room: /u/d/dhk/questsfan/room24
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "方晶層");
  set ("long", @LONG
這一區的結晶就規則多了，全是長方形式的結晶，
大大小小雖然不同。但是若取之排列想必是造石屋 (還
是高級的那種) 的好建材吧！雖然此地的結晶依然沒有
絢麗的顏色，但是它們具有方正、井然有序的氣質。若
硬要形容它，那我只能用〝雅〞這一個字來形容。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room23",
  "north" : __DIR__"room25",
]));

  setup();
}
