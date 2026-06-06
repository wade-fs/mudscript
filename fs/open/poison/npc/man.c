#include "/open/open.h"
inherit NPC;


void create()
{
	set_name("冥蠱教徒", ({"trainee"}) );
	set("age",20);
	set("class", "poisoner");
	set("gender", "男性");
        set("long", "你看到一個冥蠱教的教徒.他好像幹了甚麼壞事.現在正鬼鬼祟祟的
待在一旁.似乎怕被人撞見。\n");
	set_skill("dodge", 30);
	set_skill("parry",10);
	set_skill("move", 30);
	set_skill("unarmed", 10);
	set_skill("nine-steps",30);

	set_skill("whip", 20);
	set_skill("force", 10);
	set_skill("poison", 30);
	map_skill("dodge","nine-steps");
	set("max_kee", 200);
	set("combat_exp", 5500);
	set("score", 1700);

	
	set("chat_chance_combat", 8);
	set("chat_msg_combat", ({
			"教徒說道:嘿嘿.敢向我挑戰.小子你不想活了是不是!\n",
			"教徒說道:趕快離開吧.大爺今天心情很好.放你一馬!\n",
}) );
	set("chat_chance", 10);
	set("chat_msg", ({
			"教徒說道:小子!!還不快離開.這裡不是讓你撒野的地方!\n",
			"教徒說道:喂.大爺瞧你不順眼.還不快滾!\n",
}) );
	set("inquiry", ([
		"壞事" : "壞事?...我那裡有做壞事呢.我不過是去借了點錢而以.\n"


]) );
	setup();
	add_money("silver", 5);
	carry_object("/open/poison/obj/ewhip.c")->wield();
        carry_object("/open/poison/obj/ebelt.c")->wear();
	carry_object("/open/poison/obj/ecloth.c")->wear();
}

void greeting(object me)
{
	if(me->query("family/family_name")=="冥蠱魔教")
	{ command("smile "+me->query("id"));
	}
	if(me->query("family/family_name")=="金刀門")
	{
	 command("say 嘿嘿! 好小子! 自己送上門來找死!!");
	kill_ob(me);
	}
}

