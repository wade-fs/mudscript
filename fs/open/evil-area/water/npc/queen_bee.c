inherit NPC;
inherit SSERVER;
#include <ansi.h>

void create()
{
	set_name("女王蜂",({"queen of bee","bee"}));
	set("long","
牠就是統領著這棵樹的女王蜂,不過形體似乎與一般的蜜蜂不同。\n");
	set("race","野獸");
	set("gender","雌性");
	set("age",300);
	set("kar",30);
	set("max_gin",40000);
	set("max_kee",45000);
	set("max_sen",30000);
	set_skill("dodge",200);
	set_skill("force",100);
	set_skill("unarmed",200);
	set_skill("parry",200);
        set("limbs",({"頭部","尾部","千節背","尾毒刺","翅膀"}));
        set("verbs",({"dunt","claw","poke"}));
	setup();
}

void heart_beat()
{
	object ob,env,target;

	ob = this_object();
	env = environment(ob);


        target = offensive_target(ob);
        if( env == environment(target) )
        {
                message_vision(HIY"\n
一瞬間～一堆鼓蜂飛了過來攻擊你～\n
\n$N〔咻～〕的一聲飛走了～其它的鼓蜂也跟著飛走了～\n"NOR,ob);
                target->receive_wound("kee",500);
                COMBAT_D->report_status(target,1);
                target->start_busy(1);
                destruct(ob);           

	}
set_heart_beat(1);
::heart_beat();
}

int accept_object(object me,object ob)
{
	if( (int)me->query_temp("evil/water/mission") == 3 )
	{
		if( ob->query("id") == "flower nectar" )
		{
			message_vision("$N震動著翅膀，在樹周圍飛繞的鼓蜂們彷彿回應似的飛了過來～\n",this_object());
			(int)me->set_temp("evil/water/mission",4);
			call_out("do_dest",1,ob);
		return 1;
		}
	}
	message_vision("一群鼓蜂突然圍了過來～$N一時候到驚嚇，整個人失去了重心...\n",me);
	tell_object(me,HIY"你心想：完了...:~...\n"NOR);
	me->move("/open/evil-area/water/b-20");
	me->receive_wound("kee",800);
	COMBAT_D->report_status(me,1);
	message_vision(HIR"\n$N重重的從樹上跌落於地～\n"NOR,me);
	call_out("do_dest",1,ob);
return 1;
}

int do_dest(object ob)
{
	destruct(ob);
}
