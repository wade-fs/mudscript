
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("強盜嘍囉",({"bandit"}) );
	set("long","
一個長的矮矮小小的強盜嘍囉。\n");
	set("age",19);
	set("gender","男性");
	set("title","黑風寨");
	set_skill("blade",20);
	set_skill("dodge",15);
	set_skill("parry",20);
	set("combat_exp", 200000);
	set("attitude","aggressive");
	set("chat_chance_combat", 5);
	set("chat_nsg_combat",({
	"強盜嘍囉說道:嘿嘿，快把身上的金銀珍寶留下，大爺饒你不死。\n"
	
	              }));
	setup();
	add_money("silver", 10);
	carry_object("/open/poison/obj/publade.c")->wield();
	carry_object("/obj/cloth.c")->wear();
}
