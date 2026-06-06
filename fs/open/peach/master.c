// Room: /u/w/whatup/peach/master
inherit ROOM;
#include <command.h>
#include <mudlib.h>
#include <room.h>
#include <ansi.h>

look_well();

void create ()
{
  set ("short", "桃花源村長家");
  set ("long", @LONG
眼前這一棟氣派的屋子，想必是村長家了吧，門口有一棵高大的
(桃樹)，結著一顆顆肥美的桃子，桃花花瓣被風吹落，還有幾片掉到
你的頭髮上，傳來一股桃木香，正所謂「芳草鮮美，落纓繽紛」，一
旁還有個(水井)，看來(look)並不怎麼深，門口站著一位女子，似乎
正在等待著什麼人。
LONG);

  set("outdoors", "/u/b");
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"masterhome.c",
  "south" : __DIR__"virage5.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/daughter" : 1,
]));


  set("item_desc", ([ /* sizeof() == 3 */
  "水井" : (:look_well:),
  "well" : (:look_well:),
  "桃樹" : "你看見桃樹上的桃子成熟鮮嫩又多汁，似乎可以採下來吃，但你不喜\n不告而取。\n",
  "桃木" : "你看見桃樹上的桃子成熟鮮嫩又多汁，似乎可以採下來吃，但你不喜\n不告而取。\n",
]));
  setup();
}


void init()
{
	object me=this_player();
	add_action("do_climb","climb"); //更改為打死壞人後即可觸發可攀爬	
}

string look_well()
{
	object me = this_player();
	if (me->query_temp("quests/peach/die") == 1 || me->query_temp("quests/peach/get") == 2 || me->query_temp("quests/peach/mark") == 11)
	{
		tell_object(me,"一口平凡的水井(well)，看起來不太深，清澈見底。旁邊有繩子可以攀爬(climb)下去。\n");
	}
	else
	{
		tell_object(me,"一口平凡的水井，看起來不太深，清澈見底。它看起來似乎可以攀爬下去。\n");
	}
	return "";
}

int do_climb(string str)
{
	object me = this_player();
	if (me->query_temp("quests/peach/mark") > 4 || me->query_temp("quests/peach/get") == 2 || me->query_temp("quests/peach/know")==1)
	{
		if (me->query("quests/peach")!=1)
		{
			if (str =="well"|| str=="水井")
			{
				tell_object( me, "你順著繩子爬下。\n");
				me->move(__DIR__"well.c");
			}
			else
			{
				tell_object( me, "疑？你要爬那顆桃樹嗎？\n");
			}
			return 1;
		}
	}
		tell_object( me, "爬？？唉...你會壓死桃樹滴...（＞＿＜）\n");
	return 1;
}
