//by airke
#include <ansi.h>
#include <combat.h>

inherit NPC;

int special_att();
void clean_enemy();

void create()
{
	seteuid(getuid());
	::create();
        set_name("天地雲龍", ({ "cloud dragon", "dragon" }) );
        set("long", "它是由雲霧幻化而成神龍，專殺妖魔鬼怪。\n");

        set("race","野獸");
        set("gender","雄性");
        set("attitude", "friendly");
        set("max_gin", 4000);
        set("max_sen", 4000);
        set("max_kee", 4000);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("max_force", 6000);
        set("force", 6000);
        set("force_factor",15);
        set("str", 30);
        set("cor", 30);
        set("cps", 25);
        set("limbs",({"頭部","胸部","腹部","前爪","後爪","尾巴"}));
        set("verbs",({"bite","claw"}));

        set("chat_chance_combat",30);
        set("chat_msg_combat", ({(: special_att :)}));
	set_temp("apply/defend",100);
	set_temp("apply/attack",100);

        setup();

        carry_object("/open/tendo/kunlun/obj/cloud-dragon-claw")->wield();
}

void callset(object who)
{
        int pp;
        object me = this_object();
        
        pp=who->query("combat_exp");

        set("combat_exp",pp*3+1000);
//	set_temp("apply/defend",(int)(pp/50000));
//	set_temp("apply/attack",(int)(pp/50000));
//	set("max_kee",(int)(pp/600));
//	set("eff_kee",(int)(pp/600));
//	set("kee",(int)(pp/600));

}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIB + "兇暴的$N漸漸平息下來，再度變為雲霧。\n" + NOR, this_object ());
						 clean_enemy();

             destruct(this_object());

             return 1;
        }
	return ::heal_up() + 1;
}

void unconcious ()
{
	object winner = query_temp("last_damage_from");
  if(winner)
	winner->add("killgrow/cloud_dragon",1);
 clean_enemy();

        message_vision (HIB + "$N長嚎一聲，消失的無影無蹤。\n" + NOR, this_object ());
        destruct (this_object ());
}
void die()
{
  this_object()->unconcious();
}
int special_att()
{
        object me = this_object(), victim, *enemy = query_enemy();
        int i,j,k;

        if( !i = sizeof(enemy) )
                return 0;

        victim = enemy[random(i)];
	j = victim->query_temp("apply/armor");
	k = (int)(victim->query("killgrow/cloud_dragon")/10);
	if( k > 5000 )	k=5000;
        message_vision (HIB + "$N一聲怒吼，一道閃電向$n直劈而來。\n" + NOR,me,victim);
        victim->receive_damage("kee",100+j+k);      
        COMBAT_D->report_status(victim);       
  
        return 1;
}

void heart_beat()
{
	object mob,*enemy;
	int i,j,k;
	mob = this_object();

	enemy = mob->query_enemy();
	i = random(sizeof(enemy));

	if( mob->is_fighting() )
	{
	  if( !mob->query("changed") )
	  {
	    if( enemy[i]->query("killgrow/cloud_dragon") );
	    {
	    k=enemy[i]->query("killgrow/cloud_dragon");
	    mob->set("kee",mob->query("max_kee")+k*10);
	    mob->set("gin",mob->query("max_gin")+k*10);
	    mob->set("sen",mob->query("max_sen")+k*10);
	    mob->set("max_kee",mob->query("max_kee")+k*10);
	    mob->set("max_gin",mob->query("max_gin")+k*10);
	    mob->set("max_sen",mob->query("max_sen")+k*10);
	    mob->set("eff_kee",mob->query("max_kee"));
	    mob->set("eff_gin",mob->query("max_gin"));
	    mob->set("eff_sen",mob->query("max_sen"));
	    mob->set("max_force",mob->query("max_force")+k);
	    mob->set("force",mob->query("max_force")+k*100);
//	    mob->set("combat_exp",mob->query("combat_exp")+k*10);
//	    mob->set("bellicosity",mob->query("bellicosity")+k*10);
	    mob->add_temp("apply/defense",(int)(k/20));
	    mob->add_temp("apply/attack",(int)(k/50));
	    mob->add_temp("apply/dodge",(int)(k/20));
	    mob->add_temp("apply/parry",(int)(k/20));
	    mob->set("changed",1);
	    }
	  }
	}

	set_heart_beat(1);
	::heart_beat();
   
}
void clean_enemy()
{
	object * enemys = this_object()->query_enemy();
	foreach(object e  in enemys )
	{
		this_object()->remove_enemy(e);
		e->remove_enemy(this_object());
	}
}
