// guard.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("劉安祿", ({ "liu anru", "liu" }) );
	set("title", "門房");
	set("gender", "男性" );
	set("age", 26);
	set("str", 29);
	set("cor", 30);
	set("cps", 30);
	set("int", 11);
	set("long",
		"劉安祿是淳風武館的門房﹐除了館主柳淳風沒有人知道他的出身來歷﹐只知\n"
		"到他的武藝不弱﹐一手快刀在這一帶罕有敵手。\n" );
	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"劉安祿說道﹕你當這裡是什麼地方﹐敢來這裡撒野﹖\n",
		"劉安祿說道﹕想我堂堂....呃....連我這個淳風武館的小小的門房都可以收拾你﹗\n",
		"劉安錄忽然揮出一刀﹐招數精奇﹐但是刀到中途忽然像是想起什麼﹐急忙收招。\n",
		"劉安祿說道﹕你快走吧﹐就算我輸了你啦....\n"
	}) );
	set("inquiry", ([
		"劉老三": (: ask_me :),
		"血手劉三": (: ask_me :)
	]) );

	set_skill("blade", 40);
	set_skill("parry", 40);
	
	setup();
	
	carry_object("/d/snow/obj/blade")->wield();
	carry_object("/obj/cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
		if( is_killing(who) ) return "你既然知道了我的身分﹐今日休想活命﹗\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "老子就是血手劉三﹐血手劉三就是你老子﹗納命來﹗\n";
		}
	}

	if( (random(10) < 5)
	||	!is_fighting() )
		return "我...不知道﹗\n";
	set_temp("apply/attack", 70);
	set_temp("apply/dodge", 50);
	set_temp("apply/parry", 60);
	set_temp("apply/damage", 20);
	set("title", "野羊山寨二寨主");
	set("nickname", HIR "血手劉三" NOR);
	message("vision",
		HIY "劉安祿眼中突然放出異樣的光芒﹐顫聲說道﹕看來...你都知道了﹖\n\n"
		"劉安祿大喝一聲﹐叫道﹕既然如此﹐老子今天豁出去了﹐納命來﹗\n" NOR
		"劉安祿使開單刀﹐招數精奇﹐沈猛狠辣﹐和剛才簡直判若兩人﹗\n",
		environment(), this_object() );
	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("chat_msg_combat", ({
		(: random_move :)
	}) );
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 10000);
	set("combat_exp", 500000);
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	carry_object("/d/snow/obj/blade_book");
	set("revealed", 1);
	return 0;
}

