// garrison.c

#include <ansi.h>

inherit __DIR__"team";

void create()
{
	set_name(YEL "剛熊" NOR,({"bear beast","beast"}));
	set("race","野獸");

	set("combat_exp",10000);
	set("limbs",({"頭部","身體","腳部","尾巴"}));
	set("verbs",({"bite","claw"}));
	set_skill("unarmed",10);
	set_skill("parry",10);
	set_skill("dodge",10);

	setup();

}

