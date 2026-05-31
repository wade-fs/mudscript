// beggar.c

inherit NPC;

void create()
{
	set_name("乞丐", ({ "beggar" }) );
	set("gender", "男性" );
	set("age", 53);
	set("long", "一個滿臉風霜之色的老乞丐。\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"乞丐說道﹕好心的大爺哪～ 賞我要飯的幾文錢吧～\n",
		"乞丐懶洋洋地打了個哈欠。\n",
		"乞丐伸手捉住了身上的蝨子﹐罵道﹕老子身上沒幾兩肉﹐全叫你們給咬糜了。 \n",
		(: random_move :)
	}) );
	carry_object(__DIR__"obj/old_book");
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say 多謝這位" + RANK_D->query_respect(me) + "﹐您好心一定會有好報的﹗");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饒命﹗小的這就離開﹗\n");
	return 0;
}
