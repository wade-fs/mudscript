inherit NPC;
string do_lend();
int i=1;

string do_ask (object me);

void create()
{
	set_name("老劉", ({ "cook liu","liu" }) );
        set("long", "
他是金刀門特地從京城請來的廚師，手藝一流；看他那短小的手指，實在
很難想像能做出什麼精緻的菜肴。
");
        
        set("age", 35);
	set("combat_exp", 500);
	set_skill("blade", 34);
        set_skill("dodge", 30);
        set_skill("parry", 32);
	set("title","廚師");
        

        set("race", "人類");
        set( "gender", "男性");


        set("limbs", ({ "頭部","胸部"  "雙手", "雙腳", "背部" ,"肥大的肚子","腰部"}) );
     
        set("attitude", "friend");

	set("chat_chance",5);
        set("chat_msg", ({"你想知道怎麼樣做好吃菜嗎？\n",
        }) );
        set("chat_chance_combat",30);
set("chat_msg_combat",({"打我一個不會武功\的廚師，算得上什麼英雄好漢。\n"
        }));
	set("inquiry",([
	"捕蟲網" : "嗯 ,常常有些丫頭來向我借捕蟲網 !\n",
	"丫頭" : "就是金刀門內那些丫鬟嘛 ! 真是一個比一個愛玩 !\n",
	"巧兒" : "嗯 , 她是大小姐的貼身丫鬟 , 想接近大小姐 , 非得從她下手 !\n",
	"借捕蟲網" : (:do_lend:)
	]));
        setup();
	 carry_object("/open/gblade/obj/knife.c")->wield();
	add_money("silver",10);
}

string do_lend()
{
	if(this_player()->query_temp("net"))
	return "你還沒還我耶 !";
	if(i==0)
	return "已經借給別人囉 !";
	new("/open/gblade/obj/net")->move(this_player());
	message_vision("老劉取出了捕蟲網 , 交給$N \n",this_player());
	i=i-1;
	this_player()->set_temp("net",1);
	return "用完了可要還我喔 !";
}
int accept_object(object who, object ob)
{
	if(ob->query("id")=="net")
	{
	command("smile");
	if(!this_player()->query("quests/lotch") && this_player()->query("lotch")<1 && present("papyrus",this_player() ) )
	{
	command("say 看你是個正人君子 , 我告訴你個消息 !");
	command("say 王家大小姐可是上通天文 , 下知地理 , 有何疑難 , 找她就對啦 !");
	this_player()->set_temp("know_leing",1);
	}
	this_player()->delete_temp("net");
	destruct(ob);
	i=i+1;
	return 1;
	}
return 1;
}
