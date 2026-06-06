// heaven_soldier.c

#include <ansi.h>

inherit NPC;
//#include "common.h"
void create()
{

        set_name("軒轅劍俠",({"shan yun","shan","yun"}));
        set("long","傳說中的武林第一高手 , 一手軒轅劍法已達驚天泣鬼的造詣
但在三十年前即已身亡 , 你所看到的是他的元神\n");

        set("age",53);

        set("str", 40);
        set("cor", 30);
        set("no_exp",1);
        set("cps", 25);
	set("shan_yun_sword",1);
        set("max_force",5000);
        set("force",5000);
        set("force_factor",20);

        set("combat_exp", 2500000);

        set("chat_chance_combat", 40);
        set("chat_msg_combat",({
        (:  this_object(),"shan_yun"  :)
            }));
        set_skill("parry", 100);
         set_skill("dodge", 100);
        set_skill("sword",120);
        set_temp("apply/sword",120); 
        set_temp("apply/dodge",100);
        setup();
carry_object("/open/gsword/obj/dragon-sword")->wield();

}

void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIW"一道強光從煉妖壺射出 , 一個一臉正氣的中年男子緩步走出\n"
        + name() + "說道 : 遇到我 , 算你倒霉! 留心了 !\n"NOR,
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
        int shan_yun()
 {
    object *enemy;
    int i;
        if(this_object()->query("force")>500)
        message_vision(sprintf(HIY"$N使出軒轅劍法 , 劍光壟罩四面八方 ,空氣中充滿劍氣 ,分擊各敵\n"NOR),this_object());
        enemy = this_object()->query_enemy();
    i=sizeof(enemy);
    while(i--){
if(!enemy[i])  continue;
                enemy[i]->add("kee",-250);
                COMBAT_D->report_status(enemy[i]);
               }
        this_object()->add("force",-500);
        return 1;
  }
void init()
{

      set_heart_beat(1);
}

void heart_beat()
{
        object me=this_object();
        if(me->is_fighting() && random(100)<10)
        {
          call_out("shan_yun",0);
          return;
        }
        if(me->query("kee")<0 || !me->is_fighting())
        {
          call_out("leave",0);
          return ;
        }
         :: heart_beat();
}
void leave()
{  
   message_vision (HIG"軒轅劍俠的元神消失無蹤了\n"NOR, this_object ());  
  destruct(this_object());
}
