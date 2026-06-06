//copy from cage,re-edit from ccat
//修正強度by cyw 91/03/19
#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;

void berserk(object me, object victim, object  weapon, int damage);
void blockade(object me, object victim, object weapon, int damage);
mapping *action = ({
([ "action" : "$N手成爪狀,對準$n"+HIW+"腦門" + NOR+"直插而下,正是九陰白骨爪第一招"+
	       HIW+" 破首式" + NOR,
		"dodge"      :	  -100,
		"parry"      :	  -100,
		"force":          200,
		"damage"     :	  200,
		"damage_type":	 "抓傷",
	   ]),
([ "action" : "$N雙爪交錯而過,對準$n"+HIW+"胸口" + NOR+"抓去,正是九陰白骨抓之第二招"+
	       HIW+" 開膛式" + NOR,
		"dodge"      :	   -100,
		"parry"      :	   -100,
		"force":           180,
		"damage"     :	   180,
		"damage_type":	 "抓傷",
	   ]),
([ "action" : "$N雙爪穿過$n的防禦圈,由下而上往$n之"+HIW+"喉嚨" + NOR+"抓去,正是九陰白骨爪之"+
	      "第三招"+HIW + " 斷喉式" + NOR,
		"dodge"      :	   -100,
		"parry"      :	   -100,
		"force":          200,
		"damage"     :	  200,
		"damage_type":	 "抓傷",
	    ]),
([ "action" : "$N一爪在前,一爪在後,迅急無比的往$n"+HIW+"心臟" + NOR+"挖去,正是九陰白骨爪之"
	     +"第四招"+HIW + " 腕心式" + NOR,
		"dodge"      :	  -100,
		"parry"      :	  -100,
	        "force":         250,
		"damage"     :	 250,
		"damage_type":	 "抓傷",
	    ]),
([ "action" : "$N運起真氣,灌勁於爪,招式詭異的往$n"+HIW+"下襠" + NOR+"攻去,正是九陰白骨爪之"
	     +"第五招"+HIW + " 斷陰式" + NOR,
		"dodge"      :	  -100,
		"parry"      :	  -100,
                "force":         300,
		"damage"     :	 300,
		"damage_type":	 "抓傷",
	    ]), 	 	   	       
([ "action" : "$N虛晃一招,雙爪立刻往$n"+HIW+"雙眼" + NOR+"刺去,正是九陰白骨爪之"
	     +"第六招"+HIW + " 去目式" + NOR,
		"dodge"      :	   -100,
		"parry"      :	   -100,
		"force":         350,
		"damage"     :	 350,
		"damage_type":	 "抓傷",
	    ]), 	 
([ "action" : "$N將自身內勁提升八成,直擊$n"+HIW+"全身骨格" + NOR+",正是九陰白骨爪之"
	     +"第七招"+HIW + " 碎骨式" + NOR,
		"dodge"      :	   -100,
		"parry"      :	   -100,
		"force":         400,
		"damage"     :	 400,
		"damage_type":	 "抓傷",
	    ]), 	 
([ "action" : "$N利爪快速旋轉凌厲的攻擊$n"+HIW+"全身百穴" + NOR+",,正是九陰白骨爪之"
	     +"第八招"+HIW + " 破穴式" + NOR,
		"dodge"      :	   -100,
		"parry"      :	   -100,
                "force":         450,
		"damage"     :	 450,
		"post_action":          (: blockade :),
		"damage_type":	 "抓傷",
	    ]), 	 
([ "action" : "$N全身泛起藍色氣勁,雙爪無情的撕裂天地萬物,正是九陰白骨爪之"
	     +"最後一招"+HIB + " 九陰滅地" + NOR,
		"dodge"      :	   -100,
		"parry"      :	   -100,
		"force":         500,
		"damage"     :	 500,
		"post_action":          (: berserk :),
		"damage_type":	 "抓傷",
	    ])
   });

void create()
{
	set("title",HIR+"黑風雙剎" + NOR);
	set_name("梅超風", ({"mechoufen"}));
	set("class","fighter");
	set("age",35);
	set("long","曾經名動江湖一時,手中殺人無數,黑風雙剎之銅屍,梅超風.\n");
	set("gender","女姓");
	set("str",30);
	set("con",30);
	set("max_kee", 50000);
        set("kee", 50000);
        set("max_gin", 50000);
        set("gin", 50000);
        set("max_sen", 50000);
        set("sen", 50000);
        set("force", 20000);
        set("max_force", 20000);
	set("force_factor",60);
	set_skill("dodge",150);
	set_skill("force",200);
	set_skill("parry",100);
	set_skill("snowforce",200);
	set_skill("snow-kee",150);
	set_skill("linpo-steps",150);
	set_skill("unarmed",100);
	set_temp("apply/damage", 150);
        set_temp("apply/armor", 90);
        set_temp("apply/defense",90);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 50);
        set_temp("final-attack",3);
        map_skill("parry","snow-kee");
	map_skill("force","snowforce");
	map_skill("dodge","linpo-steps");
	set("chat_chance_combat",25);
	set("chat_msg_combat",({
	"梅超風說: 你是哪來的高手,竟趕來打擾我修練!!\n",
	"梅超風說: 不教訓你,你不知道我黑風雙剎的可怕!!\n",
	"梅超風說: 殺殺殺殺!!!\n",
	}));
	set_temp("apply/armor",100);
	set_temp("apply/damage",80);
	setup();
       carry_object("/open/gsword/obj/sick_item");
	carry_object("open/center/obj/mechoufen-head");
	add_money("gold",25);
	set("default_actions", (: call_other, __FILE__,"query_action" :));
	
	reset_action();
}

mapping query_action()
{
	return action[random(sizeof(action))];
}
void greeting(object ob)
{
    int exp,lv_1;
    string skill;
    object weapon;
    exp =ob->query("combat_exp",1);
    if( exp < 100000 )
    {
      say("梅超風說: 喂!!"+ob->name(1)+"!! 這裡不是肉腳該來的地方,快滾吧!!\n");
      return;
    }else{
      weapon = ob->query_temp("weapon");     
      if( weapon ) skill = weapon->query("skill_type");
      else skill = "unarmed";
      lv_1 =ob->query_skill(skill, 1);
      if( lv_1 > 50)
      {
	set_skill("unarmed", lv_1);
	set_skill("force", lv_1);
      }
      exp = exp * 1.5;
      set("combat_exp",exp);
      kill_ob(ob);
      ob->kill_ob(this_object());
    }
    return;
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i,kee;
 mapping exit;
 string *exit_name;

 mob = this_object();
 env = environment(mob);
 
 if( random(100) < 30 && mob->is_fighting())
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=offensive_target(mob);
    if(target){
    kee = target->query("max_kee") * 0.4;
    if( env == environment(target) )
    {
      message_vision(HIR+"$N一個不留意,被九陰白骨爪正面擊中!!!\n"+NOR,target);
      target->receive_wound("kee",random((int)kee),mob);
      COMBAT_D->report_status(target,0);
    }
    }
 }
 
 if(((mob->query("kee")<mob->query("max_kee")*0.6)||
     (mob->query("gin")<mob->query("max_gin")*0.6)||
     (mob->query("sen")<mob->query("max_sen")*0.6))&& (random(100) < 10) )
 {
    tell_room(environment(), HIY+name()+"運起九陰真經之氣療法,為自己"
	       +"療傷.\n"+NOR);
    mob->receive_curing("kee",2000);
    mob->receive_heal("kee",2000);
    mob->receive_curing("sen",2000);
    mob->receive_heal("sen",2000);
    mob->receive_curing("gin",2000);
    mob->receive_heal("gin",2000);
 }

 if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 20) && mob->is_fighting() )
 {
   exit = env->query("exits");
   exit_name = keys(exit);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
 }
   
   set_heart_beat(1);
   ::heart_beat();
   
}
void blockade(object me, object victim, object weapon, int damage)
{
      
        if( !me->query_temp("berserk") && 70>random(100) )
        {                             
                        message_vision(HIY + "$n被破穴式餘勁所遷制,全身穴道暫時被封住了。\n" + NOR, me, victim);
                        victim->receive_wound("kee",700);
                        victim->apply_condition("star-stial",random(10));
                        victim->start_busy(random(3));
                        COMBAT_D->report_status(victim);
        }else message_vision(HIY + "$n以自家內勁護體勉強擋住此式。\n" + NOR, me, victim);
}
void berserk(object me, object victim, object weapon, int damage)
{
        int i; 
     
   if( !me->query_temp("berserk") && 70>random(100) )
        {
                
                me->set_temp("berserk", 1);
                for(i = 0;i < 9; i++)
                {                 
                        message_vision(HIC + "$N催勁狂暴，九陰白骨爪向$n如利劍般殺去。\n" + NOR, me, victim);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                }
                me->delete_temp("berserk");
               
        }
}


void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;

        if(!winner)
	{
	::die();
	return ;
        }
        winner->set_temp("kill_mechoufen",1);
/*	if ( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj8/plum_wind")->move(environment(winner));
	  message_vision(HIM + "\n從梅超風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/plum_wind",sprintf("%s(%s) 讓梅超風掉下了梅飄風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj8/plum_wind")->move(environment(winner));
	  message_vision(HIM + "\n從梅超風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/plum_wind",sprintf("%s(%s) 讓梅超風掉下了梅飄風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}*/
	::die();                                                           
}

