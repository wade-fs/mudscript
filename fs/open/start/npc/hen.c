// hen.c by nako
// use in /open/start by nako

inherit NPC;

void create()
{
        set_name("母雞", ({ "hen" }) );
        set("long", "農家常見的家禽, 正四處尋找著食物。\n");
	set("race","野獸");
        set("age", 5);
        set("str", 10);
	set("con", 9);
	set("max_gin", 60);
        set("max_kee", 80);
	set("max_sen", 60);

        set("limbs", ({ "喙子", "頭部", "脖子", "翅膀", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );
	set("chat_chance", 4);
	set("chat_msg", ({
                "母雞走著走著, 忽然從地上啄起一隻蟲子。\n",
	}) );
		
        set("combat_exp", 100);
	setup();
        carry_object("/open/start/obj/egg.c");
}
