// ha.c by oda

#include "/open/open.h"

inherit F_VENDOR;

void create()
{
	set_name("哈哈兒", ({ "ha ha er", "ha", "er" }) );
	set("nickname", "笑裡藏刀笑彌陀");
	set("gender", "男性");
	set("age", 44);
	set("class", "bandit");
	set("attitude", "friendly");
	set("long", "你看到一個矮矮胖胖的圓臉胖子，臉上始終維持著一樣的笑容，好像\n不會累似的。不過要是你因此而忽略了對他的防備的話，那可就大錯\n特錯囉。\n他是這家飯館的掌櫃，你可以向他買些東西吃。\n");
	set("vendor_goods", ({
	BAD_OBJ"meal",
	BAD_OBJ"luwei",
	BAD_OBJ"wine",
	}));

	set("combat_exp", 550000);
	set("str", 25);
	set("cor", 25);
	set("int", 30);
	set("spi", 23);
	set("cps", 21);
	set("con", 25);
	set("per", 22);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 10);
	set("max_gin", 500);
	set("max_kee", 1000);
	set("max_sen", 500);

	set_skill("array", 90);
	set_skill("blade", 60);
	set_skill("dodge", 45);
	set_skill("force", 40);
	set_skill("move", 40);
	set_skill("parry", 35);
	set_skill("unarmed", 30);
	set_skill("badstrike", 60);
	set_skill("badforce", 50);
	set_skill("ghost-steps", 40);
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badblade");
	map_skill("force", "badforce");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");

	set("chat_chance", 8);
	set("chat_msg", ({
	"哈哈兒大笑道：哈哈，今天的天氣不錯，客人要不要吃點東西啊？哈哈。\n",
	"哈哈兒皮笑肉不笑的說：哈哈，我們這裡的特製大餐\不錯，肉質鮮美唷！哈哈。\n",
	}) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	}) );

	setup();
	//carry_object(BAD_OBJ"liu_blade")->wield();
	add_money("gold", 10);
}

int accept_fight(object me)
{
	command("say 在下怎麼可能是"+RANK_D->query_respect(me)+"的對手？您就別開我玩笑了。");
	remove_call_out("backstab");
	call_out("backstab", 3, me);
	return 0;
}

void backstab(object me)
{
	if(!me || environment(me)!=environment())
		return;
	message_vision("哈哈兒突然大喊了一聲：『納命來！』，便朝著$N的背後攻了過去。\n",me);
	this_object()->kill_ob(me);
}
