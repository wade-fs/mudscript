inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "白懷峰");
	set( "build", 23 );
  set ("long", @LONG
長白山著名的三峰之一，站在此地，視野所及的，只有美不勝收
能形容，在三峰之間有一個天池，但是原本的池水因經年累月，已經
乾涸了不少，在原本乾涸的地方卻長出了一片草原，登上最高峰，可
以觀賞到更美的景色。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bear.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "stand" : __DIR__"mon49",
  "south" : __DIR__"mon46",
]));

  setup();
}
