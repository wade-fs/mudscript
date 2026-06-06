// by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
inherit SSERVER;
void create() {
        
        set_name("灰衣魔將",({"seven-dark"}));
        set("long",
   "\n銀閃灰衣, 其人如風飄逸, 腰上配劍魔光閃閃, 更顯英氣.\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","人類");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",500);
        set("max_gin",13000);
        set("max_kee",13000);
        set("max_sen",13000);
        set("max_force",15000);
        set("force",15000);
        set("force_factor",49);
        set("combat_exp",6300000);
        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",100);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike7",100);
        set("clan_kill",1);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("sword", "mogi-strike7");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike7");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"頭部","胸部","背部","腰部"}));
        setup();
        carry_object(C_OBJ"/sword-1")->wield();
carry_object(C_OBJ"/ninepill");
        carry_object("open/mogi/castle/obj/seven4-dark-head");

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
$N橫劍心凝，神形意止，銀封劍開起激出陰冷寒氣，魔風狂舞圍住了在
場所有的人，溫度隨著$N的意識直線降低     
瞬間，$N將銀封劍直指向天，凜凜一式"HIC"「十等千斷  寒水無封」"HIW"，凜冽
的魔風盡化利刃劍氣，聞血而腥 
\n"NOR,mob,target);
      target->receive_damage("kee",550);
      target->start_busy(2);
      COMBAT_D->report_status(target, 1);
    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}





