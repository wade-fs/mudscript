//本房間設定為特殊福利房間 會多呼叫一隻mob
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
    "east" : __DIR__"q34.c",
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b0_obj_butterfly.c" : 1,
  ]));
  setup();
}
