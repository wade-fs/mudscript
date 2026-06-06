//小笨童 

inherit NPC;
string do_act();
int i=0;
string ask_chen()
{
  if(this_player()->query_temp("quests/confuse") != 2)
  {
    command("?");
    return "";
  }
  this_player()->set_temp("quests/confuse",3);

  return "師伯已經睡了很久了，不能隨便打擾他，我也不能讓你「進入」的。\n";
}
string ask_enter()
{
  if(this_player()->query_temp("quests/confuse") != 3)
    return "";

  this_player()->add_temp("quests/confuse1",1);
  switch(this_player()->query_temp("quests/confuse1"))
  {
    case 1:
      return "不行，你說什麼也不行讓你進去。\n";
      break;
    case 2:
      return "吼，不要再嚕我了，再說下去我也不能放你進去的。\n";
      break;
    case 3:
      return "哎唷，其實，我滿想吃糖葫蘆的。聽說京城的糖葫蘆很有名呢。";
      break;
    default :
      return "快去找糖葫蘆啦，找到我才要讓你進去！\n";
  }
}
void create()
{
  set_name("小僮",({"small boy","boy"}));
  set("gender","男性");
  set("age",8);
  set("class","scholar");
  set("str",10);
  set("long","一個年紀甚輕的小童，正看著小屋門口。\n");
  set("chat_chance",10);
  set("chat_msg",({
        "小童認真的守住門口。\n"
        }));
  set("inquiry",([
        "陳平": (:ask_chen:),
        "進入" : (: ask_enter :),
        "enter": (: ask_enter:),
        "糖葫蘆":"京城的糖葫蘆超好吃的，聽吃過的人這樣說耶。\n",
        ]));
  set("combat_exp",100);
  setup();
  add_money("silver",1);
}
int accept_object(object who,object obj)
{
  if(obj->query("id") == "sugarcoated haws on a stick" && 
      who->query_temp("quests/confuse") == 3 &&
      who->query_temp("quests/confuse1") > 2 )
  {
    who->set_temp("quests/confuse",4);
    command("say 哇，真的是京城的糖葫蘆耶！！好啦，我偷偷的讓你進去看看師伯！\n");
    command("say 你千萬不要跟師父說哦！");
  }
  else
  {
    command("say 謝啦！");
  }
}
/*
int accept_fight(object who)
{
  return notify_fail("小書僮煩道 : 我咧ooxx....真難懂.\n");
}
void init()
{
  object ob;
  ::init();
  if(interactive(ob =this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting",2,ob);
    add_action("do_say","say");
  }
}
void greeting(object ob)
{
  command("think ");
}
string do_act()
{
  if(i>10000)
  {
    return "書已經被人要走了喔 !";
  }
  command(" say 我真看不懂這一本書, 好深奧喔 ");
  command("sigh");
  this_player()->set_temp("can_say",1);
  return "古今中外以那本兵法最為出名...";
}
void do_say(string str)
{
  if(this_player()->query_temp("can_say")==1)
  {
    if(str=="孫子兵法")
    {
      i=i+1;
      message_vision("$N說道 : 孫子兵法 !\n",this_player());
      new("/open/scholar/obj/book")->move(this_player());
      message_vision("小書僮說道 : $N真是學識淵博!!\n",this_player());
      if(this_player()->query("gender")=="男性")
        command("say 寶劍贈英雄 , 我這本書就贈才子啦 !");
      if(this_player()->query("gender")=="女性")
        command("say 嗯 , 我欣賞有智慧的女人 !這本書送妳 !");
      command("smile");
      this_player()->delete_temp("can_say");
    }
  }
}
*/
