#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create()
{

	set_name("海獅", ({"sea lion","lion"}));
	set("age",24);
	set("long","趁著天氣尚可，出來曬曬太陽的海獅。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",30);
	set("con",30);
	set("class","blademan");
	set("bellicosity",3000);
	set("attitude", "friendly");
	set("max_kee",60000);
	set("kee",60000);
	set("max_gin",60000);
	set("gin",60000);
	set("max_sen",60000);
	set("sen",60000);
	set("combat_exp",16000000);
	set("max_force",20000);
	set("force",30000);
	set("force_factor",18);
	set("random_move",200);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("move",200);
	set_skill("force",150);
	set_skill("snow-kee",105);
	set_skill("winter-steps",120);
	set_skill("unarmed",110);
	set_skill("iceforce",100);
	set_skill("beast",100);
	set("chat_chance",100);
        set("chat_msg",({
       (: random_move :),
        }));
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
	set("polar_mob",1);
        set_temp("apply/armor", 210);
        set_temp("apply/defense", 210);
        set_temp("apply/damage", 190);
        set_temp("apply/attack", 190);
	setup();
}

void heart_beat()
{
        object *enemy,*all,me,room;
        int i,j;
        me = this_object();
        room = environment(me);
        enemy = me->query_enemy(room);
        j = sizeof(enemy);
        if(!me) return ;   
   if(!query_temp("unconcious"))
     {            
  	if( !is_fighting())
  	   {	
		if( query("eff_kee") < query("max_kee") ) 
			me->receive_curing("kee",400);
		if( query("eff_gin") < query("max_gin") )
		        me->receive_curing("gin",400);
		if( query("eff_sen") < query("max_sen") )
		        me->receive_curing("sen",400);
		if( query("gin") < query("eff_gin") ) 
		  {
		        message_vision(HIR"$N抓出暗藏的雪國大龍蝦，喀滋喀滋大口嚼了起來，精力復原不少。\n"NOR,me);
			me->receive_heal("gin",400);
		  }
		if( query("kee") < query("eff_kee") )
		  {
		        message_vision(HIW"$N抓出暗藏的北海錦鯉魚，喀滋喀滋大口嚼了起來，元氣振奮不少。\n"NOR,me);
			me->receive_heal("kee",400);
		  }
		if( query("sen") < query("eff_sen") )
		  { 
		        message_vision(HIY"$N抓出暗藏的龍宮鮮大蚌，喀滋喀滋大口嚼了起來，神暝\回復不少。\n"NOR,me);
			me->receive_heal("sen",400);
		  }
	   }
	    else
	        {
	         if(me->is_busy() && random(4) == 1)
	         {
	           message_vision(HIW"$N狂吼一聲，以野獸天生的蠻力解除了身上束縛。\n"NOR,me);
	           me->delete_busy();
	         }
	         if(random(2)==1)
	         {
	         message_vision(HIW"$N突然轉身，用牠厚重有如鐵板的尾巴朝著你一陣亂掃。\n"NOR,me);
	         for( i=0 ; i<j ; i++ )
	         {
	          if(random(4)==1)  
	          {
	           message_vision(HIY"$N被狠狠的掃中，疼得眼冒金星，耳內嗡嗡作響。\n"NOR,enemy[i]);
	           enemy[i]->start_busy(random(2));
	           COMBAT_D->report_status(enemy[i],1);
	          }else{
	           message_vision(GRN"$N嚇了一大跳，趕忙仆倒在地躲過。\n"NOR,enemy[i]);
	           enemy[i]->receive_damage("sen",50);
	                }
	         }
	         }
	        }
       }
        set_heart_beat(1);
        :: heart_beat();
}

void die()
{
	object winner = query_temp("last_damage_from");
	if(!winner)
        {
        ::die();
        return ;
        }    
        winner->add_temp("polar/kill",1);
        ::die();
}
