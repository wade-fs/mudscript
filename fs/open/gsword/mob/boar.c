inherit NPC;

void create()
{
	set_name("大野豬",({"boar"}));
	set("race", "野獸");
	set("age",10);
set("long","肥肥胖胖的野豬,看起來挺可愛的.\n");
	set("str",20);
	set("con",30);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳"}));
	set("verbs", ({ "bite", "claw"}));
		
        set("attitude","friendly");
	set("kee",100);
	set("combat_exp",160);
	set("max_kee",200);
	set("kee",200);
	setup();
}

