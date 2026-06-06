#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
void create()
{
        set_name("葛梁青", ({"ka lian-gin","ka","lian-gin"}));
        set("long",@LONG

        玉衡門的門主！西域土生土長的人士，是西域第一大美人, 可
        是卻跑來加入聖火教, 並且對於輕功異常喜愛, 一雙快腿倒也
        不輸給天上的飛禽!!

LONG);
        set("gender","女性");
        set("class","prayer");
        set("family/master_name","林宏昇");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",28);
        set("title","玉衡門主");
        set("kee",5850);
        set("max_kee",5850);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",3800);
        set("max_sen",3800);
        set("force_factor",5);
        set_skill("holy-force", 40);
        set_skill("superforce", 80);
        set_skill("cure", 30);
        set_skill("dodge", 90);
        set_skill("force",60);
        set_skill("move", 90);
        set_skill("canon", 80);
        set_skill("parry",60);
        set_skill("unarmed",50);
        set_skill("literate",20);
        set_skill("shift-steps",90);
        set_skill("universe",60);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/white/level",40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.white1") :),
        (: exert_function("white") :),
        }));
        setup();
    add_money("gold",5);
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/speed-ring")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    add_money("gold",5);
        create_family("玉衡門",5,"門主");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_5"))
        {
        command("say 沒有教主的同意,我不敢擅自做主讓你進門!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,那你就進入我玉衡門吧!");
        command("say 聖火教的絕學博大精深,可不是那麼好學的!");
        command("say 想學得絕頂輕功\就得好好修習腿部的功\力!");
        command("recruit "+ob->query("id"));
        ob->set("marks/聖火八天門",1);
        this_player()->set("title","聖火教玉衡門俗家弟子");
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
