#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create() 
{
        set_name(BLU + "百帶" + NOR,({"evil-clever","clever"}));
        set("long",
            "\n它是隱藏於陣邪塔的邪靈之一，一聞到生人氣息就蹦出來吃人。\n");
        set("age",1937);
        set("str",25);
        set("cor",25);
        set("race","野獸");
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",3000);
        set("max_kee",4000);
        set("max_sen",2000);
        set("max_force",10000);
        set("force",10000);
        set("force_factor",10);
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
	set("evil_mob",1);
        set("limbs",({"頭部","胸部","鉛手","籤腿","百帶腰","絲竹背"}));
        set("verbs",({"bite","claw"}));
        setup();
}

void heart_beat()
{
	object ob,env,target;
	int sk1,sk2;

	ob = this_object();
	env = environment(ob);
	if(random(100) < 50)
	{
    	target = offensive_target(ob);
	sk1 = (int)ob->query_skill("parry");
	sk2 = (int)target->query_skill("parry");
		if( env == environment(target) && random(sk1) > random(sk2))
		{
		message_vision("
\n$N" + HIR + "使出所有纏繞於身的帶子，急速旋轉，帶子彷彿雨點般的打中了$n!!\n\n" + NOR,ob,target);
		target->receive_wound("kee",200);
		COMBAT_D->report_status(target,1);
		ob->start_busy(1);
		}
	}
set_heart_beat(1);
::heart_beat();
}
