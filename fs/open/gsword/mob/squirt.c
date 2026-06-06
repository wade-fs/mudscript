inherit NPC;

void create()
{
	set_name("松鼠", ({ "squirt" }) );
	set("race", "野獸");
	set("age", 3);
	set("long", "一隻有著蓬鬆尾巴的松鼠.\n");
	set("str", 25);
	set("cor", 30);
	set("limbs", ({ "頭部", "身體", "尾巴", "腳" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 35);
	set_temp("apply/armor", 15);
	set("chat_chance",10);
	set("chat_msg", ({
	    (: this_object(),"random_move" :),
	               }) );
	set_skill("dodge",20);
	set_skill("unarmed",2);
	setup();               
	add_money("coin",10);
	
}

