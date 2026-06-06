//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIY + "兇性大發 ,銳利的龍爪向$n狠狠的抓了過去 ,似要撕裂$n" + NOR + "。",
             "dodge"      :  -70,
             "parry"      :  -65,
             "damage"     :  60,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N" + HIY + "迅速撲至$n面前 ,滿天爪影朝$n猛擊下去 ,$n當場鮮血飛濺" + NOR + "。
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  70,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIY + "將全身力量集中在尾巴 ,對準$n身上狠狠的掃去 ,好不驚人" + NOR + "。
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  70,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N" + HIY + "朝$n猛撞了過去 ,千斤重的身體 ,挾著萬均之勢 ,令人髮指" + NOR + "。
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  75,
             "damage_type":  "撞傷",
            ]),
([ "action":"$N" + HIY + "一聲狂吼 ,從口中噴出" + HIR + " 烈燄 " + HIY + "將$n的身體整個攏罩住" + NOR
"。",
             "dodge"      : 40,
             "parry"      :  -60,
             "damage"     : 72,
             "damage_type":  "嚴重灼傷",
           ]),
       });

void create()
{
     set_name(HIY + "黃金甲龍" + NOR ,({"golden dragon", "dragon"}) );
     set("race", "野獸");
     set("title", "炎龍谷守護者");
     set("age",9972);
     set("long","此乃炎龍谷的守護者 ,為上古時代的魔獸");
     set("attitude","aggressive");
     set_temp("apply/attack",140);
     set_temp("apply/damage",50);
     set_temp("apply/move",70);
     set("max_kee",12000);
     set("kee",12000);
     set("force",9000);
     set("max_force",9000);
     set("force_factor",20);
     set("max_gin", 9000);
     set("max_sen", 9000);
     set("combat_exp",3500000);
     set_skill("dodge",240);
     set_skill("parry",200);
     set_skill("literate",130);
     set_skill("unarmed",200);
 set("limbs", ({ "龍首", "龍身", "前肢" , "後足" , "龍尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);
}
mapping query_action()

{
   return action[random(sizeof(action))];
}

void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,king;
 ob=this_object();
 king=present( "dragon",environment(ob) );
 if(str=="askgod dragon" || str=="askgod golden dragon"){
 write(HIY + "黃金甲龍：「求神問卜!?先把我殺死。」去死吧!!\n" + NOR);
 command("perform fireforce.gold-fire");
 king->kill_ob(who);
 return 1;                                                 
                  }
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
      message_vision(HIY+"黃金甲龍" + MAG + "狠狠的咬住$N的頸子吸血!!!\n"+NOR,enemy[i]
);
      enemy[i]->receive_damage("kee", 70,me);
      me->receive_curing("kee",100);
      me->receive_heal("kee",100);
      COMBAT_D->report_status(enemy[i], 1);
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   :: heart_beat();
}

