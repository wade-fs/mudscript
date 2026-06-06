
#include <ansi.h>
inherit NPC;

void create()
{
	object ob;
	set_name("幻影",({"shadow"}));
	set("long","他曾經是名震江湖的一代殺手。\n");
	set("gender","男性");
	set("class","killer");
	set("combat_exp",1500000);
	set("attitude","aggressive");
	set("age",36);
	set("str", 45);
	set("cor", 34);
	set("cps", 18);
	set("per", 24);
	set("int", 42);
	set("kee",90000);
	set("max_kee",90000);
	set("gin",16000);
	set("max_gin",10600);
	set("sen",16000);
	set("max_sen",16000);
	set("atman",12000);
	set("max_atman",12000);
	set("mana",10000);
	set("max_mana",10000);
	set("force",35000);
	set("max_force",35000);
	set("quest/rain",1);
	set_skill("cure",50);
	set_skill("magic",20);
	set_skill("literate",30);
	set_skill("force",80);
	set_skill("move",80);
	set_skill("parry",60);
	set_skill("dagger",90);
	set_skill("dodge",100);
	set("quest/island",3);
	set_skill("throwing",120);
	set_skill("blackforce",95);
	set_skill("shade-steps",100);
	set_skill("rain-throwing",100);
	set_skill("shadow-kill",90);
	map_skill("throwing","rain-throwing");
	map_skill("dodge","shade-steps");
	map_skill("force","blackforce");
	set("bellicosity",1500);
	set_temp("apply/armor",70);
	set("force_factor",20);
	set("chat_chance_combat",45);
	set("chat_msg_combat",({
	(:perform_action,"throwing.manakee":),
	}));
	setup();
	ob=carry_object("/open/killer/obj/hate_knife");
	ob->set_amount(300);
	ob->wield();
	carry_object("/open/killer/weapon/k_cloth3.c")->wear();
	carry_object("/open/killer/weapon/k_boot3.c")->wear();
	carry_object("/open/killer/weapon/k_arm3.c")->wear();
	carry_object("/open/killer/weapon/k_head3.c")->wear();
	carry_object("/open/killer/obj/k_ring.c");
}

int accept_fight(object ob)
{
	this_object()->set("bellicosity",1800);
	command("cmd bellup");
	command("wear bell_ring");
	return 1;
}

int accept_kill(object ob)
{
	this_object()->set("bellicosity",3000);
	command("cmd bellup");
	command("wear bell_ring");
	return 1;
}
