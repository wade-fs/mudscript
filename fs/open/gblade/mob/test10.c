// heaven_soldier.c

#include <ansi.h>

inherit NPC;
#include "common.h"
void create()
{

        set_name("金刀戰士",({"soldier"}));
        set("long","戰士中最高等級 -- 金刀戰士 , 看他那把鋒利的鍍金刀
不知砍死了多少人命 \n");

        set("age",25);

        set("str", 40);
        set("cor", 30);
        set("cps", 25);
        set("no_exp",1);
        set("max_force",500);
        set("force",500);
        set("force_factor",5);

        set("combat_exp", 50000);
/*
        set("chat_chance", 15);
*/
        set_skill("parry", 40);
         set_skill("dodge", 35);
        set_skill("blade",60);
        set_skill("gold-blade",50);
        set_skill("fly-steps",40);
        map_skill("blade","gold-blade");
        map_skill("dodge","fly-steps");

        setup();
        carry_object("/open/gblade/mob/weapon10")->wield();

}



void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIY + "一個雄威懍懍的戰士從妖壺中走出 .\n"
        + name() + "說道 : 大膽妖孽 , 納命來 !\n" + NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        /*
        set_leader(who);
        */
}
