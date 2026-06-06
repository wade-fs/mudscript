#include "/open/open.h"
inherit NPC;
void create()
{
 set_name("扶桑隱者", ({ "injan" }) );
	set("gender", "男性" );
	set("age", 34);
	set("long", @LONG
他是扶桑上級程度的武者.
負責守衛著扶桑的安全!
LONG);
      set("attitude","aggressive");
        set("combat_exp",200000);
        set("max_force",1500);
set("force",1500);
set("force_factor",10);
set("kee",800);
set("max_kee",800);
        set_skill("season-flower-blade",70);
        set_skill("dodge",70);
	set_skill("blade",70);
set_skill("force",70);
set_skill("gforce",70);
map_skill("force",70);
	set_skill("parry",70);
	set_skill("unarmed",30);
        set_skill("mirage-steps",70);
        map_skill("blade","season-flower-blade");
        map_skill("parry","season-flower-blade");
        map_skill("dodge","mirage-steps");
        set("chat_chance",40);
        set("chat_msg",({
        (: this_object(),"random_move" :),
        }));
	setup();
        carry_object("/open/ping/obj/guard_blade")->wield();
	
}
void die(){
  object me;
  me= this_object()->query_temp("last_damage_from");
  if( me&& userp(me) ) {
      me->add("head",5);
tell_room(environment(),sprintf("%s殺死了扶桑隱者,得到五點戰功\。\n",me->name()));
}
      ::die() ;
}
