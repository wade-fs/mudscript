inherit NPC;

void create()
{
        set_name("玉面蝴蝶", ({ "butterfly" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "
稀有且珍貴的蝴蝶，翩翩飛舞在花叢間，姿態顯的格外地嫻靜高雅，仔細
一瞧，發現其頭部有一抹淡淡的斑點，色澤猶如碧玉一般。");
        set("str", 10);
        set("cor", 20);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "頭部", "身體",  }) );
        set("combat_exp",600);
	set("chat_chance",10);
	/*
        set("chat_msg", ({
	(: this_object(),"random_move" :),
                       }) );
	*/
        setup();

}
