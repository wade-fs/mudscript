inherit NPC;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        set_name("八爪章魚",({ "octopus" }) );
        set("long","生長在深溝裡面的大章魚!!\n");
        set("race", "野獸");
        set("age", 1240);
        set("max_gin", 30000);
        set("max_kee", 70000);
        set("max_sen", 30000);
        set("max_force", 50000);
        set("force", 50000);
        set("force_factor",30);
        set("bellicosity",10000);
        set("limbs", ({"頭部", "身體"}) );
        set("verbs", ({ "claw","bite" }) );
        set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor",  500);
        set_temp("apply/defense",  500);
        set_skill("move",150);
        set_skill("unarmed",300);
        set_skill("tako_combat",100);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
        map_skill("unarmed","tako_combat");
        map_skill("parry","tako_combat");
        set("combat_exp", 7000000);
        setup();
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
  if(random(100) > 65)
 {
 for (j=0 ; j < i ; j++)
 {
 if (enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j]->query("id")!="octopus")
     {   
     message_vision(HIM"$N被八爪章魚的觸手纏住了, 無法動彈!!\n"NOR,enemy[j]);
     enemy[j]->start_busy(3);
     }
 }
 }   
   set_heart_beat(1);
   ::heart_beat();
   
}
