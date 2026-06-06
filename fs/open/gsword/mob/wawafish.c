// crazy_dog.c

inherit NPC;

void create()
{
	set_name("娃娃魚", ({ "wawafish", "fish" }) );
	set("race", "野獸");
	set("age", 30);
	set("long", "他渾身散發出一道金色光芒,對你這個不速之客感到有趣。\n");
	set("attitude", "peaceful");
	
	set("str", 33);
	set("cor", 30);

	set("limbs", ({ "頭部", "身體", "魚尾" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp",410);

	set("chat_chance", 6);
	set("chat_msg", ({
	"ㄨㄚ......ㄨㄚ......\n"}) );
	
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}
