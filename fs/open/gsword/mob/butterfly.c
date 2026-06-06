inherit NPC;

void create()
{
	set_name("蝴蝶", ({ "butterfly" }) );
	set("race", "野獸");
	set("age", 1);
	set("long", "一隻翩翩飛舞的彩蝶.\n");
	set("str", 15);
	set("cor", 25);
	set("limbs", ({ "頭部", "身體", "翅膀", "觸角" }) );
        set("verbs", ({ "bite" }) );
	set("combat_exp",118);
	set_temp("apply/armor", 10);
	set("chat_chance",10);
	set("chat_msg", ({
	    (: this_object(),"random_move" :),
	               }) );
	set_skill("dodge",5);
	setup();               
	add_money("coin",10);

}

