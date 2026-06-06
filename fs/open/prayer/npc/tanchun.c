#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_study()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒榮" && (int)ob2->query("combat_exp") >= 300000 )
    {
    ob2->set("can_study",1);
    return("這是我傳家絕藝!!你首先要好好地練習基本技巧才行......\n");
    }
    else
    {
    return("我不能讓你學習這套掌法!!");
    }
}

string ask_test1()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒榮" && ob2->query("can_study",1) )
    {
    ob2->set("can_test1",1);
    ob2->set_skill("test1",1);
    return("基本技巧--插鐵沙, 是要練此掌法之人先鍛練自己的雙掌強度, \n
    然後才能力保攻敵之時, 掌勁能透敵之體, 傷敵之脈!!先將等級提高吧!!\n");
    }
    else
    {
    return("我不能讓你學習這套掌法!!");
    }
}

string ask_test2()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒榮" && ob2->query_skill("test1",1) >=30 )
    {
    ob2->set("can_test2",1);
    ob2->set_skill("test2",1);
    return("基本技巧--拍石碑, 是要練此掌法之人在鍛練自己的雙掌強度後, \n
    掌握出掌時的勁道, 才能對於掌勁做到收發自如的境界!!繼續加油!!\n");
    }
    else
    {
    return("我不能讓你學習這套掌法!!");
    }
}

string ask_test3()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="司徒榮" && ob2->query_skill("test2",1) >= 30 )
    {
    ob2->set("can_test3",1);
    return("測驗所指的, 乃是進入練功\房中, 針對特製的石人進行對打, 只要能夠擊敗石人
,便可以通過測試, 習得鐵沙掌的入門武學!!\n");
    }
    else
    {
    return("我不能讓你學習這套掌法!!");
    }
}

string ask_test4()
{
    object ob2=this_player();
    if( ob2->query_temp("win_stone",1) && ob2->query("can_test2",1) )
    {
    ob2->set_skill("ironhand",10);
    ob2->delete("can_test1");
    ob2->delete("can_test2");
    ob2->delete_skill("test1");
    ob2->delete_skill("test2");
    ob2->set("study/ironhand",1);
    ob2->set("quests/ironhand",1);
    return("很好, 你通過了測試, 我這就傳你基本的鐵沙掌法!!\n");
    }
}

string ask_book()
{
    object ob2=this_player();
    object ob3=new("/open/prayer/obj/ironbook");
    if( ob2->query("quests/ironhand",1) && !present("ironbook",ob2) )
    {
    ob3->move(this_player());
    return "你務必要好好的學習我家傳的絕藝!!\n";
    }
    else
    {
    return("我不能讓你學習這套掌法!!");
    }
}   

void create()
{
        set_name("司徒榮", ({"se-tu rong","se-tu","rong"}));
        set("long",@LONG

        天權門的門主！與其妻司徒知華兩人分別成為聖火教八天門
        的門主．鵝鰈情深，山盟海誓．司徒榮本身所修練的武學為
        外家兵器，不過他的先天乾坤功與教主所學卻也相差無幾!

LONG);
        set("gender","男性");
        set("class","prayer");
        set("family/master_name","林宏昇");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",45);
        set("title","天權門主");
        set("kee",4700);
        set("max_kee",4700);
        set("force",9000);
        set("max_force",9000);
        set("force_factor",5);
        set("max_gin",2700);
        set("max_sen",2700);
        set_skill("superforce", 80);
        set_skill("holy-force", 50);
        set_skill("cure", 40);
        set_skill("dodge", 60);
        set_skill("force",50);
        set_skill("move", 50);
        set_skill("parry", 90);
        set_skill("canon",80);
        set_skill("unarmed",60);
        set_skill("literate",40);
        set_skill("shift-steps",60);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/black/level",50);
        set("inquiry",([
        "鐵沙掌法":"這是我家傳武學, 一共分成八式!!你想要學習嗎??\n",
        "學習":(: ask_study :),
        "基本技巧":"基本技巧分別是[插沙]與[拍石], 最後再通過[測驗]就可以練成!!\n",
        "插沙":(: ask_test1 :),
        "拍石":(: ask_test2 :),
        "測驗":(: ask_test3 :),
        "通過":(: ask_test4 :),
        "拳譜":(: ask_book :),
        ]));
        set("chat_chance",10);
        set("chat_msg", ({
        HIC+"司徒榮吟道:以無為有～以退為進～以空為樂～以眾為我～!!\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("black") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    carry_object("/open/prayer/obj/speed-ring")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    create_family("天權門",5,"門主");
    add_money("gold",5);
}

int accept_kill(object ob2)
{
        ob2->set_temp("殺夫之仇",1);
        command("say 哼!!"+ob2->name()+"我妻子會替我報仇的。");
        return 1;
}

void attempt_apprentice(object ob2)
{
        if(!ob2->query_temp("allow_3"))
        {
        command("say 沒有教主的同意,我不敢擅自做主讓你進門!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,以後你就用心地好好跟我學武吧!!");
        command("recruit "+ob2->query("id"));
        ob2->set("marks/聖火八天門",1);
        this_player()->set("title","聖火教天權門俗家弟子");
        }

void greeting(object ob2)
{
    if( ob2->query("family/master_name") =="司徒榮" && (int)ob2->query("combat_exp") > 300000 )
    {
    command("pat "+getuid(ob2));
    command("say 我看你的資質頗佳, 我有意傳授你我家傳的[鐵沙掌法]!!\n");
    return;
    }

    if(ob2->query_temp("殺妻之仇",1))
    {
    command("angry "+getuid(ob2));
    command("say 還我賢妻[司徒知華]的命來!!!!");
    kill_ob(ob2);
    return;
    }

    if (ob2->query_skill("coldpoison", 1))
//      if ((present("five poison", ob2)) || (present("dark poison", ob2)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
    {
    command("say 教主有令！！凡是學有毒術之人，殺無敕！！");
    kill_ob(ob2);
    return;
    }
    if( ob2->query("class")=="dancer")
    {
    command("say 教主有令，見到舞者-----格殺勿論！！");
    kill_ob(ob2);
    return;
    }
    return ;
}


