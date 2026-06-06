// te.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("鐵戰", ({ "te jang", "te", "jang" }) );
	set("nickname", "狂獅");
	set("title", "惡人谷左護法");
	set("gender", "男性");
	set("class", "bandit");
	set("age", 48);
	set("long", "他長了一頭的亂髮，再加上滿臉的鬍子，大大的頭，看起來活像是一頭雄獅。\n一般人聽到鐵戰的名字莫不聞之喪膽，因為他一旦發起狂來可是六親不認，不\n要命的朝對手連攻，至死方休，這也正是人稱他「狂獅」的由來。\n他便是惡人谷的左護法，全權負責武道館的訓練事宜。\n");
	set("attitude", "badman");
	set("combat_exp", 950000);

	set("str", 42);
	set("cor", 45);
	set("int", 14);
	set("spi", 18);
	set("cps", 25);
	set("con", 35);
	set("per", 14);
	set("max_force", 1700);
	set("force", 1700);
	set("force_factor", 10);
	set("max_kee", 2500);
	set("max_gin", 1500);
	set("max_sen", 1500);

	set_skill("array", 100);
	set_skill("blade", 85);
	set_skill("dodge", 30);
	set_skill("force", 70);
	set_skill("move", 35);
	set_skill("parry", 40);
	set_skill("unarmed", 90);
	set_skill("badstrike", 100);
	set_skill("badforce", 80);
	set_skill("ghost-steps", 50);
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badstrike");
	map_skill("force", "badforce");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");
	set("functions/evil-blade/level", 35);

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.evil-blade" :),
	}));

	setup();
	//carry_object(BAD_OBJ"lion_blade")->wield();
	add_money("gold",10);
}
