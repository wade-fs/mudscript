//woman.c

#include "../start.h"

inherit NPC;

string give_bento();

void create()
{
	set_name("農婦",({"woman"}));
	set("long","一個平凡的農家婦女，但似乎在煩惱著什麼。\n");
	set("gender","女性");
	set("nickname", "張快嘴");
	set("age", 43);

	set("combat_exp",59);
	set("inquiry",([
	  "trouble":"你可以幫我一個忙嗎？\n",
	  "help":"我丈夫現在正等著我送便當去，可是我現在又分不開身，\n你可以幫我送去給他嗎？\n",
	  "便當":(: give_bento :),
	  "bento":(: give_bento :),
	]));

	setup();
	carry_object(S_OBJ"apron")->wear();
}

string give_bento()
{
	object who, item;
	who = this_player();

	if( who->query("quests/bento") || who->query_temp("bento")==1 )
		return "你不是已經把便當拿走了嗎？\n";
	else if( who->query_temp("bento")==2 ) {
		item = new(S_OBJ"bento2");
		item->move(who);
		message_vision("婦女給$N一個便當。\n", who);
		who->set_temp("bento", 1);
		return "這次可別再把便當吃掉了喔！\n";
	}
	else {
		item = new(S_OBJ"bento");
		item->move(who);
		printf("婦女給%s一個%s。\n",
		who->query("name"),item->short() );
		who->set_temp("bento", 1);
		return "謝謝你，請把便當拿給我丈夫，我丈夫鼻子上有顆痣。\n";
	}
}
