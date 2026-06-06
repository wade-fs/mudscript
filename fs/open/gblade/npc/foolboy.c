//小笨童 

inherit NPC;
string do_act();
 int i=0;

void create()
{
	set_name("小笨童",({"foolboy"}));
	set("gender","男性");
	set("age",8);
	set("class","blademan");
	set("str",10);
   set("long","一個呆頭呆腦的小童 ,正在讀著三字經 .\n");
	set("chat_chance",10);
	set("chat_msg",({
		"小笨童搖童晃腦的念著三字經\n"
		}));
      set("inquiry",([
		"三字經" : (:do_act:)
	]));
	set("combat_exp",100);
	setup();
	add_money("silver",1);
}

int accept_fight(object who)
{
 return notify_fail("小笨童哭道 : 哇 .. 媽呀。\n");
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
     if(i>0)
      {
 return "書已經送人了喔 !";
      }
	command("say 我被這本書稿的昏頭轉向 ");
	command("sigh");
	this_player()->set_temp("can_say",1);
     return "人之初 ...下一句倒底怎麼唸(say)呢？";
 }
void reset()
{
  i = 0;
}
   void do_say(string str)
{
  if(this_player()->query_temp("can_say")==1)
   {
  if(str=="性本善")
  {
   i=i+1;
   message_vision("$N說道 : 性本善 !\n",this_player());
	new("/open/gblade/obj/book")->move(this_player());
   message_vision("小笨童說道 : 哇 ,$N好厲害喔 !\n",this_player());
   if(this_player()->query("gender")=="男性")
  command("say 寶劍贈英雄 , 我這本書就贈才子啦 !");
  if(this_player()->query("gender")=="女性")
   command("say 嗯 , 我欣賞有智慧的女人 !這本書送妳 !");
  command("smile");
   this_player()->delete_temp("can_say");
	}
  }
}
