
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
 {
  object ob;
  set_name("米蟲基羅",({"rice worm","worm"}) );
  set("long","
    在你眼前這位人高馬大﹐錯..是噸位大﹐但他是
不是一個頭腦簡單四肢殘障的廢人﹐他所擁有的怪力
是任何人比不上的。
  ");
  set("race", "人類");
  set("gender","男性");
  set("attitude","heroism");
  set("combat_exp",300000);
  set("age",25);
  set("nickname",HIR + "阿肥肥" + NOR);
  set("class","soldier"); 
  set("str",40);
  set("cor",30);
  set("cps",30);
  set("kee",700);
  set("max_kee",700);
  set("force",1000);
  set("max_force",1000);
  set("force_factor",2);
  set("bellicosity",300);
  set("inquiry",([
      "李察雞餌" : "偶長官ㄡ..hmm..不知他在哪ㄝ..想找他說..先睡一下好了。\n",
      
      ]));
  setup();
 add_money("gold",5); 
 ob=carry_object("/open/soldier/obj/hit");
  ob->wield();

 
}

void init()
{
    object ob;
    ::init();
  if( interactive(ob = this_player())&& !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting",1,ob);   }
}

int accept_kill(object ob)
{
  message_vision( this_object()->name()+"活太膩了嗎？.....：~\n",ob);
  command("say 臭小子伙～你簡直來自殺的");
  command("hehe"+this_player()->query("id"));
  this_object()->set("combat_exp",600000);
  this_object()->set("max_force",2500);
  this_object()->set("gin",1000);
  this_object()->set("sen",1000);
  this_object()->set("max_kee",2500);
  this_object()->set("kee",2500);
  this_object()->set("eff_kee",2500);
  this_object()->set("force",2500);
  set_skill("force",60);
  set_skill("spforce",60);
  set_skill("dodge",50);
  set_skill("move",50);
  set_skill("parry",60);
  set_skill("lance",70);
  set_skill("power-lance",60);
  set_skill("eagle-steps",50);
  map_skill("lance","power-lance");
  map_skill("dodge","eagle-steps");
  map_skill("force","spforce");
  this_object()->set("title","暴力王");
  command("say 敢在此撒野？讓你看看我的利害！！");
  command("wield hit");
  this_object()->kill_ob(this_player());
    return 1;
}

int accept_fight(object me)
{
    command("say 來吧～不要以為我是米虫就好欺負～");
    command("pk "+this_player()->query("id"));
    setup();
    return 1;
    
}

void greeting(object ob)
{
  if(this_player()->query("id")=="hide")
  {
   command("say 馬仔你來了ㄚ～ 一起去買珍奶吧！！");
   command("lick hide");
  }
  else
  { command("pk "+this_player()->query("id"));}
}   
 
