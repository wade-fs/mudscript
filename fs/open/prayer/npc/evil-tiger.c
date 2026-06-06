//evil-tiger.c

#include <ansi.h>
inherit NPC;
void create()
{
      set_name("邪虎",({"evil-tiger"}));
        set("long","破邪洞窟中邪惡的野獸，毛硬如鐵，行動快速。常躲在岩壁之中，在伺機出來攻擊敵人。\n"    );
        set("race", "野獸");
        set("age", 160);
        set("attitude","aggressive");    
        set("max_kee",7000);
        set("max_sen",7000);
        set("max_gin",7000);
        set("max_force", 10000);
        set("force",10000);
        set("force_factor",5);
        set("kee",7000);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",900000);
	set_temp("apply/armor", 100);
        set_temp("apply/attack", 90);
        set("attitude","aggressive");
	set_skill("dodge",90);
	setup(); 
        carry_object("/open/gsword/obj/ff_item");
        add_money("gold",20);
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
       message_vision(HIY + "邪虎張開大口,尖銳的牙齒咬住了$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",300,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIM+"邪虎以高速向$N衝擊而來,$N被撞的飛了十多丈!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",160,me);
      COMBAT_D->report_status(enemy[i], 0);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
