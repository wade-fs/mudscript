// by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
inherit SSERVER;
void create() {
        
        set_name("碧衣魔將",({"seven-dark"}));
        set("long",
   "\n綠玉碧衣, 深沉而無語, 無法判斷他下一步的行動是什麼.\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","人類");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",7500);
        set("max_gin",9000);
        set("max_kee",9000);
        set("max_sen",9000);
        set("max_force",9000);
        set("force",9000);
        set("force_factor",65);
        set("combat_exp",6900000);
        set("clan_kill",1);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",100);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike2",100);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("unarmed", "mogi-strike2");
        map_skill("dodge","mogi-steps");
        map_skill("parry","badstrike");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"頭部","胸部","背部","腰部"}));
        setup();
carry_object(C_OBJ"/ninepill");
        carry_object("open/mogi/castle/obj/seven7-dark-head");

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
 
 if( random(100) < 15)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=offensive_target(mob);
    if(!target) return ;
    if( env == environment(target) )
    {
      message_vision(HIB"\n
$N指圓為心，方圓百里的妖邪魂魄瞬間飛奔群聚於此，鬼哭獸吼直
竄腦中轟然欲裂
隨$N迅雷一指，一式"MAG"『千首積屍  天懲無視』"HIB"的噬血屍氣活若閻羅
直奔逼竄$n的七孔之中
\n"NOR,mob,target);
      target->receive_damage("kee",750);
      COMBAT_D->report_status(target, 1);
    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}

