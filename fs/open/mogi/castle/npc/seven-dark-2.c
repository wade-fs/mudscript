// by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
inherit SSERVER;
void create() {
    object ob;    
        set_name("紫衣魔將",({"seven-dark"}));
        set("long",
   "\n攝邪紫衣, 為人詭計多端, 城府極深, 戰於詭暗.\n");

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
        set("force_factor",17);
        set("combat_exp",6200000);
        set_skill("throwing",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",100);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike4",100);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("throwing", "mogi-strike4");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike4");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("clan_kill",1);
        set("limbs",({"頭部","胸部","背部","腰部"}));
        ob=carry_object(C_OBJ"/throw-1");
        ob->set_amount(300);
        ob->wield();
        setup();
carry_object(C_OBJ"/ninepill");
        carry_object("open/mogi/castle/obj/seven2-dark-head");
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
      message_vision(HIB"\n
$N魔氣盡放，瞬間妖氣滿溢，形成一個奇異的結界 
$N腳步輕點剎那間逼近了$n，左手食指往$n眉心點去
喝道一聲"HIM"『吞噬』"HIB"，$n的精氣神在眨眼間盡被吸入$N體內
\n"NOR,mob,target);
      target->receive_damage("kee",550);
      target->add("force",-1800);
      target->set("mana",0);
      target->set("atman",0);
      target->add("sen",-550);
      target->add("gin",-550);
      COMBAT_D->report_status(target, 1);
    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}


