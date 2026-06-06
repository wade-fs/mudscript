
inherit NPC;

void create()
{
        set_name("夜鷹", ({ "eagle" }) );
        set("long", "他是此區域最高等的練功\獸。\n");
	set("race","野獸");
        set("age", 5);
        set("str", 10);
	set("con", 9);	
	set("max_gin", 1000000);
        set("max_kee", 1000000);
	set("max_sen", 1000000);
        set("gin", 1000000);
        set("kee", 1000000);
        set("sen", 1000000);
        set("limbs", ({ "喙子", "頭部", "脖子", "翅膀", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );		
        set("combat_exp", 20000);
	setup();
        
}
