#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;

string ask_man()
{
        object ob=this_player();
        if( ob->query_temp("high-man") >= 3 )
        {
        ob->set_temp("high-man", 4);
        return("他性情極為溫和, 好打抱不平, 我在 3 年前奉教主之命前往中原辦事, 回途受襲, 幸虧此位高人搭救才倖免於難!!他四處雲遊, 真不知道要如何才能遇到他??
不過老夫相信, 只要有人遇到危難時, 他應該會挺身而出吧!!\n");
        }
        else
        {
        return("嗯, 你問這些要做啥呢??\n");
        }
}        

void create()
{
        set_name("傳功\長老", ({"gonfu_elder","gonfu","elder"}));
        set("long",@LONG

        聖火教護教長老之一的傳功長老，先天乾坤功的造詣
        已是如同神一般的莫測，就連教主也自嘆弗如！非常
        喜愛武學方面的比試，而且對於各家的武學均能略述
        一二，是教內的武學通．與副教主武星君是拜把兄弟．

LONG);
        set("gender","男性");
        set("class","prayer");
        set("nickname","武痴");
        set("family/master_name","林宏昇");
        set("combat_exp",1500000);
        set("attitude","heroism");
        set("age",58);
        set("title","聖火教");
        set("kee",5500);
        set("max_kee",5500);
        set("force",10000);
        set("max_force",10000);
        set("force_factor",15);
        set("max_gin",2800);
        set("max_sen",2800);
        set_skill("superforce", 90);
        set_skill("dodge", 60);
        set_skill("cure",65);
        set_skill("literate",65);
        set_skill("force",90);
        set_skill("holy-force",85);
        set_skill("move", 70);
        set_skill("canon",90);
        set_skill("parry", 70);
        set_skill("universe",95);
        set_skill("unarmed", 90);
        set_skill("shift-steps",85);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("inquiry",([
        "隱世高人":(: ask_man :),
        ]));
        set("functions/goldsun/level",60);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("goldsun") :),
        }));
        setup();
        create_family("聖火教",4,"長老");
    carry_object("/open/prayer/obj/dragon-robe")->wear();
    carry_object("/open/prayer/obj/dragon-hat")->wear();
    carry_object("/open/prayer/obj/dragon-hands")->wear();
    carry_object("/open/prayer/obj/dragon-icer")->wield();
    carry_object("/open/prayer/obj/dragon-legging")->wear();
    add_money("gold",10);
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_9"))
        {
        command("say 沒有教主的同意,我不敢擅自做主收你為入室弟子!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,以後你就跟我好好學吧!");
        command("recruit "+ob->query("id"));
        ob->set("marks/聖火三長老",1);
        }
int accept_kill(object ob)
{
        int i,j;
        object ob1, hu_fa, *enemy;
        ob1 = this_object();
        add_temp("kill_me",1);
        if(query_temp("kill_me")>5)
        {          
          message_vision( HIY"\n$N受不了敵人的騷擾而發狂了!!\n"NOR,ob1);
          set("title",HIR"〈發狂〉"NOR);         
          enemy = all_inventory( environment(ob1) );
          j=sizeof(enemy);
          for(i=0;i<j;i++)
          {
            if(userp(enemy[i]) && !enemy[i]->is_fighting() && living(ob1))
              kill_ob(enemy[i]);
          }
        }
        if( !present("hu-fa", environment(ob)) && living(ob1)) {
        tell_room(environment(ob),HIW"\n突然！衝出兩位護法!!\n\n"NOR);
        for(i=0;i<2;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob));
        hu_fa->command("guard behavior_elder");
        hu_fa->command("follow "+ob->query("id"));        
        hu_fa->kill_ob(ob);        
        }}
        write("護法縱身飛撲過來叫道：大膽狂徒！長老你也敢動！！\n");
        return 1;
}

void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
        if(!ob) return ;
        if (ob->query_temp("high-man") == 2 )
        {
        write("\n呵呵, 我那位武癡義兄對你說了些什麼嗎??嗯, 你的資質頗佳, 難怪他會告訴你這件事情!!\n");
        write("\n那位[隱世高人]武學真的非常深厚, 尤其是在劍, 刀, 與鞭的造詣上, 更是令人拜服!!我與他曾有一面之緣呢!!\n");
        ob->delete_temp("high-man");
        ob->set_temp("high-man", 3);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
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
