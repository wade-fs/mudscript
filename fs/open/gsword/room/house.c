#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "簡陋的竹屋");
	set("long", "這屋子內除了幾張桌椅，空盪盪一無所有，不過酒倒是堆滿了牆的一角，地上還留有
一些破碎的酒罈碎片，和一大灘的酒水，可見得這屋子的主人嗜酒成性，以到了如癡
如狂的地步了。
");

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc/drunkard.c" : 1,
]) );

  set("outdoors", "n" );

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"rroad3",
]) );


  setup();
}
