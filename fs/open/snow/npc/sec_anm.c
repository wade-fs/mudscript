// celes_tiger.c

inherit NPC;

void create()
{
      set_name("狼牙虎",({"tiger"}));
      set("title","聖獸");
	set("long",
             "這是雪泉三聖獸之一的狼牙虎﹐負責看守雪泉聖水。\n"
    );

	set("race", "野獸");
	set("age", 160);
       set("attitude","aggressive");

	set("max_gin", 2000);
        set("max_kee",200);
	set("max_sen", 1000);

	set("str", 110);
	set("cor", 40);
	set("spi", 40);
	set("int", 60);

	set("limbs", ({ "頭部", "身體", "前腳", "後腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 80);
	set_temp("apply/damage", 160);
	set_temp("apply/armor", 20);

		set("combat_exp",99340);
	set("score", 100000);
	setup();
}
