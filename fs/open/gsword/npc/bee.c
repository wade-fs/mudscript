inherit NPC;

void create()
{
	set_name("蜜蜂", ({ "bee" }) );
	set("race", "野獸");
	set("age", 1);
	set("long", "一隻正在採蜜的蜜蜂.\n");
	set("str", 15);
	set("cor", 25);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
	set("combat_exp",150);
	// 設定 random_move 能離開家的步數
	set("random_move",5);
	set("chat_chance",10);
	set("chat_msg", ({
	    (: this_object(),"random_move" :),
	               }) );
	set_skill("dodge",10);
	setup();               

}

