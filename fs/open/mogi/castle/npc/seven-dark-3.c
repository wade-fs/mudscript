// by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
inherit SSERVER;
void create() {
        
        set_name("藍衣魔將",({"seven-dark"}));
        set("long",
   "\n湛天藍衣, 為七人之中最智者, 擅於計謀巧術, 殺人不見血.\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","人類");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",1500);
        set("max_gin",13000);
        set("max_kee",13000);
        set("max_sen",13000);
        set("max_force",15000);
        set("force",15000);
        set("force_factor",29);
        set("combat_exp",6200000);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",100);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike3",100);
        set_skill("force",120);
        set_skill("badforce",90);
        set("clan_kill",1);
        map_skill("unarmed", "mogi-strike3");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike3");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"頭部","胸部","背部","腰部"}));
        setup();
        carry_object("open/mogi/castle/obj/seven3-dark-head");
carry_object(C_OBJ"/ninepill");
        add_money("gold",5);
 }
void heart_beat()
{
 object env,mob,*enemy,target;
 int i;

 mob = this_object(); 
 env = environment(mob);  

 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 18)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=offensive_target(mob);
      if(!target) return ;
    if( env == environment(target) )
    {
      message_vision(HIW"\n
$N身形飄忽，髮絲在風中飛動，在$n發現的瞬間，一張天羅地網早
已交織在$n的上下 
$N嘴角一揚，一式"HIR"「活殺天羅網」"HIW"開始啟動。只見飛髮滿天，$n猶
如籠中之獸任$N宰割
\n"NOR,mob,target);
      target->receive_damage("kee",650);
      target->start_busy(2);
      COMBAT_D->report_status(target, 1);
    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}



