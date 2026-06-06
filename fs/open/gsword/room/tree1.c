#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "樹洞");
	set("long", "這是樹身的內部,走到這兒,你不禁皺了皺眉頭,前方一共岔出了三條路,每條路上似乎都
危機四伏,往哪兒走好呢??啊～這有個牌子(sign),看看不就知道該往哪走了,偶真是笨啊!
你使勁的拍了一下自己的大光頭.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/u/b/bigcat/room/ntree",
  "west" : "/u/b/bigcat/room/wtree",
  "south" : "/u/b/bigcat/room/tree",
  "east" : "/u/b/bigcat/room/etree",
]) );

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "  日木之為天
   雙士之為地
   一四之為人
",
]) );

  setup();
}
