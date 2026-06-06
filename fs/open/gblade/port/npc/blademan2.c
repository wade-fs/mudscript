inherit NPC;

void create()
{
	set_name("獨眼刀客",({"one-eyes blade man","man"}));
	set("long","一個朦著左眼的獨眼刀客 , 似乎身經百戰 !\n");
	set("gender","男性");
	set("combat_exp",5000);
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
	set_skill("blade",40);
	set_skill("dodge",30);
	set_skill("parry",50);
	set("chat_chance",20);
	set("chat_msg",({
	"獨眼刀客說道 : 別誤會 , 這個眼睛是我自己畫瞎的喔 !\n",
	"獨眼刀客說道 : 怎麼可能有人能畫瞎我的眼睛嘛 , 呵呵 !\n",
	(: "random_move" :),
	}));
	setup();
	carry_object("/open/gblade/obj/blade")->wield();
	carry_object("/open/gblade/port/obj/blademan_cloth")->wear();
	carry_object("/open/gblade/port/obj/blademan_boots")->wear();
	carry_object("/open/gblade/port/obj/blademan_hat")->wear();
	add_money("silver",3);
}
