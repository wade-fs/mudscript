inherit NPC;

void create()
{
	set_name("兔子",({"rabbit"}));
	set("long","一隻生長於黑森林的野兔。\n");
	set("race","野獸");
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("combat_exp",3000);
	set("max_gin",2000);
	set("max_kee",2000);
	set("max_sen",2000);
	set("max_force",4000);
	set("gin",2000);
	set("kee",2000);
	set("sen",2000);
	set("force",4000);
	set("chat_chance",20);
        set("chat_msg", ({ (: random_move :), }) );  
	set_temp("go","跳");
        set_temp("apply/armor", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/attack", 50);
	set_skill("dodge",100);
	set_skill("move",100);
	set_skill("unarmed",50);
	setup();
}
