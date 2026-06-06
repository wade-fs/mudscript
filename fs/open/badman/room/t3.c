// Room: /open/badman/room/t3.c

#include "../badman.h"

inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG
地道中的藤蔓一直蔓延到這裡，數量多的驚人，你注意到有一
處藤蔓(rattan)長的似乎特別的密。前面仍然是一片黑暗，不知道
會有什麼樣的東西在等著你....

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "rattan" : "這裡的藤蔓似乎長的特別的茂密，密到完全掩蓋\住了山壁。
",
]));

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/badman/room/t2",
  "east" : "/open/badman/room/t7",
]));

  set("search_desc", ([ /* sizeof() == 1 */
  "rattan" : "你撥開藤蔓，猛然發現後面竟然有個通道，但從外觀上卻完全看不出來。
或許\你能通過(pass)它。
",
]));


  setup();
}

void init()
{
	add_action("do_pass", "pass");
}

int do_pass(string arg)
{
	object who;
	who = this_player();

	if( !arg || arg!="rattan" )
		return notify_fail("你要通過什麼？\n");
	tell_object(who,"你用手撥開藤蔓，向後面的通道走了進去。\n");
	who->move(B_ROOM"t4");
	tell_room(this_object(),"你看到"+who->query("name")+"慢慢向藤蔓走去，忽然就不見蹤影了。\n");
	return 1;
}
