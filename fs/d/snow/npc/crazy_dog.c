// crazy_dog.c

inherit NPC;

void create()
{
	set_name("瘋狗", ({ "crazy dog", "dog" }) );
	set("race", "野獸");
	set("age", 4);
	set("long", "一隻渾身髒兮兮的野狗﹐一雙眼睛正惡狠狠地瞪著你。\n");
	set("attitude", "aggressive");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"瘋狗大聲吠叫﹕汪﹗汪﹗汪﹗汪﹗汪﹗汪﹗\n",
		"瘋狗突然跳了起來﹐口中亂咬﹐卻不知道是在咬誰。\n"
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}
