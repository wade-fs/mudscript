#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("地牢守衛",({"jail-guard","guard"}));
    set("title", "天機門");
    set("gender", "男性");
    set("age",42);
    set("attitude","friendly");
    set("long",@LONG

	天機門地牢的守衛,職責便是看管地牢內的人犯!!!

LONG);
 
    set("combat_exp",70000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("force",900);
    set("max_force",900);
    set("force_factor",5);
    set("max_kee",1570);
    set("kee",1570);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("universe",45);
    set_skill("force",50);
    set_skill("superforce",40);
    set_skill("move",45);
    set_skill("shift-steps",40);
    set_skill("unarmed",45);
    set_skill("parry",85);
    set_skill("dodge",40);
    map_skill("unarmed","universe");
    map_skill("move","shift-steps");
    map_skill("dodge","shift-steps");
    map_skill("parry","universe");
    map_skill("force","superforce");

    setup();
    add_money("coin",40);
    carry_object("/open/prayer/obj/wind-robe")->wear();
    carry_object("/open/prayer/obj/wind-shield")->wear();
}

int accept_fight(object who)
{
    return notify_fail("守衛說道:我要看守犯人呀!! 別鬧了啦!!");
}

void greeting(object who)
{
      
      if( (who->query("family/family_name") == "聖火教") )
      {
       command("say 又想來虐待人犯啦!!");
       command("shurg "+who->query("name"));
       command("say "+who->query("name")+"可不要把人犯弄死了!!!");
     }
    else
     {
     command("say 這裡不是你該來的地方!快離開!!");
    }
 
    if( who->query_temp("殺害人犯") )
    {
    command("angry "+getuid(who));
    command("say 你竟敢殺害人犯，還不快放下武器隨我去見門主。\n");
    kill_ob(who);
    }
    else
    {
    command("stare "+getuid(who));
    command("say 在我的地盤裡就要守規矩喔, 否則......");
    }
    return;
}


