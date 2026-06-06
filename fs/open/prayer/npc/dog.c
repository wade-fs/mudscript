#include <ansi.h>
inherit NPC;
void create()
{
	set_name("火犬", ({ "flame dog","dog" }) );
        set("race", "野獸");
	set("age", 20);
	set("long", "聖火教精心調教的守門犬,全身如火炎般通紅.\n");
	set("str", 55);
        set("max_kee", 3000);
        set("kee", 3000);
        set("limbs", ({ "頭部", "腹部","身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",250000);
	set_temp("apply/armor", 80);
        set_temp("apply/attack", 40);
        set("attitude","peaceful");
	set_skill("dodge",70);
	setup(); 
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
       message_vision(HIG+"火犬露出銳利的尖牙,一口咬住了$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",120,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIC+"火犬用牠的尾巴捲住了$N的喉嚨,企圖要讓$N窒息而亡!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",60,me);
      COMBAT_D->report_status(enemy[i], 0);
      me->receive_curing("kee",60);
      me->receive_heal("kee",60);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
