// by Onion
#include "/open/open.h"
inherit ROOM;
string do_boxes();
void create ()
{
  set ("short", "乾通天內院");
  set ("long", @LONG
走進這兒, 是乾通天住宅的內院, 一片平坦的地方, 而角落還堆放
著幾個大箱子(boxes), 不知放著什麼東西, 由於是錢通天的地方, 使
你有點想搜查(search)的好奇心。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rich",
]));
	set("item_desc",([
	"boxes"	: "幾個大箱子, 裡頭不知道放了什麼東西。\n",
	]));
	set("search_desc",([
	"boxes" : (: do_boxes :),
	]));
	set_temp("有狗",1);

  setup();
}

string do_boxes()
{
	if( query_temp("有狗") ){
		tell_room( this_object(),"不知道從哪兒衝出來一隻凶猛的獒犬。\n");
		new(CAPITAL_NPC"dog0")->move(this_object());
		delete_temp("有狗");
	}
	return "這幾個箱子都上了鎖, 你沒辦法打開。\n";
}		

	
