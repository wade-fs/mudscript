inherit NPC;
//inherit F_MASTER;
inherit SSERVER;
#include "/open/open.h"
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
void create()
{
        set_name("綿羊", ({ "Sheep","sheep"}) );
		set("long","
遊牧民族賴以維生的典型動物，可提供獸皮、奶水以及肉食，
是維繫部落生存的重要牲畜。
");
        set("race", "野獸");
        set("age",8);
        set("max_gin", 18000);
        set("max_kee", 20000);
        set("max_sen", 18000);
	    set("gin",18000);
	    set("sen",20000);
	    set("kee",18000);
        set("str", 40);
        set("cor", 23);
        set("spi", 10);
        set("int", 10);
        set("limbs", ({ "頭部", "身體", "前蹄", "後蹄", "羊角" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("bellicosity",10000);
        set("max_force",20000);
        set("force",23000);
        set("chat_chance",17);                    
        set("chat_msg", ({ (: random_move :),"咩～\n" }) );
        set_temp("apply/armor", 300);
        set_temp("apply/defense", 500);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 50);
	    set_temp("go","踏");
        set("force_factor",15);
        set("combat_exp", 7800000);
        set_skill("move",200);
        set_skill("dodge",230);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("force",300);
        set_skill("rabbit-combat",120);
        map_skill("unarmed","rabbit-combat");
		map_skill("parry","rabbit-combat");
        setup();
}

void heart_beat()
{
	object mob,me,weapon;
	int gin,kee,sen,mgin,mkee,msen,enf,dodge,k;
	string cla;
	mob = this_object();
	if(!environment()) return;
	if(!mob) return ;
	if(!mob->query_temp("unconcious"))
	{
	me = offensive_target(mob);
	if(me) 
	 {
	  weapon = me->query_temp("weapon");
	  dodge = me->query_skill("dodge");
	  cla = me->query("class");
	 }
	kee = mob->query("kee");
	sen = mob->query("sen");
	gin = mob->query("gin");
	kee = kee*3;
	gin = gin*3;
	sen = sen*3;
	mkee = mob->query("max_kee");
	msen = mob->query("max_sen");
	mgin = mob->query("max_gin");
	k = 1+random(10);
	if(!cla) cla = "none";
	if(dodge==0) dodge = 1;
	if(cla=="scholar" || cla=="taoist" || cla=="marksman" || cla=="none")
	{
     /*以裸體且dodge 120,step 100之上述四種職業為例，當mob busy時，有12.5%機率震武器
	   其他職業之裸體，假設dodge 120,step 100若mob busy,25%機率震武器,若mob不busy,12.5%機率震武器
       增加en dodge值可降低被震武器之機率*/
    dodge = dodge*2;
	k = 100;
	}
	dodge = 1+random(dodge);
	if(dodge < 40 && me && userp(me))
	if(mob->is_fighting(me) && me && weapon && weapon->query("equipped") == "wielded" && (mob->is_busy()|| (k > 5)))
	{ 
	 message_vision(HIR + "$N發狂似的朝前方猛烈一撞!!\n" + NOR,mob);
	 if(weapon->query("skill_type")=="unarmed" && !me->query_condition("power-down"))  
	 {//若所裝武器為unarmed系，則不震武器，改為附加虛弱狀態,enf越高虛弱越久
	  tell_object(me,HIY + "你被撞得眼冒金星，頓時渾身酸軟!!\n\n" + NOR);
	  enf = me->query("force_factor");
	  enf = enf/10;
	  if(enf>5) enf=5;
	  else if(enf<2) enf=2;
	  me->apply_condition("power-down",enf);
	  me->apply_condition("flower",enf);
	 } else {
	         weapon->unequip();
			 tell_object(me,HIY + "你被撞得眼冒金星，手中兵器頓時鬆脫!!\n\n" + NOR);
	        }
    }
	
	if((random(100) < 30) && ((kee<mkee)||(gin<mgin)||(sen<msen)) )
	{
          if(!mob) return ;
	      mob->receive_curing("kee",3000);
	      mob->receive_heal("kee",3000);
	      mob->receive_curing("gin",3000);
	      mob->receive_heal("gin",3000);
	      mob->receive_curing("sen",3000);
	      mob->receive_heal("sen",3000);
	      tell_room(environment(), "\n" + HIG+name()+"就地啃起新鮮牧草，表情看起來舒坦多了!!\n"+NOR);
		  COMBAT_D->report_status(mob);
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
    if(!winner->query_temp("kill_sheep")) winner->set_temp("kill_sheep",1);
	else winner->add_temp("kill_sheep",1);
    :: die();
}               
