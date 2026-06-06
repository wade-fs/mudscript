#include <ansi.h>
inherit NPC;
inherit SSERVER;
// 太平洋海神  空間傳送 by frequency
void create()
{

	set_name("海龍", ({"sea dragon","dragon"}));
	set("title",HIC + "太平洋" + HIW + "海神" + NOR);
	set("age",24);
	set("long","太平洋海域的海神，擁有穿梭不同空間的能力。\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",49);
	set("con",49);
	set("spi",49);
	set("int",49);
	set("kar",49);
	set("per",49);
	set("class","blademan");
	set("bellicosity",9000);
	set("attitude", "friendly");
	set("max_kee",140000);
	set("kee",140000);
	set("max_gin",100000);
	set("gin",100000);
	set("max_sen",100000);
	set("sen",100000);
	set("combat_exp",20000000);
	set("max_force",100000);
	set("force",600000);
	set("force_factor",85);
	set("no_die_soon",1);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",120);
	set_skill("force",400);
	set_skill("snow-kee",120);
	set_skill("winter-steps",120);
	set_skill("unarmed",160);
	set_skill("iceforce",200);
	set_skill("beast",118);
	map_skill("dodge","winter-steps");
	map_skill("unarmed","beast");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
        set_temp("apply/armor", 280);
        set_temp("apply/defense", 280);
        set_temp("apply/damage", 310);
        set_temp("apply/attack", 320);
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
	         message_vision(HIM + "\n$N劃破一道時空縫隙，" + HIB + "『" + HIY + "黃金三角洲" + HIB + "』" + HIM + "不斷發出強大的吸扯力量。\n" + NOR,me);
	         for (i=0 ; i < j ; i++)
	         {
	          if(enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) && enemy[i]->query("id")!="sea dragon" && !wizardp(enemy[i]))  
                  {
                    if(environment(me)!= environment(enemy[i]))  continue;
                    if(!enemy[i]->query_temp("de_cold"))  enemy[i]->add(kee,-random(3800));
                    else enemy[i]->add(kee,-random(2000));
                    k = random(6);
                    if(k >= 3)  message_vision("$n抵抗不住強大的拉力，掉進了時空縫隙之中。\n" + NOR,me,enemy[i]);
                    if(k==0)  enemy[i]->apply_condition("cold",12+random(9));
                    if(k==1)  enemy[i]->start_busy(2);
                    if(k==2)  enemy[i]->start_busy(1);
                    if(k==3)  enemy[i]->move("/open/north-polar/room05");
                    if(k==4)  enemy[i]->move("/open/north-polar/room30");
                    if(k==5)  enemy[i]->move("/open/north-polar/room17");
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
	message_vision(HIC + "\n$N冷笑道" + HIW + "：" + HIY + "「" + HIR + "愚蠢!!準備接受海的報復吧!!" + HIY + "」\n" + NOR,me);
    environment(winner)->delete_temp("block");


        destruct(me);
}
