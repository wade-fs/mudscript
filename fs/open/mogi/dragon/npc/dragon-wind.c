//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIC + "兇性大發 ,雙翼狂振 ,捲起狂烈的真空氣旋將$n整體圍繞住" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  290,
             "damage_type":  "割傷",
           ]),
([ "action" :"$N" + HIC + "迅速撲至$n面前 ,龍爪如旋風般朝$n直抓下去 ,$n當場鮮血飛濺" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  280,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIC + "身形忽轉 ,捲起一陣陣的狂風朝著$n襲去 ,狂猛的來勢好不嚇人" + NOR + "。",
             "dodge"      :  -30,
             "parry"      :  -25,
             "damage"     :  260,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N" + HIC + "朝$n直抓了過去 ,挾帶著狂風的真空爪勁 ,力道之猛 ,令人髮指" + NOR + "。",
             "dodge"      :  -40,
             "parry"      :  -15,
             "damage"     :  275,
             "damage_type":  "抓傷",
            ]),
([ "action":"$N" + HIC + "狂吼長嘯 ,天地為之色變 ,強勁氣旋 ,$n的身體整個都被吞噬掉" + NOR + "。",
             "dodge"      : -10,
             "parry"      :  -20,
             "damage"     : 315,
             "damage_type":  "內傷",
           ]),
       });

void create()
{
     set_name(HIC + "風龍" + NOR ,({"wind dragon", "dragon"}) );
     set("race", "野獸");
     set("title", "守護者");
     set("age",2579);
     set("cor", 30);
     set("long","四條巨龍之一 ,是傳說中上古時代的龍族\n");
     set("attitude","aggressive");   
     set_temp("apply/attack",130);
     set_temp("apply/damage",110);
     set_temp("apply/move",70);
     set("max_kee",7500);
     set("kee",7500);
     set("force",5000);
     set("max_force",5000);
     set("force_factor",37);
     set("max_gin", 7000);
     set("max_sen", 7000);
     set("combat_exp",2700000);
     set_skill("dodge",420);
     set_skill("parry",420);
     set_skill("unarmed",210);
 set("limbs", ({ "龍首", "龍身", "前肢" , "後足" , "龍尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);
 add_money("gold",45);
}
mapping query_action()
{
   return action[random(sizeof(action))];
}

void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_player();
  if( me->is_fighting() )
  {
    if( 80 > random(120) )
    {
      enemy = me->query_enemy();

      i=random(sizeof(enemy));

    message_vision(HIC+"天際狂風忽起 ,形成無數真空漩渦 ,$N被割的體無完膚!!!\n" + NOR,enemy[i]);
      
      enemy[i]->receive_damage("kee", 100,me);
      COMBAT_D->report_status(enemy[i], 1);
     
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   :: heart_beat();
}

 void die()                                                                 
{
    object winner = query_temp("last_damage_from");        

    new("/open/mogi/dragon/obj/wind")->move(environment(winner));
//	new("/open/mogi/dragon/obj/wind-1")->move(environment(winner));

   tell_object(winner,HIY + "\n\n經過一番血戰後 ,風龍終於被你降服了\n\n" + NOR);            
  tell_object(winner,HIC + "\n風龍自口中吐出一塊寶玉\n\n\n" + NOR);                             
               destruct(this_object());
                                                                    
            ::die();                                                           
      }                    













