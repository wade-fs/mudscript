#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("弟子",({"trainee"}));
    set("title", "聖火教");
    set("gender", "女性");
    set("age",22);
    set("attitude","peaceful");
    set("long",@LONG
聖火教的教徒,而且均是習武之人!!!大家的共同願望便是將聖火教傳遍中原武林.

LONG);
 
    set("combat_exp",5000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("max_kee",200);
    set("kee",200);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("move",45);
    set_skill("unarmed",30);
//    set("chat_msg_combat",({
//    (: perform_action,"unarmed." :),}));
 
    setup();
    add_money("silver",10);
    carry_object("/open/prayer/obj/wind-robe")->wear();
}
