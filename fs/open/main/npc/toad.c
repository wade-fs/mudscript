inherit NPC;

void create()
{
	set_name("癩蛤蟆", ({ "toad" }) );
	set("race", "野獸");
	set("age", 5);
	set("long", "一隻噁心的癩蛤蟆.\n");
	set("str", 10);
	set("cor", 25);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",100);
	set_temp("apply/armor", 10);
        set_temp("apply/attack", 3);
	set("random_move",2);
	set("chat_chance",10);
	set_skill("dodge",5);
	setup();               
	add_money("coin",10);

}

