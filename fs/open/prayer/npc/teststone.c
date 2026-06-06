//石人
#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("石人",({"stone man","stone","man"}));
    set("age",100);
    set("attitude","friendly");
    set("long",@LONG

	司徒家家傳的練功石人, 乃練鐵沙掌的輔助用具!!
	只要能通過石人的測試便能穫得正式的傳授!!

LONG);
 
    set("combat_exp",700000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("force",9000);
    set("max_force",9000);
    set("force_factor",30);
    set("max_kee",6700);
    set("kee",6700);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("dodge",80);
    set_skill("move",80);
    set_skill("parry",80);
    set_skill("ironhand",80);
    set_skill("unarmed",70);
    set_skill("fireforce",80);
    map_skill("force", "fireforce");
    map_skill("unarmed", "ironhand");
    map_skill("parry", "ironhand");

    setup();
}


int accept_kill(object who)
{
      
    if( who->query("can_test3",1) && (int)who->query("combat_exp",1) >= 300000 )
    {
    command("tender "+getuid(who));
    who->delete("can_test3");
    kill_ob(who);
    }
    return 1;
}

void die()
{
  object me;
  me= this_object()->query_temp("last_damage_from");
  if( me&& userp(me) ) {
      me->set_temp("win_stone",1);
      }
      ::die() ;
   }

