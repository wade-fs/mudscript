inherit NPC;

void create()
{
        set_name("野狼", ({"wild wolf","wolf"}) );
	set("race", "野獸");
        set("age",10);
        set("long", "一隻饑腸轆轆的野狼\n");
        set("str",30);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","aggressive");
	set("combat_exp",220);
        set("kee",200);
        set("max_kee",200);
	setup();
}

