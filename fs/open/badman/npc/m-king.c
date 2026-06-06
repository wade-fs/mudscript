// m-king.c by powell

inherit NPC;

void create()
{
        set_name("猴子王", ({ "monkey king", "king" }) );
        set("long", "一隻威武的大猴子，站起來比你還高。\n"+
                    "看來牠是這谷中的領導者。\n");

	set( "age", 150);

        set("str", 130);
        set("cor", 30);

	set( "force_factor", 3 );
	set( "force", 1000 );
	set( "max_force", 1000);

        set("combat_exp", 10000);

        set("race", "野獸");

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("attitude", "friendly");

        set("chat_chance", 2);
        set("chat_msg", ({
		"吱吱..吱吱...\n",
		"猴子王張大牠的雙眼, 瞧了瞧你。\n",
 		"猴子王對著你吱吱的叫了幾聲, 好像要告訴你些甚麼..\n",
        }) );
	
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 20);
	
	set_skill("dodge",80);
	set_skill("unarmed",80);
	
        setup();
}

