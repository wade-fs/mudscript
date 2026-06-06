//sheik.c

#include <room.h>
#include "../start.h"
#include <ansi.h>

inherit F_VENDOR;

string do_rest();
// string give_letter();

void create()
{
	set_name("村長",({"sheik"}) );
	set("long","一個看起來非常平凡的人，平凡到你根本不會想知道他\n的名字，如果你累了，可以問他有關休息(rest)的事。\n");
	set("gender","男性");
	set("age",47);
	set("combat_exp", 98);

	set("inquiry",([
	"rest":(: do_rest :),
	"休息":(: do_rest :),
	/* "跑腿":"我想找個人幫我把信送到平南城去，你有空嗎？\n",
	"平南城":"你從東村口出去以後走到岔路口往南走就會找到了。\n",
	"letter":(: give_letter :),
	"信":(: give_letter :), */
	]));

	set("vendor_goods", ({
		S_OBJ"thunder_hat",
		S_OBJ"rain_cloth",
		"/obj/example/dumpling",
	}) );
/*
	set("chat_chance", 5);
	set("chat_msg", ({
		"村長摸著頭說：有沒有人願意幫我跑腿呢？\n"}) );
*/
	setup();
}

void init()
{
	add_action("do_vendor_list","list");
	// add_action("do_report","report");
}

int accept_fight(object me)
{
	return notify_fail("村長搖搖頭對你說：請不要打擾我們好嗎？\n");
}

string do_rest()
{
	object who;
	string str;

	who = this_player();
	str = "休息一次五兩黃金，\n";
	if( !who->can_afford(50000) ) {
		str += "錢不夠啊！那就對不起了。\n";
		return str;
	}
	else {
                who->pay_money(50000);
		who->set_temp("sleep", 1);
		message_vision("$N付給村長一筆錢。\n", who);
		str += "嗯，你可以過去西面那客房休息。\n";
		return str;
	}
}
/*
string give_letter()
{
	object who;
	who = this_player();

	if( who->query("quests/letter") )
		return "村長笑著對你說：謝謝你上次幫我送信。\n"
	if( who->query_temp("letter") )
		return "怎麼樣？信送到了沒？\n";
	else {
		new(S_OBJ"letter")->move(who);
		message_vision("村長從懷裡拿出一封信交給$N。\n", who);
		who->set_temp("letter", 1);
		return "請你幫我把這封信送去給平南城的王老板，謝謝。\n對了！你可千萬不可以看信的內容喔！\n";
	}
}

int do_report(string arg)
{
	object who;
	who = this_player();

	if( !arg || arg!="sheik" )
		return notify_fail("你要回報給誰？\n");
	if( who->query("quests/letter") )
		return notify_fail("村長笑著說：謝謝你上次幫我送信。\n");
	else if( who->query_temp("letter")==2 ) {
		tell_object(who,"村長高興的對你說：辛苦你了，"+RANK_D->query_respect(who)+"，你累的話可以進去休息一下。\n");
		who->set("sleep", 1);
		who->set("quests/letter", 1);
		who->add("combat_exp", 30);
		tell_object(who,HIY"你完成『村長的信』任務了！\n"NOR);
		tell_object(who,HIC"你的經驗增加了！\n"NOR);
		return 1;
	}
	else if( who->query_temp("letter")==4 )
		tell_object(who,"村長高興的對你說：辛苦你了。\n");
	else
		return notify_fail("村長皺著眉頭對你說：有事嗎？\n");
}
*/
