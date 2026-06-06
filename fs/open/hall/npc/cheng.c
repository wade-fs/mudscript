inherit NPC;
#include <ansi.h>
#include <combat.h>
#include "/open/open.h"
string do_thief();
string ask_test();
void create()
{
	set_name("紀無塵", ({ "chi wu-cheng","chi", "cheng" }) );
	set("title", "總理執事");
        set("nickname", "京城之光");
    set("class","swordsman");
	set("gender", "男性" );
	set_max_encumbrance(1000000);
	set("age", 46);
	set("str", 20);
	set("cor", 20);
	set("cps", 20);
	set("int", 30);
	set("spi", 20);
	set("kar", 26);
	set("per", 20);
	set("con", 30);

	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 5);

	set("long", @LONG
    人稱『京城之光』，人說其斷案如神，決不徇私茍且。所以這裡的
百姓都很敬愛他。也因為他的功績輝煌，先皇特賜其一柄尚方寶劍，准
其將惡慣滿盈之人，先斬後奏!!
LONG);

	set("combat_exp",500000);
	set("score", 30000);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	"無塵大人喝道：大膽狂徒!!  拿下!!\n",
	"無塵大人喝道：公堂之上竟敢撒野!!  給我嚴懲!!\n"
	}) );

	set_skill("unarmed", 30);
	set_skill("force",  20);
	set_skill("parry",  20);
	set_skill("dodge",  20);
	set_skill("sword",  20);
	set_skill("literate", 90);

	set("inquiry", ([
	  "機器人" : "哼!! 誰被我抓到是機器人的話，斬立決!!",
       "試煉印記" : (:ask_test:),
	  "accuse" : "想緝捕機器人的話，請先到門口擊鼓申冤(accuse)。",
	  "thief"  : (: do_thief :),
	  "測試"   : "想抓賊(thief)就得先經過我測試, 若能連接我五招便算過關了。",
	  "test"   : "想抓賊(thief)就得先經過我測試, 若能連接我五招便算過關了。",
	  "accept" : "要接受測試嗎? 那就打(accept test)。",
	]) );

	setup();
	carry_object(HALL_NPC"obj/god_sword")->wield();
	carry_object(HALL_NPC"obj/o_cloth")->wear();
}

string do_thief()
{
	object me=this_player();
    if( me->query("quests/catch_thief") == 0 || (me->query("marks/ask_linpo") && me->query("family/family_name")=="段家"))
	{
	  if( me->query_temp("thief") == 0 )
	    me->set_temp("thief",1);
	  return (RANK_D->query_respect(me)+"是有意幫忙抓京城大盜的嗎? "+
		"只是最近有許\多沒本事的人前來應徵\n, "+RANK_D->query_respect(me)+
		"若有本事的話請先接受測試吧(accept test)。");
	}
	else
	{
	  command("smile");
	  command("pat "+me->query("id"));
	  return ("這件事真是多虧了你, 如今京城又恢復平靜了。");
	}
}					    
void init()
{
	add_action("do_accept","accept");
}
int do_accept(string str)
{
	int i;
	object ob=this_object();
	object me=this_player();
	object mark=new(CAPITAL_OBJ"mark");
	if( me->query_temp("thief") == 0)
	  command("say 先問問為何要測試吧。");
	if( me->query_temp("thief") > 1)
	  command("say 不是測試過了嗎?");
	if( me->query_temp("thief") == 1)
	{
	if( str=="test")
	{
	  command("say 好! 待老夫來試試你! 小心了");
	  for(i=0;i<5;i++)
	    COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_QUICK);
	  if( me->query("kee") > 1 )
	  {
	    command("say 果然不愧\為真英雄, 那我就將這件事原原本本的說與你聽了");
	    command("thank "+me->query("id"));
	    command("say 這京城大盜目前為止已得手不下數次, 連京城首富乾通天的宅第也\n"+
	    "		 遭殃了, 因此這才驚動皇上下令一個月之內必須破案, 既然"+RANK_D->query_respect(me)+
	    "\n 	   自告奮勇, 那這件事就拜託你了。將此名大盜逮捕歸案, 則必定重重有賞。");
	    message_vision("$N交給$n一面「衙門令牌」。\n",ob,me);
	    mark->move(me);
	    command("say 希望這面令牌對你辦案能有所助益。");
	    me->set_temp("thief",2);
	  }
	  else
	  {
	    command("say 罷了罷了, 我還是繼續等真英雄來吧");
	    command("sigh");
	  }
	}  
	else
	  write("接受什麼?!\n");
	}
	return 1;		 
}

int accept_object(object me, object man)
{
	string target = "趙琴風";
	object ob=this_object();
	object reward;
	if( me->query_temp("thief") < 2 )
	  return notify_fail(ob->query("name")+"說道﹕疑..我好像沒有託你辦這件事嘛。既然你這麼熱心, 那就謝囉。\n");
	if( man->query("victim_name") == target || man->query("name") == target )
	{
	  command("say 真是太好了, 我託付你的事終於順利的達成了。");
	  if( man->query("name") == target )
	  {
	    command("say 按照約定, 這就是你應得的賞金。\n");
	    reward = new("/obj/money/gold");
	    reward->set_amount(5);
	    reward->move(me);
	    message_vision("$N賜給$n五兩黃金。\n",ob,me);
	  }
	  else
	  {
	    command("say 可惜這京城大盜已死, 因此賞金只有一半了。");
	    reward = new("/obj/money/gold");
	    reward->set_amount(2);
	    reward->move(me);
	    message_vision("$N賜給$n二兩黃金。\n",ob,me);
	  }
	  if( !me->query("quests/catch_thief") )
	  {
	    write("\n\n**完成京城大盜之謎***\n你得到實戰經驗 200。\n");
	    me->add("combat_exp",200);
	    if( me->query("class") == "officer" )
	    {
	      write("你得到政治權力 20。\n");
	      me->add("max_officer_power",20);
	    }  
	    me->set("quests/catch_thief",1);
	    me->delete_temp("thief");
	  }
	  destruct(man);
	}
	return 1;
}	
	
void die()
{    
	object winner = query_temp("last_damage_from");
	int j;
        if(!winner)
	{
	::die();
	return ;
        }
    if(userp(winner) && winner->query_temp("not_robot") > time() )
    {
	if ( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {
	  new("/open/sky/obj9/health-charm")->move(environment(winner));
	  message_vision(HIM + "\n從紀無塵的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj9/health_charm",sprintf("%s(%s) 讓紀無塵掉下了健康之符於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj9/health-charm")->move(environment(winner));
	  message_vision(HIM + "\n從紀無塵的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj9/health_charm",sprintf("%s(%s) 讓紀無塵掉下了健康之符於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
    }

	::die();
}
string ask_test()
{
 if(this_player()->query("quests/yan")==3)
 {
 if(this_player()->query("quests/catch_thief",1)&&this_player()->query("quests/yantestmark1",1)  && this_player()->query("quests/2ndtest",2))
  {
  int i;
  i=6+random(5);
  command("say 謝謝您的幫忙.我願意將appo給我的印記傳到你身上!\n");
  tell_object(this_player(),HIW + "瞬間由紀無塵將手搭在你的肩上..你頓時覺得一股暖意由紀無塵的手中傳過來\n" + NOR);
  this_player()->set("quests/2ndtest",i);
  this_player()->set("quests/yantestmark2",1);
  return("最後一個印記在聖賢書手上,你可以去找他問問了\n");
  }
 else if (this_player()->query("quests/yantestmark2")>1)
  return ("我已經把印記給你了..你還要做什麼\n");
 else
  return ("去當我把京城大盜找出來我就跟你說印記在哪。\n");
 }
else
 return ("啥印記..你在說什麼?\n");
}
