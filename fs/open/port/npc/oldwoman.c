inherit NPC;

void create()
{
	set_name("老漁婦",({"old woman","woman"}));
	set("long","一個白髮斑斑的老漁婦 , 正在打掃著環境 .\n");
	set("gender","女性");
	set("combat_exp",1000);
	set("attitude","peaceful");
	set("age",65);
	set("str",20);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("unarmed",10);
	set_skill("parry",10);
	set_skill("dodge",10);
	set("chat_chance",10);
	set("chat_msg",({
	}));
	setup();
	add_money("coin",10);
}
