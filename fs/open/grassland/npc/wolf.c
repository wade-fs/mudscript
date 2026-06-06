inherit NPC;
inherit F_MASTER;
inherit SSERVER;
#include "/open/open.h"
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
void create()
{
        set_name("草原狼", ({ "Prairie Wolf","wolf","Wolf" }) );
        set("race", "野獸");
		set("long","
群居型的野生犬科動物，社會組織複雜而嚴密，是擁有
智慧的高等哺乳類動物，性喜以牲畜為食，擅長集體作戰。
");
		set("title",HIB+"(玩耍中)"+NOR);
        set("attitude", "aggressive");
        set("age", 10);
        set("max_gin", 20000);
        set("max_kee", 20000);
        set("max_sen", 20000);
	    set("gin",20000);
	    set("sen",20000);
	    set("kee",20000);
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
        set_temp("apply/attack", 310);
        set("force_factor",40);
        set("combat_exp", 8500000);
        set_skill("move",100);
        set_skill("dodge",270);
        set_skill("parry",120);
        set_skill("unarmed",120);
        set_skill("rabbit-combat",140);
        set_skill("force",100);
        map_skill("unarmed","rabbit-combat");
        map_skill("parry","rabbit-combat");
		set("chat_msg", ({ (: random_move :)}) );
		set("chat_chance",18);
		setup();
}

void heart_beat()
{
	object mob,me,friend;
	int gin,kee,sen,mgin,mkee,msen,i,k,j,m;
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
	  if(cla=="scholar" || cla=="taoist" || cla=="marksman" || cla=="none") j=random(330);
	  else j=random(200);
	  m = 1+((me->query("MKS"))%3);
	 }
    if(!mob->query_temp("unconcious"))
	{
	if(!mob->is_fighting())
	{
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
	 if(mob->is_busy() && j>34) //解busy機率，對手為四個弱勢職業時是10%，其他職業為17.5%
	  {
	   tell_room(environment(), "\n"HIG+name()+"猛然發出一陣驚悚狼嚎，解除了身上的束縛，並乘著這股聲勢反攻。\n"+NOR);	
	   mob->delete_busy();
	   COMBAT_D->do_attack(mob, me, mob->query_temp("weapon"), 1);
	  }
	 if((random(100) < 69) && ((kee<mkee)||(gin<mgin)||(sen<msen)) && !mob->query_temp("summon"))  
     {
	  tell_room(environment(), "\n"HIW+name()+"縱聲高叫：凹 ～ 嗚 ～ \n"+NOR);
	  tell_room(environment(), HIM+"\n鮮血的氣味與狼嚎引來飢渴的同伴，要一起追殺獵物。\n"+NOR);
	  for(k=0;k<m;k++)  //戰鬥中精氣神降到1/3以下有70%召集1~3名幫手助陣
	  {
	   friend = new(__DIR__"wolf");
	   friend->move(environment(me));
	   friend->set_temp("summon",1);
	   friend->set("title",HIR+"(狩獵)"+NOR);
	   friend->set_leader(me);
	   friend->kill_ob(me);
	  }
       mob->delete_busy();
	   set_skill("beast-combat2",100);
       map_skill("unarmed","beast-combat2");
	   mob->set_temp("summon",1);
	   mob->set("title",HIR+"(狩獵)"+NOR);
	   mob->set_leader(me);
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
    object winner,tail; 
	winner = query_temp("last_damage_from");
    if(!winner)
	{
	::die();
	return ;
    }
    if(!winner->query_temp("kill_wolf")) winner->set_temp("kill_wolf",1);
	else winner->add_temp("kill_wolf",1);
	if(winner->query_temp("sheep_mission") && !winner->query_temp("got_wolf_tail"))
	{
	 tail = new("/open/grassland/obj/wolf-tail");
	 tail->move(winner);
	 tail->set("finder",winner->query("id"));
	 winner->set_temp("got_wolf_tail",1);
	 message_vision(HIW"\n$N從$n的屍體上取下"+tail->query("name")+"。\n\n"NOR,winner,this_object());
	}
    :: die();
}               
