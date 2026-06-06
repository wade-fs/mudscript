//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIW + "兇性大發 ,銳利的龍爪向$n狠狠的抓了過去 ,電光滋滋的在$n圍繞" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  290,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N" + HIW + "迅速撲至$n面前 ,龍爪化成一道猛雷朝$n直劈下去 ,$n當場鮮血飛濺" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  280,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIW + "揚起尖角 ,對準$n身上狠狠的刺去 ,狂猛的來勢好不嚇人" + NOR + "。",
             "dodge"      :  -30,
             "parry"      :  -25,
             "damage"     :  230,
             "damage_type":  "刺傷",
            ]),
([ "action" :"$N" + HIW + "朝$n狂抓了過去 ,挾帶著閃電的雙爪 ,力道之猛 ,令人髮指" + NOR + "。",
             "dodge"      :  -40,
             "parry"      :  -15,
             "damage"     :  245,
             "damage_type":  "抓傷",
            ]),
([ "action":"$N" + HIW + "狂吼長嘯 ,背部射出數道閃光 ,在瞬間$n的身體整個都被吞噬掉" + NOR + "。",
             "dodge"      : -10,
             "parry"      :  -20,
             "damage"     : 255,
             "damage_type":  "灼傷",
           ]),
       });

void create()
{
     set_name(HIW + "雷龍" + NOR ,({"thunder dragon", "dragon"}) );
     set("race", "野獸");
     set("title", "守護者");
     set("age",2419);
     set("cor", 30);
     set("long","四條巨龍之末 ,是傳說中上古時代的龍族\n");
     set("attitude","aggressive");   
     set_temp("apply/attack",130);
     set_temp("apply/damage",110);
     set_temp("apply/move",70);
     set("max_kee",7200);
     set("kee",7200);
     set("force",4500);
     set("max_force",4500);
     set("force_factor",30);
     set("max_gin", 7000);
     set("max_sen", 7000);
     set("combat_exp",2700000);
     set_skill("dodge",300);
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
  message_vision(HIW+"雷龍挾著陣陣電光自雲端破霧而出 ,道道光劍自$N穿出!!!\n"+NOR,enemy[i]);
      
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

    new("/open/mogi/dragon/obj/thunder")->move(environment(winner));
    new("/open/mogi/dragon/obj/thunder-1")->move(environment(winner));

    
   tell_object(winner,HIY + "\n\n經過一番血戰後 ,雷龍終於被你降服了\n\n\n" + NOR);            
                   
    tell_object(winner,HIC + "\n\n雷龍自口中吐出一塊寶玉\n\n\n" + NOR);            
            destruct(this_object());
                                                                    
            ::die();                                                           
      }                    






