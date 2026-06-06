// master_yua.c 
#include <ansi.h>
#include "/open/open.h"
string magic();
inherit NPC;
int ask_gonfu();
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
            set("combat_exp",2000000);
            set("attitude","heroism");
            set("get_dan_sp",1);
            set("age",20);
            set("str", 30);
            set("cor", 30);
            set("cps", 50);
            set("per", 50);
            set("int", 40);
            set("spi",50);
            set("kar",50);
          set("kee",4000);
          set("max_kee",4000);
          set("gin",4000);
          set("max_gin",4000);
          set("atman",10000);
          set("max_atman",10000);
          set("mana",4000);
          set("max_mana",4000);
          set("force",3000);
          set("max_force",3000);
            set_skill("parry",50);
            set_skill("spells",20);
            set_skill("magic",120);
            set_skill("cure",60);
            set_skill("force",60);
            set_skill("literate",30);
            set_skill("move",100);
            set_skill("dodge",100);
            set_skill("unarmed",50);
              set_skill("paull-steps",100);
            set_skill("dremagic",100);
            set_skill("dreamforce",100);
            set_skill("dreamdance",100);
        map_skill("magic","dremagic");
        map_skill("dodge","paull-steps");
        map_skill("force","dreamforce");
        map_skill("move","paull-steps");
        map_skill("unarmed","dreamdance");
        map_skill("parry","dreamdance");
        set_temp("apply/armor",70);
        set("spells/confuse/level",100);
        set("spells/fireball/level",1);
        set("spells/thunder/level",60);
        set("spells/firedance/level",100);
        set("spells/dreamwings/level",1);
        set("spells/dreamcure/level",1);
        set("force_factor",10);
        setup();
        create_family("夜夢小築",3,"宮主");
        carry_object("/open/dancer/obj/yuaboots.c")->wear();
        carry_object("/open/dancer/obj/yuawaist.c")->wear();
        carry_object("/open/dancer/obj/ribbon.c")->wield();
//      ob->set_amount(50);
        set("inquiry", ([
            "傅劍寒"  : "你說的是神龍山莊莊主傅劍寒嗎??他是我傾慕的偶像耶!!",
            "後三式"  : (: ask_gonfu :),
        ]));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
         (: magic :),
        }));
}
void init()
{
		object ob;
        add_action("do_join","join");
        set_heart_beat(1);
	::init();
           if(interactive(ob =this_player()) && !is_fighting() ) {
           remove_call_out("greeting");
           call_out("greeting",2,ob);
}
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("conjure dreamcure");
        }
        }
        :: heart_beat();
}
  void attempt_apprentice(object ob)
{
        command("l "+ob->query("id"));
      if(this_player()->query_per()<25)
      {
          command("sigh "+ob->query("id"));
          command("say 妳相貌平庸不適合當舞者\n");
          command("shake");
          return;
      }
        command("smile");
        command("nod");
        command("chat 這個世界上又多了一個美麗的舞者了，希望各位多多愛護她..\n");
         ob->query("no_recruit");
        command("recruit "+ob->query("id"));
        call_out("do_act1",2,this_player());
}
        int do_act1(object ob)
{
        object ribbon;
        ribbon=new("/open/dancer/obj/ribbon");
        ribbon->move(ob);
        message_vision("月牙兒從懷中裡取出一條七彩緞帶 ,放在$N手中 .\n",ob);
        command("say 這是咱們夜夢小築的信物 ,務必妥善保存 !");
       return 1;
    }

void greeting(object ob)
{
  if(ob->query("family/family_name")=="夜夢小築")
  {
  if(!present("rainbow ribbon",ob))
  {
  new("/open/dancer/obj/ribbon")->move(ob);
        command("hmm");
        command("say 妳把七彩緞帶弄丟了吧 ?");
        command("say 再給妳一條, 別再弄丟囉 !");
        message_vision("月牙兒從懷中取出一條七彩緞帶, 交到$N手中\n",ob);
  }
  }
}

string magic()
{
        command("conjure confuse");
        command("conjure fireball");
        command("conjure firedance");
        command("conjure thunder");
        command("conjure dreamwings");
        command("conjure dreamcure");
        return "\n";
}
 int  ask_gonfu()
{
  object me;
  me=this_player();
  if(me->query("family/family_name")!="夜夢小築")
     write("妳不是本派弟子,問這個幹什麼??"\n);
 else if(me->query_skill("dreamdance",1) < 70 )
     write(" 妳的夜夢天舞造詣還不足 ,再多練幾年吧\n ");
  else if(me->query("combat_exp",1) < 200000 )
     write("妳的實戰經驗還不足 ,等夠了我再告訴妳吧\n");
  else 
    {
     me->set("get_dan_sp",1);
    }     	
     return 1;
}

int accept_fight(object ob)
{
        command("say 小女子怎是您的對手呢??\n");
        message_vision( this_object()->name()+"一付弱不禁風的樣子。\n",ob);
        command("say 既然你忍心欺負弱小女子，那我就不客氣了!!!\n");
        kill_ob(ob);
        command("conjure dreamwings");
        return 1;
}
int accept_kill(object who)
{
        command("say 沒想到你忍心欺負弱小女子，那我就不客氣了!!!\n");
        kill_ob(who);
        command("conjure dreamwings");
        return 1;
}
int do_join()
{
        object ob=this_player();
        if(!ob->query("class"))
        {
        if(this_player()->query_per()<25)
        {
 
            return notify_fail("你長得太醜了不適合當舞者還是另尋出路吧!!\n");
        }else
        ob->set("class","dancer");
        command("nod "+ob->query("id"));
        }
        else
        {
          return notify_fail("你已經加入門派囉，不能再加入囉。\n");
        }
        message("system",HIC + "月牙兒輕聲吟道：『龍騰八荒，鳳舞九天』
接著又愉快的說道：以"+this_player()->name()+"的資質必可
將我派舞蹈絕學發揚光大。\n" + NOR,users());
        return 1;
}
