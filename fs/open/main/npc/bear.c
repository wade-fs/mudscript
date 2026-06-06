inherit NPC;

void create()
{
        set_name("野熊", ({ "bear" }) );
	set("race", "野獸");
	set("age", 5);
        set("long", "一隻覓食中的野熊.\n");
	set("str", 45);
	set("cor", 45);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",2371);
	set_temp("apply/armor", 40);
        set_temp("apply/attack", 15);
	set("random_move",2);
	set("chat_chance",10);
/*      set("chat_msg", ({
	    (: this_object(),"random_move" :),
                       }) ); */
	set_skill("dodge",30);
	setup();               
	add_money("coin",200);

}

