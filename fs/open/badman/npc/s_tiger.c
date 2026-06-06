// s_tiger.c

#include "/open/open.h"
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小老虎", ({ "small tiger", "tiger" }) );
        set("race", "野獸");
	set("age", 1);
	set("long", "一隻可愛的小的老虎，看來好像還沒有覓食的能力。\n");
	set("str", 30);
	set("cor", 30);
	set("max_kee", 100);
 	set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
	set("verbs", ({ "bite"}));
	set("combat_exp",620);
	set_temp("apply/armor", 20);
	set_temp("apply/attack", 20);
	setup();
}

void init()
{
	add_action("do_fight", "fight");
}

int do_fight(string arg)
{
	object who;
	who = this_player();

	if( !arg || (arg!="tiger" && arg!="small tiger") )
		return notify_fail("你想攻擊誰﹖\n");
	else {
		kill_ob(who);
		accept_kill(who);
	}

        return 1;
}

int accept_kill(object who)
{
	object ob, tiger;
	ob = this_object();
   if(!ob->query_temp("my_mother")) {

	if( !present("big tiger", environment(ob)) ) {
	tell_room(environment(ob),HIW"\n突然，一隻巨大的母老虎向你衝了過來！\n\n"NOR);
	tiger = new(BAD_NPC"tiger");
	tiger->move(environment(ob));
	tiger->kill_ob(who);
	}
    ob->set_temp("my_mother",1);
  } else
  {
   tell_room(environment(ob),HIR"\n只見小老虎全身發抖,爬在地下!!!!\n\n"NOR);
  }
	return 1;
}
