//master_yua.c //cgy
#include <ansi.h>
#include "/open/open.h"
string magic();
string ask_get_dan_sp();
string ask_get_meteor();
string ask_ribbon();
inherit NPC;
inherit F_MASTER;
void create()
{
            object ob;
            set_name("月牙兒",({"master yua","yua"}));
            set("long","她是鏡月島二位美麗的島主之一，擅長舞蹈，據說
她的舞蹈之美會令人以為仙女下凡身處仙境。\n");
            set("gender","女性");
            set("class","dancer");
            set("nickname","霓裳仙子");
            set("combat_exp",5000000);
            set("attitude","heroism");
            set("age",20);
            set("str", 34);
            set("cor", 30);
            set("cps", 50);
            set("per", 24);
            set("int", 40);
          set("kee",30000);
          set("max_kee",30000);
          set("gin",1600);
          set("max_gin",1600);
          set("atman",2000);
          set("max_atman",2000);
          set("mana",400);
          set("max_mana",400);
          set("force",2000);
          set("max_force",2000);
            set_skill("array",60);
            set_skill("parry",60);
            set_skill("spells",50);
            set_skill("magic",120);
            set_skill("cure",60);
            set_skill("force",60);
            set_skill("literate",70);
            set_skill("move",90);
            set_skill("dodge",100);
            set_skill("sword",50);
            set_skill("unarmed",70);
            set_skill("paull-steps",130);
            set_skill("dremagic",100);
            set_skill("dreamforce",90);
            set_skill("dreamdance",100);
        map_skill("magic","dremagic");
        map_skill("dodge","paull-steps");
        map_skill("force","dreamforce");
        map_skill("move","paull-steps");
        map_skill("unarmed","dreamdance");
        set_temp("apply/armor",70);
		set("get_dan_sp",1);
		set("spells/reflection/level",100);
		set("spells/confuse/level",100);
        set("spells/fireball/level",100);
        set("spells/thunder/level",100);
        set("spells/firedance/level",100);
        set("spells/dreamwings/level",1);
		
        set("force_factor",30);
        setup();
        create_family("夜夢小築",3,"宮主");
        carry_object("/open/dancer/obj/yuaboots.c")->wear();
		carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
        carry_object("/open/dancer/obj/yuawaist.c")->wear();
		add_money("diamond",1);
//      ob->set_amount(50);
        set("inquiry", ([
            "傅劍寒"  : "你說的是神龍山莊莊主傅劍寒嗎??他是我傾慕的偶像耶!!",
			"後三式" :  (: ask_get_dan_sp :),
			"流星雨" :  (: ask_get_meteor :),
			"ribbon" : (: ask_ribbon :)
        ]));
        set("chat_chance_combat",60);
        set("chat_msg_combat",({
         (: magic :),
        }));
}
void init()
{       object ob;
        add_action("do_join","join");
        set_heart_beat(1);
}
void heart_beat()
{
        if( is_fighting() ){
		      if(query_temp("ref_shield")!=1)
		      command("conjure reflection");
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
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
          command("say 先去加入舞者公會再來吧\n");
          return;
      }
        command("smile");
        command("nod");
        command("chat 這個世界上又多了一個美麗的舞者了，希望各位多多愛護他..\n");
         ob->query("no_recruit");
        command("recruit "+ob->query("id"));
		new("/open/dancer/obj/ribbon")->move(ob);
        message_vision("月牙兒給了$N一條七彩緞帶 .\n",ob);
        command("say 這是咱們夜夢小築的信物 ,務必妥善保存 !");
}
string ask_ribbon()
{
        if(present("ribbon",this_player()))
		   return "妳不是有了嗎？";
		if(this_player()->query("class")!="dancer")
		   return "妳不是舞者要那個做什？？";
        else
		{
        command("say 唉 , 怎麼那樣不小心呢 !");
        new("/open/dancer/obj/ribbon")->move(this_player());
        return "希望妳能好好保管 , 別再弄不見啦 !\n";
        }
           
}
string ask_get_dan_sp()
{ 
 if(this_player()->query("get_dan_sp")==1)
  return "妳不是學過了？？";
 if(this_player()->query("class")!="dancer")
      {
          command("stare"+this_player()->query("id"));
          return "妳問那麼多幹嘛？";
      }
 if((int)this_player()->query("combat_exp") < 500000)
	   return "等妳經驗值高些再來吧！";
 else
  {
 command("say 很好.....我就將後三式傳授於妳...\n");
 this_player()->set("get_dan_sp",1);
  return "希望妳努力將舞者絕學發揚光大";
 }
}
string ask_get_meteor()
{ 
 if(this_player()->query("spells/meteor/level")==1)
  return "妳不是學過了？？";
 if(this_player()->query("class")!="dancer")
      {
          command("stare"+this_player()->query("id"));
          return "妳問那麼多幹嘛？";
      }
 if((int)this_player()->query_temp("allow_learn")!= 1)
	   return "先通過我師妹的考驗再說吧！";
 else
  {
 command("say 很好.....我就將終極火燄術流星雨傳授於妳...\n");
 this_player()->set("spells/meteor/level",1);
 message("system",HIW + "月牙兒開心的說道:有了"+this_player()->name()+"的幫助定能使舞者更加發揚光大.\n" + NOR,users());
 return "今後要更加努力喔";

 }
}
string magic()
{       
        command("conjure confuse");
        command("conjure fireball");
		command("conjure reflection");
        command("conjure firedance");
        command("conjure thunder");
        command("conjure dreamwings");
        return "\n";
}
 
int accept_fight(object ob)
{
        command("say 小女子怎是您的對手呢??\n");
		command("conjure reflection");
		command("conjure dreamwings");
		command("conjure confuse");
        message_vision( this_object()->name()+"一付弱不禁風的樣子。\n",ob);
        return 1;
}
int accept_kill(object ob)
{
        command("say 沒想到你忍心欺負弱小女子，那我就不客氣了!!!\n");
		command("conjure reflection");
		command("conjure dreamwings");
		command("conjure confuse");
        return 1;
}
int do_join()
{
        object ob=this_player();
        command("shake"+ob->query("id"));
        return notify_fail("想當舞者要去找我師妹水靈兒才行喔!!\n");
}
