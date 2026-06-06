// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
	set ("short", "小商行");
  set ("long", @LONG
  這裡是崑崙山唯一的商行,在這你可以估價(value),
賣斷(sell),交易買貨(buy),並可以察看這裡有什麼
貨品待售(list).
LONG);

  set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"v2",
]));

  set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/keeper" : 1,
]));

  set("light_up", 1);

  setup();
}
