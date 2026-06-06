// Room: /u/d/dhk/questsfan/rm9
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "雲霧松林");
  set ("long", @LONG
松林蔽日、雲霧迷濛、松果滿地，這兒最奇怪的是一片大松林
竟沒看到半株莖幹，格外特別。不時有幾隻罕見的六尾松鼠狂奔而
過，不然就是昆蟲的鳴叫聲，特別的是牠們的一起突然的大鳴，然
後再一起的安靜，那一起突發的鳴叫聲真是相當令人震撼的。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"rm16",
  "southdown" : __DIR__"rm8",
  "northup" : __DIR__"rm17",
  "eastup" : __DIR__"rm10",
]));
  set("outdoors", "/u/d");

  setup();
}
