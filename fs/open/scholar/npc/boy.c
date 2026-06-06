//小笨童 

inherit NPC;
string do_act();
 int i=0;

void create()
{
set_name("小書僮",({"bookboy"}));
	set("gender","男性");
	set("age",8);
set("class","scholar");
	set("str",10);
set("long","一個年紀甚輕的小童 ,正閱\讀著孫子兵法 .");
	set("chat_chance",10);
	set("chat_msg",({
    "小書僮一臉茫然的看著孫子兵法\n"
		}));
      set("inquiry",([
    "孫子兵法" : (:do_act:)
	]));
	set("combat_exp",100);
	setup();
	add_money("silver",1);
}

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
