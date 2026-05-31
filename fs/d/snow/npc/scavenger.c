// scavenger.c

inherit NPC;

void create()
{
	set_name("收破爛的", ({ "scavenger" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "這個人不但自己收破爛﹐身上也穿得破爛不堪。\n");
	set("combat_exp", 150);
	set("str", 27);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 1);
	setup();
	set("chat_chance", 20);
	set("chat_msg", ({
		"收破爛的吆喝道﹕收～破～爛～哪～\n",
		"收破爛的嘴裡嘟噥著﹐不知道說些什麼。\n",
		"收破爛的伸手捉住了身上的蝨子﹐一腳踩得扁扁的。 \n",
		(: random_move :)
	}) );
	carry_object("/d/snow/obj/old_book");
	add_money("coin", 5);
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say 多謝這位" + RANK_D->query_respect(me) + "﹗");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饒命﹗小的這就離開﹗\n");
	return 0;
}
