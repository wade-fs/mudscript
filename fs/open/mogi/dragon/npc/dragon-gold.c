//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIY + "兇性大發 ,銳利的龍爪向$n狠狠的抓了過去 ,似要撕裂$n" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N" + HIY + "迅速撲至$n面前 ,滿天爪影朝$n猛擊下去 ,$n當場鮮血飛濺" + NOR + "。
",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIY + "將全身力量集中在尾巴 ,對準$n身上狠狠的掃去 ,好不驚人" + NOR + "。
",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  240,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N" + HIY + "朝$n猛撞了過去 ,千斤重的身體 ,挾著萬均之勢 ,令人髮指" + NOR + "。
",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  275,
             "damage_type":  "撞傷",
            ]),
([ "action":"$N" + HIY + "一聲狂吼 ,從口中噴出" + HIR + " 烈燄 " + HIY + "將$n的身體整個攏罩住" + NOR + "。",
             "dodge"      : -30,
             "parry"      :  -30,
             "damage"     : 292,
             "damage_type":  "嚴重灼傷",
           ]),
       });

void create()
{
     set_name(HIY + "黃金甲龍" + NOR ,({"golden dragon", "dragon"}) );
     set("race", "野獸");
     set("clan_kill",1);
     set("title", "炎龍谷守護者");
     set("age",103972);
     set("long","原本是整座炎龍谷的守護者 ,上古時代的魔獸 ,但因為
身上似乎有著什麼秘密 ,被鄭柳兩家的人合力擒捕 ,後
來鄭雨橋出賣了柳家 ,將它私藏 ,才有這一段恩怨情仇\n");
     set("attitude","aggressive");   
     set_temp("apply/attack",470);
     set_temp("apply/damage",470);
     set_temp("apply/move",470);
     set("bellicosity",39999);
     set("max_kee",50000);
     set("kee",50000);
     set("force",20000);
     set("max_force",20000);
     set("force_factor",60);
     set("gin", 50000);
     set("sen", 50000);
     set("max_gin", 50000);
     set("max_sen", 50000);
     set("combat_exp",4700000);
     set("chat_chance_combat", 32);
     set_skill("dodge",590);
     set_skill("move", 540);
     set_skill("parry",570);
     set_skill("unarmed",540);
  set("chat_chance",90);                    
  set("chat_msg", ({                        
       (: random_move :),   
  }) );                                     
 set("limbs", ({ "龍首", "龍身", "前肢" , "後足" , "龍尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);
 add_money("gold",100);                      
carry_object("/open/mogi/dragon/obj/scale.c");    
carry_object("/open/mogi/dragon/obj/dragon-head.c");

}
mapping query_action()
{
   return action[random(sizeof(action))];
}

void heart_beat()
{

 mixed all;
 object me,room,obj;
 int maxkee,kee,i,j,count;
 count = random(100);
 me = this_object();
 room = environment(me);
 if(!room) return ;
 all = all_inventory(room);
 if(count < 30 && me->is_fighting())
 {
  message_vision(HIY + "\n黃金甲龍" + MAG + "瘋狂的亂竄，四處饑渴的吸食鮮血\n" + NOR,me);

  for( i = 0 ; i < sizeof(all) ; i++)
  {
    obj = all[i];
   if( obj->is_character() && !obj->is_corpse() && living(obj)
    && obj->query("id")!="golden dragon")
     {
      message_vision(HIR + "\n你被飛濺的血浪震攝住，也受到不小的衝擊\n" + NOR,obj);
      obj->add("kee",-420);
      obj->start_busy(1);
//     me->start_busy(1);
 
      COMBAT_D->report_status(obj, 1);
     }
   }
 }
 if(count < 20  && me->is_fighting())
  {
  message_vision(HIR + "\n黃金甲龍兇性大發，對你" + HIR + "做出猛烈的攻擊\n\n" + NOR,me);
  for( i = 0 ; i < sizeof(all) ; i++)
   {
    obj = all[i];
    if( obj->is_character() && !obj->is_corpse() && living(obj)
         && obj->query("id")!="golden dragon")
     {
      me->set("name","(" + HIR + "狂暴" + NOR + ")" + HIY + "黃金甲龍" + NOR);
     for(j=0;j<10;j++)
     {
     message_vision(HIY + "$N" + HIY + "被(" + HIR + "狂暴" + NOR + ")" + HIY + "黃金甲龍狠狠抓中，滿身血痕\n" + NOR,obj);
      if (obj->query("class")=="fighter" && obj->query_temp("keeup")==1)
        obj->receive_wound("kee",100+random(300));
      else if ((obj->query("class")=="prayer" && obj->query_temp("hwa_je")==1)
               || (obj->query("class")=="dancer" && obj->query_temp("ref_shield")==1)
               || (obj->query("class")=="dancer" && obj->query_temp("rainbow-steps")==1)
               || (obj->query("class")=="poisoner" && obj->query_temp("snake-steps")==1))
        obj->receive_wound("kee",100+random(200));      
      else
        obj->receive_wound("kee",100+random(100));
      COMBAT_D->report_status(obj, 1);
     }

      message_vision(HIB + "\n黃金甲龍瘋狂的撕咬後，漸漸平靜下來\n\n" + NOR,me);
      me->start_busy(1);
     }
   }
  }


 if( random(10) < 2 )
 {
  if( is_fighting() )
  {
   if( query("kee") < query("eff_kee") )
    message_vision(HIY + "\n黃金甲龍身上發出耀眼的光芒，傷口似乎慢慢癒合了\n" + NOR,me);
    me->set("name",HIY + "黃金甲龍" + NOR);
    me->receive_heal("kee",1000);
    me->receive_heal("gin",1000);
    me->receive_heal("sen",1000);
    me->delete_busy();
    me->clear_condition();
  }
  else
  {
   if( query("eff_kee") < query("max_kee") )
    command("exert heal");
    me->add("force",500);
  }
 }
::heart_beat();
  
}

 void die()           
{
    object winner = query_temp("last_damage_from");        

    new("/open/mogi/dragon/obj/power")->move(environment(winner));
    
   tell_object(winner,HIR + "\n\n龍的真元緩緩的從屍身上浮起\n\n\n" + NOR);            
   winner->set_temp("use_scale_number",15);
  //只能讓ko dragon的人 use scale 最多十五次
 if(winner->query("class")=="swordsman" && winner->query_temp("swordquest/findball")==6)
{
    object ob;
  ob=new("/open/gsword/obj1/swordball.c");
   tell_object(winner,HIR + "你從甲龍的屍體上取出下了連陽劍晶珠.." + NOR);
    ob->move(winner);
   winner->set_temp("swordquest/findball",7);
   tell_object(users(),HIR + "
黃金甲龍發出異常的哀嚎.....

在一陣駭人哀嚎之後，" + HIY + "黃金甲龍" + HIW + "終於慘遭屠戮 . .

魔界漸漸的回復了平靜，地上的人們也正為這場勝利歡呼著 !!\n" + NOR);
  ::die();
}
else
{
                   
   
   tell_object(users(),HIW + "                                                
                                                                            
    勇者" + HIB+winner->query("name")+HIW + "經過漫長艱辛的浴血之戰，終於將" + HIY + "黃金甲龍" + HIW + "手刃 . . .        
                                                                            
魔界漸漸的回復了平靜，地上的人們也正為這場勝利歡呼著 !!\n" + NOR);     
 ::die();
}
                               
}

