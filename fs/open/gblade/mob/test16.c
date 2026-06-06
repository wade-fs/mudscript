// heaven_soldier.c

#include <ansi.h>

inherit NPC;
#include "common.h"
void create()
{

        set_name("戮世妖僧",({"evil monk","monk"}));
        set("long","一名殺孽深重的怒僧 , 原本隨侍於地藏王座前 , 後因心
持不正 , 沾染了陰界冤魂之鬼氣 , 而漸漸轉化為魔 .\n");
       
        set("age",1000);

        set("str", 30);
        set("cor", 30);
        set("cps", 25);
        set("max_kee",1000);
        set("no_exp",1);
        set("max_gin",500);
        set("max_sen",300);
        set("max_force",1200);
        set("force",1200);
        set("force_factor",8);
        /*
        set("max_force",3000);
        set("force",3000);
        set("force_factor",20);
        */
        set("combat_exp", 350000);

        set("chat_chance_combat", 12);
        set("chat_msg_combat",({
                (: this_object(),"special_attack" :)
            }));
        /*
        set_skill("parry", 100);
         set_skill("dodge", 100);
        set_skill("sword",120);
        set_temp("apply/sword",120); 
        */
         set_skill("blade",80);
        set_skill("unarmed",80);
        set_skill("dodge",80);
        set_skill("parry",50);
        set_temp("apply/dodge",50);
        set_temp("apply/blade",50);
        set("attitude","peaceful");
        setup();
        carry_object("/open/gblade/mob/weapon16")->wield();
}


void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIM"一名滿身鮮血的陰界僧人從妖壺中一躍而出 \n"
        + name() + "怒道: 一念成魔斷仙風 , 一斬戮世譴塵緣\n"NOR,
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

        void special_attack()
 {
    object *enemy,target;
    int i;
        if(this_object()->query("force")>100 && present("blood blade",this_object()) )
        enemy=this_object()->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
        message_vision(sprintf(HIR"戮世妖僧手中的血斬開始泣血 , 漸漸將$N籠罩在一片血霧之中\n"NOR),target);
        target->add("kee",-50);
        this_object()->add("force",-100);
        COMBAT_D->report_status(target);
  }
 
