#include <ansi.h>
inherit NPC;
string ask_miss();
void create()
{
  set_name("少年",({"young boy","boy"}));
  set("long","一位離家出走的少年，似乎有著（心事）。\n");
  set("gender","男性");
  set("combat_exp",500);
  set("attitude","friendly");
  set("age",20);
  set("str", 50);
  set("cor", 40);
  set("cps", 30);
  set("per", 25);
  set("spi", 20);
  set("int", 30);
  set("con", 30);
  set("kar", 30);
  set("max_gin", 500);
  set("max_kee", 500);
  set("max_sen", 500);
  set("inquiry",([
      "心事" : (: ask_miss :),
      "爹地" : "我爹地住在狂想的西北方，上次我負氣離家出走，我實在太不應該了。\n",
      ]));
  setup();
}

void init()
{
  object obj;
  :: init();
  if(interactive(obj=this_player()) && !is_fighting())
  {
   remove_call_out("greeting");
   call_out("greeting",1,obj);
  }
}

string ask_miss()
{
  object me,letter;
  me=this_player();
  if (me->query("family/family_name")!="丐幫")
      return "尋尋覓覓～在無聲無息中消失～～ \n";
  if (me->query_temp("have_ask_miss")==1)
      return "你煩不煩呀，問那麼多次！\n";
  command("taoyan "+me->query("id"));
  command("say 是我爹爹叫你來找我的呀！");
  command("say 我這兒有封信，你拿給我爹地看他就曉得了。\n");
  letter=new("/open/beggar/obj/letter");
  letter->move(me);
  me->set_temp("have_ask_miss",1);
  me->set_temp("got_letter",1);
  return "賣～賣～！\n";                
}


void greeting()
{
  command ("say 好想念我（爹地）呀～～\n");
}
