#include <ansi.h>
inherit NPC;
void create()
{
        set_name("靈芝仙獸", ({ "grass beast","beast" }) );
        set("race", "野獸");
        set("age", 1000);
        set("long", "由千年靈芝所幻化成的神獸，獸身直散發出一股奇異香味。\n");
        set("str", 90);
        set("cor", 90);
        set("spi", 20);
        set("int", 20);
        set("max_gin", 100000);
        set("max_kee", 100000);
        set("max_sen", 100000);
        set("kee", 100000);
	set("gin", 100000);
	set("sen", 100000);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",10000000);
        set("attitude","aggressive");
        set_temp("apply/armor", 200);
        set_temp("apply/defense", 300);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set("force_factor",25);
        set("bellicosity",10000);
        set("max_force",25000);
        set("force",250000);
        set_skill("move",300);
        set_skill("dodge",300);
        set_skill("parry",300);
        set_skill("unarmed",300);
        set_skill("beast-combat",100);
        set_skill("force",350);
        map_skill("unarmed","beast-combat");
        map_skill("parry","beast-combat");
	setup(); 
	carry_object("/open/mon/obj/mon_item");
	carry_object("/open/mon/obj/beast_claw")->wield();
        set_heart_beat(1);
}
void heart_beat()
{
    object env,mob,*enemy,target;
    int i,kee,nd,pd,ld,kkee;

    mob = this_object();
    nd=mob->query_skill("dodge");
    env = environment(mob);

	if( mob->is_fighting() )
	{
	enemy=mob->query_enemy();
	i=random(sizeof(enemy));

	if( !enemy[i] ) return ;

	pd=enemy[i]->query_skill("dodge");
	ld=nd-pd;

	if( ld < 100 )	ld=100;
	
	kee=( enemy[i]->query("max_kee") )*0.15;
	kkee=random(kee);

	  if( random(ld) > random(pd) )
          {
	    if( environment(mob) == environment(enemy[i]) )
	    {
	      if( random(2) == 1 )
	      {
	      message_vision(HIR + "靈芝仙獸張口一吐，一道紅色光茫朝著$N" + HIR + "直射，令$N" + HIR + "無力招架！！！\n"+NOR,enemy[i]);
	      enemy[i]->receive_wound("kee", kkee );
	      enemy[i]->receive_damage("sen", random(300)+100 );
	      enemy[i]->receive_damage("gin", random(300)+100 );
	      enemy[i]->apply_condition("burn",enemy[i]->query_condition("burn")+5);
	      COMBAT_D->report_status(enemy[i],0);
	      }else{
	      message_vision(HIC + "靈芝仙獸張口一吐，一道青色光茫朝著$N" + HIC + "直射，令$N" + HIC + "無力招架！！！\n"+NOR,enemy[i]);
	      enemy[i]->receive_wound("kee", kkee );
	      enemy[i]->receive_damage("sen", random(300)+100 );
	      enemy[i]->receive_damage("gin", random(300)+100 );
	      enemy[i]->apply_condition("cold",enemy[i]->query_condition("cold")+5);
	      COMBAT_D->report_status(enemy[i],0);
	      }
	    }
	  }
	}

	if( !mob->is_fighting() && mob->query("kee") < 100000 )
	{
	tell_room(environment(), HIW+name()+HIW + "引發靈芝仙氣，輕輕地圍繞自身，將受傷的身軀慢慢的治癒。\n"+NOR);
	mob->receive_curing("kee",350);
	mob->receive_heal("kee",350);
	mob->receive_curing("gin",350);
	mob->receive_heal("gin",350);
	mob->receive_curing("sen",350);
	mob->receive_heal("sen",350);
	}

	if( ( mob->query("kee") < 85000 ) && ( random(100) < 50 ) )
	{
	tell_room(environment(), HIW+name()+HIW + "引發靈芝仙氣，輕輕地圍繞自身，將受傷的身軀慢慢的治癒。\n"+NOR);
	mob->receive_curing("kee",random(2000)+1000);
	mob->receive_heal("kee",random(2000)+1000);
	mob->receive_curing("gin",1000);
	mob->receive_heal("gin",1000);
	mob->receive_curing("sen",1000);
	mob->receive_heal("sen",1000);
	}

    set_heart_beat(1);
    :: heart_beat();
}            
