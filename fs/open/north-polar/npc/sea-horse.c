#include <ansi.h>
inherit NPC;
inherit SSERVER;
// 印度洋海神 冰火特性 by frequency
void create()
{

	set_name("海馬", ({"sea horse","horse"}));
	set("title",HIR"印度洋"CYN"海神"NOR);
	set("age",24);
	set("long","印度洋海域的水神，擅長冰火交融的魔法。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",43);
	set("con",43);
	set("spi",43);
	set("int",43);
	set("kar",43);
	set("per",43);
	set("class","blademan");
	set("bellicosity",5000);
	set("attitude", "friendly");
	set("max_kee",130000);
	set("kee",130000);
	set("max_gin",100000);
	set("gin",100000);
	set("max_sen",100000);
	set("sen",100000);
	set("combat_exp",20000000);
	set("max_force",2000000);
	set("force",2000000);
	set("force_factor",60);
    set_temp("no_die_soon",1);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",120);
	set_skill("force",400);
	set_skill("snow-kee",120);
	set_skill("winter-steps",120);
	set_skill("unarmed",130);
	set_skill("iceforce",200);
	set_skill("beast",105);
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
        set_temp("apply/armor", 290);
        set_temp("apply/defense", 290);
        set_temp("apply/damage", 290);
        set_temp("apply/attack", 300);
        set_temp("no_badroar_max",1);
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
	         message_vision(HIG"\n$N雙臂大開，左聚冰雪，右凝熔岩，"HIC"『"HIR"熱壓"HIW"極光"HIC"』"HIG"的強烈溫差像要將人撕裂。\n"NOR,me);
	         for (i=0 ; i < j ; i++)
	         {
              if(enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query("name")!="海馬" && !wizardp(enemy[i])) 
                  {
                    if(environment(me)!= environment(enemy[i]))  continue;
                    k = random(3);
                    if(enemy[i]->query_temp("def_cold"))
                     {
                      enemy[i]->add("kee",-500-random(300));
                     }
                      else{
                           enemy[i]->add("kee",-1000-random(550));
                          }
                    if(enemy[i]->query_temp("def_fire"))
                     {
                      enemy[i]->add("kee",-500-random(300));
                     }
                      else{
                           enemy[i]->add("kee",-1000-random(550));
                          }
                    if(k==0)  enemy[i]->apply_condition("burn",12+random(9));
                    if(k==1)  enemy[i]->apply_condition("cold",12+random(9));
                    if(k==2)  enemy[i]->start_busy(2);
                    COMBAT_D->report_status(enemy[i]);
                  }
                 }
	        }
      }
      
  if(me->query("kee") < 0 || me->query("gin") < 0 || me->query("sen") < 0)
  {
    for(j=0;j<i;j++)
        {
         if(enemy[j] && room == environment(enemy[j]) && userp(enemy[j]))
           {
            if(enemy[j]->query("combat_exp") < 27000000)
             {
              tell_object(enemy[j],HIG"\n在你費盡千辛萬苦打倒海神後，你感到自身戰鬥經驗又更上一層樓了!!\n"NOR);
              tell_object(enemy[j],GRN"你的戰鬥經驗上升 3000 點, 潛在能力上升 750 點!!\n"NOR);
              enemy[j]->add("combat_exp",3000);
              enemy[j]->add("potential",750);
             }
           }
        }
    me->die();
    return ;
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
	message_vision(HIC"\n$N冷笑道"HIW"："HIY"「"HIR"愚蠢!!準備接受海的報復吧!!"HIY"」\n"NOR,me);
        destruct(me);
}
