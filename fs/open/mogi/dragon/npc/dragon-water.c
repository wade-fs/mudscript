//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIB + "兇性大發 ,銳利的龍爪向$n狠狠的抓了過去 ,水勁洶湧的把$n圍繞" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  290,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N" + HIB + "迅速撲至$n面前 ,龍爪如巨滔般攻勢朝$n直抓下去 ,$n當場鮮血飛濺" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  280,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIB + "身形忽退 ,取而代之的是一波波的巨浪朝著$n襲去 ,狂猛的來勢好不嚇人" + NOR + "。",
             "dodge"      :  -30,
             "parry"      :  -25,
             "damage"     :  285,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N" + HIB + "朝$n狂抓了過去 ,挾帶著水勁的雙爪 ,力道之猛 ,令人髮指" + NOR + "。",
             "dodge"      :  -40,
             "parry"      :  -15,
             "damage"     :  295,
             "damage_type":  "抓傷",
            ]),
([ "action":"$N" + HIB + "狂吼長嘯 ,水面不停的翻攪 ,生成數個大漩渦 ,$n的身體整個都被吞噬掉" + NOR + "。",
             "dodge"      : -10,
             "parry"      :  -20,
             "damage"     : 285,
             "damage_type":  "內傷",
           ]),
       });

void create()
{
     set_name(HIB + "水龍" + NOR ,({"water dragon", "dragon"}) );
     set("race", "野獸");
     set("title", "守護者");
     set("age",2529);
     set("cor", 30);
     set("long","四條巨龍之一 ,是傳說中上古時代的龍族\n");
     set("attitude","aggressive");   
     set_temp("apply/attack",130);
     set_temp("apply/damage",110);
     set_temp("apply/move",70);
     set("max_kee",7500);
     set("kee",7500);
     set("force",4900);
     set("max_force",4900);
     set("force_factor",35);
     set("max_gin", 7000);
     set("max_sen", 7000);
     set("combat_exp",2700000);
     set_skill("dodge",400);
     set_skill("parry",400);
     set_skill("unarmed",200);
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
  message_vision(HIB+"水面波滔忽起 ,強勁的水流形成無數漩渦 ,$N全身慘被捲入!!!\n" + NOR,enemy[i]);
      
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

    new("/open/mogi/dragon/obj/water")->move(environment(winner));
//	 new("/open/mogi/dragon/obj/water-1")->move(environment(winner));

   tell_object(winner,HIY + "\n\n經過一番血戰後 ,水龍終於被你收服了\n\n" + NOR);            
   tell_object(winner,HIC + "\n水龍自口中吐出一塊寶玉\n\n\n" + NOR);
               destruct(this_object());
                                                                    
            ::die();                                                           
      }                    






