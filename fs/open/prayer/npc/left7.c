//左護法
#include <command.h>

inherit NPC;

void create()
{
    set_name("左護法",({"hu-fa left"}));
    set("title","瑤光門");
    set("gender", "女性");
    set("age",35);
    set("attitude","friendly");
    set("long",@LONG

	門主周琇虔親自挑選並加以訓練的弟子，其中所灌輸的觀念，
	就是一定要對男人有所憎恨．看見男人便要狠下心來，決不許
	談論半點感情。

LONG);
    set("combat_exp",500000);
    set("str",25);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",30);
    set("force",1400);
    set("max_force",1400);
    set("force_factor",5);
    set("max_kee",1300);
    set("max_sen",1300);
    set("max_gin",1300);
    set("kee",1300);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("universe",75);
    set_skill("force",80);
    set_skill("superforce",80);
    set_skill("stick",95);
    set_skill("move",75);
    set_skill("fire-catch",80);
    set_skill("shift-steps",75);
    set_skill("unarmed",75);
    set_skill("parry",85);
    set_skill("dodge",80);
    map_skill("unarmed","universe");
    map_skill("move","shift-steps");
    map_skill("dodge","shift-steps");
    map_skill("parry","fire-catch");
    map_skill("force","superforce");
    map_skill("stick","fire-catch");
    set("chat_chance_combat",50);
//    set("chat_msg_combat",({
//    (: perform_action,"unarmed." :),}));
 
    setup();
    add_money("gold",4);
    carry_object("/open/prayer/obj/tiger-robe")->wear();
    carry_object("/open/prayer/obj/tiger-stick")->wield();
    carry_object("/open/prayer/obj/tiger-legging")->wear();
    carry_object("/open/prayer/obj/tiger-cape")->wear();

}

void greeting(object who)
{
    if( (who->query("family/family_name") == "聖火教") )
    {
    command("smile "+who->query("name"));
     command("say 裡面是瑤光門的禁地!!沒有門主的許\可千萬不要進去喔!!");
    }
    else
    {
     command("say 裡面是瑤光門的禁地!!");
    }
return;
}
