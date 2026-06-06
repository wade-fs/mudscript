//排版 by blazakira 2011/9/30

inherit NPC;  //李爺爺 by dhk 2000.4.22
#include <ansi.h>
#include "/open/open.h"

string do_bodyguard();

void create()
{
  set_name("李爺爺",({"grandfather lee","lee","grandfather"}) );
  set("gender", "男性");
  set("age",77);
  set("attitude", "peaceful");
  set("long", "" + CYN + "他是宏禧莊莊主，富甲一方、不可一世。年前外出辦貨\n"
             +"時，不幸遇到風行山寨土匪，其隨從數百名全數命喪生\n"
             +"，他確僥倖逃過一劫，現下落難中央驛站。而山莊歸途\n"
             +"又危機四伏，他因失去數百隨從而不敢﹝回家﹞。" + NOR + "\n");
  set("kee",600);
  set("max_kee",600);
  set("goodman",1);
  set("combat_exp",1000);
  set("inquiry", ([
    "回家" : (: do_bodyguard :),
  ]));
  setup();
}

int accept_kill(object who)
{
  command("say 別殺我....");
  command("help!");
  return 1;
}

int accept_fight(object who)
{
  command("say 別打我....");
  command("help!");
  return 1;
}

string do_bodyguard()
{
  object me=this_player();
  object room = environment(this_object());
  if( me->query("family/family_name")=="段家") //&& me->query("marks/six_sp")<=2)
  {
    me->set_temp("bodyguard",1);
    return("
              原來你是段將軍的門下呀！真是老天有眼，不知道你能不能護送
              我回家，我家是宏禧山莊位於中央驛站的東北方，你就看在我是
              一個流落在外的可憐老人，拜託！拜託！");
    }
    else if( me->query_temp("find_moon")==8)
    {
      me->set_temp("bodyguard",1);
      return("
              原來你想知道魔大戰的消息呀！這樣好了，不知道你能不能護送
              我回家，我家是宏禧山莊，位於中央驛站的東北方，如果你能安
              全護送我回家的話，再考慮告訴你魔大戰的消息！");
    }
    else
    {
      command("sigh"+me->query("id"));
      return("你不是段將軍家的門人，我不放心!!");
    }
}

void init()
{
  remove_call_out("greets");
  call_out("greets",1,this_player());
  add_action("do_nod","nod");
  add_action("do_shake","shake");
  add_action("do_say","say");
}

void greets(object me)
{
  command("sigh");
}

int do_nod()
{
  object me = this_player();
  if(me->query_temp("bodyguard") != 1)
    return 0;
  me->set_temp("bodyguard",2);
  remove_call_out("greeting");
  call_out("greeting",1,me);
  return 0;
}

int do_say(string str)
{
  object me = this_player();
  if(me->query_temp("bodyguard") != 1)
    return 0;
  if(str == "yes" || str == "ok")
  {
    me->set_temp("bodyguard",2);
    remove_call_out("greeting");
    call_out("greeting",1,me);
    return 0;
  }
  delete_temp("bodyguard");
  remove_call_out("greeting2");
  call_out("greeting2",1,me);
  return 0;
}

int do_shake()
{
  object me = this_player();
  if(me->query_temp("bodyguard") != 1)
    return 0;
  me->delete_temp("bodyguard");
  remove_call_out("greeting2");
  call_out("greeting2",1,me);
  return 0;
}

void greeting(object me)
{
  object ob = this_object();
  command("smile");
  command("say 謝謝你肯幫我的忙。");
  command("follow "+me->query("id"));
  me->set_temp("goodman",1);
}

void greeting2(object me)
{
  command("sigh");
  tell_room(environment(this_object()),HIC + "只見老爺爺失望、落陌的神情。\n" + NOR);
}
