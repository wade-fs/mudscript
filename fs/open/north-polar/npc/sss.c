#include <ansi.h>
inherit NPC;
inherit SSERVER;
// 洞庭湖水神 busy poison 攻擊力稍弱 kee最少  by frequency
void create()
{

	set_name("海蛇", ({"sea snake","snake"}));
	set("title",HIB"南海"HIR"海神"NOR);
	set("age",24);
	set("long","南海海域的海神，性喜在海面上興風作浪。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",48);
	set("con",48);
	set("spi",48);
	set("int",48);
	set("kar",48);
	set("per",48);
	set("class","blademan");
	set("bellicosity",8500);
	set("attitude", "friendly");
	set("max_kee",70000);
	set("kee",70000);
	set("max_gin",200000);
	set("gin",200000);
	set("max_sen",200000);
	set("sen",200000);
	set("combat_exp",20000000);
	set("max_force",100000);
	set("force",600000);
	set("force_factor",45);
	set("no_die_soon",1);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",120);
	set_skill("force",400);
	set_skill("snow-kee",150);
	set_skill("winter-steps",140);
	set_skill("unarmed",100);
	set_skill("iceforce",200);
	set_skill("beast",100);
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
        set_temp("apply/armor", 350);
        set_temp("apply/defense", 350);
        set_temp("apply/damage", 270);
        set_temp("apply/attack", 250);
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
	         message_vision(HIC"\n$N全身劇烈翻動，引發驚人的大海嘯強襲，在洶湧浪潮下眾人皆無法動彈!!\n"NOR,me);
	         for (i=0 ; i < j ; i++)
	         {
	          if(enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query("id")!="sea snake" && !wizardp(enemy[i]))  
                  {
                    if(environment(me)!= environment(enemy[i]))  continue;
                    k = random(11);
                    if(enemy[i]->query_temp("def_cold"))
                     {
                      enemy[i]->add("kee",-600);
                      enemy[i]->start_busy(2);
                     }
                      else{
                           enemy[i]->add("kee",-900);
                           enemy[i]->start_busy(2+random(3));
                          }
                    message_vision(HIM"\n$N之牙噴出了一股毒液，凡沾上者莫不立刻昏頭轉向。\n"NOR,me);
                    if(k>=0)  enemy[i]->apply_condition("snake_poison",12+random(9));
                    if(k>=1)  enemy[i]->apply_condition("supersnake_poison",12+random(9));
                    if(k>=2)  enemy[i]->apply_condition("rose_poison",12+random(9));
                    if(k>=3)  enemy[i]->apply_condition("dog",12+random(9));
                    if(k>=4)  enemy[i]->apply_condition("fire_poison",12+random(9));
                    if(k>=5)  enemy[i]->apply_condition("u-stial",12+random(9));
                    if(k>=6)  enemy[i]->apply_condition("spring",12+random(9));
                    if(k>=7)  enemy[i]->apply_condition("ff_poison",12+random(9));
                    if(k>=8)  enemy[i]->apply_condition("fog_poison",12+random(9));
                    if(k>=9)  enemy[i]->apply_condition("five_poison",12+random(9));
                    if(k>=10)  enemy[i]->apply_condition("flower",12+random(9));
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
	object me,room;
	me = this_object();
	room = environment(me);
	room->set_temp("can_punch",1);
	room->set("no_reset",1);
	message_vision(HIC"\n$N愕然道"HIW"："HIY"「"HIR"......"HIY"」\n"NOR,me);
        destruct(me);
}
