// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
  set ("short", "蜀中商店");
	set( "build", 366 );
  set ("long", @LONG
這裡是蜀中城最大的商店,在這你可以估價(value),
賣斷(sell),交易買貨(buy),並可以察看這裡有什麼
貨品待售(list).也可以看看這裡有賣那些種類的東西(view)
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/su3",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/keeper" : 1,
]));

  set("light_up", 1);

  setup();
}
