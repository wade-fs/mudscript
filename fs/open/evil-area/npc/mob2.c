#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create() 
{
        set_name(YEL"飛蜘蛛"NOR,({"fly-spider","spider"}));
        set("long",
            "\n它是隱藏於陣邪塔的邪靈之一，一聞到生人氣息就蹦出來吃人。\n");
        set("age",1937);
        set("str",25);
        set("cor",25);
        set("race","野獸");
        set("gender","雌性");
        set("attitude","aggressive");
        set("max_gin",500);
        set("max_kee",1500);
        set("max_sen",200);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",4);
        set("combat_exp",800000);
        set_skill("unarmed",80);
        set_skill("dodge",70);
        set_skill("nine-steps",80);
        set_skill("move",60);
        set_skill("parry",70);
        set_skill("hell-evil", 90);
        map_skill("unarmed", "hell-evil");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        set("chat_chance",10);
        set("chat_msg",({
        "四處充滿蜘蛛絲，彷彿很久沒人來一般...\n",
        }));
        set_temp("invis",1);
        set("limbs",({"頭部","胸部","前肢","後肢","腹囊"}));
        set("verbs",({"bite","claw"}));
        setup();
}

void heart_beat()
{
	object ob,env,target;
	int sk1,sk2;

	ob = this_object();
	env = environment(ob);
	if(random(100) < 70)
	{
    	target = offensive_target(ob);
	sk1 = (int)ob->query_skill("parry");
	sk2 = (int)target->query_skill("parry");
		if( env == environment(target) && random(sk1) > random(sk2))
		{
                message_vision("
\n$N"HIW"口中吐出堅韌的絲，$n被困在其中無法動彈!!\n\n"NOR,ob,target);
                COMBAT_D->report_status(target,1);
                target->start_busy(2);
		}
	}
set_heart_beat(1);
::heart_beat();
}

void die()
{
object ob,me,obj;
        ob=this_object();
        me=ob->query_temp("last_damage_from");
        me->add_temp("evil/road_kill",1);
        if(random(100) < 50 && (int)me->query_temp("evil/road_kill") > random(10)+10 )
        {
                message_vision("$N在胸口掏出一個東西, $n眼明手快的搶了過來。\n",ob,me);
                tell_object(me,"你得到了一個噬蟲。\n");
                obj=new(__DIR__"obj/worm");
                obj->move(me);
                me->delete_temp("evil/road_kill");
        }
::die();
}
