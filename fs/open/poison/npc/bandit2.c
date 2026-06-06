
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("強盜小頭目",({"bandit chief","chief"}));
	set("long","
一個率領著三、四名手下的小頭目，武藝較一般嘍囉自是高了一些。\n");
	set("age",25);
	set("gender","男性");
	set("title","黑風寨");
	set_skill("blade",30);
	set_skill("dodge",25);
	set_skill("parry",30);
	set("combat_exp", 300000);
	set("attitude","aggressive");
	set("chat_chance_combat", 5);
	set("chat_msg_combat",({
	"小頭目說道:還不快放下武器，大爺留你個全屍。\n",
}) );
	
	setup();
	add_money("silver", 20);
	carry_object("/open/poison/obj/blade1.c")->wield();
	carry_object("/obj/cloth.c")->wear();
}
