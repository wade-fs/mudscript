#include "village.h"
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("許\應",({"bank boss","boss"}));
        set("gender", "男性" );
        set("title","魔界村錢莊老闆");
        set("age", 43);
        set("long","魔界村錢莊的老闆, 是一位和藹可親的中年人.\n");
        set("combat_exp",5000);
        set("attitude", "friendly");
        set("no_kill", 1);
        set_skill("dodge", 30);
        set_skill("unarmed",30 ); 
        set_skill("parry", 30);
        setup();
        add_money("coin",50);
}

void init()
{
        object ob;

        ::init();
}  
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        command("say "+RANK_D->query_respect(ob)+"你好!有什麼我能效勞的地方嗎?");
} 
