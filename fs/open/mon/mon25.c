inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "盤天巨木");
	set( "build", 14 );
  set ("long", @LONG
突然你的眼前為之一亮，一棵高聳入雲的巨木樹立在你眼前，巨
大的樹身快將光線遮的一絲不透，令這裏看來有些些的陰寒，仔細看
看樹身，有一個洞可以進入這巨大的樹身之中。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fox.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"mon58",
  "east" : __DIR__"mon22",
]));

  setup();
}
