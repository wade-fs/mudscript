inherit NPC;
#include <ansi.h>
inherit SSERVER;

void create()
{
	set_name("魍魎",({"ghost"}));
	set("long","由沼氣所培育出來有害人體的物質，不知什麼原因，漸漸的變換成\n一種生物。\n");
	set("race","野獸");
	set("attitude","aggressive");
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
        set_temp("apply/damage", 50);
        set_temp("apply/attack", 50);
	set_skill("dodge",200);
	set_skill("move",200);
	set_skill("unarmed",100);
	set_skill("force",200);
	set("force_factor",20);

	set_temp("invis",1);
	setup();
}

void heart_beat()
{
object ob,env,target;
int i,j;

        ob = this_object();
        env = environment(ob);
        target = offensive_target(ob);

        if( !target )
                return ::heart_beat(1);

        if( env == environment(target) )
        {
                i = (int)ob->query_skill("dodge");
                j = (int)target->query_skill("dodge");

		message_vision(YEL"$N身型整個猶如煙霧一般的擴散開來!突然的，整團煙霧撲向了$n!\n"NOR,ob,target);

                if( random(i) > random(j) )
                {
                        message_vision(HIR"\n$N整個人被籠罩於煙霧中，氣力緩緩減低了～\n\n"NOR,target);
                        target->receive_damage("kee",700);
                        ob->receive_curing("kee", 700 );
                        ob->receive_heal("kee",   700 );
                        COMBAT_D->report_status(target,1);
                        COMBAT_D->report_status(ob,1);
                }
		else
			message_vision(HIW"\n$N驚覺煙霧襲來～趕緊施展輕功\步伐避開了。\n\n"NOR,target);
	}
set_heart_beat(1);
::heart_beat();
}
