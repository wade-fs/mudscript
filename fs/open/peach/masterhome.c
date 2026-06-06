// Room: /u/w/whatup/peach/masterhome.c
inherit ROOM;
#include <command.h>
#include <mudlib.h>
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "村長家");
  set ("long", @LONG
這裡是村長的屋子，屋子裡沒什麼糧食，空盪燙的一片，只放著
幾張桌子和椅子，除此之外，什麼都沒有了。不過這間房子裡竟然充
滿了哀傷的氣氛，不知道倒底發生了什麼事。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"master.c",
]));

  setup();
}


void init()
{
	object me=this_player();
	if (me->query_temp("quests/peach/mark") == 6)
	{
		tell_object( me , HIY"村長熱情地招待你過來這坐下。\n"NOR);
		me->move(__DIR__"masterhome2.c");
	}
	if (me->query_temp("quests/peach/mark") == 8)
	{
		tell_object( me , HIY"\n當你一進到屋子內時，發現有一道人影衝了過來。\n"NOR);
		tell_object( me , HIY"原來是美麗的姑娘玲玲。\n"NOR);
		tell_object( me , HIY"只見玲玲欣喜不已得擁抱那年輕人。\n"NOR);
		tell_object( me , HIY"你覺得你的辛苦是值得的。\n"NOR);
		tell_object( me , HIY"有情人終成眷屬。（︿　︿）\n"NOR);
		me->move(__DIR__"masterhome2.c");
	}

	if (me->query_temp("quests/peach/mark") == 9) //呼叫新郎 新娘出來
	{
		me->set_temp("quests/peach/mark",10);
		tell_object( me , HIY"三天後....\n"NOR);
		call_out("do_enter",5,me);
	}

	if (me->query_temp("quests/peach/mark") == 11)
	{
		call_out("do_enter",0,me);
	}
	return;
}

void do_enter(object str)
{
	object me = this_player();
	me->move(__DIR__"masterhome3.c");
	return ;
}
