//master_linr.c //cgy
//加入聖火進階解謎要素    by frequency 2003 May
#include <ansi.h>
#include "/open/open.h"
string magic();
string ask_moon0();
string ask_change();
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
object ob2;
string ask_crystal();
string ask_moon();
void create()
{
            object ob;
            set("guild_master",1);
            set_name("水靈兒",({"master linr","linr"}) );
            set("long","她是月牙兒的師妹，擅長舞蹈，據說
            她的舞蹈之美會令人以為仙女下凡身處仙境。\n");
            set("gender","女性");
            set("class","dancer");
            set("nickname","虹彩仙子");
            set("combat_exp",4000000);
            set("attitude","heroism");
            set("age",20);
            set("str", 30);
            set("cor", 30);
            set("cps", 45);
            set("per", 24);
            set("int", 40);
          set("kee",30000);
          set("max_kee",30000);
          set("gin",16000);
          set("max_gin",16000);
          set("atman",20000);
          set("max_atman",20000);
          set("mana",40000);
          set("max_mana",40000);
          set("force",20000);
          set("max_force",20000);
		  set("max_sen",16000);
         set("sen",16000);
            set_skill("array",50);
            set_skill("parry",40);
            set_skill("spells",30);
            set_skill("magic",90);
            set_skill("cure",60);
            set_skill("force",60);
            set_skill("literate",70);
            set_skill("move",100);
            set_skill("dodge",95);
            set_skill("sword",50);
            set_skill("unarmed",70);
            set_skill("paull-steps",120);
            set_skill("dremagic",95);
            set_skill("dreamforce",100);
            set_skill("dreamdance",90);
        map_skill("magic","dremagic");
        map_skill("dodge","paull-steps");
        map_skill("force","dreamforce");
        map_skill("move","paull-steps");
        map_skill("unarmed","dreamdance");
        set_temp("apply/armor",70);
		set("get_dan_sp",1);
		set("spells/reflection/level",100);
		set("spells/confuse/level",100);
        set("spells/thunder/level",60);
        set("spells/firedance/level",100);
		set("spells/hellfire/level",75);
        set("spells/dreamwings/level",1);
		set("spells/dreamcure/level",100);
		set("adv_dancer",1);
		set("allow_hellfire",1);
		
        set("force_factor",20);
        setup();
        create_family("夜夢小築",3,"副宮主");
        carry_object("/open/dancer/obj/linrboots.c")->wear();
		carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
        carry_object("/open/dancer/obj/yuawaist.c")->wear();
//      ob->set_amount(50);
        set("inquiry", ([
                        "傅劍寒"      : "你說的是神龍山莊莊主傅劍寒嗎??他是我傾慕的偶像耶!!",
			"上代宮主"    : "上任宮主是我二師姐,名叫月半彎,是月牙兒師姐的姊姊",
			"王媽"        : "幾年前聽說她在楓林港過著平凡的生活，現在就不知道了。",
			"流星雨"      : "喔....想學流星雨先打贏我再說吧。",
		        "夜夢雙星"    : "我一直蠻想會會她們的。",
			"鏡月島之謎"  :(: ask_moon0 :),
			"change"      :(: ask_change :),
			"渾天水晶"    :(: ask_crystal :),
                        "太陰虛幻神鑑":(: ask_moon :),
        ]));
        set("chat_chance_combat",60);
        set("chat_msg_combat",({
         (: magic :),
        }));
}
void init()
{
        add_action("do_join","join");
        set_heart_beat(1);
}
string ask_moon0()
{       if (this_player()->query("quests/moon")==1)
        return "你不是問過了???";
		else
        this_player()->set_temp("ask_moon1",1);
		return " 嗯 ,這件事我只是隱約有聽王媽說過 , 詳細情形要問她才知道 !";		
}
string ask_change()
{       int i;
        i=(int)this_player()->query("functions/ranbow-steps/level",1);
        if (!this_player()->query("functions/ranbow-steps"))
        return "你沒學過問這做什???";
		else
        this_player()->set("functions/rainbow-steps/level",i);
		this_player()->delete("functions/ranbow-steps");
		return " 嗯 ,我幫妳改好了 !";		
}
void heart_beat()
{
        if( is_fighting() ){
		   if(query_temp("ref_shield")!=1)
		      command("conjure reflection");
		   if(random(100)>85)
		   command("conjure hellfire");
               
        }
        else{
		if( query("sen") < query("eff_sen") ) // 125
			command( "exert refresh" );
                if( query("eff_kee") < query("max_kee") )
                        command("conjure dreamcure");
        }
        :: heart_beat();
}
  void attempt_apprentice(object ob)
{
      command("l "+ob->query("id"));
      if(this_player()->query("class")!="dancer")
      {
          command("hammer"+ob->query("id"));
          command("say 先加入舞者公會才能拜師喔\n");
          return;
      }
        command("smile");
        command("nod");
        command("chat 這個世界上又多了一個美麗的舞者了，希望各位多多愛護他..\n");
         ob->query("no_recruit");
        command("recruit "+ob->query("id"));
}

 void die()
 {
  if(!ob2){
    write("水靈兒說:想不到妳的武功如此厲害\n"); 
    ::die();
    return ;
  }
   if( ob2->query("class")=="dancer")
     {write("水靈兒說:看來妳的確有這個實力去學習流星雨!\n");
      write("好了 ,妳可以去找我師姐了!\n");
      ob2->set("allow_meteor",1);
	  ob2->set_temp("allow_learn",1);}
  else   
   {
    write("水靈兒說:想不到妳的武功如此厲害\n"); 
    }
   ::die();
  }  
string magic()
{       
	command("conjure reflection");
        command("conjure confuse");
        command("conjure fireball");
        command("conjure firedance");
        command("conjure thunder");
        return "\n";
}
 
int accept_fight(object ob)
{
        
        command("say 小女子怎是您的對手呢??\n");
        message_vision( this_object()->name()+"一付弱不禁風的樣子。\n",ob);
		command("conjure reflection");
		command("conjure confuse");
        return 1;
}
int accept_kill(object ob)
{       ob2=this_player();
        command("conjure reflection");
        command("say 沒想到你忍心欺負弱小女子，那我就不客氣了!!!\n");
		command("conjure confuse");
        return 1;
}
int do_join()
{
        object ob=this_player();
        if(!ob->query("class"))
        {
		 if(this_player()->query("gender")!="女性")
		 {
		 command("grin"+ob->query("id"));
		 return notify_fail("只有女性才能當舞者喔!!你先去把自己閹了再來吧!!\n");
          } 
		if(this_player()->query_per()<25)
        {
            return notify_fail("你長得太醜了不適合當舞者，還是另尋出路吧!!\n");
        }else
        ob->set("class","dancer");
        command("nod "+ob->query("id"));
        }
        else
        {
          return notify_fail("你已經加入門派囉，不能再加入囉。\n");
        }
        message("system",HIC + "水靈兒輕聲吟道：『龍騰八荒，鳳舞九天』
接著又愉快的說道：以"+this_player()->name()+"的資質必可
將我派舞蹈絕學發揚光大。\n" + NOR,users());
        return 1;
}

string ask_crystal()
{
        object me = this_player();
        if(me->query_temp("find_crystal"))
         {
          if(me->query_temp("find_crystal") == 3)   me->set_temp("find_crystal",4);
          return "三師姊應該跟你說過林教主誤會我們了吧，不過我真的聽人謠傳說島內還有水晶。\n";
         }
         else if(me->query("class") == "prayer")
              {
               message_vision(HIW + "\n\n水靈兒冷笑道：「你也未免解太快了吧...」\n\n" + NOR,me);
               return "零分!!";
              }
         else
              {
              command ("say 不是聖火教的問啥問啊!?  去死吧");
              kill_ob(me);
              command("conjure hellfire");
              return "殺殺殺!!";
              }
}

string ask_moon()
{
        object me = this_player();
        if(me->query_temp("find_moon"))
         {
          if(me->query_temp("find_moon") == 1)  me->set_temp("find_moon",2);
          return "這是夜夢雙星所擅長的魔法，據說神奇之處不下於我們的夢玄法鑑。";
         }
         else if(me->query("class") == "prayer")
              {
               return "憑你也配知道...";
              }
         else if(me->query("class") == "dancer")
              {
              message_vision(HIW + "\n\n水靈兒冷笑道：「妳也未免解太快了吧...」\n\n" + NOR,me);
              return "零分!!";
              }
         else
              {
              command ("say 不是聖火教和本門的人問啥問啊!?  去死吧");
              kill_ob(me);
              command("conjure hellfire");
              return "殺殺殺!!";
              }
}
