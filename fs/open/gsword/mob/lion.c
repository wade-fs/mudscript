inherit NPC;

void create()
{
	set_name("獅子", ({"lion"}));
	set("race", "野獸");
        set("age",10);
	set("long", "萬獸之王,獅子,如果你想活命的話,快逃吧.\n");
        set("str",40);
	set("con",50);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","aggressive");
	set("cpmbat_exp",480);
	set("kee",400);
	set("max_kee",400);
	setup();
}

