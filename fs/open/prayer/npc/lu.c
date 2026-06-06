//陸綺芙
#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("陸綺芙",({"lu chi-fu","lu","chi-fu"}));
    set("gender", "女性");
    set("age",32);
    set("attitude","friendly");
    set("long",@LONG

        玉女派的弟子, 因為師父將掌門之位傳於師妹後, 卻不願
        將劍法與劍譜相傳, 故懷恨在心!!設下陰謀奪取劍譜!!

LONG);
 
    set("combat_exp",700000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("force",900);
    set("max_force",900);
    set("force_factor",5);
    set("max_kee",1970);
    set("kee",1970);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("dodge",80);
    set_skill("move",80);
    set_skill("parry",80);
    set_skill("sword",80);
    set_skill("henma-steps",80);
    set_skill("girlsword",70);
    set_skill("holy-force",80);
    map_skill("move","henma-steps");
    map_skill("force", "fireforce");
    map_skill("sword", "girlsword");
    map_skill("dodge", "henma-steps");
    map_skill("parry", "girlsword");
    set("chat_chance",3);
    set("chat_msg", ({
        "武林萬物～皆為生而輪迴～!!\n\n"
        "百家兵器～獨本劍得精髓～!!\n\n",
    }) );

    setup();
    carry_object("/open/prayer/obj/topknot")->wear();
    carry_object("/open/prayer/obj/tiger-robe")->wear();
//    carry_object("/open/prayer/obj/
}


int accept_kill(object who)
{
      
    if( who->query_temp("will_kill") && (int) !who->query("combat_exp")<= 500000 )
    {
    command("angry "+getuid(who));
    write("你竟然敢與我爭搶劍譜，我看你還是下地獄去跟我師父學吧!!。\n");
    kill_ob(who);
    }
    return 0;
}



