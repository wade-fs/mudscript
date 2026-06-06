#include <ansi.h>
inherit NPC;
inherit SSERVER;
// 東海海神 主打精神  附一擊死  氣血較少  by frequency
void create()
{

	set_name("海魔音", ({"sea girl","girl"}));
	set("title",HIM + "東海" + HIY + "海神" + NOR);
	set("age",24);
	set("long","東海海域的水神，其音樂方面的造詣古今罕有。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",48);
	set("con",48);
	set("spi",48);
	set("int",48);
	set("kar",48);
	set("per",48);
	set("class","blademan");
	set("bellicosity",7000);
	set("attitude", "friendly");
	set("max_kee",80000);
	set("kee",80000);
	set("max_gin",80000);
	set("gin",80000);
	set("max_sen",80000);
	set("sen",80000);
	set("combat_exp",20000000);
	set("max_force",100000);
	set("force",600000);
	set("force_factor",68);
	set("no_die_soon",1);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",140);
	set_skill("force",400);
	set_skill("snow-kee",140);
	set_skill("winter-steps",140);
	set_skill("unarmed",120);
	set_skill("iceforce",200);
	set_skill("beast",100);
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
        set_temp("apply/armor", 320);
        set_temp("apply/defense", 320);
        set_temp("apply/damage", 300);
        set_temp("apply/attack", 300);
	setup();
}

void heart_beat()
{
        object *enemy,*all,me,room;
        int i,j,k;
        me = this_object();
        room = environment(me);
        enemy = all_inventory(environment(me));
        j = sizeof(enemy);
        if(!me) return ;   
   if(!query_temp("unconcious"))
     {            
  	if( !is_fighting())
  	   {	
		if( query("eff_kee") < query("max_kee") ) 
			me->receive_curing("kee",500);
		if( query("eff_gin") < query("max_gin") )
		        me->receive_curing("gin",500);
		if( query("eff_sen") < query("max_sen") )
		        me->receive_curing("sen",500);
		if( query("gin") < query("eff_gin") ) 
		  {
			me->receive_heal("gin",500);
		  }
		if( query("kee") < query("eff_kee") )
		  {
			me->receive_heal("kee",500);
		  }
		if( query("sen") < query("eff_sen") )
		  { 
			me->receive_heal("sen",500);
		  }
	   }
	    else
	        {
	         if(random(10) < 4)
	          {      
	          	 me->delete_busy();
	          	 return;
	          }
	         message_vision(HIB + "\n$N朱唇湊近橫笛，" + HIC + "『" + HIR + "死亡交響樂" + HIC + "』" + HIB + "的悽美旋律遠遠傳了開來，所有人如癡如醉。\n" + NOR,me);
	         for (i=0 ; i < j ; i++)
	         {
	          if(enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query("id")!="sea girl" && !wizardp(enemy[i]))  
                  {
                    if(environment(me)!= environment(enemy[i]))  continue;
                    if(random(100) == 24)
                     {
                      message_vision(HIB + "\n$N演奏的樂章終了前，" + HIY + "『" + HIB + "死亡最高潮" + HIY + "』" + HIB + "同時將$n葬送於美麗的"+room->query("short")+"。\n" + NOR,me,enemy[i]);
                      enemy[i]->die();
                      continue;
                     }
                    k = random(2);
                    if(enemy[i]->query_temp("def_cold"))
                     {
                      enemy[i]->add("sen",-600);
                      enemy[i]->add("kee",-600);
                      enemy[i]->add("gin",-600);
                     }
                      else{
                           enemy[i]->add("sen",-1000);
                           enemy[i]->add("gin",-1000);
                           enemy[i]->add("kee",-1000);
                          }
                    if(k==0)  enemy[i]->apply_condition("cold",12+random(9));
                    if(k==1)  enemy[i]->start_busy(2);
                    COMBAT_D->report_status(enemy[i]);
                  }
                 }
	        }
      }
        set_heart_beat(1);
        :: heart_beat();
}

void die()
{
  object winner=query_temp("last_damage_from");
	object me,room;
	me = this_object();
	room = environment(me);
	room->set_temp("can_punch",1);
	room->set("no_reset",1);
	message_vision(HIC + "\n$N嘆道" + HIW + "：" + HIY + "「" + HIR + "想不到最後的死亡樂章竟是為我自己而奏。" + HIY + "」\n" + NOR,me);
    environment(winner)->delete_temp("block");
        destruct(me);
}
