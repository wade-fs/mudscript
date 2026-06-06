// lolo.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("小嘍嘍", ({ "lolo", "lo" }) );
	set("gender", "男性");
	set("age", 18);
	set("attitude", "badman");
	set("long", "一個剛加入惡人谷的年輕小混混，練武的時候嘴裡還唸唸有詞。\n");
	set("combat_exp", 1200);
	set_skill("blade", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	set_temp("apply/attack", 15);
	set_temp("apply/dodge",10);
	setup();
	carry_object(BAD_OBJ"steel_blade")->wield();
}
