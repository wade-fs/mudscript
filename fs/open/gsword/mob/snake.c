inherit NPC;

void create()
{
	set_name("大蟒蛇", ({"big snake","snake"}));
	set("race", "野獸");
        set("age",20);
set("long", "身長二,三十尺的大蟒蛇,大嘴一張說不定能生吞一隻小羊.\n");
	set("str",40);
	set("limbs", ({ "頭部", "身體", "尾巴"}));
	set("verbs", ({ "bite"}));
		
        set("attitude","friendly");
	set("kee",400);
	set("con",50);
	set("combat_exp",480);
	set("max_kee",400);
	setup();
}

