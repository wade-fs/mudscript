// copy from Room: /d/snow/hockshop.c

#include "/open/capital/capital.h"

inherit HOCKSHOP;

void create ()
{
  set ("short", "乾記當鋪");
  set ("long", @LONG
當初乾通天的曾祖父在替波羅王打下天下之後，決意不為朝當官，
故波羅王就賞賜許多的銀兩，並要求他留在京城，所以乾通天才會有今
天的財富與地位。這個當鋪也是他的資產之一，是由副總管哈常貴負責
管理，在這你可以典當(pawn)，當然也可以贖回(redeem)你還可以是先
詢問物品的價值(value)。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/ha" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/capital/room/h16",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "	在這裡你可以典當(pawn)物品或者贖回(redeem)典當
	在這兒的物品，也可以鑑定(value)物品的價值。
",
]));

  set("save_file","/data/hockshop");

  setup();
}
