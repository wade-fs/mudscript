inherit NPC;
void create()
{
	set_name("巧兒", ({"girl"}));
	set("long","王家大小姐的貼身丫鬟 , 長的甚是可愛 , 你真想親一下
她現在正拿著扇子撲蝶 \n");
	set("gender","女性");
	set("combat_exp",1000);
	set("attitude","friendly");
	set("age",15);
	set("title","金刀門丫鬟");
	set("score",1000);
	set("force",0);
	set("max_force",0);
	set_skill("force",5);
	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("literate",15);
	set_skill("unarmed",30);
	set("str", 20);
	set("cor", 26);
	set("per", 28);
	set("int", 15);
	set("cps", 10);
	set("con", 20);
	set("spi", 15);
	set("kar", 15);
	set("chat_chance",10);
	set("chat_msg",({
	"巧兒拿著錦扇往玉面蝴蝶一撲 , 卻撲了個空 \n",
	"巧兒嘆了口氣 , 說道 : 誰願意幫我抓一隻呢 ?\n",
	(: this_object(),"return_home" :),
	"巧兒說道 : 我一定要抓到妳 \n"
	}));
	set("inquiry",([
	"抓蝴蝶" : "當然是用捕蟲網抓啊 !\n",
	"玉面蝴蝶" : "我好喜歡喔 , 可惜都抓不到 \n",
	"白孝虹" : "他是老爺的得意弟子之一 , 長的蠻帥的喔 \n",
	"老劉" : "就是金刀門的廚師嘛 \n",
	"老爺" : "就是王原霸王老爺嘛 \n",
	"大小姐" : "她是上帝的傑作 , 我如有她的三分美貌就好啦 !\n",
	"捕蟲網" : "嗯 ! 老劉倒有一把 , 我臉薄不便向他借 \n"
	]));
	setup();
	add_money("silver",1);
	carry_object("/open/gblade/obj/fan");
	carry_object("/open/gblade/obj/green-cloth")->wear();
	carry_object("/open/gblade/obj/flower-shoes")->wear();
}
void init()
{
	object ob;
	::init();
	if(interactive(ob =this_player()) && !is_fighting() )
	{
	remove_call_out("greeting");
	call_out("greeting",2,ob);
	}
	add_action("do_kiss","kiss");
}
int greeting(object ob)
 {
	if(!ob->query_temp("know-girl") )
	command("say 誰要幫我抓隻蝴蝶呢 ?");
	if(ob->query_temp("know-girl") )
       {
	if( !ob->query_temp("girl-1") && ob->query_temp("cant-enter") )
	 {
	command("say 碰壁了吧 ?看在你幫過我的份上 , 我求小姐見你一面 ");
	 command("say 走吧 !");
	ob->set_temp("girl-1",1);
	 call_out("do_act",2,ob);
	 }
       }
return 1;
 }
void do_act(object ob)
 {
	ob->move("/open/gblade/room/g3-5");
	this_object()->move("/open/gblade/room/g3-5");
	 message_vision("巧兒帶著$N來到了大小姐閨房前 \n",ob);
	command("say "+"請小姐幫"+ob->query("name")+"一個忙吧 !");
	call_out("do_act2",3,ob);
 }
void do_act2(object ob)
 {
	 message_vision("房內傳來一聲嬌柔的聲音 : 進來吧 ! \n",ob);
	ob->delete_temp("cant-enter");
	 ob->set_temp("can-enter",1);
	call_out("do_act3",2,ob);
 }
void do_act3(object ob)
{
	command("say 我先走囉 !");
	message_vision("巧兒往花園中走去 \n",ob);
	this_object()->move("/open/gblade/room/g3-8");
}
int do_kiss(string arg)
{
	if(arg=="girl")
	{
	if(this_player()->query("gender")=="男性")
	{
	if(this_player()->query_temp("know-girl")||(string)this_player()->query("id")=="wugi")
	   {
		command("blush");
		command("say 討厭 , 不理你了啦 ");
		return 1;
		}
	command("slap "+this_player()->query("id"));
	command("say 哼 , 看我年幼好欺嗎 ?");
	return 1;
	}
	if(this_player()->query("gender")=="女性")
	command("say 我可沒有同性戀啊 ");
	return 1;
	}
}
int accept_object(object who,object ob)
{
	string ob_id;
	ob_id=ob->query("id");
	if(ob_id=="net")
	{
	command("say 我不太會用ㄝ , 你幫我抓嘛 !");
	command("give "+this_player()->query("id")+" net");
	command("addoil "+this_player()->query("id"));
	command("giggle");
	return 1;
	}
	if(ob_id=="butterfly")
	{
	if(ob->query("kee")<ob->query("max_kee"))
	{
	command("say 你給我一隻半死不活的蝴蝶幹麻 ?");
	command("say 用捕蟲網抓啦 !");
	return 1;
	}
	command("jump");
	command("say 謝謝你啦 , 我告訴你一個秘密喔 !");
	command("say 白孝虹很喜歡我們家大小姐喔 !");
	this_player()->set_temp("know-girl",1);
	this_player()->set_temp("can-get",1);
	return 1;
	}
return 1;
}
