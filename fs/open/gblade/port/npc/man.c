inherit NPC;

void create()
{
	set_name("遊街居民",({"man"}));
	set("long","楓林港的居民 , 正在遊街購物 !\n");
	set("gender","男性");
	set("combat_exp",100);
	set("attitude","peaceful");
	set("age",35);
	set("chat_chance",10);
	set("chat_msg",({
	"遊街居民到處看來看去 !\n",
	(: "random_move" :),
	}));
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("coin",30);
}
