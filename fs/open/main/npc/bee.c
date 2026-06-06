inherit NPC;

void create()
{
	set_name("蜜蜂", ({ "bee" }) );
	set("race", "野獸");
	set("age", 1);
	set("long", "一隻正在採蜜的蜜蜂.\n");
	set("str", 15);
	set("cor", 25);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
	set("combat_exp",418);
	set_temp("apply/armor", 20);
        set_temp("apply/attack", 7);
	set("random_move",3);
	set_skill("dodge",10);
	setup();               
	add_money("coin",50);

}

