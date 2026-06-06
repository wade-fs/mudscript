#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("守門弟子",({"door-looker","looker"}));
    set("gender", "女性");
    set("age",26);
    set("attitude","friendly");
    set("long",@LONG

	瑤光門大門的守衛, 職責便是過濾有無閒雜的男性
	混進瑤光門!!並嚴格執行此一任務.

LONG);
 
    set("combat_exp",40000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("force",900);
    set("max_force",900);
    set("force_factor",5);
    set("max_kee",500);
    set("kee",500);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("universe",30);
    set_skill("force",50);
    set_skill("superforce",50);
    set_skill("move",55);
    set_skill("shift-steps",50);
    set_skill("unarmed",50);
    set_skill("parry",50);
    set_skill("dodge",50);
    map_skill("unarmed","universe");
    map_skill("move","shift-steps");
    map_skill("dodge","shift-steps");
    map_skill("parry","universe");
    map_skill("force","superforce");
 
    setup();
    add_money("gold",1);
    carry_object("/open/prayer/obj/wind-robe")->wear();
    carry_object("/open/prayer/obj/wind-boots")->wear();
}

int accept_fight(object who)
{
    return notify_fail("守門弟子說道:我在值勤耶!! 不要來煩我啦!!");
}

void greeting(object who)
{
    if( who->query_temp("擅闖刑房",1) )
    {
    write("周門主已經下了通緝令, 要拿你的人頭來見!!\n");
    kill_ob(who);
    return;
    }

    if( (who->query("family/family_name") == "聖火教") )
    {
    write("\n\t男弟子可得帶教主令牌才能進去喔!!\n");
    return;
    }


    return;
}
