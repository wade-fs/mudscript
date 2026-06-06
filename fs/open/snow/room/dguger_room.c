#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","諸葛草蘆");
  set ("long", @LONG
這裡是神算先生諸葛臥龍的住處﹐只看見牆上懸掛
的都是一些有關於八卦、大極、星相、面相等等占卜一
類的東西﹐這也是為何諸葛臥龍會有「神算先生」的名
號的原因。

LONG);

  set("exits", ([ /* sizeof() == 3 */
	"west" : "/open/snow/room/room3",
]));

  set("objects",([
	"/open/snow/npc/dguger" : 1,
	]));
  set("light_up", 1);
  set("no_transmit", 1);

  setup();
}
