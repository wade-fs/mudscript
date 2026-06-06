#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
void create()
{
        set_name("葛輝", ({"ka hui","hui","ka"}));
        set("long",@LONG
        天樞門的門主！道地的西域人士，因為本身對於聖火教非常
        的崇信，所以自年輕時便投入教內的工作．雖然功勞並不是
        很顯赫，可是為教犧牲的精神被教主所欣賞，因而提拔他成
        為八天門的門主之一！
LONG);
        set("gender","男性");
        set("class","prayer");
        set("family/master_name","林宏昇");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",51);
        set("title","天樞門主");
        set("kee",6000);
        set("max_kee",6000);
        set("force",9000);
        set("max_gin",4000);
        set("max_sen",4000);
        set("max_force",9000);
        set("force_factor",5);
        set_skill("holy-force", 60);
        set_skill("superforce", 80);
        set_skill("cure", 40);
        set_skill("dodge", 80);
        set_skill("force",60);
        set_skill("move", 60);
        set_skill("parry", 80);
        set_skill("canon", 80);
        set_skill("unarmed",70);
        set_skill("literate",50);
        set_skill("shift-steps",80);
        set_skill("universe",60);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/white/level",40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("white") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    add_money("gold",5);
        create_family("天樞門",5,"門主");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_2"))
        {
        command("say 沒有教主的同意,我不敢擅自做主讓你進門!");
        return 0;
        }
        command("smile");
        command("say 進入天樞門之後,你就必需對教犧牲,奉獻!知道嗎??");
        command("recruit "+ob->query("id"));
        ob->set("marks/聖火八天門",1);
        this_player()->set("title","聖火教天樞門俗家弟子");
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
