//修整解謎線索敘述錯誤 by blazakira 2011/7/2
//修正 魔教 萬蠱蠶心術 的解迷線索bug 2013/1/1 喔 新年快樂～ tsk

#include "/open/open.h"
#include <ansi.h>
inherit NPC;

string do_ask();
string do_ep3();
string do_ep4();
string do_ep5();
string do_ep6();
string do_pbag();

void create()
{
  set_name("傳功\大長老",({"elder"}));
  set("title","冥蠱魔教長老");
  set("gender","男性");
  set("class","poisoner");
  set("combat_exp",73632);
  set("attitude","heroism");
  set("age",60);
  set("str", 40);
  set("cor", 24);
  set("cps", 18);
  set("per", 24);
  set("int", 45);
  set("force",650);
  set("max_force",650);
  set("long",
    "魔教分教壇的傳教長老。\n"
    "聽說是一個製皮專家，曾幫人作過毒囊袋。\n"
    "他正默默的調配毒藥……\n" );

  set_skill("dodge", 70);
  set_skill("parry",60);
  set_skill("coldpoison",60);
  set_skill("poison",100);
  set_skill("unarmed",40);
  set_skill("whip",60);
  set_skill("nine-steps",30);
  set_skill("ming-snake",40);
  map_skill("dodge","nine-steps");
  map_skill("poison","coldpoison");
  map_skill("whip","ming-snake");
  set("chat_chance_combat",60);
  set("chat_msg_combat",({
    (: perform_action,"poison.five" :),
    (: perform_action,"poison.dark" :),
  }));
  set("force_factor", 5);
  set("inquiry",([
    "月石"     : (: do_ask :),
    "亂子"     : (: do_ep3 :),
    "自食蠱物" : (: do_ep4 :),
    "妖女"     : (: do_ep5 :),
    "好友"     : (: do_ep6 :),
    "毒囊袋"   : (: do_pbag :),
    "長老"     : "雖然他當不上長老，但是也是教主身旁備受信賴的護法之一呢。",
//    "好友"     : "雖然他當不上長老，但是也是教主身旁備受信賴的護法之一呢。",
  ]));

  setup();
  carry_object(POISON_OBJ"green_whip")->wield();
  carry_object("/obj/poison/five_poison")->add_amount(30);
  carry_object("/obj/poison/rose_poison")->set_amount(30);
  carry_object("/obj/poison/faint_poison")->set_amount(30);
  carry_object("/obj/poison/dark_poison")->add_amount(30);
  carry_object("/obj/poison/scorpion_poison")->set_amount(15);
}

void init()
{
  add_action("do_say","say");
  add_action("do_want","want");
}

string do_ask()
{
  object me=this_player();
  command("hmm");
  if(!me->query_temp("moon-stone"))
    return "你問這幹麻？";
  me->set_temp("moon-stone",2);
  return "喔？你是啥來頭？ ";
}

string do_ep3()
{
  object me=this_player();
  if(me->query_temp("quest-e")!=2)
    return("什麼亂子??我不知道喔......");
  if(me->query("marks/evil-poison")==1) 
    return("你解過了還問喔, 都知道了說...");  //解過不可再解
  me->set_temp("quest-e",3);
  return ("亂子??難道你是說三十年前前幫主<自食蠱物>之事嗎?");
}

string do_ep4()
{
  object me=this_player();
  if(me->query_temp("quest-e")!=3)
    return("不曉得你在說什麼, 你應該不知道這事吧...");
  me->set_temp("quest-e",4);
  return("前幫主之前不知道在練什麼蠱功\, 不知道是不是練到走火入魔, 
                自己吃掉自己所養的蠱物, 結果幫主自己毒發身亡, 一切都是那
                個傢伙害的......那一位<妖女>....害得我的<好友>落得流亡的
                命運啊.....");
}

string do_ep5()
{
  object me=this_player();
  if(me->query_temp("quest-e")!=4)
    return("妖女妖女妖嬌的美女~~~");
  me->set_temp("quest-e",5);
  return("不想再提到那女人了, 快滾....");
}

string do_pbag()
{
  object me=this_player();
  if(me->query("class")!="poisoner")
    return("閣下非本教之徒, 恕不奉告。\n");
  if(me->query("combat_exp")<=500000)
    return("你經驗值不怎麼夠, 不想和你說哩。\n");
  if(me->query("quests/poison_bag"))
    return("你解過了吧?\n");
  me->set_temp("can_kill_tiger",1);
  return("想要做毒囊袋, 只要你把獨角獸的頭拿給我就好了咩。\n");
}

string do_ep6()
{
  object me=this_player();
  if(me->query_temp("quest-e")!=5)
  return("我有朋友和你有什麼關係~~~");
    me->set_temp("quest-e",6);
  return("唉, 他本是個才華洋溢的人, 無奈迷上那個女人
                不然現在應該也是長老之列啊....");
}

int do_say(string str)
{
  object me = this_player();
  string myclass=me->query("family/family_name");

  if(me->query_temp("moon-stone",2)){
    if(str == "鏢師" )
    {
      me->set_temp("moon-stone",3);
      me->delete_temp("moon-stone",2);
      command("smile");
      command("say 我等你好久了。");
      command("say 快將月石交給我好友。");
      new("/open/poison/obj/moon.c")->move(me);
      return 1;
    }
    else
    {
      command("say 哼！原來是奸細。受死吧！");
      me->delete_temp("mmon-stone");
      kill_ob(me);
    }
    return 0;
  }
}

int accept_object(object me,object ob)
{
  object bag;
  if(ob->query("id")=="tiger-head" && this_player()->query_temp("can_kill_tiger",1))
  {
    command("say 等我一下啊，我等等就把毒囊袋拿給你！");
    command("hmm");
    command("say ok, 沒問題, 做好啦！如果弄丟了, 在和我要(want)吧");
    bag = new("/daemon/class/poisoner/obj/poison_bag");
    bag->move(this_player());
    this_player()->set("quests/poison_bag",1);
    this_player()->delete_temp("can_kill_tiger");
    destruct(ob);
    return 0;
  }
}

int do_want(string arg)
{
  object me = this_player();
  object pbag = new("/daemon/class/poisoner/obj/poison_bag.c");
  if(!arg||arg!="毒囊袋")
    return notify_fail("你想要什麼???\n");
  if(!me->query("quests/poison_bag"))
    return notify_fail("你還不能拿吧??!!\n");
  if(me->query("class")!="poisoner")
    return notify_fail("你不是魔教徒呢!!\n");
  if(present("poison_bag",me))
    return notify_fail("你已經拿過了啦\n");
  pbag->move(me);
  tell_object(me,"魔教長老交給你了一個毒囊袋。\n");
  return 1;
}
