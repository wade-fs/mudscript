
inherit NPC;
string give_book();
int i=1;

void create()
{
	set_name("白孝虹",({"shou hon","hon"}));
	set("gender", "男性");
	set("age", 27);
	set("long",
		"王元霸之傑出弟子之一 , 他現在正在指點新進門徒
練習基本刀法 , 你發現他手中拿著一本書 .\n");

	set("attitude", "heroism");
	set("combat_exp", 10000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("force", 400);
	set("force_factor", 4);
	set("max_force",400);

	set("chat_chance_combat", 40);
   /*
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
   */
	create_family("金刀門",6,"弟子");

	set_skill("force", 30);
	set_skill("unarmed",30);
	set_skill("blade",50);
	set_skill("parry",40);
	set_skill("dodge",20);
	set_skill("gold-blade",40);
	set_skill("fly-steps",30);
	set_skill("sixforce",30);
	map_skill("force", "sixforce");
	map_skill("parry", "gold-blade");
	map_skill("blade", "gold-blade");
	map_skill("dodge", "fly-steps");
	map_skill("move", "fly-steps");
	set("inquiry",([
	"書"   :   "嗯 , 這是一本刀譜 \n",
	"大小姐"  :  (:give_book:)
	]));

	setup();

	carry_object("/open/gblade/obj/gold-blade")->wield();
	carry_object("/open/gblade/obj/blade-book");
	add_money("gold",1);
}

void init()
{
	::init();
	add_action("do_accept", "accept");
}
string give_book()
{
	if(!this_player()->query_temp("can-get"))
	return "嗯 , 她是個好女孩 ";
	command("say 巧兒都跟你說了 ?");
	command("blush");
	if(i<1)
	{
	return "我的書給人囉 , 下次再來向我借吧 !";
	}
	this_player()->delete_temp("can-get");
	command("say 這本書給你 , 你可別說出去喔 !");
	command("give "+this_player()->query("id")+" book");
	i=i-1;
	return "切記 , 切記 !";
}

