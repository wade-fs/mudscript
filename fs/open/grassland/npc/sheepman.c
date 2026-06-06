inherit NPC;
inherit SSERVER;
#include <ansi.h>
#include "/open/open.h"
#include <combat.h>
string ask_mission();
void create()
{
	set_name("牧羊人",({"sheepman"}));
	set("long","
他是守護家族羊群的牧羊人，雖然工作很辛苦，
但為了生計著想，還是每天咬著牙工作，確保羊
群吃飽喝飽之外，還得保護牠們的安全。
");
	set("gender","男性");
	set("combat_exp",8000000);
	set("attitude","peaceful");
	set("age",38);
	set("class","dancer");
	set("family/family_name","夜夢小築");
	set("str", 30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
         set("max_force",25000);
         set("force",25000);
         set("max_kee",25000);
		 set("max_atman",40000);
		 set("atman",400000);
		 set("bellicosity",8000);
	set_skill("blade",120);
        set_skill("sand-blade",100);
	set_skill("parry",110);
        set_skill("fly-steps",100);
		set("force_factor",35);
	set_skill("dodge",120);
        set_skill("move",90);
        set_skill("fly-steps",100);
		set_skill("dremagic",100);
		set_skill("magic",120);
        map_skill("blade", "sand-blade");
        map_skill("dodge","fly-steps");
        map_skill("move","fly-steps");
        map_skill("parry","sand-blade");
		map_skill("magic","dremagic");
		set_temp("apply/armor", 100);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 80);
        set_temp("apply/attack", 50);
		set("get_dan_sp",1);
        set("spells/fdragon/level",100);
        set("spells/confuse/level",100);
        set("spells/fireball/level",100);
        set("spells/hellfire/level",100);
        set("spells/thunder/level",100);
        set("spells/mirror/level",100);
        set("spells/firedance/level",100);
        set("spells/dreamwings/level",100);
		set("spells/meteor/level",100);
        set("allow_hellfire",1);
		set("allow_fdragon",1);
		set("allow_meteor",1);
		set("chat_chance",35);                    
        set("chat_msg", ({ (: random_move :),"山裡的老虎和狼常會來偷吃牲畜，真煩啊～\n" }) );
		set("inquiry",([
  "偷吃" : (: ask_mission :)
                     ]));
	setup();
        carry_object("/open/capital/obj/Hblade")->wield();
	add_money("silver",90);
}

void greeting(object me)
{
 object pill1,pill2,ob;
 me = this_player();
 ob = this_object();
 if(me && userp(me) && me->query_temp("kill_sheep"))
	{
	command("angry");
	if(!ob->query_condition("blade_pill") && !ob->query_condition("dodge_pill"))
	  {
		command("say 竟敢打我羊群的主意，搬出全部家當跟你拼啦！");
		pill1=new("/open/fire-hole/obj/g-pill");
		pill2=new("/open/fire-hole/obj/r-pill");
		pill1->move(ob);
		pill2->move(ob);
		command("eat pill");
		command("eat pill");
	  }
	  else command("say 竟敢打我羊群的主意，老子跟你拼啦！");
	  kill_ob(me);
	}
  return;
}

int accept_object(object me,object ob)
{
 object cloth;
 if(ob->query("finder"))
 {
   if(ob->query("finder") != me->query("id"))
   {
     command("say 這不是你依約親手取得的，所以恕我無法送你東西，但還是收下啦！感激不盡！");
	 destruct(ob);
	 return 1;
   }
   if(me->query_temp("got_sheep_cloth"))
   {
    command("太好了！");
	return 1;
   }
   if(ob->query("id") == "tiger-fur")
   {
    command("say 太好了，這真的是虎皮");
	me->set_temp("give_tiger_fur",1);
	if(me->query_temp("give_wolf_tail"))
	{
	me->set_temp("got_sheep_cloth",1);
	cloth = new("open/grassland/obj/sheep-cloth");
	cloth->move(me);
	command("say 感謝你的幫忙，這件羊皮大衣是我親手做的，穿起來非常暖和，就送給你吧！");
	} else command("say 就差狼尾了，麻煩您好人做到底嘍！");
   }
   else if(ob->query("id") == "wolf-tail")
   {
    command("say 太好了，這真的是狼尾");
	me->set_temp("give_wolf_tail",1);
	if(me->query_temp("give_tiger_fur"))
	{
	me->set_temp("got_sheep_cloth",1);
  	cloth = new("open/grassland/obj/sheep-cloth");
 	cloth->move(me);
 	command("say 感謝你的幫忙，這件羊皮大衣是我親手做的，穿起來非常暖和，就送給你吧！");
	} else command("say 就差虎皮了，麻煩您好人做到底嘍！");
   }
   destruct(ob);
   return 1;
 }
}

string ask_mission()
{
  object me,ob,pill1,pill2;
  me = this_player();
  ob = this_object();
  if(!me->query_temp("kill_sheep"))
  {
   if(!me->query_temp("sheep_mission"))
    {
    command("say 就是在這一帶活動的老虎和狼啊，每天都來偷吃我的羊，煩死了！");
	command("say 如果你能幫忙把牠們除掉，帶虎皮跟狼尾來的話，我就送你親手做的禮物！");
	me->set_temp("sheep_mission",1);
    } else {
	       command("say 麻煩你幫我解決這件事，會有報酬的。");
	       }
  } else {
           command("say 殺了我的羊還跑來裝瘋賣傻!? 給我去死吧！");
		   pill1=new("/open/fire-hole/obj/g-pill");
		   pill2=new("/open/fire-hole/obj/r-pill");
		   pill1->move(ob);
		   pill2->move(ob);
		   command("eat pill");
		   command("eat pill");
         }
  return "";
}

void heart_beat()
{
   object ob,pill,me;
   int gin,kee,sen,k,j;
   string cla;
   ob = this_object();
   if(!environment()) return;
   if(!ob) return ;
   me = offensive_target(ob);
   gin = ob->query("gin");
   kee = ob->query("kee");
   sen = ob->query("sen");
   gin = gin*3;
   kee = kee*3;
   sen = sen*3;
   if(!ob->query_temp("unconcious"))
   {
   if(me)
   {
    cla = me->query("class");
	if(!cla) cla = "none";
    k = me->query("max_kee");
    k = 1+(k/3000);
   }
   j=random(5);    //敵人為一般職業時，解busy及放hellfire、fdragon之機率為20%
   if(cla=="scholar" || cla=="taoist" || cla=="marksman" || cla=="none") j=random(10);
   //敵人為上四種職業時解busy及放hellfire、fdragon之機率為10%
   if(me && ob->is_fighting(me))
    {
	 if(!ob->is_busy())
      {
    	 if(k>1) command("conjure thunder"); //玩家max_kee>3000 施放thunder
	     if(k>2) command("conjure fireball"); //玩家max_kee>6000 追加fireball
	     if(k>3) command("conjure meteor"); //玩家max_kee>9000 追加meteor
	  }
	 else if(j==1)
     {
	  message_vision(HIW"\n$N牛脾氣上來，以遊牧民族的蠻性硬是掙脫束縛。\n",ob);
	  ob->receive_damage("kee",100);
	  ob->delete_busy();
	  COMBAT_D->report_status(ob);
      command("conjure hellfire");
	 }
	  else if(j==2)
	     {
		   message_vision(HIW"\n$N牛脾氣上來，以遊牧民族的蠻性硬是掙脫束縛。\n",ob);
		   ob->delete_busy();
		   ob->receive_damage("kee",100);
		   COMBAT_D->report_status(ob);
	       command("conjure fdragon");
		   COMBAT_D->report_status(me);
		 }
	}
   if(!ob->query_condition("mon_pill") && ((gin<ob->query("max_gin")) || (kee<ob->query("max_kee")) || (sen<ob->query("max_sen"))))
     {
	  pill=new("/open/mon/obj/mon-pill");
	  pill->move(ob);
	  command("eat pill");
	 }
   }
   set_heart_beat(1);
   :: heart_beat();
}
