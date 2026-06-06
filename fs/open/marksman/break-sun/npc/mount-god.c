inherit NPC;
inherit F_MASTER;
inherit SSERVER;
#include "/open/open.h"
#include <ansi.h>
#include <mudlib.h>
void create()
{
        set_name("五嶽神官", ({ "mount god","mount","god" }) );
		set("long","守護三山五嶽的神靈。");
        set("attitude", "friendly");
        set("age", 1200);
		set("gender","男性");
		set("family/family_name","聖火教");
        set("max_gin", 200000);
        set("max_kee", 200000);
        set("max_sen", 200000);
	    set("gin",200000);
	    set("sen",200000);
	    set("kee",200000);
        set("str", 35);
        set("cor", 30);
        set("spi", 30);
        set("int", 30);
		set("per", 30);
		set("kar", 30);
        set("bellicosity",8000);
        set("max_force",9000);
        set("force",100000);
		set("max_atman",90000);
        set("atman",500000);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set("force_factor",160);
        set("combat_exp", 20000000);
        set_skill("move",120);
		set_skill("superforce",300);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("blade",400);
		set_skill("shift-steps",150);
        set_skill("force",400);
		set_skill("starblade",120);
        map_skill("blade","starblade");
        map_skill("parry","starblade");
		map_skill("force","superforce");
		map_skill("dodge","shift-steps");
		map_skill("move","shift-steps");
		setup();
		carry_object("/autoload/open-area/super_hands")->wear();
		carry_object("/autoload/sky/claw");
}

void greeting( object me )
{
  me = this_object();
  if(!me) return;
  return;
}

void heart_beat()
{
   object me = this_object();
   if(!me->query("weareq"))
   {
     me->set("attribute","wind");
     me->set("dev_obj/wind",9999999);
     me->set("weapon/wind-full",999);
     command("change_attr blade");     
     command("wield attribute-blade");
	 command("wield attribute-blade");
	 command("wear hands");
     command("wear hands");
     me->set("weareq",1);
   }
   set_heart_beat(1);
   :: heart_beat();
}


void unconcious ()
{
        object winner = this_object()->query_temp("last_damage_from");
		if(!winner) return;
		if(winner->query_temp("ask-break-sun") && winner->query_temp("ask-break-sun")==17)
		{
        command("say 啊，原來是千年前供奉原石的那位啊，那麼請拿走吧！");
        destruct(this_object());
		}
		::die();
}


