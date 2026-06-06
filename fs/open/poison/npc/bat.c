inherit NPC;

void create()
{
        set_name("蝙幅", ({"bat"}));
	set("race", "野獸");
        set("age",2);
        set("str",30);
      set("limbs", ({ "頭部", "身體", "翅膀" }));
        set("verbs", ({ "bite"}));
		
        set("attitude","friendly");
	set("combat_exp", 220);
        set_skill("dodge",5);
	setup();
}

