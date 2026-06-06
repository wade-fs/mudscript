#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("巨蟒",({"serpent"}) );
	set ("age",1000);
	set("gender","雄性");
	set("race","野獸");
	set("limbs",({"頭部","尾部","腹部"}));
	set("verbs",({"bite"}) );
	set("combat_exp",1000);
	set_skill("dodge",30);
	set("attitude","aggressive");
	set_temp("apply/armor", 50);
	set_skill("unarmed",30);
	set("long","
一條長逾數十尺的巨蟒，昂首吐信，雙目殷紅如血，牠正惡狠狠的
瞪著你，不知是因為你侵犯了牠的地盤，抑或是饑餓而驅使牠要將
你生吞入腹。\n");
	set("str",40);
	set("max_gin",200);
	set("max_kee",150);
	set("max_sen",200);
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
	(: this_object(), "special_att" :),
}) );
	setup();
	carry_object("/open/poison/obj/tooth.c");
}
 int special_att()
{
	object me=this_player()->query_enemy();
	tell_room(me,HIG + "
巨蟒狠狠的咬了你一口，你突然覺得頭昏眼花，似乎中毒了。\n" + NOR );
	me->apply_condition("snake_poison", 1);
	return 1;
}
void die()
{
	object who;
	who = query_temp("last_damage_from");
	who->set_temp("kill_serpent", 1);
 
	::die();
}
