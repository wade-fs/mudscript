inherit NPC;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        set_name("深海隱鯊",({ "deep shark","deep","shark"}) );
        set("long","生長在深海裡面的鯊魚, 其身體有保護色, 在陰暗的深海中難以察覺其存在!!\n");
        set("race", "野獸");
        set("age", 500);
        set("max_gin", 70000);
        set("max_kee", 90000);
        set("max_sen", 70000);
        set("max_force", 50000);
        set("force", 50000);
        set("force_factor",90);
        set("bellicosity",10000);
        set("limbs", ({"頭部", "身體"}) );
        set("verbs", ({ "bite" }) ); 
        set("score",90000000);
        set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor",  500);
        set_temp("apply/defense",  500);
        set_temp("roared",1);
        set_skill("move",150);
        set_skill("unarmed",300);
        set_skill("tako_combat",100);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
        map_skill("unarmed","shark-combat");
        map_skill("parry","shark-combat");
        set("combat_exp", 12000000);
        setup();
}
void heart_beat()
{
 object env,mob,victim,obj;
 mixed enemy;
 int i,hurt,j=0;
 mob = this_object();
 env = environment(mob);
if(!env) return ;
 enemy = all_inventory( environment(mob) );
 i=sizeof(enemy);
  if(!mob->is_fighting() && mob->query("inv")!=15) mob->set("inv",15);
  if(random(100)>50 && !mob->is_fighting())
 {
 for (j=0 ; j < i ; j++)
 {
 if (enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j]->query("id")!="deep shark")
     {   
     message_vision(HIB + "$N不知道被什麼東西撞了一下, 受了幾處傷!!\n" + NOR,enemy[j]);
     enemy[j]->receive_wound("kee",500);
     COMBAT_D->report_status(enemy[j]);
     }
 }
 }   
   set_heart_beat(1);
   ::heart_beat();
   
}
