#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_man()
{
        object ob=this_player();
       if( ob->query_temp("high-man") == 1 )
       {
       ob->set_temp("high-man", 2);
       return("\n我與義兄是在 30 年前相識的, 當時他曾與我共醉倚紅樓!!由於性情相投, 我們就結拜為兄弟了!!他隱居之後, 四處為家, 3 年前我教長老曾見到他一面!!\n");
       }
       else
       {
       return("\n這位小朋友, 難道你知道 [刀神劍仙十三鞭] 現下於何處落腳嗎??\n");
       }
}




void create()
{
        set_name("陳榮鐘", ({"warrior cheng","warrior","cheng"}));
        set("long",@LONG

        聖火教的副教主，教徒們稱呼他為[武星君]．他身長
        八尺，濃眉大眼，尤其是他那一臉的落腮鬍，更是襯
        托出他那炯炯有力的模樣．是教主的左右手之一，對
        於武學的研究則是幾乎已經到了發癡的地步了！

LONG);
        set("nickname","武星君");
        set("gender","男性");
        set("class","prayer");
        set("family/master_name","林宏昇");
        set("combat_exp",2000000);
        set("attitude","heroism");
        set("age",65);
        set("title","聖火教副教主");
        set("kee",6000);
        set("max_kee",6000);
        set("force",10000);
        set("max_force",10000);
        set("force_factor",25);
        set_skill("cure", 60);
        set_skill("superforce", 95);
        set_skill("holy-force", 100);
        set_skill("dodge", 85);
        set_skill("force",95);
        set_skill("move", 85);
        set_skill("parry", 85);
        set_skill("unarmed",80);
        set_skill("fire-array",80);
        set_skill("array",80);
        set_skill("literate",60);
        set_skill("canon",100);
        set_skill("shift-steps",80);
        set_skill("universe",100);
        map_skill("array","fire-array");
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("inquiry",([
        "義兄":(: ask_man :),
        ]));
        set("functions/goldsun/level",60);
        set("chat_chance_combat", 40);
                set("chat_msg_combat", ({
                (: exert_function("goldsun") :),
                (: perform_action("force.sun1") :),
                (: perform_action("force.sun2") :),
        }));
        setup();
    add_money("gold",20);
    carry_object("/open/prayer/obj/dragon-robe")->wear();
    carry_object("/open/prayer/obj/dragon-hat")->wear();
    carry_object("/open/prayer/obj/dragon-hands")->wear();
    carry_object("/open/prayer/obj/dragon-legging")->wear();
    carry_object("/open/prayer/obj/dragon-ring")->wear();
        create_family("聖火教",2,"副教主");
}

int accept_fight(object who)
{
return notify_fail("副教主說道: 去找別人吧!!\n");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_12"))
        {
        command("say 沒有教主的同意,我不敢擅自做主收你為入室弟子!");
        return 0;
        }
        command("smile");
        command("say 哈哈哈!跟著我學武,你一定不會後悔的!!");
        command("say 嗯!老夫所涉獵的武學甚多!!小子可要好好的學呀!!");
        command("recruit "+ob->query("id"));
        ob->set("marks/文武星君",1);
        this_player()->set("title","聖火教武星君得意門生");
}

// by ACKY
int accept_kill(object ob)
{
        int i;
        object ob1, hu_fa;
        ob1 = this_object();

        if( !present("hu-fa", environment(ob)) ) {
        tell_room(environment(ob),HIW"\n突然！衝出兩位護法!!\n\n"NOR);
        for(i=0;i<2;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob));
        hu_fa->command("guard warrior");
        hu_fa->command("follow "+ob->query("id"));
        hu_fa->kill_ob(ob);
        }}
        if( ob->query_temp("warrior") > 3 ) {
		command("say 哼, 想逃? 沒那麼容易！\n" );
		ob->delete_temp("warrior");
		ob->start_busy(1);
	}
	ob->add_temp( "warrior", 1 );
           message_vision(HIR "護法縱身飛撲過來叫道：大膽狂徒！副教主耶！！\n" NOR,ob);
        return 1;
}
void greeting(object ob)
{
        if (ob->query("age") < 16 && (int)ob->query_cor() > 25 && (int) ob->query_con() > 25 )
        {
        write("\n你有沒有聽人說過[刀神劍仙十三鞭]這個外號??\n");
        write("\n他是我的義兄!!隱居了很久了!!現在我也不知道他雲遊何方了!!\n");
        ob->set_temp("high-man", 1);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
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
	  new("/open/sky/obj4/growth_shells")->move(environment(winner));
	  message_vision(HIM"\n從陳榮鐘的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj4/growth_shells",sprintf("%s(%s) 讓陳榮鐘掉下了成長之貝殼於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj4/growth_shells")->move(environment(winner));
	  message_vision(HIM"\n從陳榮鐘的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj4/growth_shells",sprintf("%s(%s) 讓陳榮鐘掉下了成長之貝殼於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();
}
