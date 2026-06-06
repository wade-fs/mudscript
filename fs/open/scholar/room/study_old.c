#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "讀書房");
  set ("long", @LONG
簡單樸實的佈置，讓人在此能放開心胸，靜下自己
的心，好好的讀書，你可以在此小睡一番，恢復一下自
己的精神。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r17.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/obj/iron.c" : 1,
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object who,string dir)
{
    if( dir == "south" && who->query_temp("sleeping") )
     return notify_fail("去哪裡？你想夢遊啊？\n");
     if( dir == "south" && who->query_temp("sleep") )
		return notify_fail("既然來了就睡(sleep)一下再走吧。\n");
	return ::valid_leave(who,dir);
}

void init()
{
	add_action("do_sleep","sleep");
	add_action("do_look", "look");
	add_action("do_score", "score");
	add_action("do_score", "hp");
    add_action("do_study", "study");
}

int do_sleep(string arg)
{
	object who;
	who = this_player();
	if( who->query_temp("sleeping") )
	{
		tell_object(who, "你已經睡著了，還想睡到死啊？\n");
		return 1;
	}
	tell_object(who, "你躺在房間裡的小床上，呼呼大睡了起來。\n");
	who->delete_temp("sleep");
        who->set_temp("sleeping", 1);
     call_out("wakeup", 10,who);
	return 1;
}

int wakeup(object who)
{
	tell_object(who, HIC"一覺醒來，你覺得你的精神稍稍恢復了。\n"NOR);
    who->receive_heal("sen",100);
	who->delete_temp("sleeping");
	return 1;
}

int do_look()
{
	object who = this_player();

	if( who->query_temp("sleeping") )
	{
		tell_object(who, "要睡覺眼睛就給我乖乖閉著，不要東張西望。\n");
		return 1;
	}
}

int do_score()
{
	object who = this_player();

	if( who->query_temp("sleeping") )
	{
		tell_object(who, "安啦！等睡起來就都好了啦。\n");
		return 1;
	}
}
int do_study()
{
        object who = this_player();

        if( who->query_temp("sleeping") )
        {
                tell_object(who, "安啦！等睡起來就可以讀了啦。\n");
                return 1;
        }
}
