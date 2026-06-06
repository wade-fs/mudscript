//three_eye lion.c

#include <ansi.h>
inherit NPC;
void create()
{
      set_name("三眼翼獅",({"three_eyes lion","lion"}));
        set("long","有獅子的身體,鷲的臉,同時又擁有翅膀的遠古神話怪物。\n"    );
        set("race", "野獸");
        set("age", 140);
        set("attitude","aggressive");    
        set("max_kee",6000);
        set("max_force",6000);
        set("force",6000);
        set("force_factor",5);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",700000);
	set_temp("apply/armor", 100);
        set_temp("apply/attack", 80);
        set("attitude","aggressive");
	set_skill("dodge",90);
	setup(); 
//        carry_object("/open/gsword/obj/ff_item");
        set_heart_beat(1);
}
void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_object();
  if( me->is_fighting() )
  {
    if( 50 > random(200) )
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
      if(environment(me) == environment(enemy[i]))
      if( random(10) > 7)
      {
       message_vision(HIG + "翼獅展開翅膀引起了巨大的砂風暴攻擊$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",300,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIM+"爆裂的音波朝$N衝擊而來,$N被震的頭昏眼花!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",150,me);
      COMBAT_D->report_status(enemy[i], 0);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
