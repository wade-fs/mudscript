//by casey
#include <ansi.h>
#include "moon.h"
inherit NPC;
inherit SSERVER;
mapping *action = ({
([ "action" :"$N將銳利的兔爪向$n狠狠的抓了過去" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  220,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N迅速撲至$n面前 ,朝$n猛抓下去" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  170,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N朝$n身上狠狠的咬去 ,動作快捷狠準" + NOR + "。",
             "dodge"      :  -30,
             "parry"      :  -25,
             "damage"     :  190,
             "damage_type":  "咬傷",
            ]),
([ "action" :"$N朝$n狂抓了過去 ,使出的力道極其強勁" + NOR + "。",
             "dodge"      :  -40,
             "parry"      :  -15,
             "damage"     :  175,
             "damage_type":  "抓傷",
            ]),
([ "action":"$N狂吼著 ,朝$n撲去 ,銳利的雙爪令人不寒而慄" + NOR + "。",
             "dodge"      : -10,
             "parry"      :  -20,
             "damage"     : 145,
             "damage_type":  "灼傷",
           ]),
   });


void create()
{
    set_name("玉兔" ,({"little rabbit", "rabbit"}) );
  set("title", "守護者");
    set("long","傳說中在月亮上守護者嫦娥的兔子。\n");
  set("race", "野獸");
  set("gender","雄性");
  set("combat_exp",2900000);
  set("age",1021);
  set("cor",32);
  set("str",20);
  set("kar",100);

  set("kee",4900);
  set("max_kee",4900);
  set("sen",2200);
  set("max_sen",2200);
  set("gin",2500);
  set("max_gin",2500);
  set("force",4200);
  set("max_force",4200);
  set("bellicosity",4000);
  set("chat_chance_combat", 25);
  set_temp("apply/armor",400);
  set_temp("apply/damage",180);
  set("limbs", ({ "兔首", "兔身", "前肢" , "後足" , "兔尾" }) );
  set("force_factor",20);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("move",300);

  set_skill("unarmed",280);
  set("attribute","fire");
  set("chat_chance",90);
  set("chat_msg", ({
       (: this_object(),"random_move" :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__,"query_action" :));
  set_heart_beat(1);
  add_money("gold",20);

  reset_action();
}
mapping query_action()
{
        return action[random(sizeof(action))];
}
void heart_beat()
{
  object *enemy,me,target,env;
  int i;
  me = this_object();
  env = environment(me);
  enemy = me->query_enemy();
 if( i=sizeof(enemy) ) {
 target=offensive_target(me);
 if(!target) return ;
 if( env == environment(target) ) {
 if( me->is_fighting() )
  {
    if( 80 > random(120) )
    {
 message_vision(HIW + "玉兔往$N身上用力的咬一口!!!\n"+NOR,target);
  target->receive_damage("kee", 300,me);
 COMBAT_D->report_status(target,0);
     }
   }
   }
   }
   if(me->query("kee") < 2000 && query_temp("already_move") != 1)
   {
     this_object()->random_move();
     this_object()->random_move();
     set_temp("already_move",1);

   }
   :: heart_beat();
}
void die()
{
  object winner = query_temp("last_damage_from");
  if(!winner)
  {
    ::die();
    return ;
  }
  if(random(100) > 10) 
  {

   message_vision(HIW + "從玉兔的身上掉下一個月餅。\n"+NOR,winner);
   new(__DIR__"mooncake.c")->move(winner);
  }
  ::die();
}
