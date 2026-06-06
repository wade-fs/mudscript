#include <ansi.h>
inherit NPC;
inherit SSERVER;
// 鄱陽湖水神 強攻型 by frequency
void create()
{

	set_name("雙頭龍", ({"double dragon","double","dragon"}));
	set("title",HIG + "鄱陽湖" + HIY + "水神" + NOR);
	set("age",24);
	set("long","職司鄱陽湖水域的水神，自古以來掌控著江南穀\倉的興衰。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",50);
	set("con",50);
	set("spi",50);
	set("int",50);
	set("kar",50);
	set("per",50);
	set("class","blademan");
	set("bellicosity",9000);
	set("attitude", "friendly");
	set("max_kee",1800000);
	set("kee",180000);
	set("max_gin",100000);
	set("gin",100000);
	set("max_sen",100000);
	set("sen",100000);
	set("combat_exp",20000000);
	set("max_force",2000000);
	set("force",2000000);
	set("force_factor",90);
    set_temp("no_die_soon",1);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",100);
	set_skill("force",400);
	set_skill("snow-kee",120);
	set_skill("winter-steps",130);
	set_skill("unarmed",180);
	set_skill("iceforce",200);
	set_skill("beast",140);
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
        set_temp("apply/armor", 280);
        set_temp("apply/defense", 270);
        set_temp("apply/damage", 320);
        set_temp("apply/attack", 350);
        set_temp("absorb",1);
        set_temp("no_badroar_max",1);
	setup();
}

void heart_beat()
{
        object *enemy,*all,me,room;
        int i,j,k;
        me = this_object();
        room = environment(me);
if(!room) return ;
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
	         message_vision(HIC + "\n$N引發大自然力量，" + HIR + "『" + HIY + "雙龍" + HIW + "冰風暴" + HIR + "』" + HIC + "一出，身旁頓時風雪大作。\n" + NOR,me);
	         for (i=0 ; i < j ; i++)
	         {
	          if(enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query("id")!="double dragon" && !wizardp(enemy[i]))  
                  {
                    if(environment(me)!= environment(enemy[i]))  continue;
                    k = random(3);
                    if(enemy[i]->query_temp("def_cold")) enemy[i]->add("kee",-1000-random(1000));
                    else enemy[i]->add("kee",-2000-random(1600));
                    if(k==0)  enemy[i]->apply_condition("ice",12+random(9));
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
              tell_object(enemy[j],GRN + "你的戰鬥經驗上升 3500 點, 潛在能力上升 800 點!!\n" + NOR);
              enemy[j]->add("combat_exp",3500);
              enemy[j]->add("potential",800);
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
	object mob,room,spirit,me;
        me = query_temp("last_damage_from");
	mob = this_object();
	room = environment(mob);
	room->set_temp("can_punch",1);
	message_vision(HIC + "\n$N冷笑道" + HIW + "：" + HIY + "「" + HIR + "竟然妄想與神作對，好好等待最後的審判吧。" + HIY + "」\n" + NOR,mob);
	if( random(36) == 18 && userp(me) )
	{
	spirit = new("/open/ghost-hole/obj/ice-spirit");
	spirit->move(me);
        write_file("/log/sky/spirit/ice-spirit",sprintf("%s(%s)讓雙頭龍掉下了%s於 %s\n",me->name(1),me->query("id"),spirit->query("name"),ctime(time())));
	message_vision(HIW + "薀含在"+this_object()->query("name")+HIW + "身體中的"+spirit->query("name")+HIW + "飛射而出，落在$N" + HIW + "手中。\n" + NOR,me);
	}
        destruct(mob);
}
