// hen.c by nako
// use in /open/start by nako

inherit NPC;

void create()
{
        set_name("比比鳥", ({ "bird" }) );
        set("long", "他是此區域最低等的練功\獸。\n");
	set("race","野獸");	 
	set("max_gin", 1000000);
        set("max_kee", 1000000);
	set("max_sen", 1000000);
        set("gin", 1000000);
        set("kee", 1000000);
        set("sen", 1000000);
        set_temp("apply/armor",2);
        set("limbs", ({ "喙子", "頭部", "脖子", "翅膀", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );		
        set("combat_exp", 1000);
	setup();      
}
