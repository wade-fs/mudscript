#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("跑堂",({"footman"}));
    set("gender", "女性");
    set("age",14);
    set("attitude","peaceful");
    set("long",@LONG

	負責運送伙食與收發教文的工作.

LONG);
 
    set("combat_exp",100);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
#include <ansi.h>
    set("cps",30);
    set("kar",20);
    set("max_kee",30);
    set("kee",30);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("dodge",10);
    set("chat_chance",3);                              //說話的機率
    set("chat_msg",({                                  
    HIC+"跑堂說 : 聽說開陽門主秦憶詩的天女散花劍法很厲害喔!!\n"+NOR,
 }));
 
    setup();
    add_money("coin",10);
    carry_object("/open/prayer/obj/communion-cloth")->wear();
}

