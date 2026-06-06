#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("廚師",({"cooker"}));
    set("title", "天機門");
    set("gender", "男性");
    set("age",58);
    set("attitude","peaceful");
    set("long",@LONG

	聖火教的教徒, 從小就是在聖火教中長大!!專門負責解決教眾
	們的民生問題.

LONG);
 
    set("combat_exp",2000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("max_kee",310);
    set("kee",310);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("universe",10);
    set_skill("force",20);
    set_skill("superforce",20);
    set_skill("move",20);
    set_skill("shift-steps",20);
    set_skill("unarmed",20);
    set_skill("parry",20);
    set_skill("dodge",20);
 
    setup();
    add_money("silver",1);
    carry_object("/open/prayer/obj/communion-cloth")->wear();
    carry_object("/open/gsword/obj/boot-1")->wear();
}
