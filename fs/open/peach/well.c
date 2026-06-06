// Room: /u/w/whatup/peach/well
inherit ROOM;
#include <command.h>
#include <mudlib.h>
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short", "水井底下");
  set ("long", @LONG
水井裡的水位並不高，雖然村民在此取水多年，但你明白它並不
會輕易乾涸。你不喜歡這種潮濕的地方，你打算爬出去了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
      "north" : __DIR__"well2",
  ]));

  set("item_desc", ([ /* sizeof() == 1 */
  "hole" : "這是一個桃花模樣的小洞，似乎可以鑲入(unlock)某種東西。\n",
]));

  create_door ("north", "石牆", "south",DOOR_LOCKED);
  close_door ("north");
  lock_door ("north");
  set("need_key/north", 1);
  set("no_clean_up", 0);
  set("have_reborn",1);
	setup();
}

void init()
{
	close_door ("north");
	lock_door ("north");
	add_action("do_climb","climb");
	add_action("do_search","search");
}

int do_search(string arg)
{
	if(!arg) 
	{
		write("經過你仔細地找尋，雖然青苔很多，但你意外地發現在前方的牆上有\n特殊(桃花)形狀的小洞(hole)。\n");
	}
	return 1;
}

int do_climb(string str)
{
	object me = this_player();
	tell_object( me, "你順著繩子爬上去。\n");
	me->move(__DIR__"master");
	return 1;
}

// 每次 reborn 就會呼叫一次這個函數
void reset()
{
	close_door ("north");
	lock_door ("north");
	::reset();
}
