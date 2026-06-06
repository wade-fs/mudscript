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
		"一位來蜀山光觀的遊客.他正在遊覽四周的美景,\n"
		"一點也沒在意你的到來...\n" );
        set("combat_exp", 400);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
                "遊客說: 這蜀山風景真不錯...\n",
                "遊客說: 這裡真是個好地方...\n",
                (: "random_move" :),
	}) );
	set_skill("dagger", 4);
	set_skill("parry", 15);
	set_skill("dodge", 25);
	setup();
        carry_object("/open/gsword/obj/map.c");
	add_money("silver",3);
        carry_object("/open/gsword/obj/robe")->wear();
        carry_object("/obj/example/dagger")->wield();
}
