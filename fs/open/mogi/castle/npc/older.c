
// by roger
#include <ansi.h>
inherit NPC;
int do_acc();
void create()
{      
        set("title","仙劍派第二代掌門");
        set_name("上官無極",({"older"}));
	set("family/family_name","仙劍派");
        set("gender","男性");
        set("age",90);
        set("str",30);
        set("long","他是仙劍派第二代掌門掌門，幾十年前將掌門傳給鄭士欣後從江湖上退
隱，沒想到竟在「妖魔古堡」裡。\n");   
        set("inquiry",([
        "妖魔古堡" : "我本是仙劍掌門，前來尋找我師弟風清揚的下落，沒想到這些妖魔實在太厲害了，尤其是「焚天魔王」。\n我現在正想辦法「逃出去」。\n" ,
        "焚天魔王" : (:do_acc:),
        "逃出去"   : "我師弟當年在古堡裡找到一個「地點」，這地點的妖氣較薄弱且比較特殊，只要花一點靈力就可逃出去。\n不過我師弟當年受傷過重，因此在逃出不久後仍被抓回。\n",
        "地點"     : "上二樓後往北到底再往西即是，後悔的話就快走吧\n",
        "風青雲" : "他是我師弟，傳承本門祖師逍遙子之另一絕學「連陽七訣劍法」，不過他甚少涉足江湖你應該沒聽過\n",
        ]));
        add_action("do_acc","acc");
        set("combat_exp",4000000);
        set("max_gin",30000);
        set("gin",3000);
        set("max_kee",30000);
        set("kee",3000);
        set("max_sen",30000);
        set("sen",3000);
	set("dragon-sword",1);
	set("str", 50);
	set("cor", 50);
	set("cps", 50);
	set("con", 50);
	set("int", 50);
	set("s_kee",1000);
	set("max_s_kee",1000);
	set("sec_kee","god");
	set("functions/sha_kee/level",100);
	set("functions/swordkee/level",100);
	set_skill("literate",40);
	set_skill("cure",50);
	set_skill("magic",20);
	set_skill("spells",20);
	set_skill("shasword",100);
	set_skill("shaforce",80);
	set_skill("sha-steps",100);
	set_skill("sha-array",100); 
        set_skill("array",100);
        set_skill("move",80);
	set_skill("force",70);
        set_skill("dodge",80);
        set_skill("parry",120);
        set_skill("sword",120);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        map_skill("parry","shasword");
        set("force_factor",30);
	set("get_sha_sp", 1);
	set("quests/sunfire",1);
	set("quest/sun_fire_sword",1);
	set("bounds", 4000000);
	set("roared",1);
	set_temp("roared",1);
	set_temp("apply/armor",150);
	set_temp("apply/attack",75);
	set_temp("apply/damage",75);
	set_temp("apply/defense",150);
	set("chat_chance_combat",90);
	set("chat_msg_combat",({
	(: perform_action,"sword.sha_kee" :)
	}));
        setup();
	carry_object("/open/gsword/obj/dragon-sword.c")->wield();
	add_money("gold",50);
}
int accept_fight(object who)
{
	return tell_object(who,"上官無極說:我快死了...還想打我？\n");
}
int accept_kill(object who)
{
	object me=this_object();
	if( me->is_fighting() )			return 1;
	if( me->query("have_kill") == 1 )	return 1;
	if( !who->query_temp("kill_older") )
	{
	who->add_temp("kill_older",1);
	return tell_object(who,"上官無極說：我快死了...還想殺我？\n");
	}else{
	  if( who->query_temp("kill_older") == 1 )
	  {
	  who->add_temp("kill_older",1);
	  return tell_object(who,"上官無極說：這位"+RANK_D->query_respect(who)+"，您真是太無禮了，不要逼我呀！\n");
	  }
	  if( who->query_temp("kill_older") == 2 )
	  {
	  who->delete_temp("kill_older");
	  kill_ob(who);
	  me->set("have_kill",1);
	  command("cmd god_kee");
	  command("perform sword.sha_kee");
	  me->full();
	  message_vision(HIR + "上官無極說：欺人太甚呀！拼盡我全部的力量也要讓你付出代價！！\n" + NOR,who);
	  message_vision(HIY + "只見$N全身暴出一陣金光，精氣神變為飽滿狀態了！\n" + NOR,who);
	  return 1;
	  }
	}
}
void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) 

        {
        remove_call_out("greeting");
        call_out("greeting",1,obj);
        }
}
void greeting(object ob)
{
	object mob=this_object();
        command("sigh");
	if( mob->query("kee") < 3000 )
	mob->set("kee",3000);
}
int do_acc()
{
object me;
me = this_player();
    command("say 焚天魔王是妖魔古堡之主，武功非常強，最可怕的是什麼極火三掌的...");
    command("say 極火三掌一出，焚天烈地，威不可擋，實在是太可怕了..."); 
    command("fear");
    command("say 聽說「風青雲」「被關」在古堡裡，地點由魔王親自把守。");
    return 1;
}
int full()
{
	object me=this_object();
	set("max_force",50000);
	set("force",500000);
	set("bellicosity", 50000);
        set("combat_exp",8000000);
        set("max_gin",80000);
        set("eff_gin",80000);
        set("gin",80000);
        set("max_kee",80000);
        set("eff_kee",80000);
        set("kee",80000);
        set("max_sen",80000);
        set("eff_sen",80000);
        set("sen",80000);
	return 1;
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
/*        if(userp(winner)) {	 
	if ( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {      
	  new("/open/sky/obj7/deer-order")->move(environment(winner));
	  message_vision(HIM + "\n從上官無極的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj7/deer_order",sprintf("%s(%s) 讓上官無極掉下了祥鹿結令於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj7/deer-order")->move(environment(winner));
	  message_vision(HIM + "\n從上官無極的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj7/deer_order",sprintf("%s(%s) 讓上官無極掉下了祥鹿結令於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
        }*/
	::die();							     
} 								    

