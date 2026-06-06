#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("林宏昇",({"master lin","master","lin"}));
	set("long","沒有人知道他的來歷，也沒人知道他的武功有多深；是一個神密莫測的人物，"+
"在三年前因風雲際會，使他創立了〔聖火教〕，也不知他是用何方法建立這個龐大的組織，"+
"也因為如此, 他被江湖上的人稱為〔武林神話〕。\n");
	set("gender","男性");
	set("class","prayer");
 	set("nickname","武林神話");
        set("title","聖火教皇～～");
        set("combat_exp",5000000);
        set("attitude","heroism");
	set("age",75);
        set("max_kee",10000);
	set("str", 50);
	set("cor", 50);
	set("cps", 45);
	set("per", 30);
	set("int", 42);
	set("force",20000);
	set("max_force",20000);
	set("force_factor", 100);
        set("max_gin",2800);
        set("max_sen",2800);
        	set_skill("superforce", 180);
        	set_skill("cure", 120);
        	set_skill("dodge", 150);
	set_skill("force",180);
        	set_skill("move", 150);
        	set_skill("parry", 150);
        	set_skill("stick",150);
        	set_skill("unarmed",150);
        	set_skill("array",150);
        	set_skill("literate",150);
	set_skill("fire-catch",150);
	set_skill("shift-steps",150);
        	set_skill("universe",150);
        	map_skill("force","superforce");
	map_skill("dodge","shift-steps");
	map_skill("move","shift-steps");
	map_skill("parry","universe");
        	map_skill("stick","fire-catch");
        	map_skill("unarmed","universe");
        	set("functions/blood/level",60);
	set("chat_chance_combat", 40);
        	set("chat_msg_combat", ({
		(: perform_action("force.ball") :),
		(: perform_action("force.hand") :),
		(: perform_action("force.sword") :),
		(: exert_function("blood") :),
        }));
	setup();
	carry_object("/u/k/kael/fire-cmd");
	add_money("thousand-cash",10);
	create_family("聖火教",1,"教皇");
}

void init()
{
     	add_action("do_join","join");
    	add_action("do_select","select");
            add_action("do_verify","verify");
}

int do_verify(string arg)
{
 object me,ob;
me=this_player();
ob=new("open/sword/obj/b1");
if( arg!="prayer")
  {
    write("你要申請什麼\n");
    return 1;
   }
if(me->query("family/family_name")!="聖火教")
  {
    write("只有聖火教徒才會有信物\n");
    return 1;
  }

 if( present(ob,me) )
  {
    write("你已經申請過了\n");
      return 1;
   }
   else
    {
     write("這是聖火教的信物 ,望你好好保存 ,切勿遺失了\n");
      ob->move(me);
         return 1;
         }
     }

void attempt_apprentice(object ob)
{
	if(ob->query("marks/聖火八天門")==1)
	{
	if((int)this_player()->query("combat_exp")<=500000)
     	return notify_fail(command("say 好好跟著你自己的師父多學幾年吧!"));
	command("look "+ob->query("id"));
	command("pat");
	command("say 好,你果然是可造之才,你可以去找三位長老作為你武學的指導!");
	ob->delete("family");
	command("say 你想選擇(select)哪一位長老呢?");
	command("say 傳功\長老(gonfu_elder)，執法長老(lawyer_elder)還是戒律長老(behavior_elder)？");
	ob->set_temp("allow_select",1);
	return 1;
            }
	if(ob->query("marks/聖火三長老")==1)
	{
	if((int)this_player()->query("combat_exp")<=1800000)
     	return notify_fail(command("say 以你的程度還不夠資格跟我學習武學與教務的處理吧!"));
	command("look "+ob->query("id"));
	command(":)");
	command("say 好,你果然不是泛泛之輩,你可以去找教內的文武星君作為你武學的指導!");
	ob->delete("family");
	command("say 你可以選擇武星君(warrior)或是文星君(literate)");
	ob->set_temp("allow_select",1);
	return 1;
            }
	if(ob->query("marks/文武星君")==1)
	{
	if((int)this_player()->query("combat_exp")<=3500000)
     	return notify_fail(command("say 好好跟著文武星君多磨練磨練吧!"));
	command("look "+ob->query("id"));
	command("pat"+ob->query("id"));
	command("say 好,你果然是可造之才,從今後就由本教主親自教導!");
	ob->delete("family");
	command("recruit "+this_player()->query("id"));
	message("mud",HIW + "〔聖火教皇〕林宏昇笑道:\n 
	哈哈哈哈....本教主實在太高興啦!\n
	聖火教徒,"+this_player()->name()+": 今後就跟著本教主好好學習如何管理教務吧.\n" + NOR,users());
	ob->set("marks/聖火教主",1);
      　ob->set("title","聖火教嫡傳弟子");
	return 1;
	}
        command("hmm");
	command("say 我教務繁忙 ,你去找聖火八天門的門主吧 !");
	command("say 你想進入(select)哪一門呢?");
	command("say 你可以選擇天機門(tangi)，天樞門(tanshu)，天權門(tanchun)");
	command("say 你可以選擇天璇門(tanshun)，玉衡門(uhen)，開陽門(kiyan)");
	command("say 你可以選擇瑤光門(youkoun)，陣勢門(zhenche)");
	ob->set_temp("allow_select",1);
            }

int do_join()
	{
	if(this_player()->query("class"))
		return notify_fail("你已經加入其他工會了。\n");
	this_player()->set("class","prayer");
	message("mud",HIW + "林宏昇縱聲大呼 :\n
	歡迎" +this_player()->name()+"加入聖火教公會!!\n\n" + NOR,users());
	return 1;
}
int do_select(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say 我又沒答應讓你挑? ");
	return 1;
	}
	if(who->query_temp("have_say")==1)
	{
	message_vision(sprintf(HIC + "$N說道﹕"+str+"\n" + NOR),who);
	command("say 你不是挑過了?");
	return 1;
	}
	if(str=="天機門" ||  str == "tangi")
        {
	 message_vision(HIC + "$N說道﹕天機門\n" + NOR,who);
	this_player()->set_temp("allow_1",1);
	command("smile");
	command("say 嗯 ,你就去加入天機門吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "天樞門" || str == "tanshu")
	{
	message_vision(HIC + "$N說道﹕天樞門\n" + NOR,who);
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say 嗯 ,你就加入天樞門吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "天權門" || str == "tanchun")
	{
	message_vision(HIC + "$N說道﹕天權門\n" + NOR,who);
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say 嗯 ,你就進去天權門修練吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "天璇門" || str == "tanshun")
	{
	message_vision(HIC + "$N說道﹕天璇門\n" + NOR,who);
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say 嗯 ,你就到天璇門好好磨練吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "玉衡門" || str == "uhen")
	{
	message_vision(HIC + "$N說道﹕玉衡門\n" + NOR,who);
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say 嗯 ,你就加入玉衡門吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "開陽門" || str == "kiyan")
	{
	message_vision(HIC + "$N說道﹕開陽門\n",who);
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say 嗯 ,你就前往開陽門學習吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "瑤光門" || str == "youkoun")
	{
	message_vision(HIC + "$N說道﹕瑤光門\n" + NOR,who);
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say 嗯 ,你就前去瑤光門拜師學藝吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "陣勢門" || str == "zhenche")
	{
	message_vision(HIC + "$N說道﹕陣勢門\n" + NOR,who);
	this_player()->set_temp("allow_8",1);
	command("smile");
	command("say 嗯 ,你就前去陣勢門拜師學藝吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "傳功\長老" || str == "gonfu" || str == "gonfu_elder")
	{
	message_vision(HIC + "$N說道﹕傳功\長老\n" + NOR,who);
	this_player()->set_temp("allow_9",1);
	command("smile");
	command("say 嗯 ,你就去傳功\長老那兒學藝吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "執法長老" || str == "lawyer" || str == "lawyer_elder")
	{
	message_vision(HIC + "$N說道﹕執法長老\n" + NOR,who);
	this_player()->set_temp("allow_10",1);
	command("smile");
	command("say 嗯 ,你就去執法長老那兒學藝吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "戒律長老" || str == "behavior" || str == "behavior_elder")
	{
	message_vision(HIC + "$N說道﹕戒律長老\n" + NOR,who);
	this_player()->set_temp("allow_11",1);
	command("smile");
	command("say 嗯 ,你就去戒律長老那兒學藝吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "武星君" || str == "warrior")
	{
	message_vision(HIC + "$N說道﹕武星君\n" + NOR,who);
	this_player()->set_temp("allow_12",1);
	command("smile");
	command("say 嗯 ,你就去武星君那兒學藝吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "文星君" || str == "literate")
	{
	message_vision(HIC + "$N說道﹕文星君\n" + NOR,who);
	this_player()->set_temp("allow_13",1);
	command("smile");
	command("say 嗯 ,你就去文星君那兒學藝吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	command("say 沒這人!");
	return 1;
	}
void greeting(object ob)
{
	if (ob->query_skill("coldpoison", 1))
//	if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
      {
       command("say 教主有令！！凡是學有毒術之人，殺無敕！！");
        kill_ob(ob);
     }
       if( ob->query("class")=="dancer")
        {
        command("say 教主有令，見到舞者-----格殺勿論！！");
        kill_ob(ob);
     }
    return;
}
  
