// garrison.c

#include <ansi.h>

inherit __DIR__"team";

string fight()
{
	object ob = query_leader();
	object *all = ob->query_enemy();
	int i;
	if( environment(ob) != environment(this_object()) ) return "";
	message_vision( "$N" HIC "不斷地飛舞著﹐幻化出無數的幻影﹐擾亂敵人。" NOR,this_object());
	message_vision("\n",this_object());
	for( i = 0 ; i < sizeof(all) ; i ++ ) 
		if(random(query("power"))>random(all[i]->query("force")))
			all[i]->start_busy(1);
}
void create()
{
	set_name(HIC "迷蝶" NOR,({ "buf beast","beast" }));
	set("race","野獸");

	set("combat_exp",10000);
	set("chat_chance_combat",40);
	set("chat_msg_combat", ({
		(: fight :),
	}) );
	set("verbs",({"bite"}));
	set("limbs",({"頭部","翅膀"}));

	set_skill("unarmed",10);
	set_skill("parry",10);
	set_skill("dodge",10);

	setup();

}

