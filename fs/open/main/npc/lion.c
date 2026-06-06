inherit NPC;

void create()
{
	set_name("獅子", ({ "lion" }) );
        set("race", "野獸");
	set("age", 5);
	set("long", "一隻雄壯的獅子.\n");
	set("str", 75);
        set("max_kee",400);
        set("kee",400);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp", 5500);
	set_temp("apply/armor", 60);
        set_temp("apply/attack", 30);
        set("attitude","aggressive");
	set_skill("dodge",50);
	setup();               
	add_money("coin",1000);

}

