#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
void create()
{
        set_name("司徒知華", ({"se-tu hua","se-tu","hua"}));
        set("long",@LONG

        天璇門的門主！是天權門主司徒榮的元配，其祖乃是中原戰國
        時期的名門將相．與夫婿兩人在教主的垂愛之下，一同加入聖
        火教．司徒知華在內功方面的修為非常專一，對聖火教的鎮教
        武學--渾天寶鑑已經修練的爐火純青!!

LONG);
        set("gender","女性");
        set("class","prayer");
        set("family/master_name","林宏昇");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",44);
        set("title","天璇門主");
        set("kee",5400);
        set("max_kee",5400);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",3800);
        set("max_sen",3800);
        set("force_factor",10);
        set_skill("holy-force", 70);
        set_skill("superforce", 80);
        set_skill("cure",60);
        set_skill("dodge", 60);
        set_skill("force",70);
        set_skill("move", 60);
        set_skill("parry", 80);
        set_skill("canon", 80);
        set_skill("unarmed",70);
        set_skill("literate",60);
        set_skill("shift-steps",60);
        set_skill("universe",60);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/goldsun/level",40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.sun2") :),
        (: exert_function("goldsun") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/speed-ring")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    add_money("gold",5);
    create_family("天璇門",5,"門主");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_4"))
        {
        command("say 沒有教主的同意,我不敢擅自做主讓你進門!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,那你就進入我天璇門吧!");
        command("say 渾天心法博大精深,可不是那麼好學的!");
        command("say 想學渾天心法就得好好修習內功\的基礎!");
        command("recruit "+ob->query("id"));
        ob->set("marks/聖火八天門",1);
        this_player()->set("title","聖火教天璇門俗家弟子");
        }

int accept_kill(object ob)
{
        ob->set_temp("殺妻之仇",1);
        command("say 哼!!"+ob->name()+"我夫婿會替我報仇的。");
        return 1;
}

void greeting(object ob)
{
        if( ob->query_temp("殺夫之仇") )
        {
        command("angry "+getuid(ob));
        command("say 還我先夫[司徒榮]的命來!!!!");
        kill_ob(ob);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
        {
        command("say 教主有令！！凡是學有毒術之人，殺無敕！！");
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
