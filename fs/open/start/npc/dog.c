// dog.c

inherit NPC;

void create()
{
	set_name("野狗", ({ "dog" }) );
	set("race", "野獸");
	set("age", 3);
	set("long", "一隻渾身髒兮兮的野狗。\n");
	
	set("str",11);
	set("con",15);

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	

	setup();
}
