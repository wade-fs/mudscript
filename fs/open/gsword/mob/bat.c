inherit NPC;

void create()
{
 	set_name("吸血蝙蝠", ({"blood bat","bat"}));
	set("race", "野獸");
        set("age",2);
set("long", "模樣恐怖的吸血蝙蝠,無情的攻擊任何人.\n");
        set("str",30);
      set("limbs", ({ "頭部", "身體", "翅膀" }));
        set("verbs", ({ "bite"}));
		
        set("attitude","aggressive");
	set("combat_exp",220);
        set_skill("dodge",5);
	set_temp("apply/attack",10);
	setup();
}

