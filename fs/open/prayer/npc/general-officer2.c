#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("總教頭",({"general-officer","officer"}));
    set("gender", "女性");
    set("age",48);
    set("attitude","peaceful");
    set("long",@LONG

	瑤光門內的總教頭, 功夫倒是不怎麼樣, 不過她是一位
	慘遭離異的女人, 所以被周門主帶回來教授武學, 並提
	報為教授武學的總教練!!

LONG);
 
    set("combat_exp",280000);
    set("str",35);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",30);
    set("force",900);
    set("max_force",900);
    set("force_factor",5);
    set("max_kee",650);
    set("kee",650);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("universe",75);
    set_skill("force",80);
    set_skill("superforce",80);
    set_skill("stick",90);
    set_skill("move",75);
    set_skill("fire-catch",75);
    set_skill("shift-steps",75);
    set_skill("unarmed",85);
    set_skill("parry",85);
    set_skill("dodge",60);
    map_skill("unarmed","universe");
    map_skill("move","shift-steps");
    map_skill("dodge","shift-steps");
    map_skill("parry","fire-catch");
    map_skill("force","superforce");
    map_skill("stick","fire-catch");
 
    setup();
    add_money("gold",3);
    carry_object("/open/prayer/obj/tiger-robe")->wear();
    carry_object("/open/prayer/obj/tiger-legging")->wear();
    carry_object("/open/prayer/obj/tiger-cape")->wear();
    carry_object("/open/prayer/obj/tiger-hander")->wield();
}

void greeting(object who)
{
    if( (who->query("id") == "rence") )
    {
       command("say 歡迎聖火教的創教大神!!");
       command("bow "+who->query("name"));
    }
    else
    {
     command("say 歡迎來到聖火教!!");
    }
return;
}
