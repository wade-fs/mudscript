//emery-giant

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("黑砂巨人", ({ "emery-giant","giant" }) );
        set("race", "人類");
	set("age", 160);
	set("long", "全身泛黑的巨型野人，肌膚有如岩石一般的堅硬。\n");
	set("str", 85);
        set("max_kee", 8000);
        set("max_force", 10000);
        set("force",10000);
        set("force_factor",5);
       set("kee", 8000);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",1100000);
	set_temp("apply/armor", 100);
        set_temp("apply/attack", 100);
        set("attitude","aggressive");
	set_skill("dodge",100);
	setup(); 
        carry_object("/open/gsword/obj/ff_item");
        carry_object("/open/gsword/obj/f_item");
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
       message_vision(HIM+"巨人從身上扯下石塊扔了過來，擊中了$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",350,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIC+"抓住了$N，狠狠地朝洞壁甩了過去!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",160,me);
      COMBAT_D->report_status(enemy[i], 0);
      me->receive_curing("kee",200);
      me->receive_heal("kee",200);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
