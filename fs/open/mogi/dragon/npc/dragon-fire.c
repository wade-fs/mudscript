//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIR + "兇性大發 ,銳利的龍爪向$n狠狠的抓了過去 ,燄火熊熊的圍住$n" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  330,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N" + HIR + "迅速撲至$n面前 ,滿天爪影火光朝$n猛擊下去 ,$n當場鮮血飛濺" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  310,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIR + "張開大口 ,對準$n身上狠狠的咬去 ,龐大的身軀好不嚇人" + NOR + "。",
             "dodge"      :  -30,
             "parry"      :  -25,
             "damage"     :  330,
             "damage_type":  "咬傷",
            ]),
([ "action" :"$N" + HIR + "朝$n狂抓了過去 ,飛舞著火燄的雙爪 ,力道之猛 ,令人髮指" + NOR + "。",
             "dodge"      :  -40,
             "parry"      :  -15,
             "damage"     :  325,
             "damage_type":  "抓傷",
            ]),
([ "action":"$N" + HIR + "狂吼長嘯 ,濃濃的火燄 ,在瞬間$n的身體整個都被吞噬掉" + NOR + "。",
             "dodge"      : -10,
             "parry"      :  -20,
             "damage"     : 315,
             "damage_type":  "灼傷",
           ]),
       });

void create()
{
     set_name(HIR + "火龍" + NOR ,({"fire dragon", "dragon"}) );
     set("race", "野獸");
     set("title", "守護者");
     set("age",2729);
     set("cor", 30);
     set("long","四條巨龍之首 ,僅次於黃金甲龍 ,是上古時代的龍族\n");
     set("attitude","aggressive");   
     set_temp("apply/attack",130);
     set_temp("apply/damage",110);
     set_temp("apply/move",70);
     set("max_kee",7700);
     set("kee",7700);
     set("force",5000);
     set("max_force",5000);
     set("force_factor",40);
     set("max_gin", 7000);
     set("max_sen", 7000);
     set("combat_exp",2700000);
     set_skill("dodge",400);
     set_skill("parry",420);
     set_skill("unarmed",220);
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
      message_vision(HIR+"紅色的烈燄自火龍口中湧湧而出 ,高溫將周遭形成真空漩渦!!\n"+NOR,enemy[i]);
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

    new("/open/mogi/dragon/obj/fire")->move(environment(winner));
//	 new("/open/mogi/dragon/obj/fire-1")->move(environment(winner));

   tell_object(winner,HIY + "\n\n經過一番血戰後 ,火龍終於被你收服了\n\n" + NOR);            
   tell_object(winner,HIC + "\n火龍自口中吐出一塊寶玉\n\n\n" + NOR);            
                 
               destruct(this_object());
                                                                    
            ::die();                                                           
      }                    








