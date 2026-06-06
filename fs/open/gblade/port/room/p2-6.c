// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
	set("short","楓林商店");
  set ("long", @LONG
這裡是楓林港最大的商店,各種貨物都聚集在此,你可以看看
這裡有些甚麼(list),交易(trade),還有估價(value).

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p2-1.c",
]));
  set("light_up", 1);

  setup();
}
