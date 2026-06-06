#include <ansi.h>
 

inherit NPC;

void create()
{
	set_name("竊賊 小七", ({"chi"}) );
	set("gender", "男性");
	set("long","
一個偷偷摸摸的小賊，看他的樣子好像是為了要尋找甚麼稀世珍寶
而來。\n");
	set_skill("dodge",30);
	set("age", 21);
	set("str",22);
	set("con",21);
	set_skill("throwing",20);
	set_skill("unarmed", 20);
	set("max_kee",500);
	set("max_sen",310);
	set("max_gin",320);
	
	set("combat_exp",5000);
	set_temp("apply/armor",30);
	set_temp("apply/dodge",16);
	set("chat_chance",10);
	set("chat_msg", ({
		"小七貪婪的說道:聽說魔教得到一樣稀世珍寶。\n",
		"小七喃喃自語:不知監牢要怎樣才能進入。\n",
		"小七微笑的對你說:你也是來尋寶的嗎?\n",
		"小七偷偷對你說:聽說寶物是藏在監牢中。\n",
}) );

	set("inquiry", ([
	 	"寶物" : "聽說那寶物是叫煉甚麼壺來著。\n",
		"監牢" : "要進監牢需要一把特殊的鑰匙。\n",
		"鑰匙" : "鑰匙在誰身上那就不得而知了。\n",
]) );
 	setup();
	add_money("silver",1);
	carry_object("/open/poison/obj/boots.c")->wear();
	carry_object("/obj/cloth.c")->wear();
	carry_object("/open/poison/obj/ball.c")->wield();
}
	
  
