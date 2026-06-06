#include <ansi.h>
inherit NPC;
inherit SSERVER;
// 北冰洋海神 主打射手狀態 by frequency
void create()
{

	set_name("魔鬼魚", ({"ghost fish","ghost","fish"}));
	set("title",HIW + "北冰洋" + HIC + "海神" + NOR);
	set("age",24);
	set("long","北冰洋海神，擁有可怕的極地靈力。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",40);
	set("con",40);
	set("spi",40);
	set("int",40);
	set("kar",40);
	set("per",40);
	set("class","blademan");
	set("bellicosity",4000);
	set("attitude", "friendly");
	set("max_kee",150000);
	set("kee",150000);
	set("max_gin",100000);
	set("gin",100000);
	set("max_sen",100000);
	set("sen",100000);
	set("combat_exp",20000000);
	set("max_force",2000000);
	set("force",2000000);
	set("force_factor",35);
    set_temp("no_die_soon",1);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",120);
	set_skill("force",400);
	set_skill("snow-kee",140);
	set_skill("winter-steps",130);
	set_skill("unarmed",150);
	set_skill("iceforce",200);
	set_skill("beast",120);
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
        set_temp("apply/armor", 300);
        set_temp("apply/defense", 300);
        set_temp("apply/damage", 300);
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
	         message_vision(HIR + "$N一式北國神技" + HIG + "『" + HIW + "極光" + HIM + "障壁" + HIG + "』" + HIR + "發出萬道耀眼寒光，在場生物非死即傷。\n" + NOR,me);
	         for (i=0 ; i < j ; i++)
	         {
	          if(enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query("id")!="ghost fish" && !wizardp(enemy[i]))  
                  {
                    if(environment(me)!= environment(enemy[i]))  continue;
                    k = random(3);
                    if(enemy[i]->query_temp("def_cold")) enemy[i]->add("kee",-1000);
                    else enemy[i]->add("kee",-2000);
                    if(k==0)
                            {
                    	     enemy[i]->set_temp("over/r-eyes",1);
                    	     enemy[i]->set_temp("over/l-eyes",1);
                    	    }
                    if(k==1)  enemy[i]->apply_condition("no_power",8+random(7));
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
              tell_object(enemy[j],HIG + "\n在你費盡千辛萬苦打倒海神後，你感到自身戰鬥經驗又更上一層樓了!!\n" + NOR);
              tell_object(enemy[j],GRN + "你的戰鬥經驗上升 3200 點, 潛在能力上升 760 點!!\n" + NOR);
              enemy[j]->add("combat_exp",3200);
              enemy[j]->add("potential",760);
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
	message_vision(HIC + "\n$N冷笑道" + HIW + "：" + HIY + "「" + HIR + "愚蠢的人們，你們就和這骯髒的地上世界一起葬送在大海之中吧。" + HIY + "」\n" + NOR,me);
        destruct(me);
}
