// dove.c by powell

inherit NPC;

void create()
{
        set_name("鴿子", ({ "dove" }) );
        set("long", "一隻溫訓的和平鴿, 正張著牠那圓滾滾的眼睛瞧著你。\n");

	set("race","野獸");
	set("age", 2);
	set("str", 8);
	set("con", 9);
	set("max_gin", 60);
	set("max_kee", 60);
	set("max_sen", 60);

	set("limbs", ({ "尖嘴", "翅膀", "左腳", "右腳", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );
	set("chat_chance", 4);
	set("chat_msg", ({
                "和平鴿眨眨牠的眼睛, 對著你 咕咕 的叫著。\n",
	}) );
		
        set("combat_exp",160);
	setup();
}
