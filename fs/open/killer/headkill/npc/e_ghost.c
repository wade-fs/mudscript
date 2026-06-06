#include <ansi.h>
inherit NPC;
void create()
{
    set_name("土之屍魂人",({"ghost"}) );
    set("long",
   "黑牙聯的禁法，所產生的怪物，將屍體浸在藥水中，只聽施藥者的命令\n");
    set("race", "人類");
     set("attitude","aggressive");
    set("gender","男性");
    set("combat_exp",1000000);
    set("age",99);
    set("class","killer");
    set("quest/rain",1);
    set("title",HIY + "土之試煉場關主" + NOR);
    set("kee",2500);
    set("max_kee",2500);
    set("sen",1500);
    set("max_sen",1500);
    set("gin",1500);
    set("max_gin",1500);
    set("max_force",2000);
    set("force",2000);
    set_skill("magic",60);
    set_skill("shade-steps",80);
    set_skill("force",70);
    set_skill("blackforce",90);
    set_skill("dodge",80);
    set_skill("parry",70);
    set_skill("throwing",70);
    set_skill("rain-throwing",90);
    set_skill("dagger",90);
    set_skill("shadow-kill",90);
map_skill("dagger","shdaow-kill");
map_skill("parry","rain-throwing");
map_skill("dodge","shade-steps");
map_skill("force","blackforce");
    set("force_factor",10);
    set("bellicosity",2000);
    setup();
    carry_object("/open/killer/headkill/obj/e_dag")->wield();
}

void die()
{
   object head,killer;
 
   killer=query_temp("last_damage_from");
   if(killer->query_temp("head") == 6 )
   {
     killer->add_temp("kill_ghost",1);
   }
   ::die();
}
