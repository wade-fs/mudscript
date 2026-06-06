// heaven_soldier.c

#include <ansi.h>

inherit NPC;
#include "common.h"
void create()
{

        set_name("四域戰魂",({"hero ghost","ghost","hero"}));
        set("long","死於戰爭中的將軍  \n");
       
        set("age",100);

        set("str", 30);
        set("cor", 30);
        set("no_exp",1);
        set("cps", 25);
  
        set("max_force",1000);
        set("force",1000);
        set("force_factor",8);
        
        set("combat_exp", 250000);

        set("chat_chance_combat", 10);
        set("chat_msg_combat",({
            (: perform_action,"blade.power-dest" :)
            }));
        
        set_skill("parry", 70);
         set_skill("dodge", 50);
        set_skill("blade",75);
        set_skill("dragon-blade",70);
        map_skill("blade","dragon-blade");
        set("attitude","peaceful");
        setup();
        
         carry_object("/open/gblade/obj/blade1")->wield();
        
}


void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIM"一個身穿鎧甲的將軍從妖壺中走了出來\n"
        + name() + "說道 : 可惡的敵人 , 我宰了你\n"NOR,
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
/*
 void special_attack(object ob)
 {
    object *enemy,target;
    int i;
    if(ob->query("mana")>50)
    enemy=ob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    message("vision",
    HIR "$N使出鬼哭神嚎 , 叫的$N心神不凝 \n"NOR,target);
    target->add("sen",-10);
    ob->add("mana",-50);
  }
 */
