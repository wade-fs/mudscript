
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "房舍");
	set("long", @LONG
一股濃厚的藥味撲鼻而來，琳瑯滿目的聊醫療器具看的你眼花
潦亂，眼前的徐大夫本來是皇宮裡頭，專門給即將入宮當太監的人
割雞雞的密醫，不井從操舊業。

LONG );

        set("exits", ([ /* sizeof() == 1 */
          "south"  : __DIR__"sexroom",
	]));

  set("objects", ([ /* sizeof() == 1 */
    "/open/capital/npc/shyu2"       :     1,
]));
set("no_fight",1);
set("no_kill",1);
set("no_magic",1);
	set("light_up", 1);

	setup();
}

int valid_leave(object who,string dir)
{
     if( dir == "south" && who->query_temp("sleeping") )
                return notify_fail("你已毫無意識，渾身沒有力氣。\n");
	return ::valid_leave(who,dir);
}

void init()
{
        add_action("do_change","change");
	add_action("do_look", "look");
	add_action("do_score", "score");
}

int do_change(string arg)
{
	object who;
	who=this_player();

	if( who->query_temp("sleeping") )
	{
  tell_object(who, "你正在手術中ㄋㄟ‧‧‧\n");
		return 1;
	}
    if( !who->query_temp("change") )
	{
  tell_object(who, "徐大夫說道 : 改？還要改就到外面付錢。\n");
		return 1;
	}
  tell_object(who, "徐大夫給你打了根麻藥，開始昏睡過去。\n");
        who->delete_temp("change");
	who->set_temp("sleeping", 1);
	call_out("wakeup", 8, who);
	return 1;
}

int wakeup(object who)
{
 tell_object(who, HIC + "徐大夫摸摸你的下面，奸笑的點了點頭。。\n" + NOR);
  if( who->query("gender") == "男性")
{    who->set("gender","女性");
}
 if( who->query("gender") == "女性")
{
 who->set("gender","男性");
}
	who->delete_temp("sleeping");
	return 1;
}

int do_look()
{
	object who = this_player();

	if( who->query_temp("sleeping") )
	{
    tell_object(who, "手術中還想亂瞄，想死喔！！\n");
		return 1;
	}
}

int do_score()
{
	object who = this_player();

	if( who->query_temp("sleeping") )
	{
 tell_object(who, "急啥勁啊？手術完就知道了咩！\n");
		return 1;
	}
}
