#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("總教頭",({"general-officer","officer"}));
    set("gender", "男性");
    set("age",38);
    set("attitude","peaceful");
    set("long",@LONG

	聖火教總壇的總教頭, 功夫極高, 且熱心武學, 故被教主授
	命為教授武學的教練!!

LONG);
 
    set("combat_exp",300000);
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
