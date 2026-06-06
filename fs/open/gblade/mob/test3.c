//test1

#include <ansi.h>

inherit NPC;
#include "common.h"
void create()
{

        set_name("蒼鷹",({"eagle"}));
        set("long","一隻雙眼炯炯有神的老鷹 .");
        set("race","野獸");

        set("max_gin", 100);
        set("max_kee", 100);
        set("max_sen", 100);

        set_temp("apply/armor",3);
        set_temp("apply/damage",8);
        set_temp("apply/attack",25);
        set_temp("apply/dodge",30);
        set("age", 5);
        set("no_exp",1);

        set("str", 40);
        set("cor", 30);
        set("cps", 25);
        set("no_exp",1);

        set("limbs",({"頭部","雙腳","身體"}));
        set("verbs",({"poke"}));
        set("combat_exp", 2000);
/*
        set("chat_chance", 15);
*/
        setup();

}



void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIB + "一聲長嘯 , 妖壺中飛出一隻蒼鷹 .\n"
        + name() + "靈活的飛來飛去 .\n" + NOR,
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
