inherit NPC;

void create()
{
	set_name("野蜂", ({ "bee" }) );
	set("race", "野獸");
	set("age", 1);
	set("long", "一隻正在採蜜的大野蜂.\n");
	set("str", 25);
	set("cor", 35);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
	set("combat_exp",535);
	set_temp("apply/armor", 20);
        set_temp("apply/attack", 20);
	set("random_move",2);
	set("chat_chance",10);
	set("chat_msg", ({
            (: "random_move" :),
	               }) );
	set_skill("dodge",20);
        set_skill("stabber",5);
	setup();               
	add_money("coin",100);

}

