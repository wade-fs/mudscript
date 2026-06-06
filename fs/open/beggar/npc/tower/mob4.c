#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create()
{

	set_name("北極熊", ({"polar bear","bear"}));
	set("age",24);
	set("long","全身覆著毛茸茸的皮，他一覺醒來，正想找些食物果腹。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",30);
	set("con",30);
	set("score",1000000);
	set("class","blademan");
	set("bellicosity",3000);
	set("attitude", "aggressive");
	set("max_kee",100000);
	set("kee",100000);
	set("max_gin",80000);
	set("gin",80000);
	set("max_sen",80000);
	set("sen",80000);
	set("combat_exp",16000000);
	set("max_force",40000);
	set("force",50000);
	set("force_factor",30);
	set("random_move",300);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",140);
	set_skill("move",200);
	set_skill("force",150);
	set_skill("snow-kee",140);
	set_skill("winter-steps",120);
	set_skill("unarmed",160);
	set_skill("iceforce",140);
	set_skill("beast",130);
	set("chat_chance",100);
        set("chat_msg",({
       (: random_move :),
        }));
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
	set("polar_mob",1);
        set_temp("apply/armor", 240);
        set_temp("apply/defense", 240);
        set_temp("apply/damage", 240);
        set_temp("apply/attack", 240);
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
		        message_vision(HIR + "$N抓出暗藏的雪國大龍蝦，喀滋喀滋大口嚼了起來，精力復原不少。\n" + NOR,me);
			me->receive_heal("gin",400);
		  }
		if( query("kee") < query("eff_kee") )
		  {
		        message_vision(HIW + "$N抓出暗藏的北海錦鯉魚，喀滋喀滋大口嚼了起來，元氣振奮不少。\n" + NOR,me);
			me->receive_heal("kee",400);
		  }
		if( query("sen") < query("eff_sen") )
		  { 
		        message_vision(HIY + "$N抓出暗藏的龍宮鮮大蚌，喀滋喀滋大口嚼了起來，神暝\回復不少。\n" + NOR,me);
			me->receive_heal("sen",400);
		  }
	   }
	    else
	        {
	         if(me->is_busy() && random(4) == 1)
	         {
	           message_vision(HIW + "$N狂吼一聲，以野獸天生的蠻力解除了身上束縛。\n" + NOR,me);
	           me->delete_busy();
	         }
	         if(random(3)==1)
	         {
	         message_vision(HIW + "$N大吼一聲，用牠長有長長利爪的熊掌劈頭就是一揮。\n" + NOR,me);
	         for( i=0 ; i<j ; i++ )
	         {
	          if(random(3)!=1)  
	          {
	           message_vision(HIY + "$N被一掌掃中，身上留下數道長長的疤痕，嚇得驚懼不已。\n" + NOR,enemy[i]);
	           enemy[i]->receive_wound("gin",100);
	           enemy[i]->receive_wound("kee",300);
	           enemy[i]->receive_wound("sen",100);
	           COMBAT_D->report_status(enemy[i]);
	          }else{
	           message_vision(GRN + "$N嚇了一大跳，趕忙仆倒在地躲過。\n" + NOR,enemy[i]);
	           enemy[i]->start_busy(1);
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
        winner->add_temp("ko_bear",1);
    environment(winner)->delete_temp("block");
    destruct(this_object());

        ::die();
}
