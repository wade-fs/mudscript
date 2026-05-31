// garrison.c

#include <ansi.h>

inherit __DIR__"team";

string fight()
{
	object ob = query_leader();
	if( environment(ob) != environment(this_object()) ) return "";
	message_vision( "$N"HIG"的身上放出靈光﹐照在$n身上﹐使$n的傷口復原。\n" NOR,this_object(),ob);
	ob->receive_heal("kee",query("power"));
	COMBAT_D->report_status( ob );
}
void create()
{
	set_name(HIG "回力鳥" NOR,({"bird beast","beast"}));
	set("race","野獸");

	set("combat_exp",10000);
	set("chat_chance_combat",30);
	set("limbs",({"頭部","翅膀","身體","腳部"}));
	set("chat_msg_combat", ({
		(: fight :),
	}) );

	set("verbs",({"bite","claw"}));
	set_skill("unarmed",10);
	set_skill("parry",10);
	set_skill("dodge",10);

	setup();

}

