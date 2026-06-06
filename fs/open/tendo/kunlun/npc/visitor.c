// guard.c

inherit NPC;
void create()
{
        set_name("遊客",({"visitor"}));
	set("gender", "男性" );
	set("age", 25);
	set("str", 10);
	set("cor", 25);
	set("cps", 25);
	set("int", 15);
	set("long",
		"一位來崑崙山遊玩的遊客.他正在遊覽四周的美景,\n"
		"一點也沒在意你的到來...\n" );
        set("combat_exp", 400);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
                "遊客說: 這崑崙山風景真優雅...\n",
                "遊客說: 這兒山高水長，真令人流連忘返...\n",
		"遊客說: 聽說崑崙原是一座火山...\n",
		"遊客說: 天池終年不結凍，想必是位於火山口上。\n"
	}) );
	set_skill("dagger", 4);
	set_skill("parry", 10);
	set_skill("dodge", 15);
	setup();
        carry_object("/open/gsword/obj/map.c");
	add_money("silver",3);
        carry_object("/open/gsword/obj/robe")->wear();
        carry_object("/obj/example/dagger")->wield();
}
