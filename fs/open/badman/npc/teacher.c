// teacher.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("武道館教頭", ({ "teacher" }) );
	set("gender", "男性");
	set("age", 30);
	set("attitude", "badman");
	set("long", "他留著滿臉的落腮鬍，臉上還有一條不小的刀疤，看來身經百戰的樣子。\n");
	set("combat_exp", 43000);
	set("str", 30);
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);
	set_skill("force", 40);
	set_skill("blade", 54);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	set_skill("move", 30);
	set_temp("apply/attack", 25);
	set_temp("apply/dodge", 20);
	setup();
	carry_object(BAD_OBJ"blade")->wield();
}
// below is add by powell...
// bcz player say when fight message is wrong..
int accept_fight(object who)
{
        object obj = this_object();
        return notify_fail("看起來" + obj->name() +"並不想跟你較量。\n");
}
