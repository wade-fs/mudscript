//old man
#include "/open/open.h"
#include <ansi.h>
inherit NPC;
string poison();
void create()
{
	set_name("老人",({"old man","man"}));
	set("gender", "男性" );
	set("age", 87);
set("long", @LONG
傳說中，帶著衝穴技巧秘籍逃跑的老人，不過他現在好像遇到一個困難。
LONG
	);
  set("no_sac",1);
  set("no_get",1);
  set("combat_exp",3000000);
  set("chat_chance",5);
  set("chat_msg", ({
        CYN + "老人說道: 身上的毒，應該只有帥父能救了。\n" + NOR,
        }) );
  set("inquiry",([
    "李秋凡":"你為什麼知道，就是我，是師父派你來找我的嘛？",
    "困難" : "哎，我身上中毒了，當年帶著秘籍逃來這，到底是好還是壞呢？",
    "秘籍" : "這....我不能說....",
    "衝穴技巧" : "別再問了，我真的不能說...",
    "衝穴" : "別再問了，我真的不能說...",
    "衝穴秘籍" : "別問了，我真的不能說...",
    "師父" : "我帥父就是當今醫術最高明的「華陀」，但我現在沒有臉見他們了。",
    "毒"   : (: poison :) , 
    "中毒" : (:poison:),
    "金蟬蠱王" : "中了這種毒，是沒有任何解藥的，只要我每移動一次，就會損失精氣神。\n"+
                 "\t我一個人是無法衝出去的，只能靠你來救我了，你願意幫我嘛？",
    "解藥" : "嗯...如果你有辦法弄到我師父的療傷聖品人靈丹的話，或許\還有救！",
    "解毒" : "嗯...如果你有辦法弄到我師父的療傷聖品人靈丹的話，或許\還有救！"

  ]));
  set("attitude", "friendly");
  set("force",7000);
  set("max_force",3000);
  set("force_factor", 15);
  set("functions/break-kee/level",200);
  set_skill("spells",20);
  set_skill("magic",20);
  set_skill("cure",120);
  set_skill("force",80);
  set_skill("stabber",120);
  set_skill("poison",70);
  set_skill("literate", 80);
  set_skill("seven-steps",100);
  set_skill("yu-needle",100);
  set_skill("shinnoforce",80);
  map_skill("force", "shinnoforce");
  map_skill("dodge", "yu-steps");
  map_skill("stabber","yu-needle");
  map_skill("cure","godcure");
  map_skill("move","seven-steps");
  map_skill("parry", "yu-needle");

  set_skill("dodge", 150);
  set_skill("parry", 150);
  
  set_skill("acupuncture",300);
  set("family/family_name","銀針門");
  set("class","doctor");
  set("doctor/sosman",1);
  set("quests/acupuncture",1);
  set("no_attack",1);
  setup();
  carry_object("/open/doctor/obj/needle9.c")->wield();
}
void init()
{
  add_action("do_nod","nod");
}
int accept_object(object me, object obj)
{
  if(obj->query("id") == "human pill")
  {
    command("say 這是銀針門聖藥人靈丹，這樣有救了！！");
  }
  else
  {
    command("hmm");
    command("say 這好像沒什麼幫助！");
  }
}
int do_nod(string arg)
{
  object me=this_player();
  if(me->query_temp("quests/acup") == 9)
  {
    command("say 準備好時，再跟我點點頭吧。");
    command("say 等等要跟好我，不要跟丟了，在這個石洞下，是會迷路的。");
    me->set_temp("quests/acup",10);
    return 1;
  }
  if(me->query_temp("quests/acup") == 10 || me->query_temp("quests/acup") == 20)
  {
    command("say 太好了，我們就出發吧！！");
    me->set_temp("quests/acup",20);
    this_object()->delete("no_attack");
    return 1;
  }
}
string poison()
{

    command ("sigh");
  if(this_player()->query_temp("quests/acup") == 10 || this_player()->query_temp("quests/acup") == 20)
  {
    return "準備好了就跟我點點頭！！\n";
  }

  if(this_player()->query_temp("quests/acup") != 4)
  {
    return "我...是中了一些毒，可是告訴你也是沒有用的。\n";
  }
  this_player()->set_temp("quests/acup",9);
  return "這是傳說中的金蟬蠱王所煉製出來的毒，依我目前的能力，我沒有辦法解開它。";

}
varargs int move(mixed dest, int silently)
{
  object me = this_object();
  int ret;
  ret = ::move(dest,silently);
  if(ret && !query("no_hurt"))
  {
    me->receive_wound("kee",(me->query("max_kee")*1/10),me);
  }
  return ret;
}
void heart_beat()
{
  object me = this_object();
  if(!environment()) return ;
  if(!query("no_attack") && !this_object()->is_fighting())
  {
   command("say 衝啊!!");
    command("go west");
    command("go south");
    command("kill killer");
    if(present("human pill",this_object()))
    {
      command("say 還好有師父的療傷聖品...");
      command("eat human pill");
      command("eat human pill");
      me->receive_heal("kee",3000);
      me->receive_cure("kee",3000);
      /*
      command("eat human pill");
      command("eat human pill");
      command("eat human pill");
      command("eat human pill");
      command("eat human pill");
      command("eat human pill");
      command("eat human pill");
      */
    }
  } 
  if( !query("no_hurt") && !environment(me)->query("exits/west") && !environment(me)->query("exits/south") && !this_object()->is_fighting())
  {
     foreach(object user in all_inventory(environment(me)))
     {
       if(user == this_object()) continue;
       if(user->query_temp("quests/acup") == 20)
       {
         user->set_temp("quests/acup",11);
         command("bow "+user->query("id"));
         command("follow "+user->query("id"));
         set("no_hurt",1);
         set("no_attack",1);
       }
     }

    if(query("no_hurt"))
    {
     command("say 我們竟然衝出來了，真是感謝您了，等等出去後，麻煩您扶我回去找我師父。");
     }
     delete("chat_msg");
  }

  ::heart_beat();
}
void call_find_master(object user,object master)
{
  command("say 師父~~~~~~~~~~~~~~~~~~~");
  command("sorry");
  command("say 對不起師父，徒兒在取得秘籍時，被一群匪人逼入山洞，所以徒兒回來晚了。");
  tell_object(user,CYN+"\n\n"+this_object()->name()+ "將秘籍恭恭敬敬的交給"+master->name()+"。\n" + NOR);
  call_out("call_find_master2",2,user,master);
}
void call_find_master2(object user,object master)
{
  tell_object(user,CYN+master->name()+"說道：回來就好，你就先回去休息吧。\n" + NOR);
  if(user->query("family/family_name") == "冥蠱魔教")
  tell_object(user,CYN+master->name()+"說道：雖然你是冥蠱魔教的，不過我還是非常的感謝您的幫忙，以後歡迎你來看看秋凡徒兒。\n" + NOR);

  user->set_temp("quests/acup",12);
  destruct(this_object());
}
int return_home(object home)
{
  return 1;
}
void die()
{
  say(HIR + "\n\n您的任務失敗了，請等重生後再次嘗試\n\n" + NOR);
  ::die();
}
