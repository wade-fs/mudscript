inherit NPC;

void create()
{
	set_name("野狼", ({ "wolf" }) );
	set("race", "野獸");
	set("age", 5);
	set("long", "一隻饑餓的野狼,牠正找東西吃.\n");
	set("str", 25);
	set("cor", 25);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp", 1050);
	set_temp("apply/armor", 30);
        set_temp("apply/attack", 10);
	set("attitude","aggressive");
	set("random_move",2);
	set("chat_chance",10);
	set_skill("dodge",20);
	setup();               
	add_money("coin",100);

}

