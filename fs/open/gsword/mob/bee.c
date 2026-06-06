inherit NPC;

void create()
{
	set_name("蜜蜂", ({"bee"}));
	set("race", "野獸");
        set("age",2);
set("long","一隻正在採蜜的蜜蜂\n");
        set("str",30);
      set("limbs", ({ "頭部", "身體", "翅膀" }));
        set("verbs", ({ "bite"}));
		
        set("attitude","friendly");
	set("combat_exp",200);
        set_skill("dodge",5);
	setup();
}

