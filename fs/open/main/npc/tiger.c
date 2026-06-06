inherit NPC;

void create()
{
	set_name("老虎", ({ "tiger" }) );
        set("race", "野獸");
	set("age", 5);
	set("long", "一隻兇惡的老虎.\n");
	set("str", 65);
        set("max_kee",300);
         set("kee",300);
       set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );

      set("verbs", ({ "bite"}));
        set("combat_exp", 4500);
	set_temp("apply/armor", 50);
        set_temp("apply/attack", 30);
	set("attitude","aggressive");
	set_skill("dodge",40);
	setup();               
	add_money("coin",500);

}

