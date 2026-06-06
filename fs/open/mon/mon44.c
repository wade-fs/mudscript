inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "西峰道");
	set( "build", 2 );
  set ("long", @LONG
往西邊走，一是條較為平順的道路，兩旁的風景已是雪白一片，
幾乎看不到任何生物的蹤跡，淒冷的寒風更顯得路途的悲涼與大自然
的無情。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/snow-bear.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mon38",
  "west" : __DIR__"mon47",
]));

  setup();
}
