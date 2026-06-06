#include "/open/gsword/npc/attack_bloodsword.h"

#include <ansi.h>
inherit NPC;
#include "/open/open.h"
#include <ansi.h>
inherit F_MASTER;
string ask_moon();

void create()
{
        set_name("李逍遙",({"shou yau","yau"}));
 set("long","
鄭士欣的第七個徒弟，在仙劍七俠中，入門最晚，但是際遇不凡，兼之
悟性奇高，據說其實際武功已在其大師兄張乘風之上，李逍遙天性不
拘小節，愛好打抱不平，近幾年來仗劍行俠於江湖，也已小有俠名。
現在在仙劍派是仙劍劍陣傳人。\n");
        set("gender","男性");
        set("nickname",HIY + "飛星傳恨" + NOR);
        set("combat_exp",500000);
        set("attitude","heroism");
        set("age",21);
        set("class","swordsman");
        set("title","仙劍派第四代七弟子");
        set("score",100000);
        set("kee",1500);
        set("max_kee",1500);
        set("gin",1500);
        set("max_gin",1500);
        set("sen",1500);
        set("max_sen",1500);
        set("force",1000);
        set("max_force",1000);
        set("force_factor",10);
        set_skill("sword",80);
        set_skill("force",50);
        set_skill("sha-array",90);       
        set_skill("shasword",80);
        set_skill("shaforce",50);
        set_skill("array",90);
        set_skill("parry",80);
        set_skill("dodge",70);
        set_skill("move",70);
        set_skill("spells",50);
        set_skill("sha-steps",70);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("parry","shasword");
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        set("str", 30);
        set("cor", 30);
        set("per", 30);
        set("int", 30);
        set("cps", 30);
        set("con", 30);
        set("spi", 30);
        set("kar", 30);
        set("inquiry",([
        "仙劍劍陣" : "仙劍劍陣分好幾種，你想問哪一種？",
        "兩儀劍陣" : "兩儀劍陣共有兩招，『鶴翔紫薇』和『二劍穿腸紅』",
        "三才劍陣" : "三才劍陣有『鱗光三劍』，另有一招『三才密招』是我不懂的，你去問掌門人吧",
        "四象璇嘰劍陣" : "有『四劍八達』此招為常用的，另有『四龍崩月』絕招，同樣也是我無法領會的",
        "八卦遊龍劍陣" : "只有一招『禁斷龍氣七訣斬』，我只領悟了一半，你最好再問問掌門人",
            "月半彎"  :  (: ask_moon :),
                      ]));
        setup();
        carry_object("/open/gsword/obj/sword-7")->wield();
        carry_object("/open/gsword/obj/white_cloth")->wear();
        carry_object("/open/gsword/obj/yau_glove")->wear();
        create_family("仙劍派",4,"弟子");
}
 int accept_fight(object me)
 {
 if((int)me->query("combat_exp")<=80000)
 {
  command(":P");
  command("say 年輕人,生命是很可貴的,請好好珍惜!");
  return 0;
 }
 command(":D");
 command("say 好久沒遇到對手了,亮劍吧!");
  return 1;
 }
string ask_moon()
{
    if(!this_player()->query_temp("ask_moon4"))
        return "嗯....這我可不清楚﹐你最好問問別人吧。";
        command("say 是皇上要你來找我的 ?");
        command("sigh");
        this_player()->set_temp("ask_moon5",1);
        return "自從皇上以鏡月島威脅使她離開後我就再也沒見過她了,不過她和王鍾靈相交甚篤你可以去問看看...";      
}         
void attempt_apprentice(object ob)
  {
        if(!ob->query_temp("allow_7"))
        {
        command("say 好小子,有眼光! ..不過 ...");
        command("say 師父說過,不能亂收徒弟!");
        command("shrug");
        return 0;
        }
  command("giggle");
 command("say 跟著我就對啦!");
 command("say 以後可要認真學喔!");
  command("recruit "+ob->query("id"));
  ob->set("marks/仙劍七俠",1);
  }

void die()
{
	object head,winner = query_temp("last_damage_from");
	int j;
        if(!winner)
	{
	::die();
	return ;
        }

	if(winner->query_temp("head") == 3 )
	{//要求解第三進職的玩家，一定要自己殺死七子之一
	//所以設下head 4，如果不是在解第三進職的玩家，並不會拿到人頭
	message_vision(HIY + "可惡！居然會敗在你的手下,看來武林將有一陣腥風血雨\n" + NOR,this_object());
	message_vision("說完之後他就倒下了。。。。\n",this_object());
	winner->set_temp("head",4);
	head=new("/open/killer/headkill/obj/sword_head.c");
	head->move(this_object());
	}
	if ((winner->query("class") == "killer") && (winner->query_temp("head") != 4))
	{//避免條件連續兩次成立（因為解headkill之謎的一定是殺手）
	//想將七子的人頭家在殺人名單中，所以是殺手來砍七子，亦可以得到人頭
	//但是因為不是在解第三進職，所以並不會設定步驟值
	message_vision(HIY + "可惡！居然會敗在你的手下,看來武林將有一陣腥風血雨\n" + NOR,this_object());
	message_vision("說完之後他就倒下了。。。。\n",this_object());
	head=new("/open/killer/headkill/obj/sword_head.c");
	head->move(this_object());
	}
    if(userp(winner) && winner->query_temp("not_robot") > time() )
    {
	if ( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {      
	  new("/open/sky/obj6/meteor_diamond")->move(environment(winner));
	  message_vision(HIM + "\n從李逍遙的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj6/meteor_diamond",sprintf("%s(%s) 讓李逍遙掉下了流星之瞬鑽於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj6/meteor_diamond")->move(environment(winner));
	  message_vision(HIM + "\n從李逍遙的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj6/meteor_diamond",sprintf("%s(%s) 讓李逍遙掉下了流星之瞬鑽於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
   ::die();
}

