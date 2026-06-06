#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_lover()
{
    object ob=this_player();
    if( ob->query("family/family_name") =="聖火教" && ob->query_temp("youkoun") >= 1 )
    {
    ob->set_temp("youkoun", 2);
    return("他叫燕十一, 是霞山派的弟子, 也就是我的救命恩人!!武功\高強, 所以我就....
可是我的[情敵]卻阻撓了我跟他的事!!\n");
    }
    else
    {
    return("我幹嘛要回答你的問題呀!!\n");
    }
}

string ask_emery()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 2 )
    {
    ob->set_temp("youkoun", 3);
    return("她叫做[紅姑], 是他的心上人, 也是他的師姐!!雖然他被我關在[刑房]多年
可是還是念念不忘她!!真是氣人!!\n");
    }
    else
    {
    return("我幹嘛要回答你的問題呀!!\n");
    }
}

string ask_room()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 3 )
    {
    ob->set_temp("youkoun", 4);
    return("雖然我把他給搶了過來, 可是他知道她還沒死, 因此心裡頭就更沒有我了!!
所以我就私設了一個刑房, 每天拷打他, 希望他受不了皮肉之苦而求我!!而且在這幾年中, 
我也自創了一套[馴獸術]!!算是一個小收穫吧!!\n");
    }
    else
    {
    return("我幹嘛要回答你的問題呀!!\n");
    }
}

string ask_skill()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 4 )
    {
    ob->set_temp("youkoun", 5);
    return("馴獸術??喔!!那是我長年在刑房中凌虐男人所悟出來的一種特異武學!!
然後它使將在制服野獸的用途上, 也特別地有效果!!\n");
    }
    else
    {
    return("我幹嘛要回答你的問題呀!!\n");
    }
}

string ask_red()
{
    object ob=this_player();
    if( ob->query_temp("youkoun") >= 3 )
    {
    ob->set_temp("youkoun", 6);
    return("只要能將她解決掉, 一定能讓燕哥哥回心轉意的!!你願意(nod)幫這個忙嗎??\n");
    }
    else
    {
    return("我幹嘛要回答你的問題呀!!\n");
    }
}

string ask_book()
{
    object ob=this_player();
    object ob3=new("/open/prayer/obj/trainbook");
    if( ob->query("quests/trainbeast",1) && !present("trainbook",ob) )
    {
    ob3->move(this_player());
    return "你自己好好地揣摩揣摩吧!!\n";
    }
    else
    {
    return "記得馴獸術只對野獸有效用而已喔!!\n";
    }
}   


void create()
{
        set_name("周琇虔", ({"chou shou-chin","chou","shou-chin"}));
        set("long",@LONG

        瑤光門的門主！生性怪異，雖貴為聖火八天門的門主
        , 可是卻極度的討厭男性, 如無教主的令牌, 任何男
        性都不得進入瑤光門, 否則必死無疑!!所修習的內功
        功力非常深厚!!

LONG);
        set("gender","女性");
        set("class","prayer");
        set("family/master_name","林宏昇");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",34);
        set("title","瑤光門主");
        set("kee",5900);
        set("max_kee",5900);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",3900);
        set("max_sen",3900);
        set("force_factor",10);
        set_skill("holy-force", 90);
        set_skill("superforce", 80);
        set_skill("cure", 20);
        set_skill("dodge",70);
        set_skill("canon",80);
        set_skill("force",90);
        set_skill("move", 40);
        set_skill("parry",70);
        set_skill("unarmed",60);
        set_skill("literate",40);
        set_skill("shift-steps",60);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("inquiry",([
        "刑房":(: ask_room :),
        "愛人":(: ask_lover :),
        "情敵":(: ask_emery :),
        "紅姑":(: ask_red :),
        "密笈":(: ask_book :),
        "馴獸術":(: ask_skill :),
        ]));
        set("functions/bluesea/level",40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.blue1") :),
        (: perform_action("force.blue2") :),
        (: exert_function("blue") :),
        }));
        setup();
    add_money("gold",5);
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
        create_family("瑤光門",5,"門主");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_7"))
        {
        command("say 沒有教主的同意,我不敢擅自做主讓你進門!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,那你就進入我瑤光門吧!");
        command("say 聖火教的絕學博大精深,可不是那麼好學的!");
        command("say 想入我瑤光門就要唾棄男人!!知道嗎??");
        command("recruit "+ob->query("id"));
        ob->set("marks/聖火八天門",1);
        this_player()->set("title","聖火教瑤光門俗家弟子");
        }

void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        add_action("do_nod","nod"); 
        }
}

int do_nod()
{
        object ob=this_player();
        if( ob->query_temp("youkoun") < 6  )
        {
        return 0;            
        }
        else
        {
        ob->set_temp("kill_red",1);
        write("那就拜託你去做了!!事成之後, 我會給你好處的!!\n");
        return 1;
        }

}

void greeting(object ob)
{
    if(!ob) return ;

        if( ob->query_temp("擅闖刑房",1) && ob->query("class") == "prayer" )
        {
          if((int)ob->query("combat_exp") > 300000)
          {
          command("tender "+getuid(ob));
          write("只有女人才會了解女人的心事!!!!\n");
          write("男人那能體會失去[愛人]的心情呢??\n");
          ob->set_temp("youkoun",1);
          return;
          }
          else
          {
          write("大膽小輩, 竟敢擅自進入本門主的刑房!!\n");
          ob->set_temp("youkoun",1);
          kill_ob(ob);
          return;
          }
        }

        if (ob->query_temp("kill_red") >= 2 && !ob->query_temp("kill_eleven") )
        {
        write("\n謝謝你幫了我這個忙!!我就教你[馴獸術]做為獎勵吧!!\n");
        ob->delete_temp("youkoun");
        ob->set_skill("train-beast",5);
        ob->set("quests/trainbeast", 1);
        ob->add("max_force",50);
        return;
        }

        if ( ob->query("kill_eleven") && ob->query("family/master_name") != "周琇虔")
        {
        write("我記得你的樣子, 就是你, 你竟然敢傷害我的燕哥哥!!\n");
        kill_ob(ob);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
        {
        write("教主有令！！凡是學有毒術之人，殺無敕！！\n");
        kill_ob(ob);
        return;
        }
        if( ob->query("class")=="dancer")
        {
        command("say 教主有令，見到舞者-----格殺勿論！！");
        kill_ob(ob);
        return;
        }
    return;
}

void die()
{

    object ob;
    ob= this_object()->query_temp("last_damage_from");
    if( ob && userp(ob) ) 
    {
    ob->delete_temp("kill_red");
    ob->set_temp("kill_youkoun", 1);
    write("你..............\n");
    }
    ::die() ;
}
