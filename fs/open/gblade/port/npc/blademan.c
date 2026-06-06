inherit NPC;

void create()
{
	 set_name("刀客",({"blade man","man"}));
	set("long","於江湖上走動的平常刀客 , 嗜刀如命 , 強調以武力解決一切 !\n");
	set("gender","男性");
	set("combat_exp",2000);
	set("attitude","peaceful");
	set("age",22);
	set("class","blademan");
	set("str",20);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("blade",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set("chat_chance",10);
	set("chat_msg",({
	"刀客說道 : 哼 , 誰能贏的了我手中之刀 !\n",
	(: "random_move" :),
	}));
	setup();
	carry_object("/open/gblade/obj/blade")->wield();
	carry_object("/open/gblade/port/obj/blademan_cloth")->wear();
	carry_object("/open/gblade/port/obj/blademan_boots")->wear();
	add_money("silver",1);
}
