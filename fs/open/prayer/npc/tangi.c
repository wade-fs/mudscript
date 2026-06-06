#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
inherit SSERVER;
object ob1=this_object();
string do_crystal();
string do_help()
{
    object ob2=this_player();
    if( !ob2->query_temp("殺害人犯") && !ob2->query_temp("can_tell",1)  )
    {
    return(" 閣下並非我聖火教的執法者, 恕在下甚難從命!!\n");
    }
    ob2->delete_temp("can_tell");
    ob2->set_temp("can_go",1);
    return(" 哼!他害我因此無法完成教主交待的任務,我實在無法原諒他..\n
    除非.........\n");
}

string do_else()
{
    object ob2=this_player();
    if( !ob2->query_temp("can_go",1) && !ob2->query_temp("殺害人犯") )
    {
    return("  在下不願多談此事!!閣下請回吧!!");
    }
    ob2->delete_temp("can_go");
    ob2->set_temp("will_go",1); 
    return(" 你去幫我完成這個任務,我就放了他!!願意嗎(nod)??\n");
} 

string ask_water()
{
    object ob=this_player();
    if(!ob->query_temp("ask_hurted") && !ob->query_temp("can_pass"))
    {
    return(" 請恕在下無禮!!閣下似乎無權過問我教中武學之事!!\n");
    }
    ob->delete_temp("ask_hurted");
    ob->set_temp("can_take",1);
    return(" 教主吩咐要我去將白水晶從囹圄池中拿出來!!\n");
}

string do_crystal()
{
    object ob2=this_player();
    object ob3;
    if( ob2->query("quests/white-crystal",1) && !present("white-crystal",ob2) )
    {
    ob3=new("/open/prayer/obj/crystal1");
    ob3->move(this_player());
    return("白水晶是你找回來的, 教主特地破例讓你學學上面的心法!!\n");
    } 
    else
    {
    return("唉!!白水晶到現在還是下落不明啊!!真是急死我了!!");
    }
} 

void create()
{
        set_name("司馬錦", ({"sema ching","ching"}));
        set("long",@LONG

        天機門的門主，在聖火教中素來有        [武學奇才]的稱號．好學
        不倦！對於各種的書籍均好涉獵！個性沉穩，內心細膩，是八
        天門各門主所公認的大哥．武學所及，對於外家兵器與內功均
        有所長．

LONG);
        set("gender","男性");
        set("class","prayer");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",48);
        set("nickname","武學奇才");
        set("title","天機門主");
        set("kee",4500);
        set("max_kee",4500);
        set("force",9000);
        set("max_force",9000);
        set("force_factor",5);
        set("max_gin",3500);
        set("max_sen",3500);
        set_skill("holy-force", 70);
        set_skill("superforce", 80);
        set_skill("cure", 40);
        set_skill("dodge", 70);
        set_skill("force",70);
        set_skill("canon",70);
        set_skill("move", 50);
        set_skill("parry", 70);
        set_skill("unarmed",70);
        set_skill("literate",60);
        set_skill("shift-steps",70);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/black/level",40);
        set("inquiry",([
        "人犯":"那名人犯竟敢擅自將人犯虐待至死,所以被我關在地牢之內反省!!\n",
        "求情":(: do_help :),
        "除非":(: do_else :),
        "拳師":"拳師是我派去洞窟的, 因為教主給了我一個任務!!\n",
        "任務":"是拿一根渾天水晶!!\n",
        "渾天水晶":"是白色的渾天水晶, 上面是記載基本心法的!!\n",
        "白水晶":(: do_crystal :),
        "囹圄池":(: ask_water :),
        ]));
        set("chat_chance",3);
        set("chat_msg", ({
        HIC+"司馬錦朗道:臨名而讓名～求名當求萬世名～!!\n\n"+NOR
        HIC+"臨利而讓利～計利當計天下利～!!\n\n"+NOR,
        HIC+"戒慎恐懼～居萬塵而不染一塵～!!\n\n"+NOR
        HIC+"臨淵履薄～理萬理而不失一機～!!\n\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("black") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    add_money("gold",5);
    create_family("聖火教",5,"天機門主");
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

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_1"))
        {
        command("say 沒有教主的同意,我不敢擅自做主讓你進門!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,以後你就跟我好好學吧!");
        command("recruit "+ob->query("id"));
        ob->set("marks/聖火八天門",1);
        this_player()->set("title","聖火教天機門俗家弟子");
}

int do_nod()
{
  object ob2=this_player();
  if( !ob2->query_temp("will_go",1))
  {
  return 0;
  }
  else
  {
  ob2->delete_temp("will_go");
  ob2->set_temp("can_pass",1);
  write(" 妳去找賣魚的老婦吧!!她會教你如何進入洞窟的!!\n");
  return 1;
  }
}

void greeting(object ob)
{
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
            
