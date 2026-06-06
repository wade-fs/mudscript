#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("毒龍",({"poison dragon", "dragon" }) );
	set("age",300);
	set("gender","雄性");
	set("race","野獸");
	set("limbs",({"頭部","尾部","腹部"}));
	set("verbs",({"bite"}) );
	set("combat_exp",20000);
	set_skill("dodge",50);
	set("attitude","aggressive");
	set_temp("apply/armor", 50);
	set_skill("unarmed",40);
	set("long","
一條巨大的毒龍。
\n");
	set("str",40);
	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
	(: "special_att" :),
}) );
	setup();
	carry_object("/obj/source/dark_heart.c");
}
 int special_att()
{
	object me=this_player()->query_enemy();
	tell_room(me,HIG "
巨蟒狠狠的咬了你一口，你突然覺得頭昏眼花，似乎中毒了。\n" NOR );
	me->apply_condition("snake_poison",me->query_condition("snake_poison")+5);
	return 1;
}
