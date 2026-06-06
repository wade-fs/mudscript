#include <ansi.h>
inherit NPC;
void create()
{
	set_name("流浪漢",({"ranger"}) );
	set("age",21);
	set("gender","男性");
	set("combat_exp",2150);
set("long","一個尋常的流浪漢，你看他在這鬼鬼祟祟似乎有所圖謀。\n");
	set("attitude","peaceful");
	set("str",21);
	set("con",20);
	set_skill("dodge",20);
	set_skill("parry",15);
	set_skill("unarmed",20);
	set_temp("apply/armor",20);
	set_temp("apply/dodge",10);
	set("max_gin",320);
	set("max_sen",300);
	set("max_kee",500);
	set("chat_chance",10);
	set("chat_msg",({
 		"流浪漢擔心的說道:小七不知怎麼樣了?\n",
		"流浪汗搓一搓手說道:小七一向很小心，應該不會出甚麼意外才是。\n",
		"流浪漢喃喃自語:我很擔心小七。\n",
		"流浪漢緊張的說道:這裡是魔教的地盤，要是被發現的話就慘啦!\n",
}) );
	set("inquiry", ([
		"小七" : "小七是我的好朋友，他一聽說這裡有寶物，便興匆匆的跑來了。\n",
]) );
	setup();
	add_money("coin",500);
	carry_object("/open/poison/obj/boots.c")->wear();
	carry_object("/obj/cloth.c")->wear();
}

