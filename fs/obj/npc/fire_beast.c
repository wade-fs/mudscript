// garrison.c

#include <ansi.h>

inherit __DIR__"team";

string fight()
{
	object ob = query_leader();
	object *all = ob->query_enemy();
	object target = all[random(sizeof(all))];
	if( environment(ob) != environment(this_object()) ) return "";
	message_vision("$N"HIR"召喚出雄雄的地獄之火﹐朝$n噴去﹗\n",
	this_object(),target);
	if( random(query("power")) > random(target->query_skill("dodge")) )
	{
		message_vision("$n閃躲不及﹐被大火燒傷。\n",this_object(),target);
		message_vision(NOR,target);
		target->receive_wound("kee",query("power"));
		COMBAT_D->report_status(target);
	}
	else
		message_vision(HIY"$N躲了開來﹐沒被火燄噴到。\n" NOR,target);
}
void create()
{
	set_name(HIR "地獄火神" NOR,({"fire beast","beast"}));
	set("race","野獸");

	set("combat_exp",10000);
	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: fight :),
	}) );

	set("verbs",({"bite","claw"}));
	set("limbs",({"頭部","身體","腳部"}));
	set_skill("unarmed",10);
	set_skill("parry",10);
	set_skill("dodge",10);

	setup();

}

