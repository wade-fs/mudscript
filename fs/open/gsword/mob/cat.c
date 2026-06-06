inherit NPC;

void create()
{
	set_name("山貓", ({"cat"}));
	set("race", "野獸");
	set("age",5);
set("long","森林中的大山貓,有著利刃一般的雙爪.\n");
        set("str",30);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		
        set("attitude","friendly");
	set("kee",100);
	set("combat_exp",220);
	set("max_kee",100);
	setup();
}

