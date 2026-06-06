#include <ansi.h>
inherit NPC;
// 洞庭湖水神 主打force by frequency
void create()
{

	set_name("劍齒虎", ({"saber-toothed tiger","tiger"}));
	set("title",HIY + "洞庭湖" + HIM + "水神" + NOR);
	set("age",24);
	set("long","洞庭湖水域的水神，自古即為中土重要神祇之一。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",48);
	set("con",48);
	set("spi",48);
	set("int",48);
	set("kar",48);
	set("per",48);
	set("class","blademan");
	set("bellicosity",8000);
	set("attitude", "friendly");
	set("max_kee",140000);
	set("kee",140000);
	set("max_gin",100000);
	set("gin",100000);
	set("max_sen",100000);
	set("sen",100000);
	set("combat_exp",20000000);
	set("max_force",2000000);
	set("force",2000000);
	set("force_factor",70);
    set_temp("no_die_soon",1);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",120);
	set_skill("force",400);
	set_skill("snow-kee",130);
	set_skill("winter-steps",130);
	set_skill("unarmed",160);
	set_skill("iceforce",200);
	set_skill("beast",125);
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
        set_temp("apply/armor", 310);
        set_temp("apply/defense", 310);
        set_temp("apply/damage", 310);
        set_temp("apply/attack", 310);
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
	         message_vision(HIY + "\n$N對空咆嘯，" + HIG + "『" + HIB + "藍天" + HIG + "碧脈衝" + HIB + "』" + HIY + "帶著在場所有人的元力直衝九霄。\n" + NOR,me);
	         for (i=0 ; i < j ; i++)
	         {
	          if(enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query("id")!="saber-toothed tiger" && !wizardp(enemy[i]))  
                  {
                    if(environment(me)!= environment(enemy[i]))  continue;
                    k = random(3);
                    if(enemy[i]->query_temp("def_cold"))
                     {
                      enemy[i]->add("force",-400-random(300));
                      enemy[i]->add("kee",-1200);
                     }
                      else{
                           enemy[i]->add("force",-800-random(400));
                           enemy[i]->add("kee",-2000);
                          }
                    if(k==0)  enemy[i]->apply_condition("power-down",12+random(9));
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
              tell_object(enemy[j],HIG + "\n在你費盡千辛萬苦打倒水神後，你感到自身戰鬥經驗又更上一層樓了!!\n" + NOR);
              tell_object(enemy[j],GRN + "你的戰鬥經驗上升 3300 點, 潛在能力上升 780 點!!\n" + NOR);
              enemy[j]->add("combat_exp",3300);
              enemy[j]->add("potential",780);
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
	object mob,winner,room,spirit;
	mob = this_object();
	winner = mob->query_temp("last_damage_from");
	room = environment(mob);
	room->set_temp("can_punch",1);
	message_vision(HIC + "\n$N冷笑道" + HIW + "：" + HIY + "「" + HIR + "算你們運氣好，不過也僅止於此了。" + HIY + "」\n" + NOR,mob);
	if( (random(36) == 18 && userp(winner)) || wizardp(winner))
	{
	spirit = new("/open/ghost-hole/obj/water-spirit");
	spirit->move(winner);
        write_file("/log/sky/spirit/water-spirit",sprintf("%s(%s)讓劍齒虎掉下了%s於 %s\n",winner->name(1),winner->query("id"),spirit->query("name"),ctime(time())));
	message_vision(HIW + "薀含在"+this_object()->query("name")+HIW + "身體中的"+spirit->query("name")+HIW + "飛射而出，落在$N" + HIW + "手中。\n" + NOR,winner);
	}
        destruct(mob);
}
