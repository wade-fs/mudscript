inherit NPC;
#include <ansi.h>
void create()
{
	set_name("有角蜈蚣",({"chimaera"}));
	set("race","野獸");
	set("long","生長於地底下的蜈蚣，頭上還長一根尖銳的角！\n");
	set("attitude","aggressive");
	set("age",120);
	set("limbs",({"頭部","身體","角","腳"}));
	set("verbs",({"bite"}));
	set("combat_exp",500000);
	set("str",50);
	set("con",20);
	set("max_gin",50000);
	set("max_kee",50000);
	set("max_sen",40000);
	set("max_force",100000);
	set("gin",50000);
	set("kee",50000);
	set("sen",40000);
	set("force",100000);
	set_skill("dodge",100);
	set_skill("move",100);
	set_skill("unarmed",100);
	set_skill("force",100);
	set_temp("apply/defense",100);
	set_temp("apply/damage",100);
	set_temp("apply/attack",100);
	set("force_factor",20);
	setup();
}

void heart_beat()
{
	object ob;
	mixed enemy;
	int i,n;
	ob = this_object();
	enemy = all_inventory(environment(this_object()));
	n = sizeof(enemy);
	
	if(ob->is_fighting() && random(100)<50 )
	{
		for(i=0;i<n;i++)
		{
			if(!enemy[i]->is_corpse() && enemy[i]->query("race")!="野獸" && enemy[i]->is_character() && random(100)<70 && enemy[i]->query("id")!="shadow" )
			{
				int q=500+random(500);
				message_vision(HIR"$N放出毒霧，$n不慎吸入，氣力受損！(-"+q+")\n"NOR,ob,enemy[i]);
				enemy[i]->add("kee",-q);
			}
		}
	}
	::heart_beat(1);
}
