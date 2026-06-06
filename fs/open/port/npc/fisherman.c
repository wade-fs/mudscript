inherit NPC;

void create()
{
	set_name("漁夫",({"fisherman","man"}));
	set("long","靠捕魚為生的漁夫 , 現在他正在海邊釣魚 .\n");
	set("gender","男性");
	set("combat_exp",1500);
	set("attitude","peaceful");
	set("age",35);
	set("str",20);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("stick",25);
	set_skill("parry",10);
	set_skill("dodge",10);
	set("chat_chance",10);
	set("chat_msg",({
	}));
	setup();
	carry_object("/open/port/obj/fishing_rod")->wield();
	carry_object("/open/port/obj/wide-brimmed_rain_hat")->wear();
	add_money("coin",20);
}
