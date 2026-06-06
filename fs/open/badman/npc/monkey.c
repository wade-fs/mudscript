// monkey.c by powell

inherit NPC;

void create()
{
        set_name("猴子", ({ "monkey" }) );
        set("long", "一隻好動的猴子，東摸摸西摸摸，沒有一刻停下來過。\n");

	set( "age", 30);

        set("str", 30);
        set("cor", 30);

        set("combat_exp", 1000);

        set("race", "野獸");

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
		"小猴子：吱吱..吱吱...\n",
 		"小猴子們躲在樹叢裡, 偷偷的望著你這個闖入者。\n",
 	}) );
	
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
        set_temp("apply/armor", 10);
	
	set_skill("dodge",30);
	set_skill("unarmed",30);
	
        setup();
}

