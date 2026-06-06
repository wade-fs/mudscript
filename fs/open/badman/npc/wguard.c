// wguard.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("兵器庫守衛", ({ "guard" }) );
	set("title", "惡人谷第二代小嘍嘍");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "badman");
	set("long", "你看到一個體格粗壯的男子，好像很無聊的在這裡擔任守衛。\n");
	set("combat_exp", 10000);
	set("str", 25);
	set("max_kee", 400);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);
	set_skill("force", 24);
	set_skill("blade", 36);
	set_skill("parry", 20);
	set_skill("dodge", 20);
	set_skill("move", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/dodge", 10);
	setup();
	carry_object(BAD_OBJ"blade")->wield();
}
