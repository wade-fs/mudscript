inherit NPC;

void create()
{
	set_name("山貓", ({ "cat" }) );
	set("race", "野獸");
	set("age", 4);
	set("long", "一隻兇狠飢餓的山貓.\n");
	set("str", 55);
	set("cor", 25);
        set("spi", 45);
        set("con", 40);
       set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );

      set("verbs", ({ "bite"}));
	set("combat_exp", 11968);
	set_temp("apply/armor", 90);
        set_temp("apply/attack", 30);
	set("attitude","aggressive");
	set("random_move",2);
	set("chat_chance",10);
	set("chat_msg", ({
	    (: this_object(),"random_move" :),
	               }) );
	set_skill("dodge",50);
        set_skill("unarmed",10);
	setup();               
	add_money("coin",900);

}

