#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "七星塔");
	set( "build", 12 );
  set ("long", @LONG
一座六角木塔聳立在你眼前,塔雖不高,伴隨著塔旁的
松柏古杉,卻顯得典雅飄逸,你仔細觀察這塔,竟找不到
一根螺絲,這可是利用高度建築技巧所建成的塔呢!!!
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"froad0",
  "enter" : "/open/gsword/star/room/room1.c",
]));
  set("light_up", 1);

  setup();
}
