inherit NPC;
inherit F_MASTER;
inherit SSERVER;
#include "/open/open.h"
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
void create()
{
        set_name("猛虎", ({ "Tiger","tiger" }) );
        set("race", "野獸");
		set("long","
位於食物鏈頂端的肉食哺乳動物，天性獨居的大貓，
在這附近常以人類所飼養的牲畜為食。
");
		set("title",HIB+"(懶洋洋)"+NOR);
        set("attitude", "aggressive");
        set("age", 10);
        set("max_gin", 25000);
        set("max_kee", 26000);
        set("max_sen", 25000);
	    set("gin",25000);
	    set("sen",25000);
	    set("kee",26000);
        set("str", 90);
        set("cor", 90);
        set("spi", 20);
        set("int", 20);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("bellicosity",12000);
        set("max_force",12000);
        set("force",52000);
		set("max_atman",90000);
        set("atman",500000);
        set_temp("apply/armor", 300);
        set_temp("apply/defense", 300);
        set_temp("apply/damage", 210);
        set_temp("apply/attack", 410);
        set("force_factor",45);
        set("combat_exp", 8800000);
        set_skill("move",100);
        set_skill("dodge",270);
        set_skill("parry",120);
        set_skill("unarmed",100);
        set_skill("beast-combat",140);
        set_skill("force",100);
        map_skill("unarmed","beast-combat");
        map_skill("parry","beast-combat");
		set("chat_msg", ({ (: random_move :)}) );
		set("chat_chance",15);
		setup();
}

void heart_beat()
{
	object mob,me,weapon;
	int gin,kee,sen,mgin,mkee,msen,i,k,j;
	string cla;
	mixed enemy;
	mob = this_object();
	if(!environment()) return;
	if(!mob) return ;
	enemy = all_inventory(environment(mob));
    i=sizeof(enemy);
	me = offensive_target(mob);
	kee = mob->query("kee");
	sen = mob->query("sen");
	gin = mob->query("gin");
	kee = kee*3;
	gin = gin*3;
	sen = sen*3;
	mkee = mob->query("max_kee");
	msen = mob->query("max_sen");
	mgin = mob->query("max_gin");
	command("open door");
	if(me)
	 {
	  cla = me->query("class");
	  if(!cla) cla="none";
	  if(cla=="scholar" || cla=="taoist" || cla=="marksman" || cla=="none") j=random(200);
	  else j=random(100);
	 }
    if(!mob->query_temp("unconcious"))
	{
	if(!mob->is_fighting())
	{
	  if(mob->query_temp("kang-power"))
	  {
	      if(!mob) return ;
		  mob->delete_temp("mana_shield"); //非戰鬥時解除dreamwings和kang_power、水月
		  mob->delete_temp("kang-power");
		  mob->delete_temp("absorb");
		  mob->set("title",HIB+"(懶洋洋)"+NOR);
	      tell_room(environment(), HIW+name()+"的怒氣漸漸平息下來。\n"+NOR);	
	  }
	  if(i>0) //非戰鬥時，對同一格的玩家和sheep下kill
	   for(k=0;k<i;k++)
	   {
        if(!wizardp(enemy[k]) && (userp(enemy[k]) || enemy[k]->query("id") == "Sheep")) 
         {
 	       kill_ob(enemy[k]);
           //break; 
	     }
	   }
	}
	if(me && mob->is_fighting(me))
	{
     if(!mob) return ;
	 if(mob->is_busy() && j>34) //解busy機率，對手為四個弱勢職業時是17.5%，其他職業為35%
	  {
	   tell_room(environment(), "\n"HIM+name()+"猛然發出一陣攝人虎嘯，解除了身上的束縛，並乘著這股聲勢反攻。\n"+NOR);	
	   mob->delete_busy();
	   COMBAT_D->do_attack(mob, me, mob->query_temp("weapon"), 1);
	  }
	 if((random(100) < 70) && ((kee<mkee)||(gin<mgin)||(sen<msen)) && !mob->query_temp("kang-power"))  
     {
      mob->set_temp("mana_shield",1);  //戰鬥中精氣神降到1/3以下有70%機率發動水月、dreamwings和kang_power
	  mob->set_temp("absorb",2);
	  mob->set_temp("kang-power",1);
	  mob->receive_curing("gin",10000);
      mob->receive_heal("gin",10000); 
	  mob->receive_curing("kee",10000);
      mob->receive_heal("kee",10000);
	  mob->receive_curing("sen",10000);
      mob->receive_heal("sen",10000);
	  mob->add("atman",10000);
	  mob->add("force",10000);
	  mob->delete_busy();
	  mob->set("title",HIR+"(憤怒)"+NOR);
	  tell_room(environment(), "\n"HIR+name()+"怒道：老虎不發威，你把我當病貓嗎!?吼～\n\n"+NOR);
	 }
	 if(me->query("id") == "Sheep" && random(10)>1)  //跟sheep戰鬥有80%機率會回復精氣神
	 {
	  tell_room(environment(), "\n"HIW+name()+"開心的從綿羊身上咬了一大口肉，瞬間恢復不少活力!!\n\n"+NOR);
	  mob->receive_curing("gin",2400);
      mob->receive_heal("gin",2400); 
	  mob->receive_curing("kee",2400);
      mob->receive_heal("kee",2400);
	  mob->receive_curing("sen",2400);
      mob->receive_heal("sen",2400);
	  mob->add("atman",5000);
	  mob->add("force",5000);
	  COMBAT_D->report_status(mob);
	  me->receive_damage("kee",2000);
	  COMBAT_D->report_status(me);
	 }
	}
	}
   set_heart_beat(1);
   :: heart_beat();
}          

void die()
{
    object winner,fur;
	winner = query_temp("last_damage_from");
    if(!winner)
	{
	::die();
	return ;
    }
    if(!winner->query_temp("kill_tiger")) winner->set_temp("kill_tiger",1);
	else winner->add_temp("kill_tiger",1);
	if(winner->query_temp("sheep_mission") && !winner->query_temp("got_tiger_fur"))
	{
	 fur = new("/open/grassland/obj/tiger-fur");
	 fur->move(winner);
	 fur->set("finder",winner->query("id"));
	 winner->set_temp("got_tiger_fur",1);
	 message_vision(HIW"\n$N從$n的屍體上取下"+fur->query("name")+"。\n\n"NOR,winner,this_object());
	}
    :: die();
}               
