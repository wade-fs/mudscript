//blackman.c by urd
//87.8.19  為了當成謎題，所以又被我修改了
//87.9.30  再次因為解謎上的需要，又被修改一次
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string ask_card();
string ask_ghostcard();
void create()
{
	set_name("黑衣人",({"black suit","suit"}));
	set("long","這是殺手跟忍者工會的長老 ,原本負責在京城中接收新會員 .\n
	                  目前因為各大門派的逼迫，不得以只好退到殺手總壇的後山.\n
		      他目前身兼黑巾殺手的靈異掌令，地位非常崇高。\n
		      他跟（葉孤城）之間似乎有不少牽扯。\n");
	set("gender","男性");
	set("class","killer");
	set("nickname","天地無用");
	set("combat_exp",1000000);
	set("attitude","heroism");
	set("age",43);
	set("title","天靈老人");
	set("str", 44);
	set("cor", 24);
	set("cps", 18);
	set("per", 24);
	set("int", 42);
	set("force",1400);
	set_skill("literate",40);
	set("max_force",1400);
	set("max_kee",2000);
	set_skill("magic",50);
	set_skill("array",50);
	set_skill("move",60);
	set_skill("force",60);
	set_skill("dodge",80);
	set_skill("parry",60);
	set_skill("spells",50);
	set_skill("sword",50);
	set_skill("unarmed",50);
	set_skill("blade",50);
	set_skill("staff",50);
	set_skill("throwing",70);
	set_skill("dagger",55);
	set("force_factor",10);
	set_skill("hammer",50);
set("inquiry",([
"葉孤城" :"他是我最要好的朋友與最佳的對手，但是因為（小如）那一件事........\n",
"小如" :"她就是葉玲如，當年的殺手第一美女，引起我與葉孤城互相(爭奪)\n",
"爭奪":"這是一件慘事，你願意點頭答應我一件事嗎？？\n",
"殺手密令" : (: ask_card :),
"靈異令牌" : (: ask_ghostcard :),
]));

setup();
carry_object("/open/killer/memory/hair.c");
carry_object("/obj/cloth")->wear();
add_money("gold",10);
}

void init()
{
	add_action("do_join","join");
	add_action("do_nod","nod");
    add_action("do_show","show");
}

int accept_object(object wo,object ob)
{
  object me,ob2,obj;  
  me=this_player();

  if(ob->query("sword_head"))
  {  //第三進階用的謎
	if( me->query_temp("head") !=4 ) 
	{
		command("say 連七子的人頭沒有辦法自己拿，沒資格出這個任務！");
		me->delete_temp("head");
		return 0;
	}
	//表有人頭，而且人頭是自己拿的
	command("nod");
	obj = new("/open/killer/headkill/obj/ghost_card");
	obj->move(this_player());
	message_vision("$N給$n一支"+obj->name()+"\n",this_object(),this_player());
        destruct(ob);
	me->set_temp("head",5);
  }
  if(ob->query("id") == "card")  //進行到給殺手密令的地方     
  {  //第二進階用的謎
    if (this_player()->query_temp("memory") != 9)
    {
	command("say 給我這個幹嘛！，別人幫你拿的吧？");
      	return 0;
    }
    command("say 果然是孤城密令！！幹的好，小鬼！看來我們殺手後繼有人了！！");
    command("say  就讓我給你殺手密令吧！！");
    message_vision(HIR + "渡永天交給$N一面殺手密令\n" + NOR,me);	
    ob2=new("/open/killer/memory/killer_card.c");
    ob2->move(me);
    command("say  這是證明殺手有資格在各組任職的密令，不見了記得回來找我要( 殺手密令）");
    command("say  只要小渡把任職系統做好，你就可以任職於各組織間");
    command("say   現在就讓我幫你把魔氣殺的限制打開到第二層，讓你可以在將限制提高50級");
    message_vision(HIR + "渡永天迅速在$N身上拍打\n" + NOR,me);	
    tell_object(me,"你感到體內一陣真氣運行，看來魔氣殺可以發揮更強大的威力了\n");
   message("system",HIW + "渡永天縱聲大呼 :\n
		" +this_player()->name()+"你已經可以把魔氣殺變的更強大了!!\n\n" + NOR,users());
    me->set("title",HIM + "新生代特級殺手" + NOR);
    me->set_temp("memory",0);
    me->set("quest/memory",1);
    return 1;
  }
 destruct(ob);
 return 0;
}

int do_join()
{
	if(this_player()->query("class"))
		return notify_fail("你已經加入其他工會了。\n");
	this_player()->set("class","avatar");
	message("system",HIW + "黑衣人縱聲大呼 :\n
		歡迎" +this_player()->name()+"加入工會!!\n\n" + NOR,users());
	return 1;
}

int do_nod()
{
  if (this_player()->query("class")  != "killer")
        return notify_fail("罷了....你這種外人沒資格知道，殺手自己的事情。");
  if (this_player()->query("quest/rain") != 1)
	return notify_fail("孩子，你還小，等你成長到夠資格後，再幫我吧。");
  if (this_player()->query("quest/memory") == 1)
return notify_fail("你不是知道了嗎？");
if (this_player()->query_temp("memroy") == 1)
return notify_fail("乖兒子你想點幾次頭呀");
  this_player()->set_temp("memory",1);
 new("/open/killer/memory/hair.c")->move(this_player());
 command("say 你幫我把這一個髮箍，交給葉玲如好嗎？");


  return 1;
}

int do_show()
{
  if ( !present("card",this_player()) )
return notify_fail("秀？你要跳脫衣舞呀？.....我可沒興趣看呀.........\n");
  if (this_player()->query_temp("memory") != 8)
return notify_fail("你從哪裡偷來的令牌？快滾！！\n");
  this_player()->set_temp("memory",9);
message_vision(HIY + "孤城密令？是玲如他給你的？快把他交給我看
看!!" + NOR,this_player());
return 1;
}

string ask_ghostcard()
{
 	object ob;
    object me=this_player();

if (me->query_temp("head") != 2)
	return "你說什麼？老人家有重聽，沒聽到耶。。。";
//ob = new("/open/killer/headkill/obj/ghost_card.c");
//ob->move(this_player());
message_vision("想要靈異令牌？去把仙劍七子中任何一個人的人頭提來見我！\n",me);
message_vision("要靈異令牌就是要削減其他門派的勢力，所以先證明你的能力吧\n",me);
me->set_temp("head",3);
return "人頭給我，我就給你令牌";
}

string ask_card()
{
 	object ob;
	if( present("killer_card",this_player()) ) return "想要甚麼 ?";
if( !this_player()->query("quest/memory") ) return "想要甚麼 ?";
ob = new("/open/killer/memory/killer_card.c");
ob->move(this_player());
message_vision("$N給$一張殺手密令。\n",this_object(),this_player());
return "小心不要再弄掉了";
}

