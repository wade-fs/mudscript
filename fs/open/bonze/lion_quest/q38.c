inherit ROOM;
#include "bonze.c"

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
這是一條通往後山的林間小徑，茂密的矮樹叢與高大原始的山林是
這裡的主色調。風景絕佳景色優美，放眼望去鳥語花卉美不勝收，偶爾
會在這裡巧見樹蛙、蝴蝶、飛鷹…等原生生態下活躍的生物。

LONG);

  set("light_up", 1);
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"q37.c",
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b0_obj_root.c" : 1,
  ]));
  setup();
}
