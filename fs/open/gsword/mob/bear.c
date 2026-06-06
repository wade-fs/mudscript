inherit NPC;

void create()
{
	set_name("大黑熊", ({"black bear","bear"}));
	set("race", "野獸");
        set("age",20);
set("long", "一隻面目猙獰的大黑熊,正惡狠狠的瞧著你.\n");
        set("str",30);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳" }));
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","friendly");
	set("kee",300);
	set("combat_exp",220);
	set("max_kee",300);
	setup();
}

