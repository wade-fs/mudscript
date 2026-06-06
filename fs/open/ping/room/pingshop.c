// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
  set ("short", "平南商店");
  set ("long", @LONG
這裡是平南城最大的商店,各總貨物都聚集在此,你可以看看
這裡有些甚麼(list),交易(sell),還有估價(value).
也可以看看這裡有賣那些種類的東西(view)
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road2",
]));
  set("light_up", 1);

  setup();
}
