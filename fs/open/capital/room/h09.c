// Room: /open/capital/room/h09.c

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "芝麻胡同");
	set( "build", 48 );
  set ("long", @LONG
這裡已接近胡同底了, 不過人潮似乎還多了一點, 原因就是乾通天
在這開了一家商行和錢莊, 買進賣出的, 人潮與貨物川流不息, 為芝麻
胡同增添另一種生氣。南邊有家錢莊，北邊則是商店。

LONG);

  set("objects", ([ /* sizeof() == 2 */
   CAPITAL_NPC"duan5" : 1,
   CAPITAL_NPC"duan12" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cshop.c",
  "west" : __DIR__"r25.c",
  "south" : __DIR__"cbank.c",
  "east" : __DIR__"h10",
]));

  setup();
}
