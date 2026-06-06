// by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({

([ "action" :"$N"HIG"獸性一起 ,前爪向$n強勁的抓了過去 ,眼看猛烈的一擊就要打到$n了"NOR"。",
          
                "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "抓傷",

           ]),
([ "action" :"$N"HIG"迅速往$n的方向衝了過去 ,用厚重的甲殼撞擊著$n ,揚起了滿天沙塵"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N"HIG"伸出長長的尾巴 ,對準$n身上狠狠的掃去 ,$n被嚇得措手不及"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N"HIG"朝$n撞了過去 ,數千斤重的身體 ,挾著萬均之勢 ,像要把$n壓進土裡"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  150,
             "damage_type":  "撞傷",
            ]),
       });

void create()
{
     set_name(HIG"盤古真龜"NOR ,({"penku turtle", "turtle"}) );
     set("race", "野獸");
     set("title", "萬年神獸");
     set("no_kill", 1);
     set("no_fight", 1);
     set("age",33972);
     set("long","長年躲居在殼中的大龜 ,和龍 ,鳳 ,麟併稱為四神獸
看起來似乎不容易殺死它 ,除非使用特殊的道具...\n");
     set("attitude","peaceful");   
     set_temp("apply/attack",120);
     set_temp("apply/damage",120);
     set_temp("apply/move",170);
     set("max_kee",129000);
     set("kee",129000);
 set("max_gin",120000);
     set("gin",120000);
 set("max_sen",120000);
     set("sen",120000);
     set("force",9000);
     set("max_force",9000);
     set("force_factor",10);
     set("max_gin", 100000);
     set("max_sen", 100000);
     set("combat_exp",3900000);
 set("chat_chance_combat", 25);         
     set_skill("dodge",400);
     set_skill("parry",400);
     set_skill("unarmed",0);
 
 set("limbs", ({ "龜首", "龜腹", "前肢" , "後足" , "龜尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);
 add_money("gold",100);                      
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
      message_vision(HIG+"盤古真龜"HIY"躲進了殼中 ,深深的吸了一口氣!!!\n"+NOR,enemy[i]);
      me->receive_curing("kee",100000);
      me->receive_heal("kee",100000);
      me->receive_curing("sen",100000);
      me->receive_heal("sen",100000);
      me->receive_curing("gin",100000);
      me->receive_heal("gin",100000);
      me->clear_condition();
      COMBAT_D->report_status(enemy[i], 1);
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   :: heart_beat();
}
void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,turtle;
 ob=this_object();
 turtle=present( "turtle",environment(ob) );
 if(str=="askgod turtle" || str=="askgod penku turtle"){
 write(HIC"龜乃是神獸 ,不可逆天行事\n"NOR);
 return 1;                                                 
                  }
}




