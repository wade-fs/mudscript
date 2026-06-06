// by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({

([ "action" :"$N"HIG"獸性一起 ,前爪向$n強勁的抓了過去 ,眼看猛烈的一擊就要打到$n了"NOR"。",
          
                "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  220,
             "damage_type":  "抓傷",

           ]),
([ "action" :"$N"HIG"迅速往$n的方向衝了過去 ,用厚重的甲殼撞擊著$n ,揚起了滿天沙塵"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  200,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N"HIG"伸出長長的尾巴 ,對準$n身上狠狠的掃去 ,$n被嚇得措手不及"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  210,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N"HIG"朝$n撞了過去 ,數千斤重的身體 ,挾著萬均之勢 ,像要把$n壓進土裡"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  220,
             "damage_type":  "撞傷",
            ]),
       });

void create()
{
     set_name(HIG"盤古真龜『"HIW"無殼"HIG"』"NOR ,({"penku turtle", "turtle"}) );
     set("race", "野獸");
     set("title", "萬年神獸");    
     set("age",33972);
     set("long","長年躲居在殼中的大龜 ,和龍 ,鳳 ,麟併稱為四神獸
但現在已經失去殼了 ,不過還是相當的可怕\n");
     set("attitude","peaceful");   
     set_temp("apply/attack",120);
     set_temp("apply/damage",120);
     set_temp("apply/move",170);
     set("max_kee",9000);
     set("kee",9000);
 set("max_gin",12000);
     set("gin",12000);
 set("max_sen",12000);
     set("sen",12000);
     set("force",9000);
     set("max_force",7900);
     set("force_factor",20);

     set("combat_exp",3400000);
 set("chat_chance_combat", 25);         
     set_skill("dodge",400);
     set_skill("parry",400);
     set_skill("unarmed",300);
 
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
      message_vision(HIG+"盤古真龜"HIY"狂吼了一聲 ,震到你氣血翻騰!!!\n"+NOR,enemy[i]);
     enemy[i]->receive_damage("kee", 90,me);
      COMBAT_D->report_status(enemy[i], 1);
     }
   }
// 經 casey 同意以下為 AceLan 增加有關武器原料的部份 98.7.16
   if( this_object()->is_fighting()
      && random( 100) > 90)
   {
      new("/u/a/acelan/weapon/turtle_blood")->move( environment());
      message_vision( HIR+"盤古真龜突然猛烈的咳嗽, 咳出了一些珍貴的真龜血晶。\n"
+NOR, this_player());
   }
// 到此為止...
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

 void die()                                                                 
{
    object winner = query_temp("last_damage_from");        

    new("/open/island/obj/power")->move(environment(winner));
    
   tell_object(winner,HIR"\n\n真龜的元神緩緩的從屍身上浮起\n\n\n"NOR);                                
   
  
            ::die();                                                           
      }                                                                     


