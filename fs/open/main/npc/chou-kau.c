//copy from cage,re-edit from ccat
//排版 by blazakira 2011/10/12

#include <ansi.h>
inherit NPC;

void create()
{
  set("title",RED + "嗜血劍" + NOR);
  set_name("趙高", ({"chou-kau","kau","chou"}));
  set("age",55);
  set("long","曾為仙劍高手之一，後因殺人過多，而被鄭士欣逐出仙劍。\n");
  set("gender","男性");
  set("str",30);
  set("con",30);
  set("max_kee",50000);
  set("max_gin",50000);
  set("max_sen",50000);
  set("kee",50000);
  set("gin",50000);
  set("sen",50000);
  set("combat_exp",500000);
  set("max_force",10000);
  set("force",100000);
  set("force_factor",15);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("move",120);
  set_skill("force",250);
  set_skill("sha-steps",120);
  set_skill("sword",120);
  set_skill("shasword",100);
  set("inquiry",([
    "鄭士欣"  :"哼！那自大的死老頭，只教劍不問仙，不知誤了仙劍多少人材。\n",
    "仙劍劍術":"仙劍劍術乃包含<仙術>與劍術，只有仙術與劍術並重，才算真正學成仙劍武功。\n",
    "仙術"    :"仙劍仙術以失傳多時，不過卻在我手中光復，就是我手中這把<火龍劍>!!",
    "火龍劍"  :"呵呵...試試便之...來過幾招吧！\n",
  ]));
  set("chat_chance",5);
  set("chat_msg",({
    "趙高說：有朝一日，我必殺回仙劍，以報今日之恥。\n",
    "趙高說：<鄭士欣>那老猴子，以為<仙劍劍術>就是如此嗎？沒有" + HIW + "仙" + NOR + "只有" + HIC + "劍" + NOR + "何言仙劍？可笑啊...\n",
  }));
//  set("chat_chance_combat",20);
//  set("chat_msg_combat",({
//    (: perform_action,"sword.sha_kee" :)
//  }));
  map_skill("dodge","sha-steps");
  map_skill("move","sha-steps");
  map_skill("sword","shasword");
  map_skill("parry","shasword");
  set_temp("apply/armor",100);
  set_temp("apply/damage",80);
  set_temp("apply/defense",90);
  set_temp("apply/dodge", 20);
  set_temp("apply/parry", 50);
//  set("ann_die",1);
  setup();
  carry_object("/open/common/obj/pill2")->set_amount(10);
  carry_object("/open/ping/obj/poison_pill")->set_amount(3);
  add_money("gold",25);
}

int accept_kill(object me)
{
  call_out("change",1,me);
  return 1;
}

int accept_fight(object me)
{
  command("say 我從來都不接受比試的，去找別人吧。");
  return 0;
}

void change(object ob)
{
  object mob,obj;
  int exp;
  mob=this_object();
  exp =ob->query("combat_exp",1);
  if( exp > 150000)
  {
    exp = exp * 1.5;
    set("combat_exp",exp);
  }
  if(!query("change"))
  {
    obj=new("/open/main/obj/firesword");
    obj->move(this_object());
    obj->set("material","crimsonsteel");
    command("wield sword");
    set("wield",1);
    set("change",1);
    set("max_kee",50000);
    set("max_gin",50000);
    set("max_sen",50000);
//    set("kee",50000);
//    set("gin",50000);
//    set("sen",50000);
    set("family/family_name","仙劍派");
    set("class","swordsman");
    set("functions/sha_kee/level",100);
    set("functions/swordkee/level",100);
    command("say 實在太小看我的本領了，今天就拿出我的真本事讓你看看吧!!");
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
  if(!mob || !env ) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    mob->die();
    return ;
  }
  else if( mob->query_temp("unconcious") == 1 ) return ;

  if(mob->is_fighting() && random(100) < 12)
  {
    command("sword_fire");
  }

  if(mob->is_fighting() && random(10) > 3 && mob->query("change") )
  {
    command("perform sword.sha_kee");
  }

  if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 25) )
  {
    command("large pill"); 
  }

  if((mob->query("kee")<mob->query("max_kee")*0.2) && (random(100) < 20) )   
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

void die()
{
  object winner = query_temp("last_damage_from");
  object obj = query_temp("weapon");
  int j;
  if(obj)
    obj->set("material","steal"); 
  if(!winner)
  {
    ::die();
    return ;
  }
  winner->set_temp("kill_kau",1);
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj4/wish_shells")->move(environment(winner));
        message_vision(HIM + "\n從趙高的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj4/wish_shells",sprintf("%s(%s) 讓趙高掉下了希望之貝殼於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
      {
        new("/open/sky/obj4/wish_shells")->move(environment(winner));
        message_vision(HIM + "\n從趙高的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj4/wish_shells",sprintf("%s(%s) 讓趙高掉下了希望之貝殼於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}
