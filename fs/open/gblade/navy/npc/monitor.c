inherit NPC;

void create()
{
	set_name("士兵班頭",({"soldier monitor","monitor"}));
	set("long","從士兵中挑選而出 , 標準的肌肉棒子 , 
他正到處教導著士兵們的動作 !\n");
	set("gender","男性");
	set("combat_exp",50000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str",30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
	set_skill("unarmed",70);
	set_skill("parry",70);
	set_skill("dodge",70);
	set("chat_chance",3);
	set("chat_msg",({
	(: this_object(),"random_move" :),
	}));
	setup();
	add_money("silver",10);
}
