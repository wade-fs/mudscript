inherit NPC;

void create()
{
        set_name("老虎", ({"tiger"}));
	set("race", "野獸");
        set("age",20);
set("long", "一頭兇猛的老虎,不過它似乎懼怕什麼似的,對於你的出現完全不理會\n");
        set("str",30);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","friendly");
        set("kee",400);
	set("combat_exp",220);
        set("max_kee",400);
	setup();
}

