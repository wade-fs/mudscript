inherit NPC;
#include "/open/open.h"
#include <ansi.h>
void create()
{
	object ob;
        set_name("水忍",({ "water ninja","water","ninja" }) );
        set("long","利用忍術潛伏在通往東瀛的海域中!!\n");
        set("race", "人類");
        set("age", 30);
        set("class","killer");
        set("max_gin", 50000);
        set("max_kee", 40000);
        set("max_sen", 50000);
        set("max_force", 50000);
        set("max_atman", 25000);
        set("atman",25000);
        set("force", 50000);
        set("force_factor",40);
        set("bellicosity",10000);
        set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor",  500);
        set_temp("apply/defense", 500);
        set_temp("mana_shield3",1);
        set_skill("move",200);
        set_skill("unarmed",300);
        set_skill("ninja_bomb1",100);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",500);
        map_skill("unarmed","ninja_bomb1");
        map_skill("parry","ninja_bomb1");
        set("combat_exp", 10000000);
        setup();
        ob=carry_object("/open/killer/obj/hate_knife");
        ob->set_amount(600);
        carry_object("/open/love/obj/ring.c")->wield();


}

void heart_beat()
{
 object env,mob,victim,obj;
 mixed enemy;
 int i,hurt,j=0;
 mob = this_object();
 env = environment(mob);
 enemy = all_inventory( environment(mob) );
 i=sizeof(enemy);
 if(mob->query_temp("k_all") != 1)
 {
 for (j=0 ; j < i ; j++)
 {
 if (enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j]->query("id")!="water ninja")
     {   
     message_vision(HIR + "$N對著$n大叫: 入侵者去死吧!!\n" + NOR,mob,enemy[j]);
     enemy[j]->kill_ob(mob);
     mob->kill_ob(enemy[j]);
     }
  }
  mob->set_temp("k_all",1);
}
   set_heart_beat(1);
   ::heart_beat();
   
}
