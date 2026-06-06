inherit NPC;
#include <ansi.h>
#include <heart.fun>
inherit SSERVER;

void create()
{
        set_name("野人哨兵",({"wild soldier","wild","soldier","wild soldier 1"}));
        set("long","最低階層的野人哨兵。\n");
        set("race","野獸");
        set("attitude","friendly");
        set("limbs", ({ "頭部", "身體", "手臂" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp",400000);
        set("max_gin",5000);
        set("max_kee",10000);
        set("max_sen",5000);
        set("max_force",10000);
        set("gin",5000);
        set("kee",10000);
        set("sen",5000);
        set("force",10000);
        set("chat_chance",20);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("unarmed",100);
        set_skill("force",200);
        set("force_factor",30);
	set("must_heart_beat",1);
        setup();
}

void heart_beat()
{
object ob,env,room;
	ob = this_object();
	room = environment(ob);

	if ( heart(ob,10) )
	{
		ob->do_command("say 該換班了...");
		ob->add("kee",-1);

		if ( room->query("mark") == 1 )
		{
			ob->do_command("south");
			ob->do_command("east");
			ob->do_command("north");
		}
		else if ( room->query("mark") == 2 )
		{
			ob->do_command("south");	
			ob->do_command("west");
			ob->do_command("north");
		}

		if ( present("wild soldier 2",environment(this_object()) ) )
		{
			ob->do_command("say 換班了~");
			present("wild soldier 2",environment(this_object()) )->set("move",1);
		}
		else
		{
			message_vision(HIR + "$N發出奇怪的吼聲～！\n" + NOR,ob);
			if ( environment(ob)->query("mark") == 1 )
			{
				ob->do_command("south");
				ob->do_command("east");
				ob->do_command("north");
			}
			tell_object(environment(ob),"野人哨兵迅速的往下跳，並關閉通道！\n");
			environment(ob)->delete("exits/down");
			destruct(ob);
		}
		::heart_beat(1);
	}
::heart_beat(1);
}

void die()
{
object ob;
	ob = this_object();

	message_vision(HIR + "$N撐著最後一口氣，急忙的將往下的路口關閉！" + NOR,ob);

		if ( environment(ob)->query("mark") == 1 )
		{
			ob->do_command("south");
			ob->do_command("east");
			ob->do_command("north");
		}

	environment(ob)->delete("exits/down");
::die();
}
