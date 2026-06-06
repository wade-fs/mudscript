inherit NPC;
#include <ansi.h>
void create()
{
	set_name("巨蚯蚓",({"earthworm"}));
	set("race","野獸");
	set("long","生長於地底下的巨蚯蚓\n");
	set("attitude","aggressive");
	set("age",102);
	set("limbs",({"頭部","身體","尾部"}));
	set("verbs",({"bite"}));
	set("combat_exp",500000);
	set("str",20);
	set("con",50);
	set("max_gin",50000);
	set("max_kee",50000);
	set("max_sen",40000);
	set("max_force",100000);
	set("eff_gin",50000);
	set("eff_kee",50000);
	set("eff_sen",40000);
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
	set_temp("apply/armor",100);
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
				message_vision(HIY"$N身體分泌出某種液體，$n一不小心碰到，被黏在地上了！\n"NOR,ob,enemy[i]);
				enemy[i]->start_busy(5);
			}
		}
	}
	set_heart_beat(1);
	::heart_beat(1);
}
