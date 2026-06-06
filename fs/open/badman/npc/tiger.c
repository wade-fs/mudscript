// tiger.c

inherit NPC;

void create()
{
	set_name("母老虎", ({ "big tiger", "tiger" }) );
        set("race", "野獸");
	set("age", 5);
	set("long", "一隻兇惡的老虎。\n");
	set("str", 65);
	set("cor", 65);
	set("max_kee", 200);
	set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
	set("verbs", ({ "bite"}));
	set("combat_exp", 20000);
	set_temp("apply/damage", 30);
	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/attack", 50);
	set("attitude","aggressive");
	set_skill("dodge",40);
	setup();               
}
